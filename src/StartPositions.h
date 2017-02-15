/*
 * StartPositions.h
 *
 *  Created on: Feb 9, 2017
 *      Author: celeste173
 */

#ifndef SRC_STARTPOSITIONS_H_
#define SRC_STARTPOSITIONS_H_

enum StartPosition{
	START_LEFT,
	START_MIDDLE,
	START_RIGHT

};
enum StartTeam{
	BLUE_TEAM,
	RED_TEAM
};
enum ObjectPositions{
	HOPPERY,
	HOPPERX,
	HOPPERR,
	BOILERY,
	BOILERX,
	BOILERR,
	LEFT_GEAR_DELIVERY,
	MIDDLE_GEAR_DELIVERY,
	RIGHT_GEAR_DELIVERY
};
	static const double leftGearPlaceX = 162.2656;
	static const double leftGearPlaceY = 146.1925;
	static const double leftGearPlaceR = 60;
	static const double rightGearPlaceX = 221.908;
	static const double rightGearPlaceY = 146.1925;
	static const double rightGearPlaceR = -60;
	static const double middleGearPlaceX = 192.0868;
	static const double middleGearPlaceY = 93.25;
	static const double middleGearPlaceR = 0;




#endif /* SRC_STARTPOSITIONS_H_ */
