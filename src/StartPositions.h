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

enum ChosenGear{
	GEAR_LEFT,
	GEAR_MIDDLE,
	GEAR_RIGHT
};
enum Objects{
	HOPPER,
	BOILER,
	LEFT_GEAR_DELIVERY,
	MIDDLE_GEAR_DELIVERY,
	RIGHT_GEAR_DELIVERY
};
enum ObjectPositions{
	HOPPERY,
	HOPPERX,
	HOPPERR,
	BOILERY,
	BOILERX,
	BOILERR,
};

enum RobotChoice {
	MIRACLE_MAX,
	ZOMBERDINCK
};

//all X,Y are in inches. all R are in radians
	//almost 100% positive starting position accounts for length of robot
	static const double StartingPlaceY = 17.25; //y coordinate of starting place roughly,
	//starting position x for red team
	static const double startingRedLeftX = 75.545;
	static const double startingRedMiddleX = 183.107;
	static const double startingRedRightX = 249.587;
	//starting position x for blue team
	static const double startingBlueLeftX = 73.712;
	static const double startingBlueMiddleX = 140.192;
	static const double startingBlueRightX = 235.584;
	//all below do not account for robot width (39.5) or length (35.5)
	//coordinates (x,y,r) of red boiler and hopper
	static const double redBoilerPositionX = 278.23058;
	static const double redBoilerPositionR = 135;
	static const double redHopperPositionX = 51.7957;
	static const double redHopperPositionR = -120;
	//coordinates (x,y,r) of blue boiler and hopper
	static const double blueBoilerPositionX = 51.79561;
	static const double blueBoilerPositionR = -135;
	static const double blueHopperPositionX = 278.23059;
	static const double blueHopperPositionR = 120;

	static const double hopperPositionY = 64.352291;
	static const double boilerPositionY = 70.562761;

	//gear positions
	// Add 90 degrees to position the Takko side forward
	static const double leftGearPlaceX = 162.2656;
	static const double leftGearPlaceY = 146.1925;
	static const double leftGearPlaceR = 60+90;

	static const double middleGearPlaceX = 192.0868;
	static const double middleGearPlaceY = 93.25;
	static const double middleGearPlaceR = 0+90;

	static const double rightGearPlaceX = 221.908;
	static const double rightGearPlaceY = 146.1925;
	static const double rightGearPlaceR = -60+90;

	static const double middleBaseLineX = 160;//rough approximation based on left gear delivery thing
	static const double middleBaseLineY = StartingPlaceY + 93.5;
	static const double middleBaseLineR = leftGearPlaceR;




#endif /* SRC_STARTPOSITIONS_H_ */
