//
// Created by neczp on 2016. 05. 07..
//

#ifndef GH_2_CIRCLE_H
#define GH_2_CIRCLE_H

#include "Point.h"
#include "Shape.h"

#include <math.h>

/**
 * Diese Klasse verwirklicht ein Kreis
 */
class Circle : public Shape {
public:
	/**
	 * Mathe Konstante PI
	 */
	constexpr static double PI = 3.14159265359;
	/**
	 * Der Anzahl von Punkten (bei der Zeichnung)
	 */
	constexpr static double CIRCLE_POINTS = 180;

	/**
	 * Iniziert ein Kreis durch <br>
	 * ( <b>x</b> , <b>y</b> ) : Mittelpunkt von der Kreis <br>
	 *  <b>r</b>       : Radius von der Kreis <br>
	 * <b>ACHTUNG</b>: r muss größer als 0 sein, sondern wird die Kreis nicht iniziert!
	 */
	Circle (double x, double y, double r);

	/**
	 * Iniziert ein Kreis durch
	 *  <b>p</b>       : Mittelpunkt von der Kreis (Referenz) <br>
	 *  <b>r</b>       : Radius von der Kreis <br>
	 * <b>ACHTUNG</b>: r muss größer als 0 sein, sondern wird die Kreis nicht iniziert!
	 */
	Circle (const Point& p, double r);

	/**
	 * Iniziert ein Kreis durch
	 *  <b>p</b>       : Mittelpunkt von der Kreis (Zeiger) <br>
	 *  <b>r</b>       : Radius von der Kreis <br>
	 * <b>ACHTUNG</b>: r muss größer als 0 sein, sondern wird die Kreis nicht iniziert!
	 */
	Circle (const Point* p, double r);


	/**
	 * Iniziert ein Kreis durch 3 Punkten ( <b>a</b> , <b>b</b> , <b>c</b> ) (Referenz) <br>
	 * Die Kreis wird die Umkreis von diesen Dreieck. <br>
	 * <b>ACHTUNG</b>: Diese Punkten sollen verschiedenen sein und dürfen nicht auf ein Gerade fallen,
	 * 			sonst wird die Kreis nicht iniziert!
	 */
	Circle (const Point& a, const Point& b, const Point& c);

	/**
	 * Iniziert ein Kreis durch 3 Punkten ( <b>a</b> , <b>b</b> , <b>c</b> ) (Zeiger) <br>
	 * Die Kreis wird die Umkreis von diesen Dreieck. <br>
	 * <b>ACHTUNG</b>: Diese Punkten sollen verschiedenen sein und dürfen nicht auf ein Gerade fallen, <br>
	 * 			sonst wird die Kreis nicht iniziert!
	 */
	Circle (const Point* a, const Point* b, const Point* c);

	/**
	 * Entfernt die Mittelpunkt <b>pP</b>
	 */
	~Circle ();

	/**
	 * Stellt die Position der Mittelpunkt zu <b>p</b> Punkt ein (Referenz)
	 */
	void setPosition (const Point& p);

	/**
	 * Stellt die Position der Mittelpunkt zu <b>p</b> Punkt ein (Zeiger)
	 */
	void setPosition (const Point* p);

	/**
	 * Entscheidet ob diese Kreis hat dieselbe Eigenschaften als die <b>another</b> Kreis
	 */
	bool operator== (const Circle& another) const;

	// Sieht in <b>Transformable</b>

	virtual void move (double dx, double dy);

	virtual void reflect (const Point* p);

	virtual void reflect (const Line* e);

	virtual void rotate (const Point* p, double degree);

	// Sieht in <b>Area</b>

	virtual double getArea ();

	virtual double getPerimeter ();

	virtual bool isInside (const Point* p);

	// Sieht in <b>Drawable</b>

	virtual void draw ();

	// GETTERS SETTERS

	double getX () const;

	void setX (double x);

	double getY () const;

	void setY (double y);

	double getR () const;

	void setR (double r);

private:
	/**
	 * Speichert der Mittelpunkt von der Kreis
	 */
	Point* pP;
	/**
	 * Speichert die Radius von der Kreis
	 */
	double pR;
};

#endif //GH_2_CIRCLE_H
