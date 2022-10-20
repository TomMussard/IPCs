/*
#include "zone.h"

float randomF(){ 
	return ((float)100.0*(rand()/(RAND_MAX+0.1))); 
} 

int randomI(){ 
	return ((int)100.0*(rand()/(RAND_MAX+0.1))); 
}




int main()
{
    
    struct donnees *ZonePartage;
    int id;
    int oldt, oldp;
    
    //création de la zone mémoire partagee
    
    id = shmget((key_t) 1234, sizeof (struct donnees), IPC_CREAT | 0600);   // autorisation de R and W
    if (id == -1) {
        if(errno !=EEXIST) {
            printf("pb shmget : %s\n", strerror(errno));
            exit(2);
        }
    }
    
    // attribution adresse virtuelle du segment
    
    ZonePartage = (struct donnees *) shmat(id, NULL, SHM_W);
    if (ZonePartage == NULL) {
         printf("pb shmat : %s\n", strerror(errno));
            exit(1);
    }
    
    
    while (1) //boucle infini
    {
        printf("ordre : %c temperature : %f pression : %d\n",
        ZonePartage->ordre,
        ZonePartage->temp,
        ZonePartage->press);
        sleep(1);
    }
}

*/
