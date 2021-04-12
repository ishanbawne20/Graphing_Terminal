#include <stdio.h>
#include <math.h>

#include "base.h"
#include "adv.h"

// Main Variables 

Output output;
Camera camera = { {-30,screen_height - 20}, 1 };

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

void mainProcess()
{
reiterate :
	
	printf("");

	//Template for Rendering Curve with one parameter.

	CurveParamOne circle = { 0, 6.5, 0.02 };

	for (float i = circle.one_start; i < circle.one_end; i += circle.one_step)
	{
		Vector point = { 30 + 10 * cos(i), 15 + 10 * sin(i) };
		ScreenVector index = indexer(point, camera);
		output.stream[index.y][index.x] = index.pixel;
	}

	// Another Template for rendering on parameter curve

	/*CurveParamOne sincurve = { -20, 50, 0.01 };

	for (float i = sincurve.one_start; i < sincurve.one_end; i+= sincurve.one_step)
	{
		Vector po = { i, 2*sin(i) };
		ScreenVector indo = indexer(po, camera);
		output.stream[indo.y][indo.x] = indo.pixel;
	}*/

	CurveParamOne Limacon = { 0, 6.5, 0.01 };

	float a = 1;
	float b = 1;

	for (float i = Limacon.one_start; i < Limacon.one_end; i += Limacon.one_step)
	{
		Vector po = { (b + (a*cos(i)))*cos(i), (b + (a * cos(i)))*sin(i) };
		ScreenVector indo = indexer(po, camera);
		output.stream[indo.y][indo.x] = indo.pixel;
	}

	drawAxes(camera);
	render(output.stream);
	camera = takeCommand(camera);
	initialize_cam();
	system("cls");
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
			if ((0 >= bounds.x_start + (i * step_x)) && (0 < bounds.x_start + ((i + 1) * step_x)))
			{
				output.stream[j][i] = '|';
			}
			if ((0 >= bounds.y_start + (j * step_y)) && (0 < bounds.y_start + ((j + 1) * step_y)))
			{
				output.stream[j][i] = '-';
			}
		}
	}
}