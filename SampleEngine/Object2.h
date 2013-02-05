// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

// Include this header only once! -- MS Visual Studio only
#pragma once

// Another way to include this header only once
#ifndef OBJECT2H
#define OBJECT2H

// Prototypes for functions in vtable for this object
DECLARE_OBJECT( Object2 );

// Struct definition for Object2
typedef struct Object2
{
  GameObject base; // Base struct, important to go at top of struct for proper typecasting!

  // All data members specific to the Object2 object type go down here
  int counter;
} Object2;

// Prototypes for functions pertaining to this object
void IncrementCounter( Object2 *self, int num );

#endif // OBJECT2H
