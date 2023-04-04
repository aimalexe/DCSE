#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int pid,i,j,k,h;

    // loop to create 4 child processes
    for(i=2;i<=5;i++){
        pid = fork(); // create a child process

        if(pid==0){ // child process
            printf("Child %d with parent %d\n", getpid(), getppid());

            if(i==2){ // if it's the second child process
                // loop to create 3 grandchild processes
                for(j=1;j<=3;j++){
                    pid = fork(); // create a grandchild process

                    if(pid==0){ // grandchild process
                        printf("Child %d with parent %d\n", getpid(), getppid());	
                        break;
                    }
                }

                if(j==1){ // if it's the first grandchild process
                    pid = fork(); // create a great-grandchild process

                    if(pid==0){ // great-grandchild process
                        printf("Child %d with parent %d\n", getpid(), getppid());
                    }
                }

                if(j==2){ // if it's the second grandchild process
                    // loop to create 2 great-grandchild processes
                    for(h=1;h<=2;h++){
                        pid = fork(); // create a great-grandchild process

                        if(pid==0){ // great-grandchild process
                            printf("Child %d with parent %d\n", getpid(), getppid());
                        }
                    }

                    if(h==1){ // if it's the first great-grandchild process
                        pid = fork(); // create a great-great-grandchild process

                        if(pid==0){ // great-great-grandchild process
                            printf("Child %d with parent %d\n", getpid(), getppid());
                        }
                    }
                }
            }

            if(i==3){ // if it's the third child process
                pid = fork(); // create a grandchild process

                if(pid==0){ // grandchild process
                    printf("Child %d with parent %d\n", getpid(), getppid());	
                }
            }

            if(i==4){ // if it's the fourth child process
                // loop to create 2 grandchild processes
                for(k=1;k<=2;k++){
                    pid = fork(); // create a grandchild process

                    if(pid==0){ // grandchild process
                        printf("Child %d with parent %d\n", getpid(), getppid());	
                    }
                }
            }		

            break; // exit the child process
        }
    }

    if(pid>0){ // parent process
        printf("parent id :%d\n",getpid());

        for(i=0;i<=14;i++){ // wait for all child processes to complete
            wait(NULL);
        }
    }

    return 0;
}

