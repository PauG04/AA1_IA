#pragma once
#include "SteeringBehavior.h"
#include <vector>

class CompositeWeightedSum : public SteeringBehavior
{
private:
	std::vector<std::pair<SteeringBehavior*, float>> steerings;

public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
};

