#include "ProcessManager.h"

ProcessManager::ProcessManager()
    : currentProcess{0}, size{1}, emptySpot{-1}
{
    init();
}

void ProcessManager::init()
{
    pcb.fill(nullptr);
    std::shared_ptr<Process> process{new Process(-1, 0)};
    pcb[0] = process;
    rl[0].push_front(0);
    currentProcess = 0;

    rcb.fill(nullptr);
    for (size_t counter = 0; counter < rcb.size(); ++counter)
    {
        std::shared_ptr<Resource> resource{new Resource(counter)};
        rcb[counter] = resource;
    }
    writeOutput(0, true);
}

void ProcessManager::create(int priority)
{
    if (size < pcb.max_size())
    {
        std::shared_ptr<Process> process{new Process(currentProcess, priority)};
        ++size;
        pcb[] = process;
        rl[priority].push_back();
        scheduler();
    }
    else
    {
        writeOutput(0, false);
    }
}

void ProcessManager::destroy(int id)
{

}

void ProcessManager::request(int id, int amount)
{

}

void ProcessManager::release(int id, int amount)
{

}

void ProcessManager::scheduler()
{
    for (size_t counter = 2; counter >= 0; --counter)
    {
        if (rl[counter].size() != 0 && pcb[rl[counter].front()]->getState() == READY)
        {
            currentProcess = rl[counter].front();
            break;
        }
    }
    writeOutput(currentProcess, false);
}

void ProcessManager::timeout()
{
    int priority = pcb[currentProcess]->getPriority(); 
    rl[priority].pop_front();
    rl[priority].push_back(currentProcess);
    scheduler();
}