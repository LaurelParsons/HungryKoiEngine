#include <math.h>
#include "Vector2.hpp"

Vector2::Vector2() {

}

Vector2::Vector2(float x, float y) {
	Set(x, y);
}

void Vector2::Set(float x, float y) {
	this->x = x;
	this->y = y;
}

Vector2 Vector2::MoveTowards(Vector2 other, float step) {
	Vector2 directional(other.x - this->x, other.y - this->y);
    float hyp = sqrt(directional.x * directional.x + directional.y * directional.y);
    Vector2 normalized(directional.x/hyp, directional.y/hyp);

	return Vector2(this->x + normalized.x * step, this->y + normalized.y * step);
}
