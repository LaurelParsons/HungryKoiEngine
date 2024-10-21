#pragma once

/**
Represents a 2D vector.

Represents a vector in 2D space, containing an x and y value.
*/
struct Vector2 {

    /**
    Creates a new Vector2.
    */
	Vector2();

    /**
    Creates a new Vector2 with the given x and y values.
    \param x X value
    \param y Y value
    */
	Vector2(float x, float y);

	/**
	Set the x and y value of this Vector2.
	\param x X value
    \param y Y value
	*/
	void Set(float x, float y);

	/**
	Returns a Vector2 that's the result of moving this vector step distance towards the passed in vector.

	\param other The Vector2 to move towards
	\param step The distance to move.
	*/
	Vector2 MoveTowards(Vector2 other, float step);

public:
    /**
    This Vector2's x value
    */
	float x;

	/**
    This Vector2's y value
    */
	float y;
};
