#pragma once
#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

