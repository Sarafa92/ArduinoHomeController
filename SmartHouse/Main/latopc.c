#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <termios.h>
#include <sys/stat.h>
#include <errno.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <termios.h>
#include <netdb.h> 
#include <sys/socket.h> 
#include <arpa/inet.h>
 #include <sys/types.h>

#include "latopc.h"


#define PORT 1234
int sockfd, connfd,len; 
struct sockaddr_in servaddr, cli; 


void connessioneSocket(){
	
	// Creazione socket e verifica
		sockfd = socket(AF_INET, SOCK_STREAM, 0); 
		if (sockfd == -1) { 
				printf("Creazione socket fallita...\n"); 
				exit(0); 
		} printf("Socket creata con successo...\n"); 
			bzero(&servaddr, sizeof(servaddr)); 

		// Assegnamento IP, e PORT 
		servaddr.sin_family = AF_INET; 
		servaddr.sin_addr.s_addr = htonl(INADDR_ANY); 
		servaddr.sin_port = htons(PORT); 

		// Assegnazione socket a ip e verifica (BIND)
		if ((bind(sockfd, (struct sockaddr*)&servaddr, sizeof(servaddr))) != 0) { 
			printf("Assegnazione socket fallita...\n"); 
			exit(0); 
		}
		printf("Socket assegnata con successo...\n"); 

	//Il server si mette in ascolto, e verifica
	if ((listen(sockfd, 5)) != 0) { 
		printf("Server in ascolto fallito...\n"); 
		exit(0); 
	} 
		printf("Server in attesa di una connessione...\n"); 
	len = sizeof(cli); 

	//Accetto connessione da un client
	connfd = accept(sockfd, (struct sockaddr*)&cli, &len); 
	if (connfd < 0) { 
		printf("Connessione con client fallita...\n"); 
		exit(0); 
	} 
		printf("Connessione con client effettuata con successo...\n"); 

 
} 
	
const char* porteSeriale[5]= {	"/dev/ttyACM0","/dev/ttyACM1","/dev/ttyACM2","/dev/ttyACM3","/dev/ttyACM4"};
								
							
							
//Ricerca della porta
int apriSeriale(int* fd){
	int i;
	for (i=0 ; i<5 ; i++){
		*fd = open(porteSeriale[i], O_RDWR | O_NOCTTY | O_NDELAY);
		if (*fd >= 0){
			printf("Porta Seriale %s trovata...\n", porteSeriale[i]);
			return i;
		}
		else { 
			printf("Porta Seriale %s non trovata...\n", porteSeriale[i]);
		}
	}
	return -1;
}


//Setto la seriale attraverso la struct termios

void setSeriale(int fd){
	struct termios Seriale;	// Struttura termios

	tcgetattr(fd, &Seriale);	//prendi gli attributi correnti della porta seriale

	cfsetispeed(&Seriale,B19200); //settaggio input e baudrate a 19200
	cfsetospeed(&Seriale,B19200); //settaggio output e baudrate a 19200

	//Settaggio Flag
	Seriale.c_cflag &= ~PARENB;   //No parità
	Seriale.c_cflag &= ~CSTOPB;   // CSTOPB = 1 bit di stop
	Seriale.c_cflag &= ~CSIZE;	 //cancella maschera per impostazione della dim dei dati
	Seriale.c_cflag |=  CS8;      //settaggio dei bit di dati a 8 bit

	Seriale.c_cflag &= ~CRTSCTS;       //Nessun controllo del flusso hardware
	Seriale.c_cflag |= CREAD | CLOCAL; //Abilitazione ricevitore

	Seriale.c_iflag &= ~(IXON | IXOFF | IXANY);         //disabilita il controllo di flusso
	Seriale.c_iflag &= ~(ICANON | ECHO | ECHOE | ISIG);  //modalità non canonica

	Seriale.c_oflag &= ~OPOST;		//Nessuna elaborazione in uscita

	if((tcsetattr(fd,TCSANOW,&Seriale)) != 0){
		printf("\nImpossibile settare i valori per la seriale...\n");
		exit(EXIT_FAILURE);
	}
	else{
		printf("\nSeriale settata correttamente...\n");
	}
}



int main(){


	int fd, bytes_read, i, flag;
	char stringa[32];
	
	//inizializzazione
	bytes_read = 0;
	i = 0;
	flag = 0;
	
	
	//connessione alla socket
	connessioneSocket();
	//connessione alla seriale
	if(apriSeriale(&fd) < 0){
		printf("Impossibile aprire connessione con la seriale...\n");
		return -1;
	}
	else printf("Connessione con seriale effettuata con successo...\n");

	//settaggio seriale
	setSeriale(fd);
	
 	
  //polling sulla socket, per ricevere dati da web 	
  while(1){
			
			bzero(stringa, strlen(stringa)); //Pulisco buffer
			bytes_read = recv(connfd,stringa,32,0); //Leggo dalla socket
			
			//se ho letto Quit allora chiudi tutte e due le connesioni, socket e seriale e interrompi il ciclo.		 	
			if(strncmp(stringa, "QUIT", strlen("QUIT"))==0){
				
				 if(close(connfd) == 0 && close(fd) == 0){
				 	 printf("\n\nConnessione chiusa correttamente\n");
				 }else{
				 	printf("\n\nErrore nella chiusura della connessione\n");
				 }		 
				 
				 break;
			} 
				
			//altrimenti invio  all'arduino
			write(fd,stringa,bytes_read);
			//printf("Scritto %s \n\n", stringa);
			
			//READ da arduino ACK da implementare
			
			bytes_read = 0;
	
	}
	
}
	
