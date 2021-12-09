#include "Camera.h"
#include "Utils.h"
#include <iostream>

Camera::Camera()
{
	viewbox = { 0,0,1280,720 };
}

Camera::~Camera()
{
}

void Camera::setTarget(Transform* newTransform)
{
	this->target = newTransform;
}

void Camera::update()
{
	if (target != nullptr) {
		viewbox.x = target->x - Utilities::getscreenwidth() / 2;
		viewbox.y = target->y - Utilities::getscreenheight() / 2;
		if (viewbox.x < 0) {
			viewbox.x = 0;
		}
		if (viewbox.y < 0) {
			viewbox.y = 0;
		}
		if (viewbox.x > (2 * Utilities::getwidth() - viewbox.w)) {
			viewbox.x = (2 * Utilities::getwidth() - viewbox.w);
		}
		if (viewbox.y > (2 * Utilities::getheight() - viewbox.h)) {
			viewbox.y = (2 * Utilities::getheight() - viewbox.h);
		}
		this->position = Transform(viewbox.x, viewbox.y);
	}
}
