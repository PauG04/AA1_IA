#include "PriorityList.h"

PriorityList::PriorityList()
{
	force = 0;
}

Vector2D PriorityList::ApplySteeringForce(Agent* agent, float dtime)
{
	for (SteeringBehavior* steering : steerings)
	{
		force = steering->ApplySteeringForce(agent, dtime);
		if (force.x > 0.f || force.y > 0.f)
			return force;
	}
	return force;
}
