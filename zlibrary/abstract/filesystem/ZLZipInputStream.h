/*
 * Copyright (C) 2005 Nikolay Pultsin <geometer@mawhrin.net>
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
 * Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#ifndef __ZLZIPINPUTSTREAM_H__
#define __ZLZIPINPUTSTREAM_H__

#include <zlib.h>
#include <list>

#include "ZLInputStream.h"

class ZLFileInputStream;

class ZLZipInputStream : public ZLInputStream {

public:
	ZLZipInputStream(const std::string &name);
	~ZLZipInputStream();
	bool open();
	int read(char *buffer, int maxSize);
	void close();

private:
	std::string myCompressedFileName;
	ZLFileInputStream *myFileStream;
	bool myIsDeflated;

	z_stream *myZStream; 
	std::string myBuffer; 
	unsigned long myAvailableSize;
	char *myInBuffer;
	char *myOutBuffer;
};

#endif /* __ZLZIPINPUTSTREAM_H__ */
