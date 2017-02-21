#include "../Commands/GetFieldPosition.h"
#include "Tracker.h"
#include "../RobotMap.h"


#include "../Robot.h"
#include "math.h"

Tracker::Tracker() :
	Subsystem("TrackerSubsystem"),
	pidxs(&this->currentPositionX),
	pidys(&this->currentPositionY),
	pidrs(&this->currentAngle),
	pidxo(&this->pidx),
	pidyo(&this->pidy),
	pidro(&this->pidr),
	pidxc(0.1, 0.001, 0.0, &pidxs, &pidxo),
	pidyc(0.1, 0.001, 0.0, &pidys, &pidyo),
	pidrc(0.1, 0.001, 0.0, &pidrs, &pidro)
{
	frontEncoder = new frc::Encoder(0,1,false, Encoder::CounterBase::k2X );//0,1 gonna change: encoder wires
	sideEncoder = new frc::Encoder(8,9,false, Encoder::CounterBase::k2X );//0,1 gonna change ^^
	frontEncoder->SetDistancePerPulse(0.012566);//encoderticks/revolution * dpi = 1/1000 * 4pi : ticks/rev = 1/1000 d = 4 pi = 3.14
	sideEncoder->SetDistancePerPulse(0.012566); //^^
	pidxc.SetTolerance(1.0); // inches
	pidyc.SetTolerance(1.0); // inches
	pidrc.SetTolerance(1.0); // degrees
	ahrs = new AHRS(SerialPort::kMXP);//check port
	table = NetworkTable::GetTable("robotPosition");
}
void Tracker::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	frontEncoder->Reset();
	sideEncoder->Reset();
	SetDefaultCommand(new GetFieldPosition());
}
void Tracker::StartTracking(){
	currentPositionX = Robot::initialX;
	currentPositionY = 17.25;
	currentAngle = 0;
}

void Tracker::GetPosition(){
	if (ahrs == nullptr) {
		ahrs = Robot::oi->GetAHRS();
	}
	double distanceX = sideEncoder->GetDistance();
	double distanceY = frontEncoder->GetDistance();
	double angle =  ahrs->GetAngle();
	double rad = angle * M_PI / 180;
	double changeInX = cos(rad) * distanceX + sin(rad) * distanceY;
	double changeInY = cos(rad) * distanceY - sin(rad) * distanceX;
	currentPositionX += changeInX;
	currentPositionY += changeInY;
	currentAngle = angle;
	frontEncoder->Reset();
	sideEncoder->Reset();
	table->PutNumber("x", currentPositionX);;
	table->PutNumber("y", currentPositionY);;
	table->PutNumber("angle", currentAngle);
}
/*double Tracker::GetOriginalPositionX(StartPosition position, frc::DriverStation::Alliance team){
	double xValue;
	if (team == StartPositions::StartTeamkRed){
		if (position == START_LEFT){
			xValue = 75.545; //all these are starting coordinates in inches
		}
		else if (position == START_MIDDLE){
			xValue = 183.107;
		}
		else{ // START_RIGHT
			xValue = 249.587;//^^
		}
	}
	else{ //frc::DriverStation::Alliance kBlue
		if (position == START_LEFT){
			xValue = 73.712;//^^
		}
		else if (position == START_MIDDLE){
			xValue = 140.192;//^^
		}
		else{//START_RIGHT
			xValue = 235.584;
		}
	}
	return xValue;

}

double Tracker::GetHopperPositionX(StartTeam team){
	double xValueHopper;
	if (team == StartPositions::StartTeam RED_TEAM){
		xValueHopper = 51.7957;//note: "actual" 26.6934 but have calc where navx is. assumes theta=45
	}
	else{ //frc::DriverStation::Alliance kBlue

	}
	return xValueHopper;
}
double Tracker::GetBoilerPositionX(StartTeam team){
	double xValueBoiler;
	if (team == StartPositions::StartTeam RED_TEAM){
		xValueBoiler = 278.23058; //note: "actual" 303.33288 but have calc where navx is. assumes theta 22.5, 45
	}
	else{ //frc::DriverStation::Alliance kBlue

	}
	return xValueBoiler;
}
double Tracker::GetGearPositionX(Objects position){
	double gearPlaceX;
	if (position == MIDDLE_GEAR_DELIVERY){
		gearPlaceX = 192.0868;
	}
	else if (position == LEFT_GEAR_DELIVERY){
		gearPlaceX = 162.2656;
	}
	else {//RIGHT_GEAR_DELIVERY
		gearPlaceX = 221.908;
	}
	return gearPlaceX;
}
double Tracker::GetGearPositionY(Objects position){
	double gearPlaceY;
	if (position == MIDDLE_GEAR_DELIVERY){
		gearPlaceY= 93.25;
	}
	else if (position == LEFT_GEAR_DELIVERY){
		gearPlaceY = 146.1925;
	}
	else { //RIGHT_GEAR_DELIVERY
		gearPlaceY = 146.1925;
	}
	return gearPlaceY;
}
double Tracker::GetGearPositionR(Objects position){
	double gearPlaceR;
	if (position == LEFT_GEAR_DELIVERY){
		gearPlaceR = 60;
	}
	else if (position == MIDDLE_GEAR_DELIVERY){
		gearPlaceR = 0;
	}
	else {//RIGHT_GEAR_DELIVERY
		gearPlaceR = -60;
	}
	return gearPlaceR;
}*/
double Tracker::GetForwardDistance(){
	return frontEncoder->GetDistance();
}
double Tracker::GetSideDistance(){
	return sideEncoder->GetDistance();
}

