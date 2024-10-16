#pragma once
#include "Vector2D.h"

class Agent;

class SteeringBehavior
{
protected:
	Vector2D force;
public:
	SteeringBehavior();
	~SteeringBehavior();

	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) = 0;
};
