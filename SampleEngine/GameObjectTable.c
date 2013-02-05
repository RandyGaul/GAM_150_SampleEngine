// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

// Object type inclusion
#include "Object1.h"
#include "Object2.h"
#include "Object3.h"

#define EMPTY_FUNC 0

#define VTABLE_INIT( OBJECT_TYPE ) \
    {                              \
      OBJECT_TYPE##Create,         \
      OBJECT_TYPE##Init,           \
      OBJECT_TYPE##Update,         \
      OBJECT_TYPE##Draw,           \
      OBJECT_TYPE##Destroy,        \
      OBJECT_TYPE##Send_MSG,       \
      OBJECT_TYPE##Serialize,      \
      OBJECT_TYPE##Deserialize,    \
    }

VTABLE GO_TABLE[] = {
  VTABLE_INIT( Object1 ),
  VTABLE_INIT( Object2 )
};
