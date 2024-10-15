#pragma once
#include "SteeringBehavior.h"
class PathFollowing : public SteeringBehavior
{
public:
	void virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

