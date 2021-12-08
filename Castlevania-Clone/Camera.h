#pragma once
#include "WorldSpaceConstructs.h"
#include "SDL.h"

class Camera {
public:
	Camera();
	~Camera();
	Transform* target;
	Transform position;
	void setTarget(Transform* newTransform);
	void update();
	SDL_Rect viewbox;
private:
};