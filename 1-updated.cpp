/******************************************************************************
Assignment 2 will introduce the concept of executing a process,
from a child process. Use the execvp() and fork() commands to accomplish this. Your program should:

"	wc (Word Count) the 1.cpp file on the child process
"	Print the results to the standard output
*/
/* Danyelle Palmore
* 9/8/2024
COMP 350 001
This program accomplishes showing process id for current process that is created and forks a child process and prints the childs id. When a child process is not started from the fork() function then and error message is displayed to alert the user
*/

/* test fork failure
    const int numProcesses = 2000;
	for (int i = 0; i < numProcesses; ++i) {
	    pid_t pid = fork();

	    sleep(2);
	}
*/

// #include <bits/stdc++.h>
// #include <sys/types.h>
#include <sys/wait.h>
#include <iostream>
#include <unistd.h> 
#include<process.h>
#include <cstdio>

using namespace std;

int main() {
	cout << "Forking a child process " << endl;
	//new process created from fork() is child process(pid) which is exact copy of parent process(ppid)
	pid_t pid = fork();

	//fork failed (fork() returns -1 when child is not created); 	Check to verify the fork was created
	if (pid < 0) {
		perror("Error in creating fork");       //prints error message why fork() failed
		exit(EXIT_FAILURE);                     //terminate program
	}

	//child runs program
	else if (pid == 0) {
		int words = 0;
		cout << " \nThis is the child process: " << getpid();
		//parent of newly created process
		cout << " \nThis is the parent process: " << getppid();

		//new program loaded, ps replaces program process was running
		//int execvp(const char *2.cpp, char *const argv[]);


		cout << "\n identical copy of parent is made, has different physical memory location by OS: " <<  pid << endl;
	}

//runs when fork returns only child process id
//wait for child process to finish/
	else {
		cout << " \nThis is the parent process: " << getppid();
		wait(NULL);
		cout << " finishing parent process" <<endl;
	}

	return 0;
}