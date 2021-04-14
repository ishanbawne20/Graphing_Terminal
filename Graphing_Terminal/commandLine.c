#include <stdio.h>
#include <math.h>

#include "base.h"
#include "adv.h"

#pragma warning(disable:4996)


Camera takeCommand(Camera camera)
{
	char pross;
	printf("|| P : (%f, %f) || S : 1:%lf :: GTerminal >>> ", camera.position.x, camera.position.y, camera.scale);
	scanf(" %c", &pross);
	Camera retcam ;

	switch (pross)
	{
	case 't':
		retcam = transCamera(camera);
		return retcam;
		break;

	case 'a':
		printf("A Addition command\n");
		return camera;
		break;

	case 's':
		retcam = scaleCamera(camera);
		return retcam;
		break;

	case 'p':
		retcam = setPosCamera(camera);
		return retcam;
		break;


	default:
		printf("Invalid command enter a proper command.");
		return camera;
	}
}


Camera transCamera(Camera camera)
{
	char dir;
	float dist;
	scanf(" %c", &dir);
	scanf(" %f", &dist);

	switch (dir)
	{
	case 'h':
		camera.position.x += dist;
		return camera;
		break;

	case 'v':
		camera.position.y += dist;
		return camera;
		break;


	default:
		printf("Enter a valid Command.");
		return camera;
		break;
	}
}

Camera scaleCamera(Camera camera)
{
	float scale;
	scanf(" %f", &scale);
	camera.scale = scale;
	return camera;
}

Camera setPosCamera(Camera camera)
{
	float x;
	float y;

	scanf(" %f", &x);
	scanf(" %f", &y);

	camera.position.x = x;
	camera.position.y = y;
	return camera;
}