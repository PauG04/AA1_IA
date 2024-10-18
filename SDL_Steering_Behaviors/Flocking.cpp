#include "Flocking.h"
#include "Separation.h"
#include "Cohesion.h"
#include "Alignment.h"
#include "Seek.h"

Flocking::Flocking()
{
	compositeWeightedSum = new CompositeWeightedSum();
	compositeWeightedSum->AddSteering(new Separation(), 7);
	compositeWeightedSum->AddSteering(new Cohesion(), 2);
	compositeWeightedSum->AddSteering(new Alignment(), 1);
	compositeWeightedSum->AddSteering(new Seek(), 1);
}

Vector2D Flocking::ApplySteeringForce(Agent* agent, float dtime)
{
	return compositeWeightedSum->ApplySteeringForce(agent, dtime);
}
