#include <stdio.h>
#include <math.h>

#include "base.h"

// Main Variables 

char output[screen_height][screen_width];

// Function Declarations

void drawAxes(Camera camera);

void initialize_cam()
{
	for (int i = 0; i < screen_height; i++)
	{
		for (int j = 0; j < screen_width; j++)
		{
			output[i][j] = ' ';
		}
	}
}



int main()
{
	initialize_cam();

	Camera camera = { {-30,screen_height-20}, 1 };
	Vector centre = { 30,15 };

	for (float i = 0; i < 6.5; i+= 0.02)
	{
		Vector point = { centre.x + 10 * cos(i), centre.y + 10 * sin(i) };
		ScreenVector index = indexer(point, camera);
		output[index.y][index.x] = index.pixel;
	}

	drawAxes(camera);

	render(output);
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
				output[j][i] = '+';
			}
			if ((0 >= bounds.x_start + (i * step_x)) && (0 < bounds.x_start + ((i + 1) * step_x)))
			{
				output[j][i] = '|';
			}
			if ((0 >= bounds.y_start + (j * step_y)) && (0 < bounds.y_start + ((j + 1) * step_y)))
			{
				output[j][i] = '-';
			}
		}
	}
}