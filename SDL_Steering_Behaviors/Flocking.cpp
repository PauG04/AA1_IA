#include "Flocking.h"
#include "AgentManager.h"

Vector2D Flocking::ApplySteeringForce(Agent* agent, float dtime)
{
	Flee(agent, dtime, AGENT_MANAGER.GetAgents());
	Seek(agent, dtime, AGENT_MANAGER.GetAgents());
	Alignment(agent, dtime, AGENT_MANAGER.GetAgents());

	return separationDirection * 5 + cohesionDirection * 3 + allignmentDirection * 1;
}

void Flocking::Flee(Agent* agent, float dtime, std::vector<Agent*> agents)
{
	neighbourCount = 0;
	Vector2D separationVector = 0;
	for (Agent* currentAgent : agents)
	{
		if(Vector2D().Distance(currentAgent->getPosition(), agent->getPosition()) < 3.f)
		{
			separationVector += (agent->getPosition() - currentAgent->getPosition());
			neighbourCount++;
		}
	}

	separationVector /= neighbourCount;
	separationDirection = separationVector.Normalize();

}

void Flocking::Seek(Agent* agent, float dtime, std::vector<Agent*> agents)
{
	neighbourCount = 0;
	Vector2D averagePosition = 0;
	for (Agent* currentAgent : agents)
	{
		if (Vector2D().Distance(currentAgent->getPosition(), agent->getPosition()) < 3.f)
		{
			averagePosition += currentAgent->getPosition();
			neighbourCount++;
		}
	}

	averagePosition /= neighbourCount;
	averagePosition -= agent->getPosition();
	cohesionDirection = averagePosition.Normalize();

}

void Flocking::Alignment(Agent* agent, float dtime, std::vector<Agent*> agents)
{
	neighbourCount = 0;
	Vector2D averageVelocity = 0;
	for (Agent* currentAgent : agents)
	{
		if (Vector2D().Distance(currentAgent->getPosition(), agent->getPosition()) < 3.f)
		{
			averageVelocity += currentAgent->getPosition();
			neighbourCount++;
		}
	}

	averageVelocity /= neighbourCount;
	allignmentDirection = averageVelocity.Normalize();

}
