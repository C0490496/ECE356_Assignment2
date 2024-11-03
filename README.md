*****ECE 356 ASSIGNMENT 2*****
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

Q4)

    
