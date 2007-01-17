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

#include "Point.h"

PointWeakPtr::PointWeakPtr() : ObjectWeakPtr() {
}

PointWeakPtr::PointWeakPtr(const PointPtr &ptr) : ObjectWeakPtr(ptr) {
}

PointWeakPtr::PointWeakPtr(const PointWeakPtr &ptr) : ObjectWeakPtr(ptr) {
}

const PointWeakPtr &PointWeakPtr::operator = (const PointPtr &ptr) {
	ObjectWeakPtr::operator = (ptr);
	return *this;
}

const PointWeakPtr &PointWeakPtr::operator = (const PointWeakPtr &ptr) {
	ObjectWeakPtr::operator = (ptr);
	return *this;
}

Point* PointWeakPtr::operator -> () const {
	return (Point*)ObjectWeakPtr::operator -> ();
}

Point& PointWeakPtr::operator * () const {
	return (Point&)ObjectWeakPtr::operator * ();
}
