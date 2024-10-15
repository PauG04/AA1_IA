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
	void virtual ApplySteeringForce(Agent* agent, float dtime) override;

};

