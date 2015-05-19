#ifndef CUBOID_H_
#define CUBOID_H_

#include "Shape.h"

/**
 * Define a cuboid geometry
 */
class Cuboid: public Shape {
public:
	Cuboid();
	Cuboid(float fSizeX,float fSizeY,float fSizeZ);
	virtual ~Cuboid();
	/**
	 * Recreate a new Cuboid with the new size.
	 * @param fSizeX
	 * @param fSizeY
	 * @param fSizeZ
	 */
	void setSize(float fSizeX,float fSizeY,float fSizeZ);
private:
	/**
	 * Initialize all cuboid property.
	 * @param fSizeX Size of cuboid on X-axis.
	 * @param fSizeY Size of cuboid on Y-axix
	 * @param fSizeZ Size of cuboid on Z-axix
	 */
	void init(float fSizeX,float fSizeY,float fSizeZ);
};

#endif /* CUBOID_H_ */