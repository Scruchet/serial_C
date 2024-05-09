#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <wiringPi.h>

#define LED_PIN 0 // GPIO 17


int setup(void){
    if (wiringPiSetup() == -1)
	return -1;
    pinMode(LED_PIN, OUTPUT);
    return 0;
}


int main() {
    if (setup() == -1){
	exit(1);
    }
    int fd;
    char buffer[1024];  // Buffer pour stocker les données lues
    ssize_t bytes_read;

    const char *port = "/dev/ttyS0";  // Port 

    // Ouvre le port série en lecture seule
    fd = open(port, O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du port série");
        return 1;
    }

    printf("Attente de données...\n");

    // Lecture des données depuis le port série
    while (1) {
        bytes_read = read(fd, buffer, sizeof(buffer));
        if (bytes_read == -1) {
            perror("Erreur lors de la lecture depuis le port série");
            close(fd);
            return 1;
        } else if (bytes_read == 0) {
            // Aucune donnée disponible, attendre un peu
            usleep(10000); // Attendre 10ms
        } else {
            // Affiche les données lues
            printf("Données reçues : %.*s", (int)bytes_read, buffer);
	    if (strncmp(buffer, "BLINK", 5) == 0){
		for (int i = 0 ; i < 10 ; i++){
		        digitalWrite(LED_PIN, HIGH);
		        delay(100); // Attend 1 seconde

		        //  ^iteint la LED
		        digitalWrite(LED_PIN, LOW);
		        delay(100); // Attend 1 seconde
}
        }
      } 
    }

    // Ferme le port série
    close(fd);
    printf("Je suis en dehors de la boucle\n");
    return 0;
}

