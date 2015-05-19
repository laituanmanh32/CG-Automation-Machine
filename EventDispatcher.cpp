/*
 * EventDispatcher.cpp
 *
 *  Created on: Apr 24, 2015
 *      Author: manh
 */

#include "EventDispatcher.h"

#include <cstdio>

EventDispatcher::EventDispatcher() {
	// TODO Auto-generated constructor stub

}

EventDispatcher::~EventDispatcher() {
	// TODO Auto-generated destructor stub
}

void EventDispatcher::onKeyPressed(unsigned char key, int x, int y) {
	for (int i = 0; i < keyboardListener.size(); i++) {
		keyboardListener[i]->onKeyPressed(key, x, y);
	}
}

void EventDispatcher::onFuncKeyPressed(int key, int x, int y) {
	for (int i = 0; i < keyboardListener.size(); i++) {
		keyboardListener[i]->onFuncKeyPressed(key, x, y);
	}
}

void EventDispatcher::addKeyboardListener(KeyboardListener* kbListener) {
	keyboardListener.push_back(kbListener);
}

void EventDispatcher::addTimeListener(TimeListener* listener) {
	timeListener.push_back(listener);
}

void EventDispatcher::onTime(int value) {
	for (int i = 0; i < timeListener.size(); i++) {
		timeListener[i]->onTime(value);
	}
}
