//
// Created by neczp on 2016. 05. 04..
//

#ifndef GH_2_TRANSFORMABLE_H
#define GH_2_TRANSFORMABLE_H


#include "Drawable.h"

class Point;

class Line;

/**
 * Diese abstrakte Klasse ist die Baseklasse aller transformierbaren Komponenten
 */
class Transformable : public virtual Drawable {
public:

	virtual ~Transformable () {

	};

	/**
	 * Verschiebt die Komponent mit <b>dx</b> und <b>dy</b>
	 */
	virtual void move (double dx, double dy) = 0;

	/**
	 * Spiegelt die Komponent auf den <b>p</b> Punkt
	 */
	virtual void reflect (const Point* p) = 0;

	/**
	 * Spiegelt die Komponent auf die Gerade <b>e</b>
	 */
	virtual void reflect (const Line* e) = 0;

	/**
	 * Rotiert die Komponent um <b>p</b> Punkt mit <b>degree</b> Grad
	 */
	virtual void rotate (const Point* p, double degree) = 0;
};


#endif //GH_2_TRANSFORMABLE_H
