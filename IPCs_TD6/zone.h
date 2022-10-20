#include <sys/types.h> 
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h> 
#include <errno.h> 
#include <time.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

#ifndef ZONE_H
#define ZONE_H


// type qui va être partager
struct donnees {
    float temp;
    int press;
    char ordre;
};
#endif /* ZONE_H */

