//
// Created by neczp on 2016. 05. 07..
//

#ifndef GH_2_AREA_H
#define GH_2_AREA_H

#include "Point.h"
#include "Drawable.h"

class Point;

/**
 * Diese abstrakte Klasse ist die Baseklasse aller Komponenten die Flächeninhalt hat.
 */
class Area : public virtual Drawable {
public:

	virtual ~Area () {

	};

	/**
	 * Gibt die Flächeninhalt zurück
	 */
	virtual double getArea () = 0;

	/**
	 * Gibt die Umfang zurück
	 */
	virtual double getPerimeter () = 0;

	/**
	 * Gibt zurück, ob die Punkt <b>p</b> ist innerhalb der Komponent
	 */
	virtual bool isInside (const Point* p) = 0;
};

#endif //GH_2_AREA_H
