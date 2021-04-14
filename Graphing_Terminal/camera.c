#include <stdio.h>
#include <math.h>

#include "base.h"
#include "adv.h"


Bound get_Bounds(Camera camera)
{
	Bound bound = { camera.position.x, (camera.position.x + screen_width) * camera.scale,(camera.position.y - screen_height) * camera.scale ,camera.position.y };
	return bound;
}

ScreenVector indexer(Vector position, Camera camera)
{
	Bound bounds = get_Bounds(camera);
	float step_x = (bounds.x_end - bounds.x_start) / screen_width;
	float step_y = (bounds.y_end - bounds.y_start) / screen_height;

	for (int i = 0; i < screen_width; i++)
	{
		for (int j = 0; j < screen_height; j++)
		{
			if ((position.x >= bounds.x_start + (i * step_x)) && (position.x < bounds.x_start + ((i + 1) * step_x)) && (position.y >= bounds.y_start + (j * step_y)) && (position.y < bounds.y_start + ((j + 1) * step_y)))
			{
				ScreenVector index = { i,j,'*' };
				return index;
			}
		}
	}
	ScreenVector index = { 0,0,' ' };
	return index;
}


void render(char output[screen_height][screen_width])
{
	for (int i = screen_height - 1; i >= 0; i--)
	{
		for (int j = 0; j < screen_width; j++)
		{
			printf("%c", output[i][j]);
		}
		printf("\n");
	}
}