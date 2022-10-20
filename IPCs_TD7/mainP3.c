/*
#include "zone.h"

float randomF() {
    return ((float) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int randomI() {
    return ((int) 100.0 * (rand() / (RAND_MAX + 0.1)));
}

int main(int argc, char** argv) {

    struct donnees File;
    char tampon[255];
    int idFile;
    int ret;
    unsigned char *pInt;

    idFile = msgget((key_t) 5678, 0666 | IPC_CREAT);
    if (idFile == -1) {
        printf("pb création file : %s\n", strerror(errno));
        exit(1);
    }

    while (1) {
        memset(File.texte, '\0', 9);
        ret = msgrcv(idFile, (void*) &File, 9, 2, IPC_NOWAIT);
        if (ret != -1) {
            printf("temp : %s\n", File.texte);
        }

        memset(File.texte, '\0', 9);
        ret = msgrcv(idFile, (void*) &File, 9, 3, IPC_NOWAIT);
        if (ret != -1) {
            printf("ordre : %s\n", File.texte);
        }
        
                memset(File.texte, '\0', 9);
        ret = msgrcv(idFile, (void*) &File, 9, 4, IPC_NOWAIT);
        if (ret != -1) {
            pInt = (unsigned int*) (File.texte);
            printf("press %d: %d\n", ret, *pInt);
        }
    }
    
    return (EXIT_SUCCESS);
}

*/
