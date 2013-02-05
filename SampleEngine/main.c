// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

static const unsigned DELAY_TIME = 1000;

// Just for demontration purposes I made these global
static const char *OBJECT_FILENAME = "SerializedObjects.txt";
static FILE *OBJECT_FILE = NULL;

// Reads stdin until a newline is found
void WaitForEnter( void )
{
  char c = 0;
  printf( "Hit enter to continue...\n" );
  while(c != '\n')
    c = fgetc( stdin );
}

// If Sleep doesn't work for some reason, probably because you're not using the same
// compiler. I made this solution with VS 2010, and you probably be working on GAM 150
// with VS 2010 too.

int main( void )
{
  GameObject *obj1, *obj2;

  // Initialize GameObjectList
  InitObjectList( );

  Sleep( DELAY_TIME );
  
  printf( "Deserializing game objects from %s ...\n", OBJECT_FILENAME );
  // Open a file for serialization operations
  SerializerOpenFile( OBJECT_FILENAME, &OBJECT_FILE );
  // Create our objects by deserialization
  obj1 = DeserializeObject( OBJECT_FILE );
  obj2 = DeserializeObject( OBJECT_FILE );

  // Close file
  SerializerCloseFile( &OBJECT_FILE );

  // Clear contents of a file
  SerializerClearFile( OBJECT_FILENAME, OBJECT_FILE );

  Sleep( DELAY_TIME );

  // Initialize our objects
  Init( obj1 );
  Init( obj2 );

  Sleep( DELAY_TIME );

  printf( "Send each object a message...\n" );
  Send_MSG( obj1, M_DECREMENT, 2, UNUSED );
  Send_MSG( obj2, M_INCREMENT, 2, UNUSED );

  Sleep( DELAY_TIME );

  printf( "Serializing game objects to %s ...\n", OBJECT_FILENAME );
  // Open a file for serialization operations
  SerializerOpenFile( OBJECT_FILENAME, &OBJECT_FILE );
  // Write our objects to file by serialization
  SerializeObject( obj1, OBJECT_FILE );
  SerializeObject( obj2, OBJECT_FILE );
  // Close file
  SerializerCloseFile( &OBJECT_FILE );

  Sleep( DELAY_TIME );
  
  // Call our object's destructors
  Destroy( obj1 );
  Destroy( obj2 );

  // Free all allocated memory
  DestroyObjectList( );

  Sleep( DELAY_TIME );

  printf( "  --- Demo end ---\n" );
  WaitForEnter( );

  return 0;
}
