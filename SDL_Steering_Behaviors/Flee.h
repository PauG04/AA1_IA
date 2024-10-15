#pragma once
#include "SteeringBehavior.h"
class Flee : public SteeringBehavior
{
public:
	void virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

