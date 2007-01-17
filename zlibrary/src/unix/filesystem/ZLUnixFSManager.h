/*
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

#ifndef __ZLUNIXFSMANAGER_H__
#define __ZLUNIXFSMANAGER_H__

#include <ZLFSManager.h>
#include <ZLFile.h>

class ZLUnixFSManager : public ZLFSManager {

protected:
	void normalize(std::string &path) const;
	ZLInputStream *createPlainInputStream(const std::string &path) const;
	ZLOutputStream *createOutputStream(const std::string &path) const;
	ZLFSDir *createPlainDirectory(const std::string &path) const;
	ZLFSDir *createNewDirectory(const std::string &path) const;
	ZLFileInfo fileInfo(const std::string &path) const;
	bool removeFile(const std::string &path) const;
};

#endif /* __ZLUNIXFSMANAGER_H__ */
