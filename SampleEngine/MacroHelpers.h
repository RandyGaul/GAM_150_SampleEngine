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
#ifndef MACROHELPERSH
#define MACROHELPERSH

// This is used to make the Send_MSG function more readable
// Instead of passing in 0 for unused params, it's more readable to see
// UNUSED in place of the zero
#define UNUSED 0

// Just a more readable version of typecasting
#define CAST( VAL, TYPE ) \
  ((TYPE *)VAL)

#define PTR_ADD( PTR, OFFSET ) \
  ((char *)(PTR) + (OFFSET))

#define PTR_SUB( PTR, OFFSET ) \
  ((char *)(PTR) - (OFFSET))

#define STATIC_ASSERT( EXPR ) \
  switch((0)) \
  { \
  case 0: \
  case (EXPR): \
  }

// Ensure proper indexing into the GO_VTABLE array
#define VALIDATE_OBJ_ID( ID ) \
  assert( ID >= 0 && ID < ID_MAX );

#endif // MACROHELPERSH
