/*
 * #include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

int main() {
    int nbOctets;
    int descTube[2];
    int descTube2[2];
    int pid;
    const char chaine[] = "message en provenence de p1";
    const char chaine2[] = "message en provenence de p2";
    char buffer[BUFSIZ];
    memset(buffer, '\0', BUFSIZ);
    char buffer2[BUFSIZ];
    memset(buffer2, '\0', BUFSIZ);
    //P1

    if (pipe(descTube) == 0) {
        if (pipe(descTube2) == 0) {
            pid = fork();
            if (pid == 0) { //P2

                nbOctets = write(descTube2[1], chaine2, strlen(chaine2));
                printf("je suis p2 : %d octets écrit \n", nbOctets);
                nbOctets = read(descTube[0], buffer, BUFSIZ);
                printf("je suis p2 : %d octets lus %s\n", nbOctets, buffer);

            } else //P1 
            {
                nbOctets = write(descTube[1], chaine, strlen(chaine));
                printf("je suis p1 : %d octets écrit \n", nbOctets);
                nbOctets = read(descTube[0], buffer, BUFSIZ);
                printf("je suis p1 :octets lus: %d: %s\n", nbOctets, buffer2);
            }
        }
    }
    return EXIT_SUCCESS;
}
*/
