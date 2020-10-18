
#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	int child1=fork();
	int child2,child3,child4,child5;
	char *s;
	char *ss;
	ss="./s.out";
	s="s.out"; 
	if(child1<0||child2<0||child3<0)
	{
	perror("fork");
	exit(1);
	}
	if(child1==0)
	{ 
	execlp("gcc","gcc","-c","sqr.c",NULL);
	printf("Compilation of sqr.c is completed\n");
    	}
    	else
    	{
    	waitpid(child1, &returni, 0);
    	//child2=fork();
    	}

	child2=fork();
	if(child2==0)
	{
    	execlp("gcc","gcc","-c","sum.c",NULL);
	printf("Compilation of sum.c is completed\n");
	}
    	else
    	{
	waitpid(child2, &returni, 0);
    	}
	child3=fork();
	if(child3==0)
	{
    	execlp("gcc","gcc","-c","test.c",NULL);
	printf("Compilation of test.c is completed\n");
	}
    	else
    	{
	waitpid(child3, &returni, 0);
    	}
	child4=fork();
	if(child4==0)
	{
  	execlp("gcc","gcc","sum.o","sqr.o","test.o","-o","s.out",NULL);
	printf("Linking is completed\n");
	printf("Execution:\n");
	}
    	else
    	{
	waitpid(child4, &returni, 0);
	  } 
	execl("./s.out", "./s.out", NULL); 	 
	exit(0);
}

