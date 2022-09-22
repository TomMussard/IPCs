#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

/*int main ( int argc, char *argv[] )
{
	int pid1,pid2;
	int cpt=0;
	pid1 = fork();
	if ( pid1 == 0 )
	{
		cpt++;
		pid2 = fork();
		if ( pid2 == 0 )
		{ 
			cpt++;
			printf("dans petit fils cpt=%d a l'adresse %p\n",cpt,&cpt);
		}
		else
		{
			cpt++;
			printf("dans fils cpt=%d a l'adresse %p\n",cpt,&cpt);
		}
	}
	else
	{
		cpt++;
		printf("dans pere cpt=%d a l'adresse %p\n",cpt,&cpt);
	}
	return EXIT_SUCCESS;
}*/
/*int main ( int argc, char *argv[] )
{
        int pid1,pid2;
        pid1 = fork();
        if ( pid1 == 0 )
        {
                boite("boite1","pid1=0");
                pid2 = fork();
                if ( pid2 == 0 )
                {
                        boite("boite2","pid2=0");
                }
                else
                {			
                        boite("boite3","pid2<>0");
                }
        }
        else
        {
                boite("boite4","pid1<>0");
        }
        return EXIT_SUCCESS;
 */

int main(int argc, char *argv[]) {
    int pid;
    char buffer[255];
    //P1
    pid = fork();
    if (pid == 0) { //P2

        sprintf(buffer, "mon pid est %d, le pid ed mon pere est %d", getpid()) {
            boite("P2", buffer);
        }
    } else //P1
    {
        pid = fork();
        if (pid == 0) //P3
        {

            sprintf(buffer, "mon pid est %d, le pid ed mon pere est %d", getpid()) {
                boite("P2", buffer);
            } else //P1
                sprintf(buffer, "mon pid est %d, le pid ed mon pere est %d", getpid()) {
                boite("P2", buffer);
            }
        }
        return EXIT_SUCCESS;
    }
    