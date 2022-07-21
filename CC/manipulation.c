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
	struct mq_attr attr, *attrp;
	attrp = NULL;
	attr.mq_maxmsg = 50;
	attr.mq_msgsize = 10;
	
	mqd_t file_c ;
	
	//reception
	int n ;
	struct ch *buffer = NULL;
	if ((buffer = malloc(sizeof(struct ch))) == NULL) {
		perror("erreur de creation du buffer");
		exit(EXIT_FAILURE);
	}
	unsigned int priorite;
	
	//creation de la file de messages
	if ((file_c = mq_open("/file_caracteres", O_CREAT, S_IRUSR | S_IWUSR, attrp)) == (mqd_t) -1) {
		perror("erreur lors de l'open");
		exit(EXIT_FAILURE);
	}
	printf("file de messages créée\n");
	
	//réception des données
	if ((n = mq_receive(file_c, buffer, attr.mq_msgsize, &priorite)) < 0) {
		perror("erreur lors du receive");
		exit(EXIT_FAILURE);
	} else {
		if(buffer->operation!="!"){
			printf("données reçues : bonjour %s => %s\n", buffer->operation, buffer->c);
		} else {
			printf("! reçu : fin de la file de messages\n");
			//destruction de la file de messages
			mq_close(file_c);
		}
		
	}

	printf("fin\n");
	return EXIT_SUCCESS ;
}