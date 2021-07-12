#include <stdio.h>
#include <math.h>

#include "base.h";
#include "adv.h"

void showVec(Vector a)
{
	printf("x: %f , y: %f ", a.x, a.y);
}

Output iterate(Output output, CurveParamOne curve, Camera camera)
{
	for (float i = curve.start; i < curve.end; i += curve.step)
	{
		ScreenVector index = indexer(curve.curve(i), camera);
		output.stream[index.y][index.x] = index.pixel;
	}
	return output;
}


Vector PolarToCartesian(Vector polar)
{
	Vector cart = { polar.x * cos(polar.y), polar.x * sin(polar.y) };
	return cart;
}