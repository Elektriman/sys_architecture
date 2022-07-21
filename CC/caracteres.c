#include <fcntl.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ch {
   char c[11] ; // chaine
   char operation ; //M, m ou ! pour l’arrêt
} CH; 

int main(int argc, char* argv[]){
	//initialisation des variables
	
	//creation
	struct mq_attr attr;
	mqd_t file_c ;
	
	//envoi
	int n ;
	char *buffer = NULL;
	if ((buffer = malloc(attr.mq_msgsize)) == NULL) {
		perror("erreur de creation du buffer");
		exit(EXIT_FAILURE);
	}
	unsigned int priorite;
	
	//creation de la file de messages
	if ((file_c = mq_open("/file_caracteres", O_WRONLY | O_CREAT, 0644, NULL)) == (mqd_t) -1) { 
		perror("erreur lors de la creation");
		exit(EXIT_FAILURE);
	}
	mq_getattr(file_c, &attr);
	printf("file de messages créée\n");
	
	//envoi des données
	struct ch CH;
	scanf("Données ? %s %s", CH.c, CH.operation);
	if (mq_send(file_c, CH, sizeof(CH), priorite) != 0){
		perror("mq_send");
		exit(EXIT_FAILURE);
	}
	
	return EXIT_SUCCESS ;
} 