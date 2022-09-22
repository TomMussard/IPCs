/*#include <stdio.h>
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
    cpt++;
    printf("cpt : %d\n",cpt);
    if (cpt==2) {
        printf("un signal SIGUSR1 je suis pid :%d\n", getppid());
    }
}

int main(int argc, char *argv[]) {
    int pid, pidP1;
    (void) signal(SIGUSR1, traitement); // rederoutage des signaux SIGUSR1
    //P1
    pidP1 = getpid();
    cpt = 0;
    // vers la fonction traitement
    pid = fork();
    if (pid == 0) //P2
    {
        pid = fork();
        if (pid == 0) //P3
        {
            printf("p3 pid=%d\n", getpid());
            kill(pidP1, SIGUSR1);
        } else //P2
        {
            printf("p2 pid=%d\n", getpid());
	    kill(pidP1, SIGUSR1);
        }

    } else //P1
    {
        printf("pere pid=%d\n", getpid());
        pause();
        pause();
    }
    return EXIT_SUCCESS;
}
 */