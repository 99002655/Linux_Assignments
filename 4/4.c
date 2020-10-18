
/* mini shell that can take 6 arguments*/
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
    pid_t ret;
    int status;
    int cmd_exec;
    char Comm[10];
    printf("Enter your command:");
    scanf("%s", Comm);                  
    ret=fork();
    
    if(ret<0)
    {
        perror("fork");
        exit(1);
    }
    if(ret==0)
    {
        cmd_exec=execlp(Comm,Comm);
        if(cmd_exec<0)
        {
            perror("execlp");
            exit(2);
        }
        exit(0);
    }
    else
    {
        waitpid(-1,&status,0); //wait(&status);
        printf("parent--child exit status=%d\n",
			WEXITSTATUS(status));
    }
}
