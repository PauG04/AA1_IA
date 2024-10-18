#include "CompositeWeightedSum.h"

Vector2D CompositeWeightedSum::ApplySteeringForce(Agent* agent, float dtime)
{
	force = 0;
	for (std::pair<SteeringBehavior*, float> steering_force : steerings)
	{
		force += steering_force.first->ApplySteeringForce(agent,dtime) * steering_force.second;
	}
	return force;
}
