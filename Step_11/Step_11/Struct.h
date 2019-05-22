#include"Enum.h"

typedef struct tagVector3
{
	float x, y, z;

	tagVector3() {};

	tagVector3(float _x, float _y) : x(_x), y(_y), z(0) {};

	tagVector3(float _x, float _y, float _z)
		: x(_x), y(_y), z(_z) {};

}Vector3;


typedef struct tagTransform
{
	DIRID eDirection;
	Vector3 Position;
	Vector3 Scale;

	

}Transform;


typedef struct tagObject
{
	char* pName;

	Transform TransPos;

	tagObject() {};

}Object;
