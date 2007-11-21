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

#ifndef __STYLESHEETPARSER_H__
#define __STYLESHEETPARSER_H__

#include "StyleSheetTable.h"

class StyleSheetParser {

public:
	StyleSheetParser(StyleSheetTable &table);
	void reset();
	void parse(const char *text, int len);

private:
	bool isControlSymbol(const char symbol);
	void processWord(std::string &word);
	void processWordWithoutComments(const std::string &word);
	void processControl(const char control);

private:
	StyleSheetTable &myTable;

	std::string myWord;
	std::string myAttributeName;
	enum {
		TAG_NAME,
		ATTRIBUTE_NAME,
		ATTRIBUTE_VALUE,
		BROKEN,
	} myReadState;
	bool myInsideComment;
	StyleSheetTable::Element myElement;
};

#endif /* __STYLESHEETPARSER_H__ */