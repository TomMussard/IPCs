#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <bits/signum-generic.h>

void traitement(int sig) {
    (void) signal(SIGUSR1, traitement);
    printf("un signal SIGURS1 je suis pid  %d\n", getppid());
}

int main() {

    int nbOctets;
    int descTube[2];
    int pid;
    int pid2;
    int pid3;
    char buffer[BUFSIZ];


    (void) signal(SIGUSR1, traitement);
    
    memset(buffer, '\0', BUFSIZ);
    
    pid2 = getpid();
    printf("debut pid p1 : %d\n", pid);
    if (pipe(descTube) == 0) { //P1
            pid = fork();
            if (pid == 0)  //P2
            {
                pid = fork();
                if (pid == 0)  //P3
                {
                pid3 = getpid();
                printf("p3 pid=%d\n", pid3);
                nbOctets = write(descTube[1], &pid3, sizeof(pid3));
                printf("Je suis p3 : %d octets ecrit\n", nbOctets);
                pause();
                            
                }
                else //P2
                {
                    printf("p2 pid=%d\n", getpid());
                    pause();
                    sleep(5);
                }
            } else //P1
            {
                pid2 = pid;
                printf("pere pid=%d\n", getpid());
                sleep(3);
                kill(pid2, SIGUSR1);
                nbOctets = read(descTube[0], &pid2, sizeof(pid2));
                kill(pid3, SIGUSR1);
                sleep(3);   
            }
    }
    return EXIT_SUCCESS;
}