#pragma once
#include <iostream>

enum CoordinateSystem {
	GRAPHICS_ORIENTED,
	ROBOT_GLOBAL,
	ARM_I,
	ARM_II,
	ARM_III,
	ARM_IV
};

class Point {
public:
	Point() : x(0), y(0), r(0), theta(0), polar(false), system(ROBOT_GLOBAL) {};

	double getX();
	double getY();
	double getR();
	double getTheta();
	CoordinateSystem getSystem();

	Point asGraphicsOriented();
	Point asRobotGlobal();
	Point asArmI();
	Point asArmII();
	Point asArmIII();
	Point asArmIV();
	Point asSystem(CoordinateSystem system);

	void print() const;

	static Point fromRobotGlobal(double x, double y);
	static Point fromGraphicsOriented(double x, double y);
	static Point withCoordinateSystem(double x, double y, CoordinateSystem system);
private:
	Point(double x, double y, CoordinateSystem system) : x(x), y(y), r(0), theta(0), polar(false), system(system) {};

	//x, y, r in units of inches, theta in units of degrees
	double x;
	double y;
	double r;
	double theta;

	bool polar;

	CoordinateSystem system;
};