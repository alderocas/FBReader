![compile-master-focal_fossa](https://github.com/alderocas/FBReader/workflows/compile-master-focal_fossa/badge.svg)

***This is a very short description of the FBReader build procedure.***

##### Compiler

All version of FBReader are configured for building on linux desktop
computer. You need the gcc compiler for building the desktop version or cross
gcc compiler for building the package for another platform.

##### Libraries

FBReader requires:
  - expat -- library for XML parsing  
      AFAIK, all popular distributions include packages with names like 'expat-dev' or 'libexpat-dev'.  
      If you cannot find expat in your distribution, please visit https://libexpat.github.io.
      
  - libz and libbz2 -- libraries for zip and bzip2 (de)compression
  - UI library -- this depends on your target platform  
      For desktop:
	1. Qt library, version 3.* or 4.*  
	  **OR**
	2. GTK+ library, version >= 2.4
	
  - libunibreak (https://github.com/adah1972/libunibreak) -- library for line breaking in a Unicode sequence
  - libfribidi -- for bidirectional text support
  - libcurl, version >= 7.17 -- for network libraries integration
  - libsqlite3
  
For the win32 version we also require:
  - libpng
  - libungif
  - libjpeg
  - libtiff

##### How to configure

Before building FBReader, you should check (and maybe edit) 2 files:  

  - makefiles/target.mk  
  
    In this file you should define 3 variables:
    
       * TARGET_ARCH -- target platform for building FBReader  
       * UI_TYPE -- UI library  
       * TARGET_STATUS -- "release", "debug" or "profile". "release" is a reasonable choice for almost all users  
       
       Possible pairs for TARGET_ARCH + UI_TYPE are:

	    TARGET_ARCH = desktop               UI_TYPE = gtk
	    TARGET_ARCH = desktop               UI_TYPE = qt
	    TARGET_ARCH = desktop               UI_TYPE = qt4
		TARGET_ARCH = pepperpad3            UI_TYPE = gtk
		TARGET_ARCH = zaurus                UI_TYPE = qtopia-240x320
		TARGET_ARCH = zaurus                UI_TYPE = qtopia-640x480
		TARGET_ARCH = openzaurus            UI_TYPE = opie
		TARGET_ARCH = openzaurus            UI_TYPE = gpe
		TARGET_ARCH = pdaxrom               UI_TYPE = gtk
		TARGET_ARCH = pdaxrom               UI_TYPE = qt
		TARGET_ARCH = opensimpad-0.9.0      UI_TYPE = opie
		TARGET_ARCH = maemo                 UI_TYPE = maemo2
		TARGET_ARCH = maemo                 UI_TYPE = maemo4
		TARGET_ARCH = pma400                UI_TYPE = qtopia
		TARGET_ARCH = moto                  UI_TYPE = ezx
		TARGET_ARCH = win32                 UI_TYPE = win32
		TARGET_ARCH = macosx                UI_TYPE = cocoa

  - makefiles/arch/$(TARGET_ARCH).mk  
     This file defines compiler name and location, headers and libraries
     locations, compilation flags, installation path (for desktop), etc.

##### How to build

Just type `make` in FBReader root directory. (FBReader root directory ==
directory containing this file.)

##### How to install

If you want to install FBReader on your desktop computer, just run `make install`
as root in FBReader root directory.

If you want to create package for another platform, run `make packages` in
FBReader root directory.
