//
// Created by neczp on 2016. 05. 04..
//


#include "Point.h"
#include "Line.h"

#include <GLUT/GLUT.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>


Point::Point (double x, double y) : Transformable () {
	setPosition (x, y);
}

void Point::setPosition (double x, double y) {
	pX = x;
	pY = y;
}

void Point::setPosition (const Point* p) {
	setPosition (p->pX, p->pY);
}

void Point::setPosition (const Point& p) {
	setPosition (&p);
}

double Point::distance (const Point* p) {
	return sqrt (pow (p->pX - pX, 2) + pow (p->pY - pY, 2));
}

double Point::distance (const Point& p) {
	return distance (&p);
}

bool Point::operator== (const Point& another) const {
	return this->pX == another.pX && this->pY == another.pY;
}

void Point::move (double dx, double dy) {
	pX += dx;
	pY += dy;
}

void Point::reflect (const Point* p) {
	setPosition (2 * p->pX - pX, 2 * p->pY - pY);
}

void Point::reflect (const Line* e) {
	Line* f = new Line (*e);
	f->perpendicularRotate (this);
	Point* p = f->intersect (e);
	setPosition (2 * p->getX () - getX (), 2 * p->getY () - getY ());

	delete p;
	delete f;
}

void Point::rotate (const Point* p, double df) {
	double dx = p->pX - pX;
	double dy = p->pY - pY;
	double cosf = cos (df);
	double sinf = sin (df);

	setPosition (p->pX - (dx * cosf - dy * sinf),
				 p->pY - (dx * sinf + dy * cosf));
}


void Point::draw () {
	setupColor ();

	glBegin (GL_POINTS);
	{
		glVertex2d (pX, pY);
	}
	glEnd ();
}



