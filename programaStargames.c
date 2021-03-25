#include <stdio.h>

int main () {
	
	char juego1,juego2,juego3,jugador1,opcion;
	

	do{
	printf("BIENVENIDO AL MENU DE STARGAMES \n");
	printf("J (Seleccionar juego), R (Reglas del juego), 4 (Salir del programa) \n");
	printf("Introduzca numero del juego que desea jugar:\n");
	scanf("%c",&opcion);
	
	switch (opcion){
		case '1'://Solitario
			printf("J1 introduzca su nombre de usuario:\n");
			fflush(stdin);
			scanf("%c",&jugador1);
			printf("Es un juego basado en cartas , solo puede jugar un jugador.\n");
			printf("El usuario tendra que completar el solitario en menos de 15 min.\n");
			printf("Si el usuario completa el juego le saldra un mensaje de reiniciaro o volver al menu del programa.\n");
			printf("El usario tendra 3 comodines en caso de no poder compleatr el solitario.\n");
			break;
			
			
			
		case '2'://TRivial	
			printf("J1 introduzca su nombre de usuario:\n");
			fflush(stdin);
			scanf("%c",&jugador1);
			printf("Es un juego  basado en preguntas y respuestas,hay 4 categorias .\n");
			printf("El usuario tendra que responder al menos un quesito de cada categoria para poder jugar la ronda final,\n");
			printf("La Ronda final consta de 10 preguntas de categorias aleatorias, se permite fallar 2 \n");
			printf("Al inicio del juego, el usuario debera elegir un color con el que comenzara a jugar.\n");
			printf("Las categorias de este juego son:\n");
			printf(" -Ciencias.\n");
			printf(" -Deportes.\n");
			printf(" -Cultura general.\n");
			printf(" -Entretenimiento.\n");
			printf(" \n");
			printf("Cuando el jugador acierta la pregunta correspondiente a dicha categoria consigue un quesito ,\n");
			printf(" si el jugador no acierta la pregunta cambiaria de categoria al azar y tendria que responder dos preguntas en vez de una para ganar un quesito.\n");
			printf("Si el usuario que consiga los 4 quesitos jugara la ronda final\n");
			printf(" Consta de 10 preguntas pudiendo fallar 3.\n");
			printf("SI el usuario completa la ronda final ganará el juego.\n");
			break;
			
		case '3'://Ahorcado
			printf("J1 introduzca su nombre de usuario:\n");
			fflush(stdin);
			scanf("%c",&jugador1);
		    printf("Es un juego que trata de adivinar ciertas palabras con un numero de oportunidades.\n");
			printf("El usuario tendra que decir una letra de abecedario en cad turno para intentar deducir la palabra,");
			printf("pero no solo tiene 6 oportunidades,sino fallara el juego\n");
			printf("Cada vez que una letra dicha no aparezca en la palabra,se le restara una oportunidad y aparecera una notificacion con las restantes.\n");
			printf("Si tambien falla al intentar adivinar la palabra, contara tambien como oportunidad perdida.\n");
			printf("Los temas de este juego son:\n");
			printf(" -Famosos.\n");
			printf(" -Ciudades.\n");
			printf(" -Paises.\n");
			printf("Cuando el jugador acierta la palabra el juego mostrara un mensaje de VICTORIA!!! ,\n");
			printf(" si el jugador no acierta la palabra y no tiene oportunidades restantes aparecera un mensaje de FIN DE JUEGO.\n");
			printf("En ambos casos se mostrara la opcion de volver al menu o reiniciar el juego\n");
			break;
	
			  
	    case'4'://Abandonar juego
			printf("Hasta la proxima!!!!!!!!\n");
			default:
		printf("la opcion es incorrecta:\n");
			return 0;//salir del programa
	}
		
}while (juego1||juego2||juego3);
		
	}

	
	

