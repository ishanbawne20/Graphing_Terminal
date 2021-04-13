#include <stdio.h>
#include <math.h>

#include "base.h";
#include "adv.h"

void showVec(Vector a)
{
	printf("x: %f , y: %f ", a.x, a.y);
}


Vector PolarToCartesian(Vector polar)
{
	Vector cart = { polar.x * cos(polar.y), polar.x * sin(polar.y) };
	return cart;
}