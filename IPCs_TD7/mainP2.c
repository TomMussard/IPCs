#include "zone.h"


float randomC() {
    return ((char) ('A' + ((char))))
}
int main(int argc, char** argv) {
    
    struct donnees File;
    char tampon[255];
    int idFile;
    
    idFile = msgget((key_t) 5678, 0666 | IPC_CREAT);
    if ( idFile == -1) {
        printf("pb création file : %s\n", strerror(errno));
        exit(0);
    }
    
    while (1) {
        File.texte[0] = 'A');
        File.type = 3;  // message de type 2
        msgsnd(idFile, (void*) &File, sizeof (char), IPC_NOWAIT);
        sleep(1);
    }

    return (EXIT_SUCCESS);
}

