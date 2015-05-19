/*
 * KeyboardListener.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef KEYBOARDLISTENER_H_
#define KEYBOARDLISTENER_H_

class KeyboardListener {
public:
	KeyboardListener();
	virtual ~KeyboardListener();

	virtual void onKeyPressed(unsigned char key, int x, int y) =0;
	virtual void onFuncKeyPressed(int key, int x, int y) = 0;
};

#endif /* KEYBOARDLISTENER_H_ */
