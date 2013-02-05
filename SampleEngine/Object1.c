// Reset anything that init setup
// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"
#include "Object1.h"

// Vtable functions
// Creates: A single Game Object via the Factory
GameObject *Object1Create ( void )
{
  List *GameObjectList = GetObjectList( );
  
  Node *node = InsertBackRaw( GameObjectList, sizeof( Object1 ) );
  GameObject *obj = &NODE_DATA( node, GameObject );
  obj->id = ID_Object1;
  return obj;
}

// Initialization: allocate any necessary memory, intialize any settings
void Object1Init     ( GameObject * _self )
{
  printf( "Initializing Object1...\n" );
}

void Object1Update   ( GameObject * _self, float dt )
{
}

void Object1Draw     ( GameObject * _self )
{
}

// Things to reset: Allocated memory, intializating code, etc.
void Object1Destroy  ( GameObject * _self )
{
  // Create temporary casted self
  Object1 *self = CAST( _self, Object1 );

  printf( "Shutting down Object1...\n" );
  self->counter = 0;
}

void Object1Send_MSG ( GameObject * _self, M m, int var1, int var2 )
{
  // Create temporary casted self
  Object1 *self = CAST( _self, Object1 );

  switch(m)
  {
  case M_TEST1:
      printf( "Object1: Recieved message : M_TEST1\n" );
      break;
  case M_TEST2_1PARAM:
      printf( "Object1: Recieved message : M_TEST2_1PARAM\n" );
      printf( "  Param: %d\n", var1 );
      break;
  case M_DECREMENT:
      DecrementCounter( self, var1 );
      break;
  }
}

void Object1Serialize( GameObject *obj, FILE *fp )
{
  SerializeInt( obj->id, fp );
  SerializeInt( CAST( obj, Object1 )->counter, fp );
}

GameObject *Object1Deserialize( FILE *fp )
{
  GameObject *obj = CreateObject( ID_Object1 );
  Object1 *p = CAST( obj, Object1 );
  DeserializeInt( &CAST( obj, Object1 )->counter, fp );
  return obj;
}

// Object specific functions that do not exist in vtable
void DecrementCounter( Object1 *self, int num )
{
  printf( "Object1: Decrementing counter..." );
  self->counter -= num;
  printf( "  Counter now at: %d\n", self->counter );
}
