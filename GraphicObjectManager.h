/*
 * GraphicObjectManager.h
 *
 *  Created on: Apr 25, 2015
 *      Author: manh
 */

#ifndef GRAPHICOBJECTMANAGER_H_
#define GRAPHICOBJECTMANAGER_H_

#include <vector>

#include "Shape/Shape.h"

using namespace std;

class GraphicObjectManager {
private:
	vector<Shape*> GraphicObjectList;
public:
	GraphicObjectManager();
	virtual ~GraphicObjectManager();

	void add(Shape* object);
	void draw(bool isWireframe);
};

#endif /* GRAPHICOBJECTMANAGER_H_ */
