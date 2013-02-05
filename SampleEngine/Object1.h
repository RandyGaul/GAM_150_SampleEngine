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
#ifndef OBJECT1H
#define OBJECT1H

// Prototypes for functions in vtable for this object
DECLARE_OBJECT( Object1 );

// Struct definition for Object1
typedef struct Object1
{
  GameObject base; // Base struct, important to go at top of struct for proper typecasting!

  // All data members specific to the Object1 object type go down here
  int counter;
} Object1;

// Prototypes for functions pertaining to this object
void DecrementCounter( Object1 *self, int num );

#endif // OBJECT1H
