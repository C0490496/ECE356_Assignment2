#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Process{
	int pid;		//The Process ID.
	char name[100];		//The string represnting the process name.
	struct Process* next;	//The pointer to the next process.
	struct Process* prev; 	//The pointer to the previous process.
}Process;

void add_process(Process** head, int pid, const char* name){
	Process* new_process = (Process*)malloc(sizeof(Process)); //This sets a new pointer variable called new process to the memory address where we allocated tbe Process instance.
	new_process -> pid = pid;		//This assigns the pid value to the new process pid.
	strcpy(new_process -> name, name);	//This copies the name of the new process and  replaces the new process name to the specified name.
	new_process -> next = NULL;		//This initializes the next pointer of the new process structure to null.
	new_process -> prev = NULL;		//This initializes the previous pointer of the prev process structure to null.

	if(*head == NULL){			//This checks if the list is empty.		
		*head = new_process;		//This sets the  new process to be the head of the list.
	}else{
		Process* temp = *head;		//If the head is not empty then we will place the current head into a temporary pointer.
		while(temp-> next != NULL){	
			temp = temp -> next;	//This moves through until the last node is found. 
		}
	temp->next = new_process;		//This places the new process into the last node. 
	new_process -> prev = temp;		//This creates the link between the previous node and the new process.

	}
}

void remove_process(Process** head, int pid){
	Process* temp = *head;
	while(temp != NULL){					//Iterate through the linked list until the end of the node.
		if(temp -> pid == pid){				//This checks if the pid's match one another.
			if(temp->prev != NULL){

			temp->prev->next = temp -> next;	//This links the previous node to the next one.
		}
		else{
			*head=temp->next;			//This moves the head if the first process is removed.
		}
		if(temp->next != NULL){				//This makes sure that the last node does not have a another node after.
			temp->next->prev = temp -> prev;	//In the event that it does the previous pointer is pointed at previous temporary node which bypasses the node to be removed in the opposite direction.
		}
			free(temp);				//This deallocates the memory allocated in the temporary memory.
			return;
		}
	temp = temp->next;					//This moves to the next process.
	}
	printf("Process with PID %d not found. \n", pid);
}

void display_process(Process* head){
	Process* temp = head;						//This sets a temporary pointer to point to the head of the list.
	printf("Process in the list: \n");				
	while(temp != NULL){						//This goes through the entire list until it reaches the end(head).
		printf("PID: %d, Name: %s\n", temp->pid, temp->name);	//This prints the PID and the name of the process.
		temp = temp->next;					//This moves to the next process.

	}
}

Process* find_process(Process* head, int pid){				//This function is to find the process given a pid.
	Process* temp =head;						//This sets a temporary point to point to the head of the list.
	while(temp != NULL){						//This goes through the entire list until it reaches the head again.
		if(temp->pid == pid){					//This checks if the PIDs match with the given PID.
			return temp;					//This returns the process once it has been found.
		}	
	temp = temp->next;						//This moves to the next process.
}
	return NULL;							//This returns a null if it can't find it.
}

void terminate_process(Process** head, int pid){	//A double pointer is used so that any changes in the remove process function will be reflected also outside of the function.
	remove_process(head, pid);			//Call the remove process and pass in the head and pid that you would like to remove.
}							//This is basically a wrapper function (does not do much but only call the single function).


void navigate_process(Process* current){			//This takes the current process node.
	if(current){						//This checks if the current process is not NULL.
		printf("Current Process - PID: %d, Name: %s\n", current -> pid, current -> name);	//This prints the current process PID  and NAME.
		if(current -> next){									//This checks if there is a node existing after the current process.
			printf("Next Process - PID: %d, Name: %s\n", current->next->pid, current->next->name);	//This prints the node after the current node.
		}else{							//This informs that there is no process after the current process.
			printf("No next process. \n");
		}
		if(current->prev){					//This does the same way the next process works but instead it checks if there was a previous  process. 
			printf("Previous Process - PID: %d, Name %s\n", current->prev->pid, current->prev->name);
		}else{
			printf("No previous process. \n");
		}
	}else{
			printf("No current process. \n");
		}
}

void process_switching(Process** current, int direction){
	if(direction == 1 && (*current)->next){			//This checks if the direction is forward.
		*current = (*current)->next;
	}else if(direction == -1 && (*current)->prev){		//This checks if the direction is backward.
		*current = (*current)->prev;
	}else {
		printf("Cannot switch process in that direction. \n");
	}

}

int main(){
	Process* head = NULL;
	Process* current = NULL;

	for(int i = 1; i<=5; i++){			//This creates 5 processes.
	char process_name[50];
	snprintf(process_name, sizeof(process_name), "Process %d", i);
	add_process(&head, i, process_name);
	}

	display_process(head);

	current = find_process(head, 2); //This finds the specific current process
	if(current){
		printf("Found: PID: %d, Name: %s\n", current->pid, current->name);
	}

	navigate_process(current);


	process_switching(&current, 1);
	navigate_process(current);

	terminate_process(&head, 2);
	display_process(head);

	while(head != NULL){
		remove_process(&head, head->pid); //This free's up all processes
	}

return 0;
}
