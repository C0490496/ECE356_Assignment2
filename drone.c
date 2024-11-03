#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void takeoff(){		//This function simulates the drone takeoff sequence.
	printf("DRONE TAKING OFF, CHILD PROCESS PID %d is executing the drone's takeoff. \n", getpid());
	sleep(5);
	printf("DRONE HAS TAKEN OFF SUCCESSFULLY. \n");
}

void land(){		//This Function simlates the drones landing sequence.
	printf("DRONE LANDING, PARENT PROCESS %d is dealing with the drone's landing. \n", getpid());
	sleep(5);
	printf("DRONE HAS LANDED SUCCESSFULLY. \n");
}

int main(){

	pid_t pid;

	pid = fork(); //Create a child process.

	if(pid<0){
		perror("The FORK Child creation Process has failed");
		return 1;
	}else if(pid == 0){
		takeoff();	//Let the child process deal with the takeoff sequence.
		exit(0);	//Exit after the takeoff sequence has been completed.
	}else{
		wait(NULL); 	//Wait for the child process (Takeoff) to complete.
		land();		//Now allow the parent process to deal with the landing after the takeoff has been completed.
	}
	return 0;
}
