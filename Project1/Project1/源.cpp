#include<stdio.h>
#include<easyx.h>
#include<conio.h>
#include<windows.h>
#include<malloc.h>
#include<time.h>
#pragma comment(lib,"Winmm.lib")
#define ROW 46
#define COL 64
//枚举
IMAGE  Img_Menu[2];
enum game
{
	SPACE, WALL, SNAKE, FOOD, HEAD
};

int mode = 0;			//Modo de juego
int score = 0;			//fracción
DWORD t1, t2;			//Defina dos tiempos para controlar la velocidad de movimiento.
int map[ROW][COL];		//Tamaño de mapa
COORD snake[1024];		//snake			typedef struct _COORD {SHORT X;SHORT Y;} COORD, *PCOORD;
size_t SnakeSize;		//longitud de snake		typedef unsigned int     size_t;
char SnakeDir;			//dirrccion de snake

void start();	//Interfaz de inicio
void chose();	//Modo de selección 0: Modo dificil 1: Modo normal 2: Modo sencillo
void DrawMap();	
void init();	
void addfood();	
void ChangeDir();	
void move();


void Pause() {	//pause
	TCHAR s4[] = _T("pause....");
	settextstyle(30, 20, _T("宋体"));//Establecer tamaño y formato de fuente
	outtextxy(220, 200, s4);
	char c = _getch();
	while (c != 'p')
		c = _getch();
}
int main()
{

	initgraph(640, 480);

	start();
	outtextxy(220, 150, "->");		
	chose();
	init();

	while (1)
	{




		t2 = GetTickCount();
		DrawMap();
		if (kbhit())
		{



			ChangeDir();
			move();

			t2 = GetTickCount();
			t1 = t2;


		}
		if (t2 - t1 > 50)
		{
			move();
			t1 = t2;
		}


	}
	getchar();
	closegraph();



	return 0;
}
void init()
{
	srand((unsigned)time(NULL));	
	setbkcolor(WHITE);				//Establecer color de fondo

	memset(map, SPACE, sizeof(map));
	//La primera y la última de cada fila son paredes.
	for (int i = 0; i < ROW; i++)
	{
		map[i][0] = map[i][COL - 1] = WALL;
	}
	//La segunda y penúltima de cada columna son paredes.
	for (int j = 1; j < COL - 1; j++)
	{
		map[0][j] = map[ROW - 1][j] = WALL;
	}
	//Definir cabeza de serpiente y cuerpo de serpiente
	map[3][5] = HEAD;
	map[3][4] = map[3][3] = SNAKE;
	//Inicializar la serpiente
	SnakeSize = 3;	//longitud
	SnakeDir = 'D';	//girar a la derecha
	snake[0].X = 3;
	snake[0].Y = 5;
	snake[1].X = 3;
	snake[1].Y = 4;
	snake[2].X = 3;
	snake[2].Y = 3;
	addfood();
}
void start()
{
	setbkcolor(LIGHTCYAN);		//Establecer el color de fondo de la ventana en amarillo
	cleardevice();			//Actualizar pantalla
	setbkmode(TRANSPARENT);	//Establecer el color de fondo de la fuente en transparente
	settextcolor(RED);		//Establecer el color de la fuente en rojo
	/*****************regla*****************/
	TCHAR s[] = _T("modo:");

	settextstyle(50, 35, _T("宋体"));
	outtextxy(150, 20, "snake");
	settextstyle(30, 20, _T("宋体"));
	outtextxy(230, 100, s);

	settextstyle(15, 5, _T("黑体"));
	outtextxy(250, 150, "1.normal");
	outtextxy(250, 200, "2.sencillo");
	outtextxy(250, 250, "3.dificil");
	outtextxy(30, 280, "Teclas numéricas 1, 2, 3 para seleccionar el modo, Enter para ingresar al juego");
	outtextxy(30, 300, "Teclas de letras W, S, A, D Teclas de dirección Dirección de control hacia arriba, abajo, izquierda y derecha");
	outtextxy(30, 330, "Presione p para pausar / continuar el juego, e para finalizar el juego");
	outtextxy(80, 360, "Contenido relacionado: Serpientes");
	outtextxy(100, 390, "Productor: Hu, Moisis,Alex ");
	outtextxy(100, 430, "grupo：XXXX");
	settextcolor(RED);
	mciSendString("open h.mp3 alias mymusic", NULL, 0, NULL);//abrir la musica
	settextstyle(10, 10, _T("方正顷刻"));
	outtextxy(10, 70, " Presione cualquier tecla para comenzar a reproducir música ");
	getch();
	mciSendString("play mymusic", NULL, 0, NULL);

}
void chose()
{
	while (1)
	{
		switch (getch())
		{
		case '1':
			start();
			outtextxy(220, 150, "->");
			mode = 0;
			break;
		case '2':
			start();
			outtextxy(220, 200, "->");
			mode = 1;
			break;
		case '3':
			start();
			outtextxy(220, 250, "->");
			mode = 2;
			break;
		case 13:
			return;
			break;
		}
	}
}
void DrawMap()
{
	BeginBatchDraw();	//Empieza a dibujar
	setbkcolor(WHITE);	//Establecer el color de fondo en blanco
	settextcolor(RGB(238, 0, 0));
	cleardevice();		//Pantalla clara
	char arr[10];		//Guardar calificaciones
	sprintf(arr, "nota：%d", score);	//Formatee los resultados en la cadena arr
	settextstyle(20, 15, _T("黑体"));
	outtextxy(0, 0, arr);				//Mostrar calificaciones
	for (int y = 0; y < ROW; y++)		
	{
		for (int x = 0; x < COL; x++)	
		{
			switch (map[y][x])
			{
			case SPACE:
				break;
			case WALL:
				setlinecolor(BLACK);
				setfillcolor(RGB(238, 233, 233));	//gris
				fillrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
				break;
			case SNAKE:
				setlinecolor(RGB(0, 245, 255));		//verde 
				setfillcolor(WHITE);
				fillrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
				break;
			case HEAD:
				
				switch (rand() % 7)
				{
				case 0:
					setfillcolor(RGB(255, 0, 0));		//rojo 255 0 0
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 1:
					setfillcolor(RGB(255, 165, 0));		//naranja  255 165 0 
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 2:
					setfillcolor(RGB(255, 255, 0));		//amarillo  255 255 0
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 3:
					setfillcolor(RGB(0, 255, 0));		//verde  0, 255, 0
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 4:
					setfillcolor(RGB(0, 255, 255));		//verde  0 255 255
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 5:
					setfillcolor(RGB(0, 0, 255));		//azul  0 0 255
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				case 6:
					setfillcolor(RGB(160, 32, 240));	//púrpura  160 32 240
					solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
					break;
				default:
					break;
				}
				break;
			case FOOD:
				setfillcolor(RGB(255, 0, 0));			//rojo
				solidrectangle(x * 10, y * 10 + 20, x * 10 + 10, y * 10 + 30);
				break;
			default:
				break;
			}
		}
	}
	EndBatchDraw();
}
void addfood()
{
	int row, col;
	do
	{
		row = rand() % (ROW - 1) + 1;
		col = rand() % (COL - 1) + 1;
	} while (map[row][col] != SPACE);
	map[row][col] = FOOD;
}
void ChangeDir()
{
	switch (getch())
	{
	case'A':
	case'a':
	case 75:
		if (SnakeDir != 'D') SnakeDir = 'A';	//La serpiente no puede volver
		break;
	case'D':
	case'd':
	case 77:
		if (SnakeDir != 'A') SnakeDir = 'D';
		break;
	case'W':
	case'w':
	case 72:
		if (SnakeDir != 'S') SnakeDir = 'W';
		break;
	case'S':
	case's':
	case 80:
		if (SnakeDir != 'W') SnakeDir = 'S';
		break;
	case 'p':
		Pause();break;//pause
	case 'e':
	{MessageBox(GetHWnd(), "game over", "SORRY", MB_OK);//terminar el juego   
	exit(0);}break;

	case 32:
		getch();
		break;
	default:
		break;
	}
}
void move()
{
	COORD next;		//La siguiente posición de la cabeza de serpiente.
	int i;
	switch (SnakeDir)
	{
	case'A':
		next.X = snake[0].X;
		next.Y = snake[0].Y - 1;
		break;
	case'W':
		next.X = snake[0].X - 1;
		next.Y = snake[0].Y;
		break;
	case'D':
		next.X = snake[0].X;
		next.Y = snake[0].Y + 1;
		break;
	case'S':
		next.X = snake[0].X + 1;
		next.Y = snake[0].Y;
		break;

	default:
		break;
	}

	switch (map[next.X][next.Y])
	{
	case SPACE://Mover directamente
		map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE;//La ubicación del mapa de la cola de la serpiente se deja en blanco.
		for (i = SnakeSize - 1; i > 0; i--)						//Desde la cola hasta la cabeza de la serpiente, mueva una posición como un todo
		{
			snake[i] = snake[i - 1];
		}
		map[snake[0].X][snake[0].Y] = SNAKE;						//Posición de la cabeza de la serpiente
		snake[0] = next;											//Asignar la siguiente posición a la cabeza de serpiente
		map[snake[0].X][snake[0].Y] = HEAD;							//Establecer encabezado
		break;
	case WALL:
		if (mode)		//Modo 1 El modo 2 puede atravesar paredes
		{
			map[snake[SnakeSize - 1].X][snake[SnakeSize - 1].Y] = SPACE;//La cola de serpiente está vacía
			for (i = SnakeSize - 1; i > 0; i--)						//Desde la cola hasta la cabeza de la serpiente, mueva una posición como un todo
			{
				snake[i] = snake[i - 1];
			}
			map[snake[0].X][snake[0].Y] = SNAKE;						
			switch (SnakeDir)											//A través de la pared
			{
			case'A':next.Y = COL - 2; break;
			case 'D':next.Y = 1; break;
			case 'W': next.X = ROW - 2; break;
			case 'S':next.X = 1; break;

			default:
				break;
			}
			snake[0] = next;											//La cabeza de la serpiente se mueve a una nueva posición
			map[snake[0].X][snake[0].Y] = HEAD;							//La ubicación de la nueva cabeza de serpiente.
		}
		else {
			MessageBox(GetHWnd(), "game over", "SORRY", MB_OK);
			main();
		}
		break;
	case SNAKE:
		if (mode == 2)		//Modo dos invencible
		{
			break;
		}
		else {
			MessageBox(GetHWnd(), "game over", "SORRY", MB_OK);
			main();
		}
		break;
	case FOOD:
		for (i = SnakeSize; i > 0; i--)							//Desde la cola hasta la cabeza de la serpiente, mueva una posición como un todo
		{
			snake[i] = snake[i - 1];
		}
		map[snake[0].X][snake[0].Y] = SNAKE;						
		snake[0] = next;											
		score++;			//Puntuación más uno				
		(SnakeSize)++;		//Escala de serpiente más uno
		map[snake[0].X][snake[0].Y] = HEAD;							//Restablecer la cabeza de serpiente en el mapa
		addfood();
		break;
	default:break;
	}
}