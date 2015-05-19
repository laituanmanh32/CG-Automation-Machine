/*
 * GraphicObjectManager.cpp
 *
 *  Created on: Apr 25, 2015
 *      Author: manh
 */

#include "GraphicObjectManager.h"

#include <cstdio>

GraphicObjectManager::GraphicObjectManager() {
	// TODO Auto-generated constructor stub

}

GraphicObjectManager::~GraphicObjectManager() {
	// TODO Auto-generated destructor stub
}

void GraphicObjectManager::add(Shape* object){
	GraphicObjectList.push_back(object);
}

void GraphicObjectManager::draw(bool is){
	for(int i = 0; i < GraphicObjectList.size(); i++){
		GraphicObjectList[i]->drawSefl(is);
	}
}
