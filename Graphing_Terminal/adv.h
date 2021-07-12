#pragma once

#ifndef COMMAND_H
#define COMMAND_H

// Structs

typedef struct CurvesParamOne
{
	double start;
	double end;
	double step;
	Vector(*curve)(float);
} CurveParamOne;

// Function Declaration

Camera takeCommand(Camera camera);
Camera transCamera(Camera camera);
Camera scaleCamera(Camera camera);
Camera setPosCamera(Camera camera);

Vector PolarToCartesian(Vector polar);
Output iterate(Output output, CurveParamOne curve, Camera camera);

#endif // !COMMAND_H

