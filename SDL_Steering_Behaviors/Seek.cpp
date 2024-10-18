#include "Seek.h"

Vector2D Seek::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D desiredVelocity = agent->getTarget() - agent->getPosition();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	force = desiredVelocity - agent->getVelocity();
	force /= agent->getMaxVelocity();
	return force * agent->getMaxForce();
}
