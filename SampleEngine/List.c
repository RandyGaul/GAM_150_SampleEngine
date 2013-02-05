// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

#include "Precompiled.h"

/*------------------------------------------------------------------------------------------------

                                         Create / Destroy

------------------------------------------------------------------------------------------------*/
List *CreateList( void )
{
  List *list = (List *)malloc( sizeof( List ) );

  // Set Node count to zero
  list->NodeCount = 0;

  // Make dummy head point to tail
  list->head.next = &list->tail;
  list->head.prev = NULL;

  // Make dummy tail point to head
  list->tail.prev = &list->head;
  list->tail.next = NULL;

  return list;
}

// Creates a new Node and initializes the data fields
Node *CreateNode( unsigned data_size )
{
  Node *newNode = (Node *)malloc( sizeof( Node ) + data_size );
  newNode->next = NULL;
  newNode->prev = NULL;

  // Make data point to end of the allocated Node where the data's space is
  newNode->data = PTR_ADD( newNode, sizeof( Node ) );

  return newNode;
}

Node *DeleteNode( List *list, Node *n )
{
  // Get the next pointer so we can return it
  Node *next = n->next;

  // We're not going to delete the head or tail >.<
  assert( n != &list->head );
  assert( n != &list->tail );

  // Unlink Node from list then free Node
  UnlinkNode( list, n );
  free( n );

  return next;
}

/*------------------------------------------------------------------------------------------------

                                           Modifiers

------------------------------------------------------------------------------------------------*/
// Create a Node at front of a list and initialize data
Node *InsertFront( List *list, void *data, unsigned data_size )
{
  // Create our Node with initialized data fields
  Node *newNode = CreateNode( data_size );

  // Copy our data into the newNode's memory space
  AssignData( data, newNode, data_size );

  // Make newNode point to what head points at
  newNode->next = list->head.next;
  newNode->prev = &list->head;

  // Make head point to newNode
  list->head.next->prev = newNode;
  list->head.next = newNode;

  // Add one to the NodeCount
  ++list->NodeCount;

  return newNode;
}

// Create a Node at front of a list
Node *InsertFrontRaw( List *list, unsigned data_size )
{
  // Create our Node with initialized data fields
  Node *newNode = CreateNode( data_size );

  // Make newNode point to what head points at
  newNode->next = list->head.next;
  newNode->prev = &list->head;

  // Make head point to newNode
  list->head.next->prev = newNode;
  list->head.next = newNode;

  // Add one to the NodeCount
  ++list->NodeCount;

  return newNode;
}

// Create a Node at back of a list and initialize data
Node *InsertBack( List *list, void *data, unsigned data_size )
{
  // Create our Node with initialized data fields
  Node *newNode = CreateNode( data_size );

  // Copy our data into the newNode's memory space
  AssignData( data, newNode, data_size );
  
  // Make newNode point to what tail points at
  newNode->next = &list->tail;
  newNode->prev = list->tail.prev;
  
  // Make tail point to newNode
  list->tail.prev->next = newNode;
  list->tail.prev = newNode;
  
  // Add one to the NodeCount
  ++list->NodeCount;

  return newNode;
}

// Create a Node at back of a list
Node *InsertBackRaw( List *list, unsigned data_size )
{
  // Create our Node with initialized data fields
  Node *newNode = CreateNode( data_size );
  
  // Make newNode point to what tail points at
  newNode->next = &list->tail;
  newNode->prev = list->tail.prev;
  
  // Make tail point to newNode
  list->tail.prev->next = newNode;
  list->tail.prev = newNode;
  
  // Add one to the NodeCount
  ++list->NodeCount;

  return newNode;
}

// Copy data into a Node
void AssignData( void *data, Node *n, unsigned data_size )
{
  memcpy( n->data, data, data_size );
}

// Unhooks a Node from a list
void UnlinkNode( List *list, Node *n )
{
  // Unhook Node from the list
  n->prev->next = n->next;
  n->next->prev = n->prev;

  // Decrement list's Nodecount
  --list->NodeCount;
}

void EmptyList( List *list )
{
  Node *n;

  for(n = ListBegin( list ); n != ListEnd( list ); )
  {
    n = DeleteNode( list, n );
  }
}

void FreeList( List *list )
{
  free( list );
}

/*------------------------------------------------------------------------------------------------

                                          Data Access

------------------------------------------------------------------------------------------------*/
// Checks to see if a Node is apart of a list at all
int IsLinked( Node *n )
{
  return n->prev || n->next;
}

Node *ListBegin( List *list )
{
  return list->head.next;
}

Node *ListEnd( List *list )
{
  return &list->tail;
}