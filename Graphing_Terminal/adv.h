#pragma once

#ifndef COMMAND_H
#define COMMAND_H

// Structs

typedef struct CurvesParamOne
{
	double one_start;
	double one_end;
	double one_step;
} CurveParamOne;


typedef struct CurvesParamTwo
{
	double one_start;
	double two_start;
	double one_end;
	double two_end;
	double one_step;
	double two_step;
} CurveParamTwo;

// Function Declaration

Camera takeCommand(Camera camera);
Camera transCamera(Camera camera);
Camera scaleCamera(Camera camera);
Camera setPosCamera(Camera camera);

#endif // !COMMAND_H

