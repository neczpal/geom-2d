//
// Created by neczp on 2016. 05. 05..
//

#ifndef GH_2_LINE_H
#define GH_2_LINE_H

#include "Point.h"
#include "Segment.h"

#include <stddef.h>

/**
 * Diese Klasse verwirklicht eine Gerade
 */
class Line {
public:

	/**
	 * Iniziert die Gerade durch <b>xc</b> , <b>yc</b> und <b>ec</b> <br>
	 * so dass xc * x + yc * y = ec ist die Gleichung der Geraden
	 */
	Line (double xc, double yc, double ec);

	/**
	 * Iniziert die Gerade durch <b>s</b> Sektion (Zeiger)
	 */
	Line (const Segment* s);

	/**
	 * Iniziert die Gerade durch <b>s</b> Sektion (Referenz)
	 */
	Line (const Segment& s);

	/**
	 * Iniziert die Gerade durch 2 Punkten: <b>p1</b> und <b>p2</b> (Zeiger)
	 */
	Line (const Point* p1, const Point* p2);

	/**
	 * Iniziert die Gerade durch 2 Punkten: <b>p1</b> und <b>p2</b> (Referenz)
	 */
	Line (const Point& p1, const Point& p2);

	/**
	 * Iniziert die Gerade durch 1 Punkten: <b>p</b> (Zeiger) <br>
	 * und ein Richtungsvektor ( <b>nx</b> , <b>ny</b> )
	 */
	Line (const Point* p, double nx, double ny);

	/**
	 * Iniziert die Gerade durch 1 Punkten: <b>p</b> (Zeiger)
	 * und ein Richtungstangente <b>m</b>
	 */
	Line (const Point* p, double m);

	/**
	 * Entscheidet ob <b>p</b> ist auf der Gerade
	 */
	bool isOn (const Point* p);

	/**
	 * Gibt die Schnittpunkt von dieser Gerade und <b>l</b> Gerade zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Point* intersect (const Line* l);

	/**
	 * Rotiert die Gerade so, dass es wird durch <b>p</b> Punkt gehen <br>
	 * und wird rechtwinklig zu der originale Gerade
	 */
	void perpendicularRotate (const Point* p);

	// GETTERS SETTERS

	double getX () const {
		return pX;
	}

	void setX (double x) {
		pX = x;
	}

	double getY () const {
		return pY;
	}

	void setY (double y) {
		pY = y;
	}

	double getE () const {
		return pE;
	}

	void setE (double e) {
		pE = e;
	}

private:
	/**
	 * Speichert die x, z, und e Komponenten
	 */
	double pX, pY, pE;
};


#endif //GH_2_LINE_H
