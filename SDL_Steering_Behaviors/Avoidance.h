#pragma once
#include "SteeringBehavior.h"

class Avoidance : public SteeringBehavior
{
private:

public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

