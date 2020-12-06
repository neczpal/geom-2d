//
// Created by neczp on 2016. 05. 05..
//

#include "../inc/Line.h"

/**
 * xc * x + yc * y = ec
 */
Line::Line (double xc, double yc, double ec) : pX (xc), pY (yc), pE (ec) {
}

Line::Line (const Segment* s) : Line (s->getA ()->getY () - s->getB ()->getY (),
									  s->getB ()->getX () - s->getA ()->getX (),
									  (s->getA ()->getY () - s->getB ()->getY ()) *
									  s->getA ()->getX () +
									  (s->getB ()->getX () - s->getA ()->getX ()) *
									  s->getA ()->getY ()) {
}

Line::Line (const Segment& s) : Line (&s) {
}

Line::Line (const Point* a, const Point* b) : Line (Segment (a, b)) {
}

Line::Line (const Point& a, const Point& b) : Line (Segment (a, b)) {
}

Line::Line (const Point* p, double nx, double ny) : Line (nx, ny, p->getX () * nx + p->getY () * ny) {
}

Line::Line (const Point* p, double m) : Line (-m, 1, p->getY () - m * p->getX ()) {
}

Point* Line::intersect (const Line* l) {
	if ( pX == l->pX && pY == l->pY ) {
		return NULL;
	}
	double nX, nY;

	if ( pX == 0 ) {//pY = e
		if ( l->pY == 0 ) {//l->pX = l->pE
			nX = l->pE / l->pX;
			nY = pE / pY;
		} else {
			double pYp = l->pY / pY;
			nX = (l->pE - pE * pYp) / (l->pX - pX * pYp);
			nY = (l->pE - l->pX * nX) / l->pY;
		}
	} else {
		if ( pY == 0 && l->pX == 0 ) {//pX = pE | l->pY = l->pE
			nX = pE / pX;
			nY = l->pE / l->pY;
		} else {
			double pXp = l->pX / pX;
			nY = (l->pE - pE * pXp) / (l->pY - pY * pXp);
			nX = (l->pE - l->pY * nY) / l->pX;
		}
	}
	return new Point (nX, nY);
}

void Line::perpendicularRotate (const Point* p) {
	double nxc = pY;
	double nyc = -pX;

	pX = nxc;
	pY = nyc;
	pE = pX * p->getX () + pY * p->getY ();
}

bool Line::isOn (const Point* p) {
	return pX * p->getX () + pY * p->getY () == pE;
}
