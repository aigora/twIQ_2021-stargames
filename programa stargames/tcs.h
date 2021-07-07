#ifndef SQLISH_H
#define SQLISH_H
#include <windows.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <conio.h>
#define N 21  //Tamano de mapa



int apple[3];
char score[3];// score [0] es el puntaje actual, score [1] es el r谷cord m芍s alto, score [2] controla la velocidad l赤mite
char tail[3]; 

void gotoxy(int x, int y)   
{
        COORD pos; 
        pos.X = x; 
        pos.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
		                  
}

void color(int b)         //color 
						
{
    HANDLE hConsole = GetStdHandle((STD_OUTPUT_HANDLE)) ; 
    SetConsoleTextAttribute(hConsole,b) ;
} 

int Block(char head[2])   //Juzgar fuera de l赤mites
{
	if ((head[0] < 1) || (head[0] > N) || (head[1] < 1) || (head[1] > N))//head[0]coor de cabeza,head[1]coor de cola
	    return 1;
	return 0;
}

int Eat(char snake[2])   
{
    if ((snake[0] == apple[0]) && (snake[1] == apple[1]))   //La abscisa del cuerpo de la serpiente es igual a la abscisa de la manzana, y la ordenada es igual a la ordenada de la manzana (a juzgar que has comido una manzana). 
    {
        apple[0] = apple[1] = apple[2] = 0;//Cuando appple [2] es 0, el programa reasignar芍 la ubicaci車n de la manzana.
        gotoxy(N+44,10);
        color(13);//color
        printf("%d",score[0]*10);//por cada manzana ingerida, sume 3 * 10 = 30 puntos
       color(11);//color
        return 1;
	}
    return 0;
}

void Draw(char **snake, int len)    //Movimiento de serpiente
{
    if (apple[2]) 						//Si el n迆mero de manzanas no es 0, dibuja manzanas
	{
        gotoxy(apple[1] * 2, apple[0]); //Dibuja la posici車n de la manzana (abscisas, ordenadas)
        color(12);//color
        printf("♂");//manzana♂
        color(11);
    }
    gotoxy(tail[1] * 2, tail[0]);// Dibuja la posici車n de la cola de la serpiente (abscisas, ordenadas)
    if (tail[2]) //Si el n迆mero de colas de serpiente no es 0, despu谷s de comer la manzana, la cuadr赤cula detr芍s de la cola de serpiente se agregar芍 al cuerpo de la serpiente.
    {  
		color(14); 
        printf("∴");//cuerpo ∴
        color(11);
    }
    else 
        printf("←");
    gotoxy(snake[0][1] * 2, snake[0][0]);
    color(14);
    printf("∴");
    color(11);
    putchar('\n');
}

char** Move(char **snake, char dirx, int *len)   //direcci車n de control
{
    int i, full = Eat(snake[0]);	
    memcpy(tail, snake[(*len)-1], 2);	
    for (i = (*len) - 1; i > 0; --i)
        memcpy(snake[i], snake[i-1], 2);//avanzar
    switch (dirx) 						//dirreccion
    { 
		case 'w': case 'W': --snake[0][0]; break;//subir
		case 's': case 'S': ++snake[0][0]; break;//bajar
		case 'a': case 'A': --snake[0][1]; break;//izquierda 
		case 'd': case 'D': ++snake[0][1]; break;//derecha
		default: ;
    }  
    if (full)   		
    { 
        snake = (char **)realloc(snake, sizeof(char *) * ((*len) + 1));	
        snake[(*len)] = (char *)malloc(sizeof(char) * 2);				
        memcpy(snake[(*len)], tail, 2);								
        ++(*len);					//longitud de snake
        ++score[0];					//punto+1 
        if(score[2] < 16) 			//velocidad<16
        	++score[2];				//punto+1 
        tail[2] = 1;						
    }
    else 
        tail[2] = 0;			
	return snake;
}

void init(char plate[N+2][N+2], char ***snake_x, int *len) 
{
    int i, j;
    char **snake = NULL;                      

    *len = 3;							
    score[0] = score[2] = 3;                
    snake = (char **)realloc(snake, sizeof(char *) * (*len));
    for (i = 0; i < *len; ++i)
        snake[i] = (char *)malloc(sizeof(char) * 2);		
            
    for (i = 0; i < 3; ++i)                 
    {
    	snake[i][0] = N/2 + 1;			
        snake[i][1] = N/2 + 1 + i;			//coor de x y y
    }

    for (i = 1; i <= N; ++i)				//El rango m車vil es 1
        for (j = 1; j <= N; ++j) 
            plate[i][j] = 1;
                     
    apple[0] = rand()%N + 1; 			
	apple[1] = rand()%N + 1;			
    apple[2] = 1;							//coordenada y numero de manzana

    for (i = 0; i < N + 2; ++i) 			//dibjar mapa 
    {
        gotoxy(0, i);					    
        for (j = 0; j < N + 2; ++j)         
        {
            switch (plate[i][j]) 
            {
            	case 0: 
            		color(12);			
					printf("↓"); 			//pared 
					continue;
            	case 1: 
            		color(11);				
					printf("←"); 			
					continue;
            }
        }
        putchar('\n');
    } 
    
	for (i = 0; i < (*len); ++i)			
	{
    	gotoxy(snake[i][1] * 2, snake[i][0]);
    	printf("∴");					
	} 
    putchar('\n');
    *snake_x = snake;						
}

void Manual()	//introduccion						
{
    gotoxy(N+30,2);
    color(10);
    printf("Presione W S A D para mover la direcci車n");
    gotoxy(N+30,4);//Ubicaci車n de la informaci車n
    printf("Presione la barra espaciadora para pausar"); 
    gotoxy(N+30,8);
    color(11);
    printf("Puntacion mas alta: ");
    color(12);
    gotoxy(N+50,8);
    printf("%d",score[1]*10);
    color(11);
    gotoxy(N+30,10); 
    printf("Tu puntuacion: ");         
}

int File_in()     //Tomar puntuaci車n grabada
{
	FILE *fp;   
	if((fp = fopen("01.txt","a+")) == NULL)	
   	{
		gotoxy(N+18, N+2);
    	printf("No se puede reproducir el archivo\n");
    	exit(0);//salir
   	}
   	if((score[1] = fgetc(fp)) != EOF);		//leer archivo 
   	else
   		score[1] = 0;//La puntuaci車n m芍s alta registrada en el archivo al principio es 0
   	return 0;
}

int File_out()    //guardar 
{
        
    FILE *fp;
    if(score[1] > score[0]) 		
    {
		gotoxy(10,10); 
    	color(12);
    	puts("sorry game over");
    	gotoxy(0,N+2); 
    	return 0;
    }
    // Cuando la puntuaci車n obtenida es superior al r谷cord
    if((fp = fopen("01.txt","w+")) == NULL)
    {
        printf("el archivo n se puede abrir\n");
        exit(0);
    }
	if(fputc(--score[0],fp)==EOF) 
       printf("Salida fallida\n");
	gotoxy(10,10);
    color(12);
    puts("you lost"); 
    gotoxy(0,N+2);
    return 0;
}



void Free(char **snake, int len)    
{
	int i;
    for (i = 0; i < len; ++i) 
        free(snake[i]);
    free(snake);	
}


#endif

