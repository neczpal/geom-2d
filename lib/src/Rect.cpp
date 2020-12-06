//
// Created by neczp on 2016. 05. 13..
//

#include <iostream>
#include "../inc/Rect.h"

#include <GLUT/GLUT.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>


Rect::Rect (double x, double y, double w, double h) {
	if ( w <= 0 || h <= 0 ) {
		std::cerr << "Rect width and height must be bigger than 0!" << std::endl;
		return;
	}
	pA = new Point (x, y);
	pB = new Point (x + w, y + h);
}

Rect::Rect (const Point& a, double w, double h) : Rect (a.getX (), a.getY (), w, h) {
}

Rect::Rect (const Point* a, double w, double h) : Rect (a->getX (), a->getY (), w, h) {
}

Rect::~Rect () {
	delete pA;
	delete pB;
}


bool Rect::operator== (const Rect& another) const {
	return *pA == *another.pA && *pB == *another.pB;
}

double Rect::getArea () {
	return getWidth () * getHeight ();
}

double Rect::getPerimeter () {
	return 2 * (getWidth () + getHeight ());
}

bool Rect::isInside (const Point* p) {
	return getX () <= p->getX () && p->getX () <= pB->getX () &&
		   getY () <= p->getY () && p->getY () <= pB->getY ();
}

void Rect::draw () {
	setupColor ();

	glBegin (GL_LINE_LOOP);
	{
		glVertex2d (pA->getX (), pA->getY ());
		glVertex2d (pA->getX (), pB->getY ());
		glVertex2d (pB->getX (), pB->getY ());
		glVertex2d (pB->getX (), pA->getY ());
	}
	glEnd ();
}

double Rect::getX () const {
	return pA->getX ();
}

double Rect::getY () const {
	return pA->getY ();
}

double Rect::getWidth () const {
	return pB->getX () - pA->getX ();
}

double Rect::getHeight () const {
	return pB->getY () - pB->getY ();
}

void Rect::setX (double x) {
	double w = getWidth ();
	pA->setX (x);
	pB->setX (x + w);
}

void Rect::setY (double y) {
	double h = getHeight ();
	pA->setY (y);
	pB->setY (y + h);
}

void Rect::setWidth (double width) {
	if ( width <= 0 ) {
		std::cerr << "Rect width must be bigger than 0!" << std::endl;
		return;
	}
	pB->setX (pA->getX () + width);
}

void Rect::setHeight (double height) {
	if ( height <= 0 ) {
		std::cerr << "Rect height must be bigger than 0!" << std::endl;
		return;
	}
	pB->setY (pA->getY () + height);
}

