// Reset anything that init setup
// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"
#include "Object2.h"

// Vtable functions
// Creates: A single Game Object via the Factory
GameObject *Object2Create ( void )
{
  List *GameObjectList = GetObjectList( );
  
  Node *node = InsertBackRaw( GameObjectList, sizeof( Object2 ) );
  GameObject *obj = &NODE_DATA( node, GameObject );
  obj->id = ID_Object2;
  return obj;
}

// Initialization: allocate any necessary memory, intialize any settings
void Object2Init     ( GameObject * _self )
{
  printf( "Initializing Object2...\n" );
}

void Object2Update   ( GameObject * _self, float dt )
{
}

void Object2Draw     ( GameObject * _self )
{
}

// Things to reset: Allocated memory, intializating code, etc.
void Object2Destroy  ( GameObject * _self )
{
  printf( "Shutting down Object2...\n" );
}

void Object2Send_MSG ( GameObject * _self, M m, int var1, int var2 )
{
  // Create temporary casted self
  Object2 *self = CAST( _self, Object2 );

  switch(m)
  {
  case M_TEST1:
      printf( "Object2: Recieved message : M_TEST1\n" );
      break;
  case M_TEST2_1PARAM:
      printf( "Object2: Recieved message : M_TEST2_1PARAM\n" );
      printf( "  Param: %d\n", var1 );
      break;
  case M_INCREMENT:
      IncrementCounter( self, var1 );
      break;
  }
}

void Object2Serialize( GameObject *obj, FILE *fp )
{
  SerializeInt( obj->id, fp );
  SerializeInt( CAST( obj, Object2 )->counter, fp );
}

GameObject *Object2Deserialize( FILE *fp )
{
  GameObject *obj = CreateObject( ID_Object2 );
  DeserializeInt( &CAST( obj, Object2 )->counter, fp );
  return obj;
}

// Object specific functions that do not exist in vtable
void IncrementCounter( Object2 *self, int num )
{
  printf( "Object2: Incrementing counter..." );
  self->counter += num;
  printf( "  Counter now at: %d\n", self->counter );
}
