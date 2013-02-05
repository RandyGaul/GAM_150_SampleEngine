#include "Precompiled.h"

void Init( GameObject *obj )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Init( obj );
}

void Update( GameObject *obj, float dt )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Update( obj, dt );
}

void Draw( GameObject *obj )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Draw( obj );
}

void Destroy( GameObject *obj )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Destroy( obj );
}

void Send_MSG( GameObject *obj, M m_id, int var1, int var2 )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Send_MSG( obj, m_id, var1, var2 );
}

void Serialize( GameObject *obj, FILE *fp )
{
  VALIDATE_OBJ_ID( obj->id );
  GO_TABLE[obj->id].Serialize( obj, fp );
}

GameObject *Deserialize( GameObject *obj, FILE *fp )
{
  VALIDATE_OBJ_ID( obj->id );
  return GO_TABLE[obj->id].Deserialize( fp );
}
