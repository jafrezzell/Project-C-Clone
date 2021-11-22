#pragma once
class Transform {
public:
	Transform(int x = 0, int y= 0, float scale = 1);
	~Transform();
	int x;
	int y;
	float scale;

};