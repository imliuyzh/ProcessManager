# ICSOSProcessManager
A simple process and resource manager provides the basic operations invoked by processes to create and destroy processes, and to request and release resources. A manually invoked timeout function mimics the behavior of preemptive scheduling. 

## Background
### Process
A process can be in one of three states: ready, running, blocked. It typically cycles through the states many times throughout its lifetime:

<img src="https://i.ibb.co/3MX25Vf/ch1img1v2.png" />
<br />

Each process is represented by a data structure called the process control block (PCB). The PCBs are organized as a fixed-size array, PCB[n], where n is the maximum number of processes that can be created. Each process is uniquely identified by the PCB index:

<img src="https://i.ibb.co/r6fTVsX/3.png" width="600" />
<br />

Each PCB only consists of the following fields:

<img src="https://i.ibb.co/y8fVbXF/1.png" width="600" />
<br />

* State: The current state of the process i
* Parent: Index of the process that created process i
* Priority: Level of important of process i
    + 0 being lowest, 2 being highest
* Children: A linked list of processes that process i has created
* Resources: A linked list of resources that process i is holding

### Resource
Processes may request, acquire, and later release a fixed set of resources. When a process requests a resource that is unavailable, the process becomes blocked.

Each resource is represented by a data structure called the resource control block (RCB). Analogous to the PCBs, the RCBs are organized as a fixed-size array, RCB[m], where m is the number of resources in the system. Each resource is uniquely identified by the RCB index. Each RCB consists only of the following fields, organized as a structure:

<img src="https://i.ibb.co/pd5x5t1/2.png" width="600" />
<br />

* State: The current amount of the resource r
* Inventory: The initial number of units of the resource r
    + The number depends on the resource ID
* Waitlist: A linked list of processes blocked and their requested amount on the resource r 

## Running the Application
These instructions will get you a copy of the project up and running on your local machine for development purposes.

### Steps
1. Clone/download this repository to your local machine
2. Navigate to the folder in your console
3. Type ```make compile``` to compile the program
4. Type ```make dev``` to run the program
5. Press ```Ctrl+C``` to terminate the program
6. Type ```make clean``` to remove all the trace of this program in your device

### Commands
| Shell Command  | Function | Description |
| ------------- | ------------- | ------------- |
| ```cr <p>```  | create() | Make a new process with priority ```p```. |
| ```de <i>```  | destroy() | Delete a process ```i```. |
| ```rq <r> <k>```  | request() | Try to acquire ```k``` units of resource ```r```. |
| ```rl <r> <k>```  | release() | Free ```k``` units of resource ```r```. |
| ```to```  | timeout() | Change the current running process. |
| ```in```  | init() | Initialize/reset this program. |

## Acknowledgments
This project is originally developed for UC Irvine's CS 143B taught by Prof. Lubomir Bic. Its prerequisite is Prof. Nalini Venkatasubramanian's CS 143A. Without their classes, I cannot start this project.