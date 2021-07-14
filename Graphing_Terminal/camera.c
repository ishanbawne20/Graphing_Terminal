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

	ScreenVector origin = {  - bounds.x_start / step_x, - bounds.y_start / step_y, ' ' };
	
	ScreenVector index = { origin.x + (position.x / step_x), origin.y + (position.y / step_y), '*' };
	if (index.x >= 0 && index.y >= 0 && index.x < screen_width && index.y < screen_height)
	{
		return index;
	}
	else {
		ScreenVector alt = { 0,0,' ' };
		return alt;
	}
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