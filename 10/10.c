#include <signal.h> 
#include <stdio.h> 
#include <stdlib.h> 
#include <sys/types.h> 
#include <unistd.h> 
  

void sighup(); 
void sigint(); 
void sigquit(); 
  
 
void main() 
{ 
    int pid; 
  
    /* child process */
    if ((pid = fork()) < 0) { 
        perror("fork"); 
        exit(1); 
    } 
  
    if (pid == 0) { /* child */
        signal(SIGHUP, sighup); 
        signal(SIGINT, sigint); 
        signal(SIGQUIT, sigquit); 
        for (;;) 
            ; /* loop for ever */
    } 
  
    else /* parent */
    { 
        printf("\nParent: sends SIGHUP signal\n\n"); 
        kill(pid, SIGHUP); 
  
        sleep(3); 
        printf("\nParent: sends SIGINT signal\n\n"); 
        kill(pid, SIGINT); 
  
        sleep(3); 
        printf("\nParent: sends SIGQUIT signal\n\n"); 
        kill(pid, SIGQUIT); 
        sleep(3); 
    } 
} 
  
// sighup() function definition 
void sighup() 
  
{ 
    signal(SIGHUP, sighup); /* reset signal */
    printf("Child  received a SIGHUP signal\n"); 
} 
  
// sigint() function definition 
void sigint() 
  
{ 
    signal(SIGINT, sigint); /* reset signal */
    printf("Child received a SIGINT signal\n"); 
} 
  
// sigquit() function definition 
void sigquit() 
{ 
    printf("Killed!\n"); 
    exit(0); 
} 
