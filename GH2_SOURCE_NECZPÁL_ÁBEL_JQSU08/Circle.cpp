//
// Created by neczp on 2016. 05. 13..
//

#include <iostream>
#include "Point.h"
#include "Line.h"
#include "Circle.h"

Circle::Circle (double x, double y, double r) {
	if ( r <= 0 ) {
		std::cerr << "Radius of a circle should be bigger than 0." << std::endl;
		return;
	}
	pP = new Point (x, y);
	pR = r;
}

Circle::Circle (const Point& p, double r) : Circle (p.getX (), p.getY (), r) {
}

Circle::Circle (const Point* p, double r) : Circle (*p, r) {
}

Circle::Circle (const Point& a, const Point& b, const Point& c) {
	if ( a == b || a == c || b == c ) {
		std::cerr << "Can't describe a circle with 2 different Points / 1 Point!" << std::endl;
		return;
	}
	Segment* s1 = new Segment (a, b);
	Segment* s2 = new Segment (b, c);

	Line* l1 = s1->getBisector ();
	Line* l2 = s2->getBisector ();

	if ( l1->isOn (&c)) {
		std::cerr << "Can't describe a circle with 3 Points on the same line!" << std::endl;
		delete s1;
		delete s2;
		delete l1;
		delete l2;
		return;
	}

	this->pP = l1->intersect (l2);
	this->pR = pP->distance (a);

	delete s1;
	delete s2;
	delete l1;
	delete l2;
}

Circle::Circle (const Point* a, const Point* b, const Point* c) : Circle (*a, *b, *c) {
}

Circle::~Circle () {
	delete pP;
}

void Circle::setPosition (const Point& p) {
	pP->setPosition (p);
}

void Circle::setPosition (const Point* p) {
	setPosition (*p);
}

bool Circle::operator== (const Circle& another) const {
	return *pP == *another.pP && pR == another.pR;
}

void Circle::move (double dx, double dy) {
	pP->move (dx, dy);
}

void Circle::reflect (const Point* p) {
	pP->reflect (p);
}

void Circle::reflect (const Line* e) {
	pP->reflect (e);
}

void Circle::rotate (const Point* p, double degree) {
	pP->rotate (p, degree);
}

double Circle::getArea () {
	return pR * pR * PI;
}

double Circle::getPerimeter () {
	return 2 * pR * PI;
}

bool Circle::isInside (const Point* p) {
	return pow (pP->getX () - p->getX (), 2) + pow (pP->getY () - p->getY (), 2) <= pR * pR;
}

void Circle::draw () {
	setupColor ();

	glBegin (GL_LINE_LOOP);
	{
		double maxAngle = 2 * PI;
		double difAngle = maxAngle / CIRCLE_POINTS;

		for ( double curAngle = 0.0; curAngle < maxAngle;
			  curAngle += difAngle ) {
			double x = pR * cos (curAngle);
			double y = pR * sin (curAngle);
			glVertex2d (pP->getX () + x, pP->getY () + y);
		}
	}
	glEnd ();
}

double Circle::getX () const {
	return pP->getX ();
}

void Circle::setX (double x) {
	pP->setX (x);
}

double Circle::getY () const {
	return pP->getY ();
}

void Circle::setY (double y) {
	pP->setY (y);
}

double Circle::getR () const {
	return pR;
}

void Circle::setR (double r) {
	if ( r <= 0 ) {
		std::cerr << "Radius of a circle should be bigger than 0!" << std::endl;
		return;
	}
	pR = r;
}



