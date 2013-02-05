// STL includes
#include <stdlib.h> // malloc, free, NULL
#include <stdio.h>  // printf, scanf, fprintf, fscanf
#include <string.h> // strlen, strcpy, strcat, memset
#include <assert.h> // assert

// This define speeds up compiling Windows.h -- this used to be a pretty big deal
// but nowadays I think people just do it out of habit.
#define WIN32_LEAN_AND_MEAN
#include <Windows.h> // sleep

// Place here things you want every file to have included
// Note: The order is important!
#include "MacroHelpers.h"
#include "GameObjectID.h"
#include "GameObject.h"
#include "Factory.h"
#include "GameObjectTable.h"

// Containers
#include "List.h"
