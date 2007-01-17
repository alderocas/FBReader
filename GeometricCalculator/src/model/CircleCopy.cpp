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

#include "Circle.h"
#include "PointPtr.h"
#include "Point.h"
#include "../polynom/Polynom.h"
#include "../translator/Translator.h"

CircleCopy::CircleCopy(PointPtr center, CirclePtr base) : myCenter(center), myBase(base) {
	myDependsOn.push_back(myCenter);
	myDependsOn.push_back(myBase);
}

CirclePtr CircleCopy::create(PointPtr center, CirclePtr base) {
	return new CircleCopy(center, base);
}

const Coordinates CircleCopy::center() const {
	return myCenter->coordinates();
}

double CircleCopy::radius() const {
	return myBase->radius();
}

PointPtr CircleCopy::centerPoint() const {
	return myCenter;
}

const std::list<ObjectPtr> &CircleCopy::dependsOn() const {
	return myDependsOn;
}

static const std::string TYPE_VALUE = "CircleCopy";
static const std::string CENTER_KEY = "center";
static const std::string BASE_KEY = "base";

void CircleCopy::saveInfo(ObjectInfoMap &info) const {
  info.addAttribute(TYPE_KEY, TYPE_VALUE);
  info.addAttribute(CENTER_KEY, myCenter);
  info.addAttribute(BASE_KEY, myBase);
}

CirclePtr CircleCopy::create(const ObjectInfoMap &info) {
	CirclePtr ptr;

	if (info.stringValueEqualsTo(TYPE_KEY, TYPE_VALUE)) {
		PointPtr center = info.getObjectValue(CENTER_KEY);
		CirclePtr base = info.getObjectValue(BASE_KEY);
		if (!center.isNull() && !base.isNull()) {
			ptr = new CircleCopy(center, base);
		}
	}

	return ptr;
}

std::list<Polynom> CircleCopy::polynoms(Translator &translator) const {
	std::list<Polynom> list;
	Monom radius = translator.monom(*this, "radius");
	Monom baseRadius = translator.monom(myBase, "radius");
	list.push_back(radius  - baseRadius);
	return list;
}
