#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

//Declaring Global Variables Here.
double average = 0;
int minimum;
int maximum;

//This is the data structure.
typedef struct{
	int *numbers;
	int count;
}Data;

//This thread function calculates the average value of the integers passed.
void* avg(void *param){
	Data *data = (Data *)param;
	int sum =0;
	for(int i =0; i<data->count; i++){
		sum+=data->numbers[i];
	}
	average = (double)sum/data->count;	//Divide the summed up value by the number of integers entered.
	pthread_exit(0);			//Exit the thread.
}

//This thread function calculates the maximum value of the integers entered.
void* max(void *param){
	Data *data = (Data *)param;
	maximum =data->numbers[0];
	for(int i =1; i<data->count; i++){
		if(data->numbers[i] > maximum){
			maximum = data -> numbers[i];	//Save the bigger number to the maximum variable.
		}
	}
	pthread_exit(0);	//Exit the thread.
}

//This thread function calculates the minimum value of the integers entered.
void* min(void *param){
	Data *data = (Data *)param;
	minimum = data->numbers[0];
	for(int i=1; i<data->count; i++){
		if(data->numbers[i] < minimum){
			minimum = data->numbers[i];	//Save the smallest number to the minimum variale.
		}
	}
	pthread_exit(0);	//Exit the thread.
}


int main(int argc, char *argv[]){
	if(argc < 2){		//Check that atleast more than one integer has been pass in the command-line argument. 
		fprintf(stderr, "Usage: %s <list of integers> \n", argv[0]);
		return 1;
	}
	int count = argc -1;	//Store the integers entered in the numbers array.
	int numbers[count];
	for(int i = 0; i < count; i++){
		numbers[i] = atoi(argv[i + 1]); //Convert the string input into an integer. 
	}

	Data data = {numbers, count};		//The Data strucutre is initialized.

	pthread_t tid_avg, tid_max, tid_min;	//This is where the thread creation is made.


	pthread_create(&tid_avg, NULL, avg, &data);
	pthread_create(&tid_max, NULL, max, &data);
	pthread_create(&tid_min, NULL, min, &data);

	//Wait for the threads to be completed. 
	pthread_join(tid_avg, NULL);
	pthread_join(tid_max, NULL);
	pthread_join(tid_min, NULL);

	//Displays the results.
	printf("The average value is %.3f\n", average);	
	printf("The maximum value is %d\n", maximum);
	printf("The minimum balue is %d\n", minimum);

	return 0;
}
