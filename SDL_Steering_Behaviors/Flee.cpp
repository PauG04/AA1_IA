#include "Flee.h"

void Flee::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D desiredVelocity = agent->getPosition() - agent->getTarget();
	desiredVelocity.Normalize();
	desiredVelocity *= agent->getMaxVelocity();
	agent->setSteering_force(desiredVelocity - agent->getVelocity());
	agent->setSteering_force(agent->getSteering_force() / agent->getMaxVelocity());
	agent->setSteering_force(agent->getSteering_force() * agent->getMaxForce());
}