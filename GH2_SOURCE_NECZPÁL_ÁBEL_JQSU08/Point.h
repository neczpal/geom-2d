//
// Created by neczp on 2016. 05. 04..
//

#ifndef GH_2_POINT_H
#define GH_2_POINT_H

#include "Transformable.h"

#include <math.h>
#include <GL/gl.h>

/**
 * Diese Klasse verwirklicht ein Punkt
 */
class Point : public Transformable {
public:
	/**
	 * Iniziert die Punkt durch <b>x</b> , <b>y</b>
	 */
	Point (double x = 0.0, double y = 0.0);

	/**
	 * Verändert die Position von dem Punkt zu <b>x</b> , <b>y</b>
	 */
	void setPosition (double x, double y);

	/**
	 * Verändert die Position von dem Punkt zu einem gegebenen Punkt <b>p</b> (Zeiger)
	 */
	void setPosition (const Point* p);

	/**
	 * Verändert die Position von dem Punkt zu einem gegebenen Punkt <b>p</b> (Referenz)
	 */
	void setPosition (const Point& p);

	/**
	 * Gibt die Entfernung von <b>p</b> zurück (Zeiger)
	 */
	double distance (const Point* p);

	/**
	 * Gibt die Entfernung von <b>p</b> zurück (Referenz)
	 */
	double distance (const Point& p);

	/**
	 * Entscheidet ob dieses Punkt hat dieselbe Position wie <b>another</b> hat.
	 */
	bool operator== (const Point& another) const;

	// Sieht in <b>Transformable</b>

	virtual void move (double dx, double dy);

	virtual void reflect (const Point* p);

	virtual void reflect (const Line* e);

	virtual void rotate (const Point* p, double degree);

	// Sieht in <b>Drawable</b>

	virtual void draw ();

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

private:
	/**
	 * Speichert die Position von dem Punkt
	 */
	double pX, pY;
};


#endif //GH_2_POINT_H
