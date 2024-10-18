#include "Separation.h"

Vector2D Separation::ApplySteeringForce(Agent* agent, float dtime)
{
	Vector2D separationVector = 0;
	for (Agent* currentAgent : agent->GetNeighbours())
	{
		separationVector += (agent->getPosition() - currentAgent->getPosition());
	}

	if (agent->GetNeighbours().size() > 0)
		separationVector /= agent->GetNeighbours().size();

    return separationVector.Normalize();
}
