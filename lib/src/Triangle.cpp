//
// Created by neczp on 2016. 05. 15..
//
#include "../inc/Triangle.h"

Triangle::Triangle (const Point& a, const Point& b, const Point& c) : MyPolygon (a, b, c) {
}

Triangle::Triangle (const Point* a, const Point* b, const Point* c) : MyPolygon (a, b, c) { }

Point& Triangle::getA () {
	return getPoint (0);
}

Point& Triangle::getB () {
	return getPoint (1);
}

Point& Triangle::getC () {
	return getPoint (2);
}

double Triangle::getLengthA () {
	return getB ().distance (getC ());
}

double Triangle::getLengthB () {
	return getC ().distance (getA ());
}

double Triangle::getLengthC () {
	return getA ().distance (getB ());
}


double Triangle::getAngleA () {
	double a = getLengthA ();
	double b = getLengthB ();
	double c = getLengthC ();
	return acos ((a * a - b * b - c * c) / (2 * b * c));
}

double Triangle::getAngleB () {
	double a = getLengthA ();
	double b = getLengthB ();
	double c = getLengthC ();
	return acos ((b * b - a * a - c * c) / (2 * a * c));
}

double Triangle::getAngleC () {
	double a = getLengthA ();
	double b = getLengthB ();
	double c = getLengthC ();
	return acos ((c * c - b * b - a * a) / (2 * b * a));
}

Point* Triangle::getCentroid () {
	return new Point ((getA ().getX () + getB ().getX () + getC ().getX ()) / 3.0,
					  (getA ().getY () + getB ().getY () + getC ().getY ()) / 3.0);
}

Segment* Triangle::getAB () {
	return new Segment (getA (), getB ());
}

Segment* Triangle::getBC () {
	return new Segment (getB (), getC ());
}

Segment* Triangle::getCA () {
	return new Segment (getC (), getA ());
}

Circle* Triangle::getInnerCircle () {
	Line* b1 = getAngleBisectorC ();
	Line* b2 = getAngleBisectorA ();
	Point* p = b1->intersect (b2);
	Point k = *p;

	delete b1;
	delete b2;
	delete p;

	return new Circle (k, getArea () * 2 / (getPerimeter ()));
}

Circle* Triangle::getOuterCircle () {
	return new Circle (getA (), getB (), getC ());
}

Line* Triangle::getAngleBisectorA () {
	return getAngleBisector (getAB (), getCA (), getA ());
}

Line* Triangle::getAngleBisectorB () {
	return getAngleBisector (getBC (), getAB (), getB ());
}

Line* Triangle::getAngleBisectorC () {
	return getAngleBisector (getCA (), getBC (), getC ());
}

Line* Triangle::getAngleBisector (Segment* s1, Segment* s2, Point& vert) {
	//Fontos:
	s2->reverse ();

	double s1l = s1->getLength ();
	double s2l = s2->getLength ();


	if ( s1l > s2l ) {
		s1->setLength (s2l);
	} else {
		s2->setLength (s1l);
	}
	Line* l1 = new Line (s1);
	Line* l2 = new Line (s2);

	l1->perpendicularRotate (s1->getB ());
	l2->perpendicularRotate (s2->getB ());

	Point* p = l1->intersect (l2);
	Point nb = *p;

	delete s1;
	delete s2;
	delete l1;
	delete l2;
	delete p;

	return new Line (vert, nb);
}

Line* Triangle::getSegmentBisectorAB () {
	return Segment (getA (), getB ()).getBisector ();
}

Line* Triangle::getSegmentBisectorBC () {
	return Segment (getB (), getC ()).getBisector ();
}

Line* Triangle::getSegmentBisectorCA () {
	return Segment (getC (), getA ()).getBisector ();
}

void Triangle::setA (const Point& p) {
	double dx = p.getX () - getA ().getX ();
	double dy = p.getY () - getA ().getY ();
	getA ().setPosition (p);
	getB ().move (dx, dy);
	getC ().move (dx, dy);
}

void Triangle::setB (const Point& p) {
	double dx = p.getX () - getB ().getX ();
	double dy = p.getY () - getB ().getY ();
	getB ().setPosition (p);
	getA ().move (dx, dy);
	getC ().move (dx, dy);
}

void Triangle::setC (const Point& p) {
	double dx = p.getX () - getC ().getX ();
	double dy = p.getY () - getC ().getY ();
	getC ().setPosition (p);
	getB ().move (dx, dy);
	getC ().move (dx, dy);
}


