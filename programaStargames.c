

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main () {
	
	char juego1,juego2,jugador1,opcion;
	

	do{
	printf("BIENVENIDO AL MENU DE STARGAMES \n");
	printf("Introduzca numero del juego que desea jugar:\n");
	
	scanf("%c",&opcion);
	
	switch (opcion){
		case '1'://Snake
			printf("J1 introduzca su nombre de usuario:\n");
			fflush(stdin);
			scanf("%c",&jugador1);
			printf("Es un juego basado en aumentar la longitud de la serpiente , solo puede jugar un jugador.\n");
		     printf("El usuario tendra tres niveles de dificultad:facil,medio,dificil.\n");
			printf("Si el usuario completa el juego le saldra un mensaje de reiniciaro o volver al menu del programa.\n");
			printf("Si el usuario choca con alguna de las paredes le aparecera un mensaje de GAME OVER y la opcion de volver a empezar.\n");
			break;
			
			
		case '2'://Ahorcado
			printf("J1 introduzca su nombre de usuario:\n");
			fflush(stdin);
			scanf("%c",&jugador1);
		    printf("Es un juego que trata de adivinar ciertas palabras con un numero de oportunidades.\n");
			printf("El usuario tendra que decir una letra del abecedario en cada turno para intentar deducir la palabra,");
			printf("pero solo tiene 5 oportunidades,sino fallara el juego\n");
			printf("Cada vez que una letra dicha no aparezca en la palabra,se le restara una oportunidad .\n");
			printf("Cuando el jugador acierta la palabra el juego mostrara un mensaje de VICTORIA!!! ,\n");
			printf(" si el jugador no acierta la palabra y no tiene oportunidades restantes aparecera un mensaje de FIN DE JUEGO.\n");
			printf("En ambos casos se mostrara la opcion de volver al menu o reiniciar el juego\n");
			break;
	
		
	    case'3'://Abandonar juego
			printf("Hasta la proxima!!!!!!!!\n");
			break;
		default:
		    printf("la opcion es incorrecta:\n");
		    break;
			return 0;//salir del programa
	}
		
}while (juego1||juego2);
		
	}
