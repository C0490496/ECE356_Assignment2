#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
	int shareData = 100;						//Each process will  get a copy of this variable whenever fork() is called.

	printf("PARENT: Hey guys, I am the Parent Process!\n");		//Print the Parent Process with its given PID.
	printf("PARENT: THIS IS MY PID: %d\n", getpid());

	pid_t child = fork();						//Create a Child by forking.

	if(child<0){							//This checks if the child fork failed.
	perror("The Child fork failed");
	exit(1);
	}

	if(child == 0){								//If the child is equal to zero the code will execute the child process.
		printf("CHILD: Hello guys, I am the child process!\n");
		printf("CHILD: THIS IS MY PID: %d\n", getpid());
		printf("CHILD: My Parent's PID is: %d\n", getppid());		//Obtain the parent's PID by using getppid();

		printf("CHILD: SharedData = %d\n", shareData);			//Display the shared data.
		shareData=20;							//Change the shared data.
		printf("CHILD: Changing the SharedData to %d\n", shareData);	//Display the changed shared data.

		printf("CHILD: Creating a grandchild process... \n");		//Create a grand child process.
		pid_t grandchild = fork();					//Do this by forking again.


		if(grandchild < 0){						//check is the grandchild fork has failed.
			perror("The grandchild fork has failed");
			exit(1);
		}

		if(grandchild == 0){								//Do the same thing that the child process was doing.
			printf("GRANDCHILD: Hello family, I am the grandchild process!\n");
			printf("GRANDCHILD: THIS IS MY PID: %d\n",getpid());
			printf("GRANDCHILD: My Parent's PID is: %d\n", getppid());
			printf("GRADNCHILD: I will now go sleep Zzzzz.....\n");			//Demonstrate that the grandchild is sleeping which simulates work.
			sleep(5);

			exit(100);								//Diplay the exit status of the grandchild as status code 100;
		}else{
			int status;
			waitpid(grandchild, &status, 0);
			if(WIFEXITED(status)){
				printf("CHILD: The Grandchild has exited with status: %d\n", WEXITSTATUS(status)); //Attain the exit status using WECITSTATUS.
			}
		}
		exit(0);
		}else{
		int status2;					//Exit the Child Process also.
		waitpid(child, &status2, 0);


		if(WIFEXITED(status2)){										//Exit the parent status.
			printf("PARENT: Child has exited with Status: %d\n", WEXITSTATUS(status2));
		}
		printf("PARENT: SharedData = %d (unchaned in parent)\n", shareData);				//Print the sharedData.
		printf("PARENT: Goodbye!\n");									//Say goodbye.
		}

	return 0; 
}
