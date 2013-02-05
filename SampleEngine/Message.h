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
#ifndef MESSAGEH
#define MESSAGEH

typedef enum Message
{
  M_TEST1,                  // No params, prints some test info
  M_TEST2_1PARAM,           // One param: int, prints param and some test info
  
  // Object1
  M_DECREMENT,              // Decrements Object1's internal counter by int value var1
                            // and prints current counter value

  M_INCREMENT,              // Increments Object2's internal counter by int value var1
                            // and prints current counter value
} M;

#endif // MESSAGEH
