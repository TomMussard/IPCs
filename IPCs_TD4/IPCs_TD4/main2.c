/*
 * #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int nbOctets;
    int descTube[2];
    int pid;
    const char chaine[] = "message en provenence de p1";
    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    //P1

    if (pipe(descTube) == 0) {
            pid = fork();
            if (pid == 0) { //P2
                nbOctets = read(descTube[0], buffer, BUFSIZ);
                printf("je suis p2: octets lus: %d: %s\n", nbOctets, buffer);
            } else //P1 
            {
                nbOctets = write(descTube[1], chaine, strlen(chaine));
                printf("je suis p1: %d octets ecrits\n", nbOctets);
            }
        }
    return EXIT_SUCCESS;
}
*/