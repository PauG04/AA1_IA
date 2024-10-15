#pragma once
#include "SteeringBehavior.h"

class Seek : public SteeringBehavior
{
public:
	void virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

