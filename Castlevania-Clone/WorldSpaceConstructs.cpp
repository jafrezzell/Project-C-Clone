#include "WorldSpaceConstructs.h";

Transform::Transform(int x, int y, float scale)
{
	this->x = x;
	this->y = y;
	this->scale = scale;
}

Transform::~Transform()
{
}
