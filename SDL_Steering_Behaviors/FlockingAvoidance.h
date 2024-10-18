#pragma once
#include "SteeringBehavior.h"
#include "PriorityList.h"

class FlockingAvoidance : public SteeringBehavior
{
private:
	PriorityList* priorityList;

public:
	FlockingAvoidance();
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
};

