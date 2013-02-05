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
#ifndef GAMEOBJECTH
#define GAMEOBJECTH

#include "GameObjectID.h"
#include "Message.h"

// Prototypes for functions in vtable for this object
#define DECLARE_OBJECT( NAME )                     \
GameObject *NAME##Create( void );                  \
void NAME##Init     ( GameObject * );              \
void NAME##Update   ( GameObject *, float );       \
void NAME##Draw     ( GameObject * );              \
void NAME##Destroy  ( GameObject * );              \
void NAME##Send_MSG ( GameObject *, M, int, int ); \
void NAME##Serialize( GameObject *, FILE * );      \
GameObject *NAME##Deserialize( FILE * )

// Forward declare this structure so we can use it in our
// VTABLE definition properly
struct GameObject;

// Game object virtual table, just a bunch of function pointers
typedef struct GameObjectVtable
{
  struct GameObject *(*Create)   ( void );
  void (*Init)       ( struct GameObject * );
  void (*Update)     ( struct GameObject *, float );
  void (*Draw)       ( struct GameObject * );
  void (*Destroy)    ( struct GameObject * );
  void (*Send_MSG)   ( struct GameObject *, M, int, int );
  void (*Serialize)  ( struct GameObject *, FILE * );
  struct GameObject *(*Deserialize) ( FILE * );
} VTABLE;

// The game object struct! Only an enum ID
typedef struct GameObject
{
  GO_ID id;
} GameObject;

// Generic functions for operating on GameObjects
void Init( GameObject *obj );
void Update( GameObject *obj, float dt );
void Draw( GameObject *obj );
void Destroy( GameObject *obj );
void Send_MSG( GameObject *obj, M m_id, int var1, int var2 );
void Serialize( GameObject *obj, FILE *fp );
GameObject *Deserialize( GameObject *obj, FILE *fp );

#endif // GAMEOBJECTH
