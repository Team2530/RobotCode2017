/*
 * StartPositions.h
 *
 *  Created on: Feb 9, 2017
 *      Author: celeste173
 */

#ifndef SRC_STARTPOSITIONS_H_
#define SRC_STARTPOSITIONS_H_

#include "Orientation.h"

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
	static const double startingRedLeftX =84.8;//left??: 98.5;//94.2941; // center: 75.545;
	static const double startingRedMiddleX = 179.4;//left: but...//157.5;//163.794; //center: 183.107;
	static const double startingRedRightX = 256;// left??:231.5;//262.75; //center: 249.587;
	//starting position x for blue team
	static const double startingBlueLeftX =68;// right: 106-(35.5/2);// 86.5;//71.4559;// center: 73.712;
	static const double startingBlueMiddleX = 144.6;//right: 106+76.5-(35.5/2);//110.5;//121.206;//center: 140.192;
	static const double startingBlueRightX = 239.2;// right:106+76.5+57-(35.5/2);//259.206;//center: 235.584;
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
	static const double redBoilerPositionR = 133.75;

	static const double redHopperPositionABSLX = 0;
	static const double redHopperPositionABSLY = 204;
	static const double redHopperPositionLX = redHopperPositionABSLX + (centerFromHopper * root3over2);
	static const double redHopperPositionLY= redHopperPositionABSLY;// + (centerFromHopper * root3over2);//check
	static const double redHopperPositionLR = -90;
	static const double redHopperPositionABSRX = 324;
	static const double redHopperPositionABSRY = 95.5;
	static const double redHopperPositionRX = redHopperPositionABSRX - (centerFromHopper * root3over2);
	static const double redHopperPositionRY = redHopperPositionABSLY;// + (centerFromHopper * root3over2);
	static const double redHopperPositionRR = 90;
	//coordinates (x,y,r) of blue boiler and hopper
	static const double blueBoilerPositionABSX = 51.79561;
	static const double blueBoilerPositionX = blueBoilerPositionABSX + (centerFromBoiler * root2over2);
	static const double blueBoilerPositionR = -133.5;

	static const double blueHopperPositionABSLX = 0;
	static const double blueHopperPositionABSLY = 95.5;
	static const double blueHopperPositionLX = blueHopperPositionABSLX+(centerFromHopper* root3over2);
	static const double blueHopperPositionLY = blueHopperPositionABSLY;//+(centerFromHopper * root3over2);//check
	static const double blueHopperPositionLR = -90;
	static const double blueHopperPositionABSRX = 324;
	static const double blueHopperPositionABSRY = 204;
	static const double blueHopperPositionRX = blueHopperPositionABSRX-(centerFromHopper*root3over2);
	static const double blueHopperPositionRY = blueHopperPositionABSRY;//+(centerFromHopper*root3over2);//check
	static const double blueHopperPositionRR = 90;

	//static const double hopperPositionABSY = 64.352291;
	static const double boilerPositionABSY = 70.562761;
	static const double boilerPositionY = boilerPositionABSY + (centerFromBoiler*root2over2);

	//gear positions
	// Add 90 degrees to position the Takko side forward


	static const double leftGearPlaceABSX = 138-21.867;//162.2656;
	static const double leftGearPlaceABSY = 133;//146.1925;
	static const double leftGearPlaceX = leftGearPlaceABSX - (centerFromGear * root3over2);
	static const double leftGearPlaceY = leftGearPlaceABSY - (centerFromGear / 2);
	static const double leftGearPlaceR = 60;

	static const double middleGearPlaceABSX = 138;//192.0868;
	static const double middleGearPlaceABSY = 93.25;
	static const double middleGearPlaceX = middleGearPlaceABSX;
	static const double middleGearPlaceY = middleGearPlaceABSY - distanceFromGear;
	static const double middleGearPlaceR = 0;

	static const double rightGearPlaceABSX = 138+21.867;//210;//221.908; ESTIMATE
	static const double rightGearPlaceABSY = 133;//146.1925;
	static const double rightGearPlaceX = rightGearPlaceABSX + (centerFromGear * root3over2);
	static const double rightGearPlaceY = rightGearPlaceABSY - (centerFromGear / 2);
	static const double rightGearPlaceR = -60;

	static const double middleBaseLineX = 160;//rough approximation based on left gear delivery thing
	static const double middleBaseLineY = StartingPlaceY + 93.5;
	static const double middleBaseLineR = 0;




#endif /* SRC_STARTPOSITIONS_H_ */
