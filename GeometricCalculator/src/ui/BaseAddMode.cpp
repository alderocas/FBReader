/*
 * Geometric Calculator -- interactive geometry program
 * Copyright (C) 2003-2007 Nikolay Pultsin <geometer@mawhrin.net>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301, USA.
 */

#include "BaseAddMode.h"
#include "../model/Point.h"
#include "../model/Line.h"
#include "../model/Circle.h"

BaseAddMode::BaseAddMode(DiagramView &view) : EditMode(view) {
}

PointPtr BaseAddMode::getPoint(ObjectPtr object0, ObjectPtr object1, int x, int y, bool createNewPoint) {
	if (object0.isNull()) {
		return createNewPoint ? IndependentPoint::create(x, y) : PointPtr();
	}

	int rtti0 = object0->rtti();

	if (rtti0 == Object::POINT) {
		return object0;
	}

	if (!createNewPoint) {
		return PointPtr();
	}

	if (object1.isNull()) {
		PointPtr point;
		if (rtti0 == Object::LINE) {
			LinePtr line = object0;
			point = PointOnTheLine::create(line->point(START), line->point(END), line, 0);
		} else if (rtti0 == Object::CIRCLE) {
			point = PointOnTheCircle::create(object0, 0);
		}
		point->moveTo(x, y);
		return point;
	}

	PointPtr point0, point1;
	if (rtti0 == Object::LINE) {
		if (object1->rtti() == Object::LINE) {
			return LinesCrossing::create(object0, object1);
		} else {
			point0 = LineAndCircleCrossing::create(object0, object1, true);
			point1 = LineAndCircleCrossing::create(object0, object1, false);
		}
	} else {
		if (object1->rtti() == Object::LINE) {
			point0 = LineAndCircleCrossing::create(object1, object0, true);
			point1 = LineAndCircleCrossing::create(object1, object0, false);
		} else {
			point0 = CirclesCrossing::create(object0, object1, true);
			point1 = CirclesCrossing::create(object0, object1, false);
		}
	}

	double distance0 = point0->distance(x, y);
	double distance1 = point1->distance(x, y);
	return (distance0 < distance1) ? point0 : point1;
}

PointPtr BaseAddMode::getPoint(int x, int y, bool createNewPoint) {
	unselect(mySelectedObject0); mySelectedObject0.reset();
	unselect(mySelectedObject1); mySelectedObject1.reset();
	mySelectedObject0 = closestObject(x, y);
	if (!mySelectedObject0.isNull() && (mySelectedObject0->rtti() != Object::POINT)) {
		mySelectedObject1 = closestObject(x, y);
	}
	PointPtr point = getPoint(mySelectedObject0, mySelectedObject1, x, y, createNewPoint);
	if (!point.isNull() && !point->isReal()) {
		mySelectedObject1.reset();
		point = getPoint(mySelectedObject0, mySelectedObject1, x, y, createNewPoint);
	}
	if (!point.isNull() && !point->isReal()) {
		mySelectedObject0.reset();
		point = getPoint(mySelectedObject0, mySelectedObject1, x, y, createNewPoint);
	}
	return point;
}
