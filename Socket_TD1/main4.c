/*#include <stdio.h>
#include <stdlib.h>
// include pour socket
#include <sys/types.h>
#include <sys/socket.h>
// include pour sockaddr_in
#include <netinet/in.h>
#include <arpa/inet.h>
// include gestion erreurs
#include <string.h>
#include <errno.h>
#include <unistd.h>

int main(int argc, char** argv) {
    int sock;
    int retour;
    int valEnvoyee, valRecue;
    int retourRead;
    int retourConnect;
    int retourWrite;
    struct sockaddr_in infosServeur;
    struct sockaddr_in infosReception;
    socklen_t taille = sizeof(infosServeur);
    // creation de la socket udp
    sock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP);
    if (sock == -1) {
        printf("pb socket : %s\n", strerror(errno));
    }
    // init de la structure pour communiquer avec le serveur
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555); // port dans ordre reseau
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.150");
    
    retourConnect = connect(sock,(struct sockaddr*)&infosServeur, taille);
    if (retour == -1){
        printf("pb socket : %s\n", strerror(errno));
        exit(errno);
    }
    
    valEnvoyee = 4853;
    
    retourWrite = write (sock,(void *) &valEnvoyee, sizeof(&valEnvoyee));
    if (retour == -1){
        printf("pb write : %s\n", strerror(errno));
        exit(errno);
    }
    
    retourRead = read (sock,(void *) &valRecue, sizeof(&valRecue));
    if (retour == -1){
        printf("pb read : %s\n", strerror(errno));
        exit(errno);
    }

     printf("%d\n", valRecue);
     
     return (EXIT_SUCCESS);
     
}*/