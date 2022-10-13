#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <string.h>
#include <sys/syscall.h>


typedef struct {
	int v1;
	int v2;
	int v3;
}laStruct;

laStruct partage;

void *threadMulti(void *arg) {
    laStruct *ptr = (laStruct *) arg;
    printf("dans le threadMulti mon tid est : %ld\n", syscall(SYS_gettid));
    printf("mise a jour de v1, v2, v3 avec la valeur %d, %d, %d\n", ptr->v1, ptr->v2, ptr->v3);
    
    partage.v1 = ptr->v1;
    partage.v2 = ptr->v2;
    partage.v3 = ptr->v3;
    
    pthread_exit(NULL);
}

void affichePartage() {
    printf("____________________\n");
    printf("v1 = %d\n", partage.v1);
    printf("v2 = %d\n", partage.v2);
    printf("v3 = %d\n", partage.v3);
}


int main(int argc, char** argv) {
    pthread_t t1, t2, t3;
    int ret;
    void *thread_result;
    laStruct param1, param2, param3;
    
    // element de la structure commune aux thread
    partage.v1 = 0;
    partage.v2 = 0;
    partage.v3 = 0;
    printf("avant création thread\n");
    
    
    //création du thread 1
    param1.v1 = 1;
    param1.v2 = 1;
    param1.v3 = 1;
    ret = pthread_create(&t1, NULL, threadMulti, (void *) &param1);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("création thread 1 \n");
    affichePartage();
    
    //création du thread 2
    param2.v1 = 2;
    param2.v2 = 2;
    param2.v3 = 2;
    ret = pthread_create(&t2, NULL, threadMulti, (void *) &param2);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("création thread 2 \n");
    affichePartage();
    
    
    //création du thread 3
    param3.v1 = 3;
    param3.v2 = 3;
    param3.v3 = 3;
    ret = pthread_create(&t3, NULL, threadMulti, (void *) &param3);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    printf("création thread 3 \n");
    affichePartage();
    
    
    ret = pthread_join(t1, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
    
    
     ret = pthread_join(t2, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
     
     
      ret = pthread_join(t3, &thread_result);
    if (ret != 0) {
        perror("Thread join a foir... echoué");
        exit(EXIT_FAILURE);
    }
      
    //printf("OK, valeur de retour du Thread join :%s\n", (char *) thread_result);
    //printf("Le message est maintenant %s\n", message);
      
    exit(EXIT_SUCCESS);
}

