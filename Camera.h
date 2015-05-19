/*
 * Camera.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef CAMERA_H_
#define CAMERA_H_

#include "KeyboardListener.h"
#include "GraphicObjectManager.h"

class Camera: public KeyboardListener {

	bool b4View;

	float camera_angle;
	float camera_height;
	float camera_dis;

	float screenWidth;
	float screenHeight;

public:
	Camera();
	Camera(float screenWidth,float screenHeight);
	virtual ~Camera();

	void onKeyPressed(unsigned char key, int x, int y);
	void onFuncKeyPressed(int key, int x, int y);
	void DisplayOneView(int nType, int left, int right, int top, int bottom);
	void SetupCameraVolume(int nType);
	void configDisplay(GraphicObjectManager gom);
};

#endif /* CAMERA_H_ */
