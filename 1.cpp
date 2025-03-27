/* Danyelle Palmore
* 9/8/2024
COMP 350 001
This program accomplishes showing process id for current process that is created and forks a child process and prints the childs id. When a child process is not started from the fork() function then and error message is displayed to alert the user
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

    //runs when fork returns only child process id
    else {
        cout << " \nThis is the parent process: " << getppid();
    }

    return 0;
}