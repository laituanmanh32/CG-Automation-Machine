/*
 * EventDispatcher.h
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#ifndef EVENTDISPATCHER_H_
#define EVENTDISPATCHER_H_

#include <vector>

#include "KeyboardListener.h"
#include "TimeListener.h"

using namespace std;

class EventDispatcher {
	vector<KeyboardListener*> keyboardListener;
	vector<TimeListener*> timeListener;
public:
	EventDispatcher();
	virtual ~EventDispatcher();

	void addKeyboardListener(KeyboardListener* listener);
	void addTimeListener(TimeListener* listener);
	void onKeyPressed(unsigned char key, int x, int y);
	void onFuncKeyPressed(int key, int x, int y);
	void onTime(int);
};

#endif /* EVENTDISPATCHER_H_ */
