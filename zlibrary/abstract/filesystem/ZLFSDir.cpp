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

#include <sys/stat.h>
#include <dirent.h>

#include "ZLFSDir.h"

void ZLFSDir::create() {
	mkdir(name().c_str(), 0x1FF);
}

void ZLFSDir::collectSubDirs(std::vector<std::string> &names) {
	DIR *dir = opendir(name().c_str());
	if (dir != 0) {
		const dirent *file;
		while ((file = readdir(dir)) != 0) {
			if (file->d_type == DT_DIR) {
				std::string fname = file->d_name;
				if ((fname != ".") && (fname != "..")) {
					names.push_back(file->d_name);
				}
			}
		}
		closedir(dir);
	}
}

void ZLFSDir::collectRegularFiles(std::vector<std::string> &names) {
	DIR *dir = opendir(name().c_str());
	if (dir != 0) {
		const dirent *file;
		while ((file = readdir(dir)) != 0) {
			if (file->d_type == DT_REG) {
				names.push_back(file->d_name);
			}
  	}
		closedir(dir);
	}
}
