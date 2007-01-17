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

#include <gtk/gtk.h>

#include <ZLApplication.h>
#include <ZLibrary.h>

#include "../../gtk/filesystem/ZLGtkFSManager.h"
#include "../time/ZLGtkTime.h"
#include "../dialogs/ZLGtkDialogManager.h"
#include "../../gtk/image/ZLGtkImageManager.h"
#include "../view/ZLGtkPaintContext.h"

void ZLibrary::init(int &argc, char **&argv) {
	gtk_init(&argc, &argv);

	ZLGtkFSManager::createInstance();
	ZLGtkTimeManager::createInstance();
	ZLGtkDialogManager::createInstance();
	ZLGtkImageManager::createInstance();
}

ZLPaintContext *ZLibrary::createContext() {
	return new ZLGtkPaintContext();
}

void ZLibrary::run(ZLApplication *application) {
	ZLDialogManager::instance().createApplicationWindow(application);
	application->initWindow();
	gtk_main();
	delete application;
	pthread_exit(0);
}
