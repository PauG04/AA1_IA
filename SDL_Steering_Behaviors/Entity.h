#pragma once
#include "Vector2D.h"

class Entity
{
private:
	Vector2D position;
	float radius;
	
public:
	Entity(Vector2D _position, float _radius);
	void Draw();
	void Update();
};

