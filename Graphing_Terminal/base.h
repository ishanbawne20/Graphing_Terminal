#pragma once

#ifndef BASE_H
#define BASE_H

#define screen_width 100
#define screen_height 50

#include <stdio.h>

//Structs

typedef struct Vectors{
	float x;
	float y;
} Vector;


typedef struct ScreenVectors{
	int x;
	int y;
	char pixel;
} ScreenVector;

typedef struct Cameras
{
	Vector position;
	float scale;
} Camera;


typedef struct Bounds
{
	float x_start;
	float x_end;
	float y_start;
	float y_end;
} Bound;

//Function declarations 

// // From Camera.c

Bound get_Bounds(Camera camera);
ScreenVector indexer(Vector position, Camera camera);
void render(char output[screen_height][screen_width]);

// // From curves.c
void showVec(Vector a);

#endif // !1
