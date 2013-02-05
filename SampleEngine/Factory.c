// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

static List *GameObjectList = NULL;

void InitObjectList( void )
{
  GameObjectList = CreateList( );
}

List *GetObjectList( void )
{
  return GameObjectList;
}

void DestroyObjectList( void )
{
  Node *o;

  for(o = ListBegin( GameObjectList ); o != ListEnd( GameObjectList ); )
  {
    o = DeleteNode( GameObjectList, o );
  }

  free( GameObjectList );
}

GameObject *CreateObject( GO_ID id )
{
  VALIDATE_OBJ_ID( id );
  return GO_TABLE[id].Create( );
}

// Eats a newline character to move the file pointer to a new line
// fscanf_s will not pick up newlines, so we must do it ourselves
#define GOTO_NEXT_LINE( ) \
  fgetc( fp )

void SerializeFloat( float f, FILE *fp )
{
  fprintf_s( fp, "%f\n", f );
}

void SerializeInt( int i, FILE *fp )
{
  fprintf_s( fp, "%d\n", i );
}

void SerializeString( const char *s, FILE *fp )
{
  fprintf_s( fp, "%s\n", s );
}

void DeserializeFloat( float *f, FILE *fp )
{
  fscanf_s( fp, "%f", f );
  GOTO_NEXT_LINE( );
}

void DeserializeInt( int *i, FILE *fp )
{
  fscanf_s( fp, "%d", i );
  GOTO_NEXT_LINE( );
}

void DeserializeString( const char *s, FILE *fp )
{
  fscanf_s( fp, "%s", s );
  GOTO_NEXT_LINE( );
}

GameObject *DeserializeObject( FILE *fp )
{
  GO_ID id;
  DeserializeInt( (int *)&id, fp );
  VALIDATE_OBJ_ID( id );
  return GO_TABLE[id].Deserialize( fp );
}

void SerializeObject( GameObject *obj, FILE *fp )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Serialize( obj, fp );
}

void SerializerClearFile( const char *fileName, FILE *fp )
{
  // Make sure we aren't trying to clear the SerializeFile while it's open
  assert( fp == NULL );

  fopen_s( &fp, fileName, "w" );
  fclose( fp );
}

void SerializerOpenFile( const char *fileName, FILE **fp )
{
  fopen_s( fp, fileName, "a+" );
}

void SerializerCloseFile( FILE **fp )
{
  fclose( *fp );
  *fp = NULL;
}
