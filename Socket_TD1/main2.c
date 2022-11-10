/*#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <errno.h>

struct datePerso
{
    unsigned char jour;
    unsigned char mois;
    unsigned short int annee;
    char jourDeLaSemaine[255];
};

int main(int argc, char** argv)
{
    // créer une socket DGRAM(udp)
    int sock = socket(PF_INET, SOCK_DGRAM, IPPROTO_UDP);
    if (sock == -1)
    {
        printf("PB socket : %s\n", strerror(errno));
        exit(errno);
    }
    // initialiser la structure sockaddr_in avec l'adresse et le port du serveur (172.18.18.158 2222)
    struct sockaddr_in infosServeur;
    infosServeur.sin_family = AF_INET;
    infosServeur.sin_port = htons(5555); // de l'hote vers le réseau sur 2 octets
    infosServeur.sin_addr.s_addr = inet_addr("172.18.58.150");
    // envoyer une date au serveur
    struct datePerso date;
    strcpy(date.jourDeLaSemaine, "mardi");
    date.jour = 18;
    date.mois = 10;
    date.annee = 2022;

    int retour = sendto(sock, &date, sizeof (date), 0, (struct sockaddr *) &infosServeur, sizeof (infosServeur));
    if (retour == -1)
    {
        printf("PB retour : %s\n", strerror(errno));
        exit(errno);
    }
    return (EXIT_SUCCESS);
}*/