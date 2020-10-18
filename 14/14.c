
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
	int child2;
	int child3;
	int child4;
	int child5,child6;
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
	execlp("gcc","gcc","-c","test.c","sum.c","sqr.c",NULL);
    	}
    	else
    	{
    	waitpid(child1, &returni, 0);
    	//child2=fork();
    	}
	child2=fork();
	if(child2==0)
    	execlp("ar","ar","rc","libfunctions.a","sum.o","sqr.o",NULL);
    	else
    	{waitpid(child2, &returni, 0);
    	}
	 
	child3=fork();
	if(child3==0)
	execlp("gcc","gcc","-L.","test.o","-o","all.out","-lfunctions",NULL);
	else
    	{
	waitpid(child3, &returni, 0);
	  }
	child4=fork();
	if(child4==0)
	
	execlp("gcc","-L.","test.o","-o","libout.out","-lmyfunctions",NULL);
	else
    	{
	waitpid(child4, &returni, 0);
	  }
	child5=fork();
	if(child5==0)
	execl("libout.out","libout.out",NULL);
		 
	exit(0);
}

   

