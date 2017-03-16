//
// Created by neczp on 2016. 05. 16..
//
#include "Drawable.h"

Drawable::Drawable () {
	setColor (1.0f, 1.0f, 1.0f);
}

Drawable::~Drawable () {

}

void Drawable::setColor (float red, float green, float blue) {
	pColor[0] = red;
	pColor[1] = green;
	pColor[2] = blue;
}

const float* Drawable::getColor () const {
	return pColor;
}

void Drawable::setupColor () {
	glColor3f (pColor[0], pColor[1], pColor[2]);
}


