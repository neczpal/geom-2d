//
// Created by neczp on 2016. 05. 07..
//


#ifndef GH_2_RECT_H
#define GH_2_RECT_H

#include "Point.h"
#include "Area.h"

/**
 * Diese Klasse verwirklicht ein Rechteck, dessen Seiten sind parallel zur x- bzw. zur y-Achse <br>
 * <b>ACHTUNG</b>: Nicht transformierbar!
 */
class Rect : public Area {
public:
	/**
	 * Iniziert den Rechteck durch <br>
	 * Punkt( <b>x</b> , <b>y</b> ) : links unteren Punkt des Rechtecks <br>
	 * <b>w</b> : die Breite <br>
	 * <b>h</b> : die Höhe
	 */
	Rect (double x, double y, double w, double h);

	/**
	 * Iniziert den Rechteck durch <br>
	 * <b>p</b> : links unteren Punkt des Rechtecks (Referenz) <br>
	 * <b>w</b> : die Breite <br>
	 * <b>h</b> : die Höhe
	 */
	Rect (const Point& p, double w, double h);

	/**
	 * Iniziert den Rechteck durch <br>
	 * <b>p</b> : links unteren Punkt des Rechtecks (Zeiger) <br>
	 * <b>w</b> : die Breite <br>
	 * <b>h</b> : die Höhe
	 */
	Rect (const Point* p, double w, double h);

	/**
	 * Entfernt <b>A</b> und <b>B</b> <br>
	 * <b>A</b> : links unteren Punkt <br>
	 * <b>B</b> : rechts obenen Punkt
	 */
	~Rect ();

	/**
	 * Entscheidet ob diese Rechteck hat dieselbe Position und Größe als die <b>another</b> Rechteck
	 */
	bool operator== (const Rect& another) const;

	// Sieht in <b>Area</b>

	virtual double getArea ();

	virtual double getPerimeter ();

	virtual bool isInside (const Point* e);

	// Sieht in <b>Drawable</b>

	virtual void draw ();

	//GETTERS SETTERS

	/**
	 * Gibt die x Position der links unteren Punkt zurück
	 */
	double getX () const;

	/**
	 * Gibt die y Position der links unteren Punkt zurück
	 */
	double getY () const;

	/**
	 * Gibt die Breite zurück
	 */
	double getWidth () const;

	/**
	 * Gibt die Höhe zurück
	 */
	double getHeight () const;

	/**
	 * Stellt die x Position der links unteren Punkt ein
	 */
	void setX (double x);

	/**
	 * Stellt die y Position der links unteren Punkt ein
	 */
	void setY (double y);

	/**
	 * Stellt die Breite ein
	 */
	void setWidth (double width);

	/**
	 * Stellt die Höhe ein
	 */
	void setHeight (double height);

private:
	/**
	 * Speichert <b>A</b> <br>
	 * <b>A</b> : links unteren Punkt
	 */
	Point* pA;
	/**
	 * Speichert <b>B</b> <br>
	 * <b>B</b> : rechts obenen Punkt
	 */
	Point* pB;
};

#endif //GH_2_RECT_H
