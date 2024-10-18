#pragma once
#include "SteeringBehavior.h"
class PriorityList : public SteeringBehavior
{
private:
	std::vector<SteeringBehavior*> steerings;
	Vector2D force;

public:
	PriorityList();
	Vector2D virtual ApplySteeringForce(Agent* agent, float dtime) override;
	inline void AddSteeringBehavior(SteeringBehavior* _behavior) { steerings.push_back(_behavior); }
};

