#include <stdio.h>
#include <math.h>

#include "base.h"
#include "adv.h"

// Main Variables 

Output output;
Camera camera = { {-screen_width/2,screen_height/2}, 1 };

// Function Declarations

void drawAxes(Camera camera);

void initialize_cam()
{
	for (int i = 0; i < screen_height; i++)
	{
		for (int j = 0; j < screen_width; j++)
		{
			output.stream[i][j] = ' ';
		}
	}
}
//Functions for calculating vectors

Vector lim(float i)
{
	float a = 1;
	float b = 1;
	Vector po = { (b + (a * cos(i))) * cos(i), (b + (a * cos(i))) * sin(i) };
	return po;
}

Vector Circle(float i)
{
	Vector point = { 5, i };
	return PolarToCartesian(point);
}

void mainProcess()
{
reiterate :
	
	drawAxes(camera);

	//Template for Rendering Curve with one parameter.
	CurveParamOne circle = { 0, 6.5, 0.02 , Circle};
	output = iterate(output, circle, camera);

	//Template for Rendering Curve with one parameter.
	CurveParamOne Limacon = { 0, 6.5, 0.01 ,lim};
	output = iterate(output, Limacon, camera);
	
	render(output.stream);
	camera = takeCommand(camera);
	initialize_cam();
	system("@cls||clear");
	goto reiterate;
}


int main()
{
	initialize_cam();
	mainProcess();
	return 0;
}


void drawAxes(Camera camera)
{
	Bound bounds = get_Bounds(camera);
	float step_x = (bounds.x_end - bounds.x_start) / screen_width;
	float step_y = (bounds.y_end - bounds.y_start) / screen_height;

	for (int i = 0; i < screen_width; i++)
	{
		for (int j = 0; j < screen_height; j++)
		{
			if ((0 >= bounds.x_start + (i * step_x)) && (0 < bounds.x_start + ((i + 1) * step_x)) && (0 >= bounds.y_start + (j * step_y)) && (0 < bounds.y_start + ((j + 1) * step_y)))
			{
				output.stream[j][i] = '+';
			}
			else if ((0 >= bounds.x_start + (i * step_x)) && (0 < bounds.x_start + ((i + 1) * step_x)))
			{
				output.stream[j][i] = '|';
			}
			else if ((0 >= bounds.y_start + (j * step_y)) && (0 < bounds.y_start + ((j + 1) * step_y)))
			{
				output.stream[j][i] = '-';
			}
		}
	}
}