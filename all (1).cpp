/* Danyelle Palmore
COMP 350
This program prints process id for current process that is created and forks a child process and prints their id
*/
#include <bits/stdc++.h>

#include <sys/types.h>

#include <unistd.h>

using namespace std;


int main() {
    //pid_t pid = getpid();
    //cout << " This is the process id: " << pid;

    cout << "Forking a child process " << endl;
    //new process created from fork() is child process(pid) which is exact copy of parent process(ppid)
    pid_t child_pid = fork();

    //error handling; forking process failing condition; fork() usually returns 0 when ran successfully
    if (child_pid == -1) {
        cout << "ERROR : failed to fork child process \n";
        exit(EXIT_FAILURE);
    }

    else if (child_pid == 0) {
        cout << " \nThis is the child process: " << getpid();
        //parent of newly created process
        cout << " \nThis is the parent process: " << getppid();
    }

    //fork returns child process id
    else {
        cout << " \nThis is the parent process: " << getppid();
    }

    return 0;
}