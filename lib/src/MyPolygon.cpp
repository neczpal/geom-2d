//
// Created by neczp on 2016. 05. 07..
//
#include "../inc/MyPolygon.h"

#include <GLUT/GLUT.h>
#include <OpenGL/gl3.h>
#include <OpenGL/glu.h>


MyPolygon::MyPolygon (const Point& a, const Point& b, const Point& c) : Shape () {
	if ( a == b || b == c || a == c ) {
		std::cerr << "Can't describe a polygon with less than 3 different Point" << std::endl;
		return;
	}
	Line* l = new Line (a, b);
	if ( l->isOn (&c)) {
		std::cerr << "Can't describe a polygon with 3 Point on the same line" << std::endl;
		return;
	}

	pLast = new Node<Point> (b);
	pLast->next = pLast;
	pNum = 1;
	addPoint (a);
	addPoint (c);
}

MyPolygon::MyPolygon (const Point* a, const Point* b, const Point* c) : MyPolygon (*a, *b, *c) {
}

MyPolygon::~MyPolygon () {
	Node<Point>* toDel = pLast->next;
	Node<Point>* start = pLast->next;
	pLast->next = NULL;

	while ( toDel != NULL ) {
		start = start->next;
		delete toDel;
		toDel = start;
	}
}

void MyPolygon::addPoint (const Point& p, int pos) {
	if ( contains (p))
		return;

	Node<Point>* t = new Node<Point> (p);
	Node<Point>* s = pLast->next;
	for ( int i = 0; i < pos; i++ ) {
		s = s->next;
		if ( s == pLast->next ) {
			std::cerr << "There is no " << pos << " Points in the MyPolygon." << std::endl;
			return;
		}
	}
	t->next = s->next;
	s->next = t;
	if ( s == pLast ) {
		pLast = t;
	}
	pNum++;
}

void MyPolygon::delPoint (const Point& p) {
	if ( pNum <= 3 ) {
		std::cerr << "Can't delete P( " << p.getX () << ", " << p.getY () <<
		") from MyPolygon because it has only 3 Points." << std::endl;
		return;
	}
	Node<Point>* s = pLast->next;

	if ( s->value == p ) {
		Node<Point>* temp = s;
		pLast->next = s->next;

		delete temp;

		pNum--;
		return;
	}
	while ( s->next != pLast ) {
		if ( s->next->value == p ) {
			Node<Point>* temp = s->next;
			s->next = temp->next;

			delete temp;

			pNum--;
			return;
		}
		s = s->next;
	}
	if ( s->next->value == p ) {
		Node<Point>* temp = s->next;
		s->next = pLast->next;

		delete temp;
		pLast = s;

		pNum--;
		return;
	}
}

bool MyPolygon::contains (const Point& p) {
	Node<Point>* s = pLast;
	do {
		if ( s->value == p ) {
			return true;
		}
		s = s->next;
	} while ( s != pLast );

	return false;
}

Point& MyPolygon::getPoint (int pos) {
	Node<Point>* s = pLast->next;

	if ( pos > pNum ) { std::cerr << "There is no " << pos << " Points in the MyPolygon!" << std::endl; }

	for ( int i = 0; i < pos; i++ ) {
		s = s->next;
	}
	return s->value;
}

Point& MyPolygon::operator[] (int pos) {
	return getPoint (pos);
}


void MyPolygon::move (double dx, double dy) {
	Node<Point>* s = pLast;
	do {
		s->value.move (dx, dy);
		s = s->next;
	} while ( s != pLast );
}

void MyPolygon::reflect (const Point* p) {
	Node<Point>* s = pLast;
	do {
		s->value.reflect (p);
		s = s->next;
	} while ( s != pLast );
}

void MyPolygon::reflect (const Line* e) {
	Node<Point>* s = pLast;
	do {
		s->value.reflect (e);
		s = s->next;
	} while ( s != pLast );
}

void MyPolygon::rotate (const Point* p, double degree) {
	Node<Point>* s = pLast;
	do {
		s->value.rotate (p, degree);
		s = s->next;
	} while ( s != pLast );
}

double MyPolygon::getArea () {
	double d = 0.0;

	Node<Point>* s = pLast;
	do {
		d += s->value.getX () * s->next->value.getY () - s->next->value.getX () * s->value.getY ();
		s = s->next;
	} while ( s != pLast );

	return fabs (d / 2.0);
}

double MyPolygon::getPerimeter () {
	double d = 0.0;

	Node<Point>* s = pLast;
	do {
		d += s->value.distance (&s->next->value);
		s = s->next;
	} while ( s != pLast );

	return d;
}

bool MyPolygon::isInside (const Point* p) {
	Point& lp = pLast->value;
	double minX = lp.getX ();
	double maxX = lp.getX ();
	double minY = lp.getY ();
	double maxY = lp.getY ();

	for ( Node<Point>* s = pLast->next; s != pLast; s = s->next ) {
		Point& q = s->value;
		minX = q.getX () < minX ? q.getX () : minX;
		maxX = q.getX () > maxX ? q.getX () : maxX;
		minY = q.getY () < minY ? q.getY () : minY;
		maxY = q.getY () > maxY ? q.getY () : maxY;
	}

	if ( p->getX () < minX || p->getX () > maxX || p->getY () < minY || p->getY () > maxY ) {
		return false;
	}

	bool c = false;

	Node<Point>* s = pLast;
	do {
		if (((s->next->value.getY () > p->getY ()) != (s->value.getY () > p->getY ())) &&
			(p->getX () < (s->value.getX () - s->next->value.getX ()) *
						  (p->getY () - s->next->value.getY ()) / (s->value.getY () - s->next->value.getY ()) +
						  s->next->value.getX ())) {
			c = !c;
		}
		s = s->next;
	} while ( s != pLast );

	return c;
}

void MyPolygon::draw () {
	setupColor ();

	glBegin (GL_LINE_LOOP);
	{
		Node<Point>* s = pLast;
		do {
			glVertex2d (s->value.getX (), s->value.getY ());
			s = s->next;
		} while ( s != pLast );
	}
	glEnd ();
}
