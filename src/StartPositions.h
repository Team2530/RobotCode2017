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

	//changed below starting positions: plate by loading station: left wheel of robot on line
	                                  //middle plate: wheel by overflow bin
	                                  //plate by boiler: right wheel of robot on line
	static const double startingRedLeftX = 94.2941; // center: 75.545;
	static const double startingRedMiddleX = 163.794; //center: 183.107;
	static const double startingRedRightX = 223.25; //center: 249.587;
	//starting position x for blue team
	static const double startingBlueLeftX = 61.7059;// center: 73.712;
	static const double startingBlueMiddleX = 121.206;//center: 140.192;
	static const double startingBlueRightX = 259.206;//center: 235.584;
	//all below do not account for robot width (39.5) or length (35.5)
	//TODO: make below coordinates where navx should be, not absolute target coordinates
	//coordinates (x,y,r) of red boiler and hopper
	static const double RobotWidth = 39.5;
	static const double RobotLength = 35.5;

	static const double distanceFromGear = 36;
	static const double centerFromGear = distanceFromGear + RobotWidth / 2;
	static const double centerFromBoiler = RobotLength/2;
	static const double centerFromHopper = RobotLength/2;
	static const double root3over2 = 0.86602540378443864676372317075294;
	static const double root2over2 = 0.70710678118654752440084436210485;


	static const double redBoilerPositionABSX = 278.23058;
	static const double redBoilerPositionX = redBoilerPositionABSX-(centerFromBoiler * root2over2);
	static const double redBoilerPositionR = 135;
	static const double redHopperPositionABSX = 51.7957;
	static const double redHopperPositionX = redHopperPositionABSX + (centerFromHopper * root3over2);
	static const double redHopperPositionR = -120;
	//coordinates (x,y,r) of blue boiler and hopper
	static const double blueBoilerPositionABSX = 51.79561;
	static const double blueBoilerPositionX = blueBoilerPositionABSX + (centerFromBoiler * root2over2);
	static const double blueBoilerPositionR = -135;
	static const double blueHopperPositionABSX = 278.23059;
	static const double blueHopperPositionX = blueHopperPositionABSX-(centerFromHopper* root3over2);
	static const double blueHopperPositionR = 120;

	static const double hopperPositionABSY = 64.352291;
	static const double hopperPositionY= hopperPositionY + (centerFromHopper * root3over2);
	static const double boilerPositionABSY = 70.562761;
	static const double boilerPositionY = boilerPositionABSY + (centerFromBoiler*root2over2);

	//gear positions
	// Add 90 degrees to position the Takko side forward


	static const double leftGearPlaceABSX = 162.2656;
	static const double leftGearPlaceABSY = 146.1925;
	static const double leftGearPlaceX = leftGearPlaceABSX - (centerFromGear * root3over2);
	static const double leftGearPlaceY = leftGearPlaceABSY - (centerFromGear / 2);
	static const double leftGearPlaceR = 60+90;

	static const double middleGearPlaceABSX = 192.0868;
	static const double middleGearPlaceABSY = 93.25;
	static const double middleGearPlaceX = middleGearPlaceABSX;
	static const double middleGearPlaceY = middleGearPlaceABSY - distanceFromGear;
	static const double middleGearPlaceR = 0+90;

	static const double rightGearPlaceABSX = 221.908;
	static const double rightGearPlaceABSY = 146.1925;
	static const double rightGearPlaceX = rightGearPlaceABSX + (centerFromGear * root3over2);
	static const double rightGearPlaceY = rightGearPlaceABSY - (centerFromGear / 2);
	static const double rightGearPlaceR = -60+90;

	static const double middleBaseLineX = 160;//rough approximation based on left gear delivery thing
	static const double middleBaseLineY = StartingPlaceY + 93.5;
	static const double middleBaseLineR = leftGearPlaceR;




#endif /* SRC_STARTPOSITIONS_H_ */
