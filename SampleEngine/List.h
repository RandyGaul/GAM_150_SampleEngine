// Copyright (C) 2013 Randy Gaul
// All rights reserved.
// This code is for illustration purposes to be studied in
// conjunction with online slideshows. Do not use any of
// this code in your project. You must write every character
// in your own projects from scratch. Trust me, you don't
// actually WANT to use any of this code in your project.

typedef struct Node
{
  void *data;
  struct Node *next;
  struct Node *prev;
}Node;

typedef struct List
{
  Node head;
  Node tail;
  unsigned NodeCount;
} List;

// Retrieves the data of a Node by typecasting the Node's data void pointer to a 
// pointer of desired type, followed by a dereference.
#define NODE_DATA( NODE, TYPE ) \
  (*(TYPE *)(NODE->data))

#define NODE_FROM_DATA( DATA ) \
  CAST( Node *, PTR_SUB( DATA, sizeof( Node ) ) )

    /*----------------
      Create/Destroy
    ----------------*/
// Create an empty linked list
List *CreateList( void );

// Delete a Node from a list
Node *DeleteNode( List *list, Node *n );

    /*----------------
        Modifiers
    ----------------*/
// Create a Node at front of a list
Node *InsertFront( List *list, void *data, unsigned data_size );
Node *InsertFrontRaw( List *list, unsigned data_size );

// Create a Node at back of a list
Node *InsertBack( List *list, void *data, unsigned data_size );
Node *InsertBackRaw( List *list, unsigned data_size );

// Copy data into a Node
void AssignData( void *data, Node *n, unsigned data_size );

// Unhooks a Node from a list
void UnlinkNode( List *list, Node *n );

void EmptyList( List *list );

void FreeList( List *list );

    /*----------------
       Data Access
    ----------------*/
// Checks to see if a Node is apart of a list at all
int IsLinked( Node *n );

// It is important to use these for looping over the list
Node *ListBegin( List *list );
Node *ListEnd( List *list );