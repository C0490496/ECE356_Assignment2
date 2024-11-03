#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <ctype.h>

/* ***The Idea of the Collatz Conjecture is that any positive number will eventually reach the number 1 with the following conditions.
		-If the number is even, divide it by 2.
		-If the number is odd, multiply it by 3 and add 1.
*/

int integercheck(const char *str){			//This is a function to check if the input is a positive integer.
	for(int i =0; str[i] != '\0'; i++){		//Iterate through the string and determine if the string entered was only integers. 
		if(!isdigit(str[i])){
		return 0;
		}
	}
	return 1;
}

void collatz(int n){
	while(n != 1){
	printf("%d ", n);
	if(n % 2 == 0) {		//Determine if the number is even or odd.
		n /= 2;			//If even then divide it by 2.
	}else{
		n = 3 * n + 1;		//If odd then multiply it by 3 and add 1.
		}
	}
	printf("1 \n"); 		//fnish the sequence with 1
}

int main(){
	pid_t pid;
	char input [50];


	//The parent process promtpts for a positive integer
	printf("PARENT: Please enter a postive integer: ");
	fgets(input, 50, stdin);				//Get the input from the user.

	input[strcspn(input, "\n")]= '\0';			//Remove any new line characters in the input by the user.

	if(!integercheck(input)){				//Check if the input entered by the user was only integers.
		fprintf(stderr, "Error: Please renter a valid positive integer. \n");
		return 1;

	}
	int i = atoi(input);       //Convert the input into an integer.
	if(i <= 0) {		   //Check if the input was a positive integer greater than 0.
		fprintf(stderr, "Error: Please renter a positive integer greater than 0. \n");
		return 1;
	}

	pid = fork();		//Create the Child Process.

	if(pid < 0){		//Check if the PID failed.
		perror("The Fork has failed");
		return 1;
	}else if(pid == 0){	//Call the Collatz Function and pass through the entered integer value.
		printf("Collatz sequence for %d: ", i);
		collatz(i);
		exit(0);
	}else{			//Prompt that the sequence was completed.
		wait(NULL);
		printf("Sequence generation complete. \n");
	}
	return 0;
}

