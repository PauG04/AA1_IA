#pragma once
#include <vector>
#include "Agent.h"
#define AGENT_MANAGER AgentManager::Instance()

class AgentManager
{
private:
    AgentManager()
    {
    }

    ~AgentManager() {};
    AgentManager(const AgentManager&) = delete;
    AgentManager& operator =(const AgentManager&) = delete;
    std::vector<Agent*> agents;

public:
    inline static AgentManager& Instance()
    {
        static AgentManager manager;
        return manager;
    }
    inline std::vector<Agent*> GetAgents()
    {
        return agents;
    }
    inline void AddAgent(Agent* agent)
    {
        agents.push_back(agent);
    }
    inline void ResetAgents()
    {
        agents.clear();
    }
};
