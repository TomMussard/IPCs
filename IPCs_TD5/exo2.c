/*#include <stdio.h>
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

// thread 1
void *thread1(void *arg) {
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread1 mon tid est : %ld\n", syscall(SYS_gettid));
    printf("mise a jour de v1 avec la valeur %d\n", val);
    partage.v1 = val;
    pthread_exit(NULL);
}

//thread 2
void *thread2(void *arg) {
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread2 mon tid est : %ld\n", syscall(SYS_gettid));
    printf("mise a jour de v2 avec la valeur %d\n", val);
    partage.v2 = val;
    pthread_exit(NULL);
}

//thread 3
void *thread3(void *arg) {
    int *ptr = (int *) arg;
    int val = *ptr;
    printf("dans le thread3 mon tid est : %ld\n", syscall(SYS_gettid));
    printf("mise a jour de v3 avec la valeur %d\n", val);
    partage.v3 = val;
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
    int valParam1, valParam2, valParam3;
    void *thread_result;
    
    // element de la structure commune aux thread
    partage.v1 = 0;
    partage.v2 = 0;
    partage.v3 = 0;
    printf("avant création thread\n");
    
    
    //création du thread 1
    valParam1 = 4;
    ret = pthread_create(&t1, NULL, thread1, (void *) &valParam1);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    affichePartage();
    printf("création thread 1 \n");
    
    
    //création du thread 2
    valParam2 = 5;
    ret = pthread_create(&t2, NULL, thread2, (void *) &valParam2);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    affichePartage();
    printf("création thread 2 \n");
    
    
    
    //création du thread 3
    valParam3 = 6;
    ret = pthread_create(&t3, NULL, thread3, (void *) &valParam3);
    if (ret != 0) {
        perror("Thread creation failed");
        exit(EXIT_FAILURE);
    }
    affichePartage();
    printf("création thread 3 \n");
    printf("____________________\n");
    
    
    
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
*/