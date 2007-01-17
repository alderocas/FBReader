/*
 * FBReader -- electronic book reader
 * Copyright (C) 2004-2007 Nikolay Pultsin <geometer@mawhrin.net>
 * Copyright (C) 2005 Mikhail Sobolev <mss@mawhrin.net>
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

#ifndef __ROWMEMORYALLOCATOR_H__
#define __ROWMEMORYALLOCATOR_H__

#include <vector>

class RowMemoryAllocator {

public:
	RowMemoryAllocator();
	~RowMemoryAllocator();

	char *allocate(size_t size);
	char *reallocateLast(char *ptr, size_t newSize);

private:
	const size_t myRowSize;
	size_t myCurrentRowSize;
	std::vector<char*> myPool;
	size_t myOffset;

private: // disable copying
	RowMemoryAllocator(const RowMemoryAllocator&);
	const RowMemoryAllocator &operator = (const RowMemoryAllocator&);
};

#endif /* __ROWMEMORYALLOCATOR_H__ */
