//
// Created by neczp on 2016. 05. 10..
//

#ifndef GH_2_DRAWABLE_H
#define GH_2_DRAWABLE_H


/**
 * Diese abstrakte Klasse ist die Baseklasse aller zeichenbaren Komponenten
 */
class Drawable {
public:
	/**
	 * Leerkonstuktor, stellt das Farbe zu weiß
	 */
	Drawable ();

	virtual ~Drawable ();

	/**
	 * Zeichnet die Komponent auf einer openGL Fläche zeichnen
	 */
	virtual void draw () = 0;

	/**
	 * Stellt die Farbe ein
	 */
	void setColor (float red, float green, float blue);

	/**
	 * Gibt die Farbe zurück
	 */
	const float* getColor () const;

protected:
	/**
	 * Stellt die Farbe in openGL zu der eingestellten Farbe ein
	 */
	virtual void setupColor ();

private:
	/**
	 * Speichert die Farbe
	 */
	float pColor[3];
};

#endif //GH_2_DRAWABLE_H

