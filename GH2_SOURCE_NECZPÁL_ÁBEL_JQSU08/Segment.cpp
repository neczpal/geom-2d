//
// Created by neczp on 2016. 05. 11..
//

#include <iostream>
#include "Line.h"

Segment::Segment (const Point* a, const Point* b) {
	if ( *a == *b ) {
		std::cerr << "Can't describe a Segment with 1 Point!" << std::endl;
		return;
	}
	pA = new Point (*a);
	pB = new Point (*b);
}

Segment::Segment (const Point& a, const Point& b) : Segment (&a, &b) {
}

Segment::~Segment () {
	delete pA;
	delete pB;
}

bool Segment::operator== (const Segment& another) const {
	return *pA == *another.pA && *pB == *another.pB;
}

Point* Segment::getBisectorPoint () {
	return new Point ((pA->getX () + pB->getX ()) / 2, (pA->getY () + pB->getY ()) / 2);
}

Line* Segment::getBisector () {
	Line* l = new Line (this);
	Point* p = getBisectorPoint ();
	l->perpendicularRotate (p);
	delete p;
	return l;
}

void Segment::reverse () {
	Point* tmp;
	tmp = pA;
	pA = pB;
	pB = tmp;
}

void Segment::setLength (double new_length) {
	double dx = pB->getX () - pA->getX ();
	double dy = pB->getY () - pA->getY ();
	double old_length = getLength ();
	double nx = (dx * new_length) / old_length;
	double ny = (dy * new_length) / old_length;

	pB->setPosition (getB ()->getX () - dx + nx, getB ()->getY () - dy + ny);
}

double Segment::getLength () {
	return pA->distance (pB);
}

void Segment::move (double dx, double dy) {
	pA->move (dx, dy);
	pB->move (dx, dy);
}

void Segment::reflect (const Point* p) {
	pA->reflect (p);
	pB->reflect (p);
}

void Segment::reflect (const Line* e) {
	pA->reflect (e);
	pB->reflect (e);
}

void Segment::rotate (const Point* p, double degree) {
	pA->rotate (p, degree);
	pB->rotate (p, degree);
}

void Segment::draw () {
	setupColor ();

	glBegin (GL_LINES);
	{
		glVertex2d (pA->getX (), pA->getY ());
		glVertex2d (pB->getX (), pB->getY ());
	}
	glEnd ();
}



