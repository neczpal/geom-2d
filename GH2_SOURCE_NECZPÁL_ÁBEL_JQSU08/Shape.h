//
// Created by neczp on 2016. 05. 07..
//

#include "Transformable.h"
#include "Area.h"

#ifndef GH_2_SHAPE_H
#define GH_2_SHAPE_H

/**
 * Diese Klasse ist nur eine Vereinfachung,
 * mit dieser Klasse kann man einfacher erben
 */
class Shape : public virtual Transformable, public virtual Area {
public:
	Shape () : Transformable (), Area () {
	}

	virtual ~Shape () {

	};
};

#endif //GH_2_SHAPE_H
