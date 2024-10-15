#pragma once
#include "SteeringBehavior.h"
class Flocking : public SteeringBehavior
{
public:
	void virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

