#pragma once
#include "SteeringBehavior.h"
class Cohesion : public SteeringBehavior
{
public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
};

