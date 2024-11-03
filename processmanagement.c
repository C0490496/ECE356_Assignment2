#include <stdio.h>
#include <stdlib.h>
#include <string.h>



typedef enum { READY, WAIT, RUNNING, TERMINATED } ProcessState;	//These are the different states that the process can be.

typedef struct Process {			//This is processes structure. 
	int pid;
	ProcessState state;
	struct Process* next;
	struct Process* prev;

}Process;

typedef struct Queue{				//This is where we declared our double linked list Queue structure.
	Process* head;
	Process* tail;
}Queue;

Queue* initQueue(){					//Initializes the queue head and tail to nothing.
	Queue* q = (Queue*)malloc(sizeof(Queue));
	q->head = q->tail = NULL;
	return q;
}


//Function Declarations.
Queue* initQueue();
Process* createProcess(int pid, ProcessState state);
Process* removeProcess(Queue* process);
void addProcess(Queue* queue, Process* process);
void executeProcess(Queue* readyQueue, Queue* ioWaitQueue);
void requestIO(Queue* readyQueue, Queue* ioWaitQueue);
void ioComplete(Queue* ioWaitQueue, Queue* readyQueue);




Process* createProcess(int pid, ProcessState state){			//This creates a new process.
	Process* newProcess = (Process*)malloc(sizeof(Process));
	newProcess->pid = pid;
	newProcess->state=state;
	newProcess->next=newProcess->prev=NULL;
	return newProcess;
}

void addProcess(Queue* queue, Process* process){			//This adds the process to the end of the queue.
	process->next=NULL;						//Initialize the next process to be empty.
	if(queue->tail){
	process->prev=queue->tail;					//Update the previous pointer of the queue to the tail process.
	queue->tail->next = process;					//The tails next pointer is updated to the current process.
	queue->tail =process;						//The tail is then updated to the process. 

	}else{
	process->prev = NULL;						//This makes sure that the processes previous pointer is epmty.
	queue->head = queue->tail = process;				//This updates the ques tail and head into the process.
	}
}

Process* removeProcess(Queue* queue){					//This is a function that removes a process from the queue.
	if(!queue-> head) return NULL;					//Checks if the que is empty.
	Process* removedProcess = queue->head;				//Removes the process head.
	queue->head=queue->head->next;					//Updates the head of the queue.
	if(queue->head)queue->head->prev=NULL;				//This then also updates the previous pointer.
	else queue->tail = NULL;					//Updates the Tail instead.
	return removedProcess;						//Return the removed process.
	}



void moveProcess(Queue* fromQueue, Queue* toQueue, Process* process){ 	 //This function moves a process .
	if(process->prev)process->prev->next=process->next;		 //Checks if the process has a previous node and if it does then  update the next pointer instead. 
	if(process->next)process->next->prev=process->prev;
	if(process == fromQueue-> head)fromQueue->head=process->next;
	if(process ==fromQueue->tail)fromQueue->tail=process->prev;

	addProcess(toQueue, process);					//Calls the addProcess function to insert the process into the queue.
}

void executeProcess(Queue* readyQueue, Queue* ioWaitQueue){			//This function simulates the execution process.
	Process* currentProcess = removeProcess(readyQueue);			//Calls removeprocess to remove the head process from the readyQueue.
	if(currentProcess){
	currentProcess->state = RUNNING;					//Set the currents process state into a running state.
	printf("Executing process %d\n", currentProcess->pid);			//Print a Prompt to mention that the process has been executed.

	}
}


void requestIO(Queue* readyQueue, Queue* ioWaitQueue){				//This  moves the process  to I/O wait que.
	Process* process=removeProcess(readyQueue);
	if(process){								//This checks if the process is not empty.
	process->state = WAIT;							//Set the process state into wait.
	addProcess(ioWaitQueue, process);					//This adds another process passing in the IOWaitQueue and the process.
	printf("Process %d moved to I/O wait queue \n", process ->pid);		//Prompt that the process has been moved to the IO wait que.

	}
}

void ioComplete(Queue* ioWaitQueue, Queue* readyQueue){				//If the process is complete  return the process from the I/O wait que.
	Process* process = removeProcess(ioWaitQueue);
	if(process){
		process->state = READY;						//This sets the process state as being ready.
		addProcess(readyQueue, process);				//This then adds another process.
		printf("Process %d returned to ready queue from I/O wait\n", process->pid);	//Prompt which process has been returned to the ready queue. 
	}else{
		printf("No process in I/O wait queue to complete I/O. \n");
	}
}

void interruptProcess(Queue* readyQueue, Process* process){			//Interrupts a running process and moves it back to the ready que.
	if(process->state == RUNNING){
	process->state = READY;							//Sets the process state to ready.
	addProcess(readyQueue, process);
	printf("Process %d interrupted and returned to ready queue\n", process->pid);
	}
}

void terminateProcess(Process* process){					//This function Terminates a process.
	process->state = TERMINATED;						//Set the process state into Terminated.
	printf("Process %d terminated \n", process ->pid);			//Show which process has been terminated.

}

void simulateBackupProcessFlow(Queue* readyQueue, Queue* ioWaitQueue){		//This Function simulates a Backup Process Scenario.
	Process* backupProcess = createProcess(1, READY);
	addProcess(readyQueue, backupProcess);
	//Step 1: Process P1 is created and added to the ready queue.
	printf("Process %d (Backup) created and added to ready queue\n", backupProcess->pid);
	//Step 2: CPU Execution.
	executeProcess(readyQueue, ioWaitQueue);
	//Step 3: I/O Rquest
	requestIO(readyQueue, ioWaitQueue);
	//Step 4: Completion of I/O
	ioComplete(ioWaitQueue, readyQueue);
	//Step 5:Interrupt handling
	executeProcess(readyQueue, ioWaitQueue);
	interruptProcess(readyQueue, backupProcess);
	//Step 6:Termination of the Process.
	Process* terminatedProcess =removeProcess(readyQueue);
	if(terminatedProcess) terminateProcess(terminatedProcess);
}


int main(){
	Queue* readyQueue= initQueue();
	Queue* ioWaitQueue = initQueue();
	//Simulate the Backup Process Flow Scenario. 
	simulateBackupProcessFlow(readyQueue, ioWaitQueue);
}
