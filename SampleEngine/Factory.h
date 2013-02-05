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
#ifndef FACTORYH
#define FACTORYH

// Forward declare list
struct List;

void InitObjectList( void );
struct List *GetObjectList( void );
void DestroyObjectList( void );

GameObject *CreateObject( GO_ID id );

// Serialization functionality
GameObject *DeserializeObject( FILE *fp );
void SerializeObject( GameObject *obj, FILE *fp );
void SerializerClearFile( const char *fileName, FILE *fp );
void SerializerOpenFile( const char *fileName, FILE **fp );
void SerializerCloseFile( FILE **fp );

// Serialize/Deserialize POD types
void SerializeFloat( float f, FILE *fp );
void SerializeInt( int i, FILE *fp );
void SerializeString( const char *s, FILE *fp );
void DeserializeFloat( float *f, FILE *fp );
void DeserializeInt( int *i, FILE *fp );
void DeserializeString( const char *s, FILE *fp );

#endif // FACTORYH
