#include "Flee.h"

Vector2D Flee::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D desiredVelocity = agent->getPosition() - agent->getTarget();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	force = desiredVelocity - agent->getVelocity();
	force /= agent->getMaxVelocity();
	return force * agent->getMaxForce();
}