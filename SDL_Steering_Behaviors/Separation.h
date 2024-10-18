#pragma once
#include "SteeringBehavior.h"
class Separation : public SteeringBehavior
{
public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
};

