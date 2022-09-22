#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <signal.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

// fonction de traitement du signal SIGUSR1
int cpt;

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
        printf("un signal SIGUSR1 je suis pid :%d\n", getppid());
}

int main(int argc, char *argv[]) {
    int pidP2;
    int pid;
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1
    //P1
    // vers la fonction traitement
    pid = fork();
    if (pid == 0) //P2
    {
        pid = fork();
        if (pid == 0) //P3
        {
            pidP2 = getppid();
            printf("p3 pid=%d\n", getpid());
            sleep(2);
            kill(pidP2, SIGUSR1);
       
        } else //P2
        {
            printf("p2 pid=%d\n", getpid());
            pause();
            pause();
        }
    } else //P1
    {
        pidP2 = pid;
        printf("pere pid=%d\n", getpid());
        sleep(1);
        kill(pidP2, SIGUSR1);
        sleep(2);      
    }
    return EXIT_SUCCESS;
}

