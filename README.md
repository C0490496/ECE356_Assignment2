ECE 356 ASSIGNMENT 2

Name: Matthew Yap
Student Number: V00944282

Q1) In this question we were asked to implement a doubly link list process and to complete the goals presented in the question to simulate a simplified verision of how the 
    linux kernel maintain and manages processes using a doubly linked list. 
    To run the program follow the following steps:
      1. Run the DLLP executable file in linux by doing ./DLLP
      2. To check the code you can do cat DLLP.
    The code basically runs 5 simulated processes and display their given PIDs along with it.
    Then a specific process is found in this case process 2 was used as an example for the process that needed to be found. 
    After the process has been found a termination simulation is then done.
    A process navitigation then follows the termination which implements a way to move between processes.
    The current process is then swapped changinging its process to the next process.
    
Q2)This question is to implement process management with read and wait queues. Basically to implement a process management system using doubly linked lists to simulate how an operating
    system handles process. A ready and I/O wait queues will be used. There will be 4 states that the process will have: Ready, Wait, Running, and Terminated. 
    To run this code the ./processmanagement executable file should be run.
    The code basically calls a simulation function called simulateBackupProcessFlow which consists of calling the different functions related to the questions requirements:
      1) Prompt that Process 1 is created and added to the ready que.
      2) Call the executeProcess function to execute the proces.
      3) Call the requestIO function to move the process into the IO wait que.
      4) Call the ioComplete function which basically waits for the process to be completed and to return the process from the IO wait que.
      5) Call the exectureProcess function and call the interruptProcess to simulate interrupting a running process.
      6) Terminate the process once all the work has been completed.
      
Q3)The goal for this question is to develop a program that demosntrates the use of process creation using the fork() system call, inter-process communication via shared data, and process synchronization
    using the wait() system call.
    To run this code the ./processcreation executable file should be run.
    What is happening in this code is basically broken down in these steps:
    1) The parent process prompts the user that he exists and shows his associated PID.
    2) The fork function is then called to create a child process.
    3) The child process then does the same and shows he exists and demonstrates his PID.
    4) The child then shows his shared data with his parent.
    5) The child then changes his data.
    6) The fork function is then called to create a grandchild process.
    7) The grandchild does the same thing and shows he exists and shows his PID.
    8) The grandchild then simulates that he doing work by sleeping.
    9) The child terminates and shows his exit status.
    10) The parent then prompts that the child has exited with the given status.
    11) The parent shows the shared data and it should have not changed into the childs shared data.
    12) The parent then exits. 

Q4) This question is the problem that involves the Collatz Conjecture where you are rqeuired to use the fork() system call to generate the collatz sequence.
    To run this code the ./collatzfork executable file should be run.
    The sequence of what is happening in this code can be broken down into the following:
    1) A parent process is created where it request for an input from the user.
    2) It basically checks if they are valid positive integer values.
    3) Once all things are good a child process is created.
    4) If the child process creations is successful the collatz sequence is called. 
    5) Once the generation has been completed it then prompts the user that it has been completed.

Q5)This questions consists of creating a multiple operations for a drones takeoff or landing operations. The implementation of fork() system calls are requried to handle the different opertaions. 
    To run this code the ./drone exectuable file should be run.
    The codes flow is broken down into the following sequence:
    1) A child process is created and is responsible for dealing with the drones take off operations.
    2) Once the drone has taken off and has completed its task t he parent deals with the drones landing operations.
    3) Finally a prompt is given once the drone has successfully landed (parent process done).

Q6) An orphan is a child process whose parent process has been terminated or exited.  It is when the parent exits before the child process exits or gets terminated. It becomes a zombie process when it has completed its         execution, but the exit status has not been collected by the parent process yet. Although zombie processes do not take up or consume CPU usage or memory it still occupies a slot in the process table.  Now an orphan process becomes a zombie if the init process doe not properly collect its exit status. To avoid this the parent should use wait() or waitpid() to read the exit  status of this child processes as soon as they are finished.

Q7) If the fork returned a negative value then the for has failed usually an if statement with the condition: if(pid<0) can be used to detect if the fork has failed. To detect a exec() failure the same method of using an if statement can be used to detect if the function returned a -1 value or an errno.

Q8) This question requires to write a multithreading program that calculates for various statistical values for a list of numbers. The program will ask for a series of numbers on the command line and then will create three
    separate threads. One thread will deal with averaging of the number, another to determine the max value, and lastly to calcualte the minimum. 
    To run this code the ./multithread should be executed with the given series of numbers i.e ./multithread <90 80 55 67 89 24 65>

Q9) The final questions is a problem where the Monte Carlo techinique is involved to solve a series of random points as simple coordinates and that these points must fall within the Cartesian coordinates that bound the square        that hold the circle. Basically multithreading should be applied to this problem.
    To run this code the ./montecarlo executable file should be ran with the number of points and number of thread i.e ./montecarlo <12345 5>.
    1) Check if the number of arguements are valid. 
    2) Scale the values using rand().
    3) After the iteration of values the mutex thread is locked in order to update the global variables.
    4) Lock the mutex thread once the points have been updated. 
    5) Display the value using the given formula to esitmate the pi value.
    6) Terminate the resources allocated to the mutex threads. 



    
