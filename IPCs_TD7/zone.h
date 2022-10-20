#ifndef ZONE_H
#define ZONE_H

#include <sys/types.h> 
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/ipc.h> 
#include <sys/msg.h>
#include <errno.h> 
#include <time.h> 
#include <unistd.h> 
#include <stdlib.h> 
#include <stdio.h>
#include <string.h>

struct donnees{
	long type;
	char texte[9];
};

#endif /* ZONE_H */

