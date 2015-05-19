/*
 * TimeListener.h
 *
 *  Created on: Apr 25, 2015
 *      Author: manh
 */

#ifndef TIMELISTENER_H_
#define TIMELISTENER_H_

class TimeListener{
public:
	TimeListener(){}
	virtual ~TimeListener(){}

	virtual void onTime(int) = 0;
};



#endif /* TIMELISTENER_H_ */
