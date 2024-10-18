#pragma once
#include "SteeringBehavior.h"
#include <vector>

class CompositeWeightedSum : public SteeringBehavior
{
private:
	std::vector<std::pair<SteeringBehavior*, float>> steerings;

public:
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
	inline void AddSteering(SteeringBehavior* steeringBehavior, float weight)
	{
		std::pair<SteeringBehavior*, float> pair;
		pair.first = steeringBehavior;
		pair.second = weight;
		steerings.push_back(pair);
	}
};

