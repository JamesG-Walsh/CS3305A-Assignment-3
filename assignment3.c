/* 	CS3305A 	Assignment 3
	James Walsh	jwalsh57	250481718	
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <errno.h>
#include <pthread.h>

int x, y, z; 

void *sum(){
	z=y+x;
	return NULL;
}

int main(){
	pid_t child, forking_pid;
	pthread_t thread;

    // Initializing the global variables
	x=10, y=20, z=0;

	/* MOVE THE FOLLOWING LINES INTO THEIR PROPER PLACES...
    */

   /* Add code under every comment to demonstrate differences between child and thread */
   
	forking_pid = fork(); // create child process
	
	if (forking_pid<0) // check for child creation error
	 {
		 printf("fork unsuccessful\n");
		 printf("main function: errno number is %d\n", errno);	
		 exit(1);
	 }

	if(forking_pid>0) // in parent:
	{
	wait(NULL); // wait for child, and print value of z
	printf("Using a fork(), the value of z in the parent process is: %d\n", z); //value of z after the fork process won't change
	
	// create thread, wait for it to complete, then print value of z
	pthread_create(&thread, NULL, sum, NULL);
	pthread_join(thread, NULL);
	printf("Using a thread, the value of z is: %d\n", z); //value of z after passing to the thread will change

	}

	if(forking_pid==0)// in child:
	{
	sum();// sum x and y and store it in z
	printf("Using a fork(), the value of z in the child process is: %d\n", z); // print value of z
	}

	return 0;
}