void Tracker::RotateTo(double angle) {
	pidrc.SetSetpoint(angle);
	pidxc.SetSetpoint(currentPositionX);
	pidyc.SetSetpoint(currentPositionY);
}
/*double Tracker::GetTargetPositionX(Objects aTarget, frc::DriverStation::Alliance aTeam){
	double targetX;
	if (aTarget == HOPPER){
		targetX = Robot::tracker->GetHopperPositionX(aTeam);
	}
	else if (aTarget == BOILER){
		targetX = Robot::tracker->GetBoilerPositionX(aTeam);
	}
	else{//if it's a gear thing
		targetX = Robot::tracker->GetGearPositionX(aTarget);
	}
	return targetX;
}
double Tracker::GetTargetPositionY(Objects aTarget){
	double targetY;
	if (aTarget == HOPPER){
		targetY = 64.352291;//hopperPositionY
	}
	else if (aTarget == BOILER){
		targetY = 70.562761;//boilerPositionY
	}
	else{//if it's a gear thing
		targetY = Robot::tracker->GetGearPositionY(aTarget);
	}
}*/

void Tracker::RotateBy(double deltaAngle) {
	double angle = currentAngle + deltaAngle;
	RotateTo(angle);
}

void Tracker::MoveToRel(double forward, double right) {
}

void Tracker::MoveToAbs(double x, double y) {
	pidxc.SetSetpoint(x);
	pidyc.SetSetpoint(y);
	pidrc.SetSetpoint(currentAngle); // make sure we stay aligned while moving
	//pidxc.Enable();
	pidyc.Enable();
	//pidrc.Enable();
}

double Tracker::GetPIDX() {
	return pidx;
}

double Tracker::GetPIDY() {
	return pidy;
}

double Tracker::GetPIDRotation() {
	return pidr;
}

bool Tracker::PIDFinished() {
	return pidxc.OnTarget() && pidyc.OnTarget() && pidrc.OnTarget();
}

void Tracker::PIDReset() {
	pidxc.Reset();
	pidyc.Reset();
	pidrc.Reset();
}
double Tracker::GetPIDBackward() {
	double rad = currentAngle * M_PI / 180;
	return -sin(rad) * pidx - cos(rad) * pidy;
}

double Tracker::GetPIDRight() {
	double rad = currentAngle * M_PI / 180;
	return cos(rad) * pidx + sin(rad) * pidy;
}
double Tracker::GetCurrentPositionX(){
	return currentPositionX;
}
double Tracker::GetCurrentPositionY(){
	return currentPositionY;
}
