//
// Created by neczp on 2016. 05. 07..
//

#ifndef GH_2_TRIANGLE_H
#define GH_2_TRIANGLE_H

#include "MyPolygon.h"
#include "Line.h"
#include "Circle.h"
#include "Segment.h"

/**
 * Diese Klasse verwirklicht ein Dreieck ( <b>a</b> , <b>b</b> , <b>c</b> )
 */
class Triangle : public MyPolygon {
public:
	/**
	 * Iniziert den Dreieck durch (Referenz) <br>
	 * <b>a</b> : Punkt <br>
	 * <b>b</b> : Punkt <br>
	 * <b>c</b> : Punkt <br>
	 * Die Seiten wird AB, BC und CA.
	 */
	Triangle (const Point& a, const Point& b, const Point& c);

	/**
	 * Iniziert den Dreieck durch (Zeiger) <br>
	 * <b>a</b> : Punkt <br>
	 * <b>b</b> : Punkt <br>
	 * <b>c</b> : Punkt <br>
	 * Die Seiten wird AB, BC und CA.
	 */
	Triangle (const Point* a, const Point* b, const Point* c);

	// UNIQUE
	/**
	 * Gibt die Referenz zur A Punkt zurück
	 */
	Point& getA ();

	/**
	 * Gibt die Referenz zur B Punkt zurück
	 */
	Point& getB ();

	/**
	 * Gibt die Referenz zur C Punkt zurück
	 */
	Point& getC ();

	/**
	 * Stellt die Position von der Kreis bezüglich Punkt <b>A</b> ein <br>
	 * <b>ACHTUNG</b>: Diese ändert die Position von die anderen Punkten! <br>
	 * Falls du möchtest nur A verändern, dann benutz getA().setPosition()!
	 */
	void setA (const Point& p);

	/**
	 * Stellt die Position von der Kreis bezüglich Punkt <b>B</b> ein <br>
	 * <b>ACHTUNG</b>: Diese ändert die Position von die anderen Punkten auch! <br>
	 * Falls du möchtest nur A verändern, dann benutz getB().setPosition()!
	 */
	void setB (const Point& p);

	/**
	 * Stellt die Position von der Kreis bezüglich Punkt <b>C</b> ein <br>
	 * <b>ACHTUNG</b>: Diese ändert die Position von die anderen Punkten auch! <br>
	 * Falls du möchtest nur A verändern, dann benutz getC().setPosition()!
	 */
	void setC (const Point& p);

	/**
	 * Gibt die Länge der <b>a</b> = BC Seite zurück
	 */
	double getLengthA ();

	/**
	 * Gibt die Länge der <b>b</b> = CA Seite zurück
	 */
	double getLengthB ();

	/**
	 * Gibt die Länge der <b>c</b> = AB Seite zurück
	 */
	double getLengthC ();

	/**
	 * Gibt die Grad bei der <b>A</b> Ecke zurück
	 */
	double getAngleA ();

	/**
	 * Gibt die Grad bei der <b>B</b> Ecke zurück
	 */
	double getAngleB ();

	/**
	 * Gibt die Grad bei der <b>C</b> Ecke zurück
	 */
	double getAngleC ();

	/**
	 * Gibt die Winkelhalbierendegerade bei der <b>A</b> Ecke zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getAngleBisectorA ();

	/**
	 * Gibt die Winkelhalbierendegerade bei der <b>B</b> Ecke zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getAngleBisectorB ();

	/**
	 * Gibt die Winkelhalbierendegerade bei der <b>C</b> Ecke zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getAngleBisectorC ();

	/**
	 * Gibt die Seitehalbierendegerade bei der <b>AB</b> Seite zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getSegmentBisectorAB ();

	/**
	 * Gibt die Seitehalbierendegerade bei der <b>BC</b> Seite zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getSegmentBisectorBC ();

	/**
	 * Gibt die Seitehalbierendegerade bei der <b>CA</b> Seite zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Line* getSegmentBisectorCA ();

	/**
	 * Gibt die Inkreis des Dreiecks zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Circle* getInnerCircle ();

	/**
	 * Gibt die Umkreis des Dreiecks zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Circle* getOuterCircle ();

	/**
	 * Gibt die Seite <b>AB</b> zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Segment* getAB ();

	/**
	 * Gibt die Seite <b>BC</b> zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Segment* getBC ();

	/**
	 * Gibt die Seite <b>CA</b> zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Segment* getCA ();

	/**
	 * Gibt der Schwerpunkt des Dreiecks zurück <br>
	 * <b>ACHTUNG</b>: man muss es entfernen mit <b>delete</b>
	 */
	Point* getCentroid ();

private:
	/**
	 * Hilfsmethode für Winkelhabierendegerade Funktionen
	 */
	Line* getAngleBisector (Segment* s1, Segment* s2, Point& vert);
	/**
	 * Kann man nicht benutzen
	 */
	using MyPolygon::addPoint;//not usable
	/**
	 * Kann man nicht benutzen
	 */
	using MyPolygon::delPoint;//not usable
};

#endif //GH_2_TRIANGLE_H
