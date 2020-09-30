#include "Resource.h"

/**
 * Create a Resource object
 * @param id an int for the index of the resource in the RCB
 */ 
Resource::Resource(int id)
    : state{0}, INVENTORY{(id <= 1) ? 1 : id}
{
}

/**
 * See how many units of the resource are utilized by other processes
 * @return an int showing how much of the resource is being used
 */ 
int Resource::getState()
{
    return state;
}

/**
 * Set the number of resource units that are being used
 * @param state an int for the number of resource units that are being used
 */ 
void Resource::setState(int state)
{
    this->state = state;
}

/**
 * See the total units of the resources
 * @return an int for the total units of the resource
 */
int Resource::getInventory() const
{
    return INVENTORY;
}

/**
 * Add a process in the waitlist
 * @param id an int representing the index of the process in the PCB
 * @param amount an int for how many units does the process needs
 */
void Resource::addProcess(int id, int amount)
{
    waitlist.push_back(std::make_tuple(id, amount));
}

/**
 * Remove a process in the waitlist
 * @param id an int representing the index of the process in the PCB
 * @param amount an int for how many units does the process needs
 */
void Resource::removeProcess(int id, int amount)
{
    waitlist.remove(std::make_tuple(id, amount));
}