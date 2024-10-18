#pragma once
#include "CompositeWeightedSum.h"
#include <vector>

class Flocking : public SteeringBehavior
{
private:
	CompositeWeightedSum* compositeWeightedSum;

public:
	Flocking();
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
};

