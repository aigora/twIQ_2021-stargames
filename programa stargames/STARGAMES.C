#include <stdlib.h>
#include "tcs.h"

#define N 21  //Tamano de mapa


char menu();


int main () {
	
	char juego1,juego2,jugador1,opcion,opcion1,opcion2,jugador2;
	
	int i=0;
	do{
		system("cls");
		opcion=menu();
		
	
		
	
	switch (opcion){
		case '1'://Snake
			printf("Seleccione 'r' si desea ver como jugar \n");
			printf("Seleccione 'i' para iniciar el juego\n");
			scanf("%c",&opcion1);
			switch(opcion1){
					case 'R':
					case 'r':
						system("cls");
						printf("Es un juego basado en aumentar la longitud de la serpiente , solo puede jugar un jugador.\n");
						printf("Si el usuario completa el juego le saldra un mensaje de reiniciaro o volver al menu del programa.\n");
						printf("Si el usuario choca con alguna de las paredes le aparecera un mensaje de GAME OVER y la opcion de volver a empezar.\n");
						printf("J1 introduzca su nombre de usuario:\n");
						fflush(stdin);
						char asa[60];
						scanf("%s",asa);
						system("cls");
						int len;					   	//longitud de snake
    					char ch = 'g';				   	//Definir variables para almacenar caracteres escritos desde el teclado
					    char a[N+2][N+2] = {{0}};      	//Inicializar la matriz de mapas
    					char **snake;				   	
    					srand((unsigned)time(NULL));   	
    					color(11);					   	//Establecer el color de la consola 
    					File_in();					   	//sacar la nota 
    					init(a, &snake, &len);		   	 
    					Manual();					   
    					while (ch != 0x1B){   		   	// Presione ESC para finalizar 
    						Draw(snake, len);
        					if (!apple[2]){
            					apple[0] = rand()%N + 1;
          						apple[1] = rand()%N + 1;
            					apple[2] = 1;
        					}
        					Sleep(200-score[2]*10);		//A medida que aumenta la puntuación, aumenta la velocidad, cuántos segundos para dormir, cuanto más corto sea el tiempo entre paréntesis, más rápido será el movimiento
        					setbuf(stdin, NULL);	  	
        					if (kbhit()){
            					gotoxy(0, N+2);			
            					ch = getche();		
        					}
        					snake = Move(snake, ch, &len); 
        					if (Block(snake[0])==1){		//Cuando la cabeza de la serpiente toca la pared, muere.
        
            					gotoxy(N+2, N+2);
            					puts("game over");
            					File_out();			
            					Free(snake, len);	
            					getche();				
            					exit(0); 			
        					}                        
    					}
    					Free(snake, len);						 
    					exit(0);
						break;
			
					case 'I':
					case 'i':
						
						system("cls");
						int lena;					   	//longitud de snake
    					char cha = 'g';				   	//Definir variables para almacenar caracteres escritos desde el teclado
    					char s[N+2][N+2] = {{0}};      	//Inicializar la matriz de mapas
    					char **snakes;				   	
    					srand((unsigned)time(NULL));   	
    					color(11);					   	//Establecer el color de la consola 
    					File_in();					   	//sacar la nota 
    					init(s, &snakes, &lena);		   	 
    					Manual();					   
    					while (cha != 0x1B){   		   	// Presione ESC para finalizar 
    						Draw(snakes, lena);
        					if (!apple[2]){
            					apple[0] = rand()%N + 1;
            					apple[1] = rand()%N + 1;
            					apple[2] = 1;
        					}
        					Sleep(200-score[2]*10);		//A medida que aumenta la puntuación, aumenta la velocidad, cuántos segundos para dormir, cuanto más corto sea el tiempo entre paréntesis, más rápido será el movimiento
        					setbuf(stdin, NULL);	  	
        					if (kbhit()){
            					gotoxy(0, N+2);			
            					cha = getche();		
        					}
        					snakes = Move(snakes, cha, &lena); 
        					if (Block(snakes[0])==1){		//Cuando la cabeza de la serpiente toca la pared, muere.
        
            					gotoxy(N+2, N+2);
       							puts("game over");
            					File_out();			
            					Free(snakes, lena);	
            					getche();				
            					exit(0); 			
        					}                        
    					}
    					Free(snakes, lena);						 
    					exit(0);
	
						fflush(stdin);
						printf("J1 introduzca su nombre de usuario:\n");
						scanf("%c",&jugador1);
						fflush(stdin);
			}while('r'||'i');
		case '2'://Ahorcado
			while(1){
			while(1){
		
			system("cls");

			printf("Seleccione 'r' si desea ver como jugar \n");
			printf("Seleccione 'i' para iniciar el juego\n");
			scanf("%c",&opcion2);
			int als;

			switch(opcion2){
					case 'r':
					case 'R':
						system("cls");
						printf("Es un juego que trata de adivinar ciertas palabras con un numero de oportunidades.\n");
						printf("El usuario tendra que decir una letra del abecedario en cada turno para intentar deducir la palabra,");
						printf("pero solo tiene 5 oportunidades,sino fallara el juego\n");
						printf("Cada vez que una letra dicha no aparezca en la palabra,se le restara una oportunidad .\n");
						printf("Cuando el jugador acierta la palabra el juego mostrara un mensaje de VICTORIA!!! ,\n");
						printf(" si el jugador no acierta la palabra y no tiene oportunidades restantes aparecera un mensaje de FIN DE JUEGO.\n");
						printf("En ambos casos se mostrara la opcion de volver al menu o reiniciar el juego\n");
						
						fflush(stdin);
						fflush(stdin);
						scanf("%d",&als);
						if(als==3)
						break;

					case 'I':
					case 'i':
						system("cls");
							
						
			
						fflush(stdin);
						printf("J1 introduzca su nombre de usuario:\n");
						scanf("%c",&jugador1);
						fflush(stdin);
						printf("J2 introduzca su nombre de usuario:\n");
						scanf("%c",&jugador2);
						fflush(stdin);
		    
			char frase[60],rep[100],temporal[100];
			char pal=-87;
			int longitud=0,i,j=0,inicial=0,acertado=0,temp=0,oportunidades=5;
			int repetido=0,gano=0;

						printf("\tJuego del Ahorcado\n");
						printf("Introduzca la palabra a adivinar: ");
						gets(frase);

						system("cls");

						do {
				
				
								temp=0;
				
								if(inicial == 0) {
									for(i=0;i<strlen(frase);i++) {
										if(frase[i] == ' ') {
											temporal[i] = ' ';
											longitud++;
										}
										else {
											temporal[i] = '_';
											longitud++;
										}
									}
									inicial = 1;
									temporal[longitud] = '\0';
								}
								else {	

									for(i=0;i<strlen(rep);i++) {
										if(rep[i] == pal) {
											repetido = 1;
											break;
										}		
										else {
											repetido = 0;
										}
									}

									if(repetido == 0) {
										rep[j] = pal;
										j++;
										for(i=0;i<strlen(frase);i++) {
											if(frase[i] == pal) {
												temporal[i] = pal;
												acertado++;
												temp=1;
											}
										}
									}			

									if(repetido == 0) {
										if(temp == 0 && pal!=-87) {
											oportunidades = oportunidades - 1;
										}

										system("cls");

										for(i=0;i<strlen(temporal);i++) {
											printf(" %c ",temporal[i]);
										}

										printf("\n");

										if(strcmp(frase,temporal) == 0) {
											gano = 1;
											break;
										}
										printf("\n");
										printf("Letras Acertadas: %d",acertado);
										printf("\n");
										printf("Oportunidades Restantes: %d",oportunidades);
										printf("\n");
									}
									else {
										printf("Ya se ha introducido la '%c' en esta partida. ",pal);
									}
									if (oportunidades!=0){
										printf("Introduzca una letra:");
										scanf(" %c",&pal);
									}

								}
							} while(oportunidades != 0);


							if(gano) {
								printf("\n\n");
								printf("Enhorabuena, has ganado.");
							}
							else {
								printf("\n\n");
								printf("Has perdido.");
							}

							printf("\n\n");
							system("PAUSE");
							return 0;
	
							break;
							break;
			}}

		
	   	case'3'://Abandonar juego
			printf("Hasta la proxima!!!!!!!!\n");
			break;
		default:
		    printf("la opcion es incorrecta:\n");
		    break;
			return 0;//salir del programa
	}
	
	i++;
		
}
		
	}while (juego1||juego2);
     }
	char menu(){
		int opcion;
		printf("BIENVENIDO AL MENU DE STARGAMES \n");
		printf("Introduzca numero del juego que desea jugar:\n");
		printf("Introduzca 1 si desea jugar al snake,\n");
		printf("Introduzca 2 si desea jugar al ahorcado\n");
		printf("Introduzca 3 si desea salir del menu.\n");
		scanf("%c",&opcion);
		fflush(stdin);
		return opcion;
	}
	

		

	
	
	

