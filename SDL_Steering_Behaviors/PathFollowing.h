#pragma once
#include "SteeringBehavior.h"
#include <vector>

class PathFollowing : public SteeringBehavior
{
private:
	std::vector<Vector2D> path;
	int currentTarget;
	float minDistance;

public:
	PathFollowing();
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

