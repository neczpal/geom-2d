//
// Created by neczp on 2016. 05. 07..
//

#ifndef GH_2_POLYGON_H
#define GH_2_POLYGON_H

#include "Shape.h"

#include "Line.h"
#include <math.h>
#include <iostream>

/**
 * Benutzt bei der Speicherung der Punkten von Polygon
 */
template<typename T>
struct Node {
	T value;
	Node* next;

	Node (const T value) {
		this->value = value;
		next = NULL;
	}
};

/**
 * Diese Klasse verwirklicht ein Polygon
 */
class MyPolygon : public Shape {
public:
	/**
	 * Iniziert die Polygon durch 3 Punkten ( <b>a</b> , <b>b</b> , <b>c</b> ) (Referenzen) <br>
	 * mehrere Punkten kann man mit addPoint() hinzufügen
	 */
	MyPolygon (const Point& a, const Point& b, const Point& c);

	/**
	 * Iniziert die Polygon durch 3 Punkten ( <b>a</b> , <b>b</b> , <b>c</b> ) (Zeiger) <br>
	 * mehrere Punkten kann man mit addPoint() hinzufügen
	 */
	MyPolygon (const Point* a, const Point* b, const Point* c);

	/**
	 * Entfernt alle Punkte der Polygons
	 */
	~MyPolygon ();

	/**
	 * Fügt <b>p</b> Punkt zu dem Polygon hinzu <br>
	 * <b>pos</b> : nach welchem Punkt wird es hinzufügt <br>
	 * <b>ACHTUNG</b>: Falls pos größer ist als der Anzahl der Punkten, dann wird es nicht hinzufügt!
	 */
	virtual void addPoint (const Point& p, int pos = 0);

	/**
	 * Entfern <b>p</b> Punkt von dem Polygon <br>
	 * Falls es ist nicht in die Liste, dann wird nichts passieren
	 */
	virtual void delPoint (const Point& p);

	/**
	 * Entscheidet ob ein Punkt ist in der Liste
	 */
	bool contains (const Point& p);

	/**
	 * Gibt die Referenz zu dem <b>pos</b> -sten Punkt zurück
	 */
	Point& getPoint (int pos);

	/**
	 * Gibt die Referenz zu dem <b>pos</b> -sten Punkt zurück
	 */
	Point& operator[] (int pos);

	/**
	 * Gibt die Anzahl der Punkten zurück
	 */
	inline int size () {
		return pNum;
	}


	// Sieht in <b>Transformable</b>

	virtual void move (double dx, double dy);

	virtual void reflect (const Point* p);

	virtual void reflect (const Line* e);

	virtual void rotate (const Point* p, double degree);

	// Sieht in <b>Area</b>

	virtual double getArea ();

	virtual double getPerimeter ();

	virtual bool isInside (const Point* e);

	// Sieht in <b>Drawable</b>

	virtual void draw ();

private:
	/**
	 * Die zirkulär gekettete List von Punkten
	 */
	Node<Point>* pLast;
	/**
	 * Die Anzahl der Punkten
	 */
	int pNum;
};

#endif //GH_2_POLYGON_H
