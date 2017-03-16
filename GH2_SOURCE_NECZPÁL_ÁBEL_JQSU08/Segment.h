//
// Created by neczp on 2016. 05. 07..
//

#ifndef GH_2_SEGMENT_H
#define GH_2_SEGMENT_H

#include "Transformable.h"
#include "Point.h"

#include <GL/gl.h>

/**
 * Diese Klasse verwirklicht ein Sektion (A Punkt und B Punkt)
 */
class Segment : public Transformable {
public:
	/**
	 * Iniziert die Komponent durch (Zeiger)
	 * <b>a</b> : die Startpunkt
	 * <b>b</b> : die Endpunkt
	 * <b>ACHTUNG</b>: Falls <b>a</b> und <b>b</b> hat dieselbe Position dann wird die Sektion nicht gemacht!
	 */
	Segment (const Point* a, const Point* b);

	/**
	 * Iniziert die Komponent durch (Referenz)
	 * <b>a</b> : die Startpunkt
	 * <b>b</b> : die Endpunkt
	 * <b>ACHTUNG</b>: Falls <b>a</b> und <b>b</b> hat dieselbe Position dann wird die Sektion nicht iniziert!
	 */
	Segment (const Point& a, const Point& b);

	/**
	 * Entfernt <b>A</b> und <b>B</b>
	 */
	~Segment ();

	/**
	 * Entscheidet ob <b>another</b> hat die solche Punkten, wie diesen
	 * falls <b>another</b> ist umgekehrt a == another.b und b == another.a
	 * dann die sind nicht gleich und gibt false zürück
	 */
	bool operator== (const Segment& another) const;

	/**
	 * Gibt die Halbierendepunkt auf der Sektion zurück
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Point* getBisectorPoint ();

	/**
	 * Gibt die Halbierendegerade auf der Sektion zurück
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getBisector ();

	/**
	 * Kehrt <b>A</b> und <b>B</b> um
	 */
	void reverse ();

	/**
	 * Gibt die Länge zurück
	 */
	double getLength ();

	/**
	 * Stellt die Länge ein
	 * <b>A</b> bleibt <b>B</b> bewegt
	 */
	void setLength (double length);

	// Sieht in <b>Transformable</b>

	virtual void move (double dx, double dy);

	virtual void reflect (const Point* p);

	virtual void reflect (const Line* e);

	virtual void rotate (const Point* p, double degree);

	// Sieht in <b>Drawable</b>

	virtual void draw ();

	// GETTER SETTER

	Point* getB () const {
		return pB;
	}

	void setB (Point* b) {
		pB = b;
	}

	Point* getA () const {
		return pA;
	}

	void setA (Point* a) {
		pA = a;
	}

private:
	/**
	 * Speichert <b>A</b> Punkt
	 */
	Point* pA;
	/**
	 * Speichert <b>B</b> Punkt
	 */
	Point* pB;
};

#endif //GH_2_SEGMENT_H
