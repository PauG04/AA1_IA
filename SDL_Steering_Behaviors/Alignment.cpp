#include "Alignment.h"

Vector2D Alignment::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D averageVelocity = 0;
	for (Agent* currentAgent : agent->GetNeighbours())
	{
		averageVelocity += currentAgent->getVelocity();
	}

	if (agent->GetNeighbours().size() > 0)
		averageVelocity /= agent->GetNeighbours().size();
	return averageVelocity.Normalize();
}
