/*
#include "zone.h"


float randomF(){ 
	return ((float)100.0*(rand()/(RAND_MAX+0.1))); 
} 

int randomI(){ 
	return ((int)100.0*(rand()/(RAND_MAX+0.1))); 
}



int main(int argc, char** argv) {
    
    struct donnees File;
    int idFile;
    unsigned int val;
    unsigned int *pVal;
    char *pTexte;
    unsigned char *pInt;
    int cpt;
    float valF;
    
    idFile = msgget((key_t) 5678, 0666 | IPC_CREAT);
    if ( idFile == -1) {
        printf("pb création file : %s\n", strerror(errno));
        exit(1);
    }
    
    while (1) {
        valF =randomF();
        sprintf(File.texte, 8, ",f", valF);
        File.type = 2;  // message de type 2
        msgnsd(idFile, (void*) &File, sizeof (float), IPC_NOWAIT);
        
        val = randomI();
        printf("val = %d\n", val);
        pVal = &val;
        pInt = (char*) &val;
        pTexte = File.texte;
        
        for (cpt = 0; cpt<sizeof (int); cpt++) {
            pTexte[cpt] =pInt[cpt];
        }
        pVal = (unsigned int*) pTexte;
        printf("int genere : %d\n", *pVal);
        File.type = 4;
        msgsnd(idFile, [void*] &File, sizeof (int), IPC_NOWAIT);
        sleep(1);
    }

    return (EXIT_SUCCESS);
}

*/
