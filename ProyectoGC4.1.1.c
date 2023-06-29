/*********************************************************/
/*	    UNIVERSIDAD NACIONAL DE INGENIERIA           */
/*	 Facultad de Electrotecnia y Computacion         */
/*                                                       */
/*	            Geometria Computacional              */
/*                                                       */
/*      Grupo: Erick Jeronimo Landero Bracamontes        */
/*		       Jose Luis Lovo Rodriguez          */
/*             Rafael Humberto Poveda Poveda             */
/*                                                       */
/*********************************************************/
/*                  *Version 4.1.1*                      */
/****************************/                  
/*        Librerias         */
/****************************/
#include <STDLIB.H>
#include <CONIO.H>
#include <STDIO.H>
#include <GRAPHICS.H>
#include <DOS.H>
#include <STRING.H>
#include <CHINO.H>

/****************************/
/* Prototipado de Funciones */
/****************************/
void Presentacion(void);
void PantallaPrincipal(void);
void SeleccionarDestino(void);
void GPS(int);
void ColorearDestino(int);
void Lugares(void);
void Tiempo(int,int);
int MoverRobot(void);
void Circulo(int, int);
void BorraRastro(int, int);
void MostrarCaniones(void);
void OcultarCaniones(void);
void VerProyectil(int, int);
void EsconderProyectil(int, int);
void Introduccion(void);
void PantallaCarga(void);
void RobotI(int);
void RobotII(void);
int VentanaDerrota(void);
int ColorearBotones(char);
void MostrarVida(void);
int ComprobandoGps(int, int, int);

/****************************/
/*        Macros            */
/****************************/
#define UP 72
#define DOWN 80
#define RIGHT 77
#define LEFT 75
#define ENTER 13
#define ESPACE 32

/****************************/
/*    Variables Globales    */
/****************************/
int driver = DETECT, modo;
int x1, x2, x3, x4, y1, y2, y3;
int x = 0, y = 0, i, pasey, pasex;
int xM = 309, yM = 263;
int Sitio;
int opcion = 0, lifes = 3;
char tecla;
char *destinos[] = {
        "1. Pizza Hut",
	    "2. Academia de danza",
	    "3. Discoteca \"El chaman\"",
        "4. Billar",
	    "5. Estadio \"Dennis Martinez\"",
        "6. Interlocales UCA",
        "7. Autolote",
	    "8. Enel",
	    "9. Casa Pellas",
        "10. Hospital Militar",
	    "11. Pricesmart",
	    "12. Banpro",
        "13. Paris Grand Auto",
		"14. Auto Hotel Luna",
		"15. Feria",
		"16. Catedral Metropolitana",
		"17. Direccion General de Ingresos",
		"18. Metrocentro",
		"19. Hotel Intercontinental",
		"20. PUMA",
		"21. Hispamer",
		"22. UCA",
		"23. Banco Lafise",
		"24. Hotel Holiday INN"};
int UNI[14] = {
        213,302,
        245,318,
        283,318,
        283,248,
        317,248,
        317,340,
        213,340};
int Estadio[16] = {
        220,362,
        226,356,
        311,356,
        316,362,
        316,399,
        309,405,
        229,405,
        220, 399};
int Catedral [10] = {
        111,318,
        137,298,
        163,318,
        152,349,
        122,349};
int Motel [6] = {
        423,360,
        448,386,
        398,386};

/************************************************************************************************************************/
/* MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN */
/************************************************************************************************************************/
void main()
{
	int seg = 1, temp, repetir = 1, Victoria = 0;
    initgraph(&driver,&modo,"c:\\TC20\\BIN");

    Presentacion();
    Introduccion();
    PantallaCarga();

	do
	{
        if (repetir == 1){
            xM = 309; yM = 263;
		    temp = 30;
		    lifes = 3;
        }

		PantallaPrincipal();
		SeleccionarDestino();

		x1 = x2 = x3 = x4 = 0;
		y1 = y2 = y3 = 0;

		/*Funcionalidad Cañones*/
		Circulo(xM,yM);
		Tiempo(temp,1);
		MostrarVida();
		do{
			if (seg % 3 == 0)
			{
				temp--;
				Tiempo(temp,1);
			}

			if (temp == 0)
			{
				lifes--;
				MostrarVida();

				if(lifes == 0)
				{   
					repetir = VentanaDerrota();
					break;
				}
				
				BorraRastro(xM, yM);
				xM = 309; yM = 263;
				Circulo(xM,yM);
				
				temp = 30;
			}
			
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*Ver TODO*/
			MostrarCaniones();
			MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*Proyectiles*/
			/*-------Proyectiles lado izquierdo-------------*/
			if (y >= 132 && y1 <=100)
			{
				VerProyectil(58 + y1, 215);
				VerProyectil(58 + y1, 250);
				
				if (getpixel(58 + y1 + 9, 215) == BLUE || getpixel(58 + y1 + 4, 215) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				
				if (getpixel(58 + y1 + 9, 250) == BLUE || getpixel(58 + y1 + 4, 250) == BLUE )
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				
			}
			/*---------------------------------------------*/
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles lado derecho-------*/
			if (y >= 198 && y3 <= 100)
			{
				/*1ro*/
				VerProyectil(580 - y3, 179);
				
				if (getpixel(580 - y3 - 9, 179) == BLUE || getpixel(580 - y3 - 4, 179) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (y >= 110 && y2 <= 150)
			{
				/*2do*/
				VerProyectil(580 - y2, 301);
				
				if (getpixel(580 - y2 - 9, 301) == BLUE || getpixel(580 - y2 - 4, 301) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
			}
			/*---------------------------------------*/
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles abajo -------*/
			if (x >= 132 && x1 <= 150)
			{
				/*1ro*/
				VerProyectil(197, 412 - x1);
				
				if (getpixel(197, 412 - x1 - 9) == BLUE || getpixel(197, 412 - x1 - 4) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x >= 242 && x2 <= 180)
			{
				/*2do*/
				VerProyectil(326, 412 - x2);
				
				if (getpixel(326, 412 - x2 - 9) == BLUE || getpixel(326, 412 - x2 - 4) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles arriba -------*/
			if(x >= 88 && x3 <= 150)
			{
				VerProyectil(482, 67 + x3);
				if (getpixel(482, 67 + x3 + 9) == BLUE || getpixel(482, 67 + x2 + 4) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{   
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x >= 374 && x4 <= 180)
			{
				VerProyectil(175, 67 + x4);
				VerProyectil(195, 67 + x4);
				if (getpixel(175, 67 + x4 + 9) == BLUE || getpixel(175, 67 + x4 + 4) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{   
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
				if (getpixel(195, 67 + x4 + 9) == BLUE || getpixel(195, 67 + x4 + 4) == BLUE)
				{
					lifes--;
					temp = 30;
					MostrarVida();	
					if(lifes == 0)
					{   
						repetir = VentanaDerrota();
						break;
					}
					BorraRastro(xM, yM);
					xM = 309; yM = 263;
					Circulo(xM,yM);
				}
			}
			/*--------------------------------*/
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			delay(333);
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*Borrando Rastro*/
			OcultarCaniones();
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }

			/*Proyectiles ocultar*/
			/*-------Proyectiles lado izquierdo-------------*/
			if (y >= 132 && y1 <=100)
			{
				EsconderProyectil(58 + y1, 215);
				EsconderProyectil(58 + y1, 250);
				y1 += 10;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles lado derecho-------*/
			if (y >= 198 && y3 <= 100)
			{
				/*1ro*/
				EsconderProyectil(580 - y3, 179);
				y3 += 10;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (y >= 110 && y2 <= 150)
			{
				/*2do*/
				EsconderProyectil(580 - y2, 301);
				y2 += 10;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles abajo -------*/
			if (x >= 132 && x1 <= 150)
			{
				/*1ro*/
				EsconderProyectil(197, 412 - x1);
				x1 += 10;
				
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x >= 242 && x2 <= 180)
			{
				/*2do*/
				EsconderProyectil(326, 412 - x2);
				x2 += 10;
				
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/*-----Proyectiles arriba -------*/
			if(x >= 88 && x3 <= 150)
			{
				EsconderProyectil(482, 67 + x3);
				x3 += 10;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x >= 374 && x4 <= 180)
			{
				EsconderProyectil(175, 67 + x4);
				EsconderProyectil(195, 67 + x4);
				
				x4 += 10;
			}
			/*--------------------------------*/
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			/* ----------------Validaciones para reiniciar variables para mover cañones y proyectiles--------------*/
			if (y == 88)
			{
				y2 = 0; /*esta controla el 2do cañon derecho*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (y == 176)
			{
				y3 = 0; /*Esta controla el 1er cañon derecho */
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x == 66)
			{
				x3 = 0; /*Controla el proyectil que sale solo arriba*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x == 352)
			{
				x4 = 0; /*Controla los dos proyectiles juntos arriba*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (y == 0)
			{
				pasey = 0; /*Esta controla los cañones sobre las y*/
				y1 = 0; /*Esta controla los cañones izquierdos*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (y == 308){
				pasey = 1; /*Se reinicia el movimiento sobre las y*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (pasey == 0){
				y += 22;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (pasey == 1){
				y -= 22;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x == 0)
			{
				pasex = 0; /*Esta variable controla los caniones sobre las x*/
				x1 = 0; /*Controla el 1er cañon de abajo*/
				x2 = 0; /*Controla el 2do cañod de abajo*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (x == 484)
			{
				pasex = 1; /*Se reinicia el movimiento sobre las x*/
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (pasex == 0){
				x += 22;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			if (pasex == 1){
				x -= 22;
			}
			Victoria = MoverRobot();
            if(Victoria == 1){
                BorraRastro(xM,yM);
                xM = 309; yM = 263;
		        temp = 30;
		        lifes++;
                MostrarVida();
                SeleccionarDestino();
            }
			seg++;
		}while(1);

	}while(repetir == 1 || Victoria == 1);

sleep(1);
closegraph();
exit(1);
}
/************************************************************************************************************************/
/* MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN          MAIN */
/************************************************************************************************************************/

/************************************************************************************************************************/
/* FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES        FUNCIONES */
/************************************************************************************************************************/
void Presentacion()
{
    setfillstyle (SOLID_FILL ,BLUE);
	bar3d(200,20,155,200,25,1);
	delay(50);
	bar3d(210,200,330,160,25,1);
	delay(50);
	bar3d(280,160,330,80,25,1);
	delay(50);
	bar3d(220,20,340,65,25,1);
	delay(50);
	bar3d(270,145,220,65,0,1);
	delay(50);
	bar3d(340,20,390,200,25,1);
	delay(50);
	bar3d(390,160,410,200,25,1);
	delay(50);
	bar3d(410,70,450,200,25,1);
	delay(50);
	bar3d(410,20,450,60,25,1);
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,0,2);
    outtextxy(132,210,"UNIVERSIDAD NACIONAL DE INGENIERIA");
    outtextxy(110,230,"Facultad de electrotecnia y computacion");
    setcolor(YELLOW);
    outtextxy(127,260,"Proyecto de Geometria Computacional");
    setcolor(WHITE);
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(155,290,"Docente: Ing Grevin Alexander Silva");
    outtextxy(100,320,"Presentado por:");
    outtextxy(115,340,"Erick Jeronimo Landero Bracamontes");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(455,345,"2021-0089U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(115,360,"Jose Luis Lovo Rodriguez");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(350,365,"2021-0103U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(115,380,"Rafael Humberto Poveda Poveda");
    settextstyle(SMALL_FONT,0,6);
    outtextxy(410,385,"2021-0272U");
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(230,420,"Grupo: 2M1 - CO.");
getch();
cleardevice();
}
void PantallaPrincipal()
{
    int Dibujo[6] = {9,19, 14,27, 19,19};
    int Dibujo1[6] = {446,18, 454,27, 462,18};
    int UNI[14] = {213,302, 245,318, 283,318, 283,248, 317,248, 317,340, 213,340};
    int Estadio[16] = {220,362, 226,356, 311,356, 316,362, 316,399, 309,405, 229,405, 220, 399};
    int Catedral [10] = {111,318, 137,298, 163,318, 152,349, 122,349};
    int Parque [16] = {380,88, 384,85, 407,85, 411,89, 411,106, 407,110, 384,110, 380,107};
    int Motel [6] = {423,360, 448,386, 398,386};

    cleardevice();

    /*INTERFAZ*/
    /*Cuadro blanco y franjas grises*/
    setfillstyle(SOLID_FILL,WHITE);
    bar(23,33,615,448);
    setfillstyle(SOLID_FILL,DARKGRAY);
    bar(23,33,615,60);
    bar(23,420,615,448);
    bar(23,33,50,420);
    bar(615,33,588,448);

    /*Barra de tiempo + Temporizador*/
    setcolor(WHITE);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    rectangle(290,3,350,30);
    settextstyle(DEFAULT_FONT,0,1);
    outtextxy(300, 13, "00:00");

    /*Icono puntero*/
    setcolor(RED);
    circle(15,15,5);
	setfillstyle(SOLID_FILL,RED);
    fillpoly(3,Dibujo);

    /*Texto*/
    setcolor(WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(26,8, "Google Maps");
    settextstyle(SMALL_FONT,0,5);
    outtextxy(240,7, "Tiempo");

    /*X de cierre*/
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(615,11,"X");

    /*Vidas + Cantidad*/
    setcolor(RED);
    setfillstyle(SOLID_FILL,RED);
    circle(450,15,5);
    floodfill(450,15, RED);
    circle(458,15,5);
    floodfill(458,15,RED);
    fillpoly(3,Dibujo1);
    settextstyle(DEFAULT_FONT,0,1);
    setcolor(WHITE);
    outtextxy(468,15, "X");
	
    

    /*Destino*/
	setcolor(WHITE);
    settextstyle(SMALL_FONT,0,6);
    outtextxy(15,454, "Destino:");

    /*Marco para Gris y blanco*/
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    line(50,60,588,60);
    line(50,420,588,420);
    line(50,60,50,420);
    line(588,60,588,420);

	/*MAPA*/
    /*Cuadras*/
    setfillstyle(SOLID_FILL,GREEN);
    bar(52,62,162,201);
    bar(68,262,178,418);
    bar(209,257,320,340);
    bar(234,243,320,256);
    bar(209,353,320,406);
    bar(208,80,473,195);
    bar(334,244,383,402);
    bar(334,244,522,295);
    bar(396,308,541,418);
    bar(489,62,586,172);
    bar(488,186,586,231);
    bar(536,208,587,290);
    bar(557,308,586,419);
    bar(209,62,367,66);
    bar(380,62,411,66);
    bar(424,62,473,66);
    bar(52,225,143,237);

    /*Calles*/
    setfillstyle(SOLID_FILL,WHITE);
    /*1*/
    bar(57,65,162,75);
    bar(57,69,69,201);
    /*2*/
    bar(208,95,240,105);
    bar(230,97,240,150);
    bar(208,140,240,150);
    /*3*/
    bar(240,95,376,105);
	bar(368,80,378,120);
    bar(368,114,480,126);
    bar(412,80,422,126);
    /*4*/
    bar(480,111,579,123);
    bar(569,71,579,123);
    bar(499,71,579,81);
    bar(499,71,510,123);
    /*5*/
    bar(68,395,182,405);
    bar(154,368,165,402);
    bar(154,368,182,379);
    bar(165,318,182,328);
    /*6*/
    bar(213,246,279,256);
    bar(256,246,266,299);
    /*7*/
    bar(334,365,383,375);
    bar(334,315,383,325);
    /*8*/ 
    bar(362,243,374,278);
    bar(356,274,466,288);
    bar(454,243,466,277);
    /*9*/
    bar(452,308,462,391);
    bar(452,382,472,392);
    bar(465,382,475,415);
    /*10*/
    bar(468,403,586,415);
    bar(569,308,579,412);

    /*Sitios*/
    /*UNI*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    drawpoly(7,UNI);
    fillpoly(7,UNI);
    /*EstadioN*/
    drawpoly(8,Estadio);
    fillpoly(8,Estadio);
    /*Billar*/
	rectangle(336,381,381,400);
    bar(337,380,380,399);
    /*Chaman*/
    rectangle(336,329,371,361);
    bar(337,330,370,360);
    /*Academia*/
    rectangle(336,246,361,293);
    bar(337,247,360,292);
    /*Estacion*/
    rectangle(377,246,450,269);
    bar(378,247,449,268);
    /*Pizza*/
    rectangle(212,261,252,300);
    bar(213,262,251,299);
    /*Motel1*/
    rectangle(399,309,444,347);
    bar(400,310,443,346);
    /*Motel2*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    drawpoly(3,Motel);
    fillpoly(3,Motel);
    /*Banpro*/
    rectangle(397,397,462,420);
    bar(398,398,461,419);
    /*Pricesmart*/
    rectangle(478,368,522,400);
    bar(479,369,521,399);
    /*Hospital*/
    rectangle(467,310,539,364);
    bar(468,311,538,363);
    /*AutosUsados*/
    rectangle(470,246,520,293);
    bar(471,247,519,292);
    /*Casapellas*/
    rectangle(541,208,587,287);
    bar(542,209,586,286);
    /*Enel*/
    rectangle(490,188,540,229);
    bar(491,189,539,228);
    /*Lafise*/
    rectangle(491,127,510,170);
    bar(492,128,509,169);
    /*HolidayINN*/
    rectangle(519,128,587,170);
    bar(520,129,586,169);
    /*UCA*/
    rectangle(305,131,471,192);
    bar(306,132,470,191);
    /*PUMA*/
    rectangle(212,154,253,190);
    bar(213,155,252,189);
    /*Hispamer*/
    rectangle(243,107,297,145);
    bar(244,108,296,144);
    /*Intercontinental*/
    rectangle(72,79,156,122);
    bar(73,80,155,121);
    /*Metrocentro*/
    rectangle(72,132,157,196);
    bar(73,132,156,195);
    /*Feria*/
    rectangle(83,265,175,287);
    bar(84,266,174,286);
    /*Catedral*/
    drawpoly(5,Catedral);
    fillpoly(5,Catedral);
    /*DGI*/
    rectangle(75,352,115,392);
    bar(76,353,114,391);
    /*Rotonda*/
    setfillstyle(SOLID_FILL,GREEN);
    circle(189,225,18);
    floodfill(189,225,BLACK);
    /*Parque*/
    setfillstyle(LTBKSLASH_FILL,LIGHTGREEN);
    drawpoly(8,Parque);
    fillpoly(8,Parque);
    /*Salida*/
    setfillstyle(SOLID_FILL,WHITE);
    circle(305,263,12);
    floodfill(309,263,BLACK);
    bar(313,255,323,271);
}
void SeleccionarDestino()
{   
    setfillstyle(SOLID_FILL,WHITE);
    rectangle(91,451,421,477);
	bar(92, 452, 420, 476);
	ColorearDestino(opcion);
	do{
		setfillstyle(1, WHITE);
		bar(93, 453, 419, 475);

        setcolor(BLACK);
        settextstyle(SMALL_FONT,0,6);
		outtextxy(97, 454, destinos[opcion]);
		ColorearDestino(opcion);
		tecla = getch();
		if((tecla == UP)|(tecla == DOWN)|(tecla == ENTER)){
            switch (tecla)
            {
            case UP:
                opcion--;
                if(opcion < 0){
                    opcion = 23;
                }
                break;
            case DOWN:
                opcion++;
                if(opcion > 23){
                    opcion = 0;
                }
                break;

            case ENTER:
                Sitio = opcion;
                GPS(opcion);
                break;
                
            default:
                break;
            }
        }
		
	}while(tecla != ENTER);
}
void ColorearDestino(int i)
{
    switch (i)
    {
    case 0:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(213,262,251,299);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(227,273,"1");
    break;
    case 1:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(337,247,360,292);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(344,263,"2");
    break;

    case 2:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(337,330,370,360);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(347,340,"3");
    break;

    case 3:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(337,380,380,399);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(352,385,"4");
    break;

    case 4:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        drawpoly(8,Estadio);
        fillpoly(8,Estadio);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(266,375,"5");
    break;

    case 5:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(378,247,449,268);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(407,251,"6");
    break;

    case 6:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(471,247,519,292);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(490,265,"7");
    break;

    case 7:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(491,189,539,228);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(509,203,"8");
    break;

    case 8:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(542,209,586,286);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(560,242,"9");
    break;

    case 9:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(468,311,538,363);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(487,330,"10");
    break;

    case 10:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(479,369,521,399);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(488,380,"11");
    break;

    case 11:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(398,398,461,419);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(417,402,"12");
    break;

    case 12:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(400,310,443,346);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(409,323,"13");
    break;

    case 13:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        drawpoly(3,Motel);
        fillpoly(3,Motel);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(408,372,"14");
    break;

    case 14:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(84,266,174,286);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(116,269,"15");
    break;

    case 15:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        drawpoly(5,Catedral);
        fillpoly(5,Catedral);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(125,320,"16");
    break;

    case 16:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(76,353,114,391);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(82,368,"17");
    break;

    case 17:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(73,132,156,195);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(101,158,"18");
    break;

    case 18:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(73,80,155,121);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(101,94,"19");
    break;

    case 19:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(213,155,252,189);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(218,167,"20");
    break;

    case 20:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(244,108,296,144);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(257,120,"21");
    break;

    case 21:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(306,132,470,191);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(375,160,"22");
    break;

    case 22:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(492,128,509,169);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,1,2);
        outtextxy(510,133,"23");
    break;

    case 23:
        Lugares();
        setfillstyle(XHATCH_FILL,RED);
        bar(520,129,586,169);
        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,2);
        outtextxy(542,142,"24");
    break;

    default:
        break;
    }
}
void GPS(int i)
{
    switch (i)
    {
    case 0:
        GpsPizza();
    break;

    case 1:
        GpsAcademia();
    break;

    case 2:
        GpsDiscotecaChaman();
    break;

    case 3:
        GpsBillar();
    break;

    case 4:
        GpsEstadio();
    break;

    case 5:
        GpsInterlocales();
    break;

    case 6:
        GpsAutolote();
    break;

    case 7:
        GpsEnel();
    break;

    case 8:
        GpsCasaPellas();
    break;

    case 9:
        GpsHospitalMilitar();
    break;

    case 10:
        GpsPricesmart();
    break;

    case 11:
        GpsBanpro();
    break;

    case 12:
        GpsParisGrandAuto();
    break;

    case 13:
        GpsAutoHotelLuna();
    break;

    case 14:
        GpsFeria();
    break;

    case 15:
        GpsCatedral();
    break;

    case 16:
        GpsDGI();
    break;

    case 17:
        GpsMetrocentro();
    break;

    case 18:    
        GpsHotelIntercontinental();
    break;

    case 19:
        GpsPUMA();
    break;

    case 20:
        GpsHispamer();
    break;

    case 21:
        GpsUCA();
    break;

    case 22:
        GpsLafise();
    break;

    case 23:
        GpsHotelHolidayInn();
    break;
    
    default:
        break;
    }
}
void Lugares()
{
    /*Sitios*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    /*EstadioN*/
    drawpoly(8,Estadio);
    fillpoly(8,Estadio);
    /*Billar*/
	rectangle(336,381,381,400);
    bar(337,380,380,399);
    /*Chaman*/
    rectangle(336,329,371,361);
    bar(337,330,370,360);
    /*Academia*/
    rectangle(336,246,361,293);
    bar(337,247,360,292);
    /*Estacion*/
    rectangle(377,246,450,269);
    bar(378,247,449,268);
    /*Pizza*/
    rectangle(212,261,252,300);
    bar(213,262,251,299);
    /*Motel1*/
    rectangle(399,309,444,347);
    bar(400,310,443,346);
    /*Motel2*/
    setfillstyle(SOLID_FILL,DARKGRAY);
    drawpoly(3,Motel);
    fillpoly(3,Motel);
    /*Banpro*/
    rectangle(397,397,462,420);
    bar(398,398,461,419);
    /*Pricesmart*/
    rectangle(478,368,522,400);
    bar(479,369,521,399);
    /*Hospital*/
    rectangle(467,310,539,364);
    bar(468,311,538,363);
    /*AutosUsados*/
    rectangle(470,246,520,293);
    bar(471,247,519,292);
    /*Casapellas*/
    rectangle(541,208,587,287);
    bar(542,209,586,286);
    /*Enel*/
    rectangle(490,188,540,229);
    bar(491,189,539,228);
    /*Lafise*/
    rectangle(491,127,510,170);
    bar(492,128,509,169);
    /*HolidayINN*/
    rectangle(519,128,587,170);
    bar(520,129,586,169);
    /*UCA*/
    rectangle(305,131,471,192);
    bar(306,132,470,191);
    /*PUMA*/
    rectangle(212,154,253,190);
    bar(213,155,252,189);
    /*Hispamer*/
    rectangle(243,107,297,145);
    bar(244,108,296,144);
    /*Intercontinental*/
    rectangle(72,79,156,122);
    bar(73,80,155,121);
    /*Metrocentro*/
    rectangle(72,132,157,196);
    bar(73,132,156,195);
    /*Feria*/
    rectangle(83,265,175,287);
    bar(84,266,174,286);
    /*Catedral*/
    drawpoly(5,Catedral);
    fillpoly(5,Catedral);
    /*DGI*/
    rectangle(75,352,115,392);
    bar(76,353,114,391);
}
void Tiempo(int temp, int module)
{   
    if(module == 1){
        char tempo[6];
        char aux[5];

        itoa(temp,aux,10);

        setfillstyle(1,BLACK);
        bar(291,4,349,29);

        setcolor(WHITE);
        settextstyle(DEFAULT_FONT,0,1);

        if (temp == 30) 
	    {
	    	outtextxy(300, 13, "00:30");
    
	    }else if(temp == 20)
	    {
	    	outtextxy(300, 13, "00:20");
    
	    }else if(temp == 10)
	    {
	    	outtextxy(300, 13, "00:10");
    
	    }else if((temp > 10 && temp < 20) || (temp > 20 && temp < 30)){
	    	strcpy(tempo, "00:");
	    	strcat(tempo, aux);
	    	outtextxy(300, 13, tempo);
	    }else{
	    	strcpy(tempo, "00:0");
	    	strcat(tempo, aux);
	    	outtextxy(300, 13, tempo);
	    }
    }else if(module == 2){
        char tempo[6];
        char aux[5];

        itoa(temp,aux,10);

        setfillstyle(SOLID_FILL,WHITE);
        bar(300,210,350,240);

        setcolor(RED);
        settextstyle(SANS_SERIF_FONT,0,1);

        if (temp == 10) 
	    {
	    	outtextxy(312, 215, "10");
    
	    }else{
            strcpy(tempo, "0");
	    	strcat(tempo, aux);
	    	outtextxy(312, 215, tempo);
	    }
        sleep(1);
        if(temp < 1){
            delay(500);
            exit(1);
        }
    }
}
int MoverRobot()
{
    if (kbhit()){
        
		tecla = getch();
		
		if (tecla == 27)
		{   
			closegraph();
			exit(0);
		}
		
        switch (tecla){
			case UP:

				if(getpixel(xM, yM - 8) == BLACK || getpixel(xM, yM - 8) == GREEN || getpixel(xM, yM - 8) == DARKGRAY){
					break;
				}
				
				BorraRastro(xM, yM);
				yM -= 4;
				Circulo(xM, yM);
			break;

			case LEFT:
				if(getpixel(xM - 8, yM) == BLACK || getpixel(xM - 8, yM) == GREEN || getpixel(xM - 8, yM) == DARKGRAY){
					break;
				}
				
				BorraRastro(xM, yM);
				xM -= 4;
				Circulo(xM, yM);
			break;
			case RIGHT:
			
				if(getpixel(xM + 8, yM) == BLACK || getpixel(xM + 8, yM) == GREEN || getpixel(xM + 8, yM) == DARKGRAY){
					break;
				}
				
				BorraRastro(xM, yM);
				xM += 4;
				Circulo(xM, yM);
			break;
			case DOWN:
			
				if(getpixel(xM, yM + 8) == BLACK || getpixel(xM, yM + 8) == GREEN || getpixel(xM, yM + 8) == DARKGRAY){
					break;
				}
				
				BorraRastro(xM, yM);
				yM += 4;
				Circulo(xM, yM);
            break;

            case ESPACE:
                return ComprobandoGps(Sitio,xM,yM);
        }
    }
    return 0;
}
void Circulo(int xR, int yR){
    setcolor(BLUE);
	setlinestyle(0,0,2);
    setfillstyle(1, BLUE);
    fillellipse(xR,yR,4,4);
}
void BorraRastro(int xR,int yR){
    setcolor(WHITE);
	setlinestyle(0,0,2);
    setfillstyle(1,WHITE);
    fillellipse(xR,yR,4,4);
}
void MostrarCaniones()
{   
    MoverRobot();
    /*Cañones izquierdos */
	setfillstyle(1,CYAN);
	/*1ro*/
	bar(30, 63 + y, 46, 79 + y);
	bar(46, 60 + y, 48, 82 + y);
    MoverRobot();
	/*2do*/
    setfillstyle(1,CYAN);
	bar(30, 91 + y, 46, 107 + y);
	bar(46, 88 + y, 48, 110 + y);
    MoverRobot();
	/*Cañones derechos*/
	/*1ro*/
    setfillstyle(1,CYAN);
	bar(593, 370 - y, 608, 386 - y);
	bar(593, 367 - y, 590, 389 - y);
    MoverRobot();
	/*2do*/
    setfillstyle(1,CYAN);
	bar(593, 398 - y, 608, 414 - y);
	bar(593, 395 - y, 590, 417 - y);
    MoverRobot();
	/*Cañones de Arriba*/
	/*1ro*/
    setfillstyle(1,CYAN);
	bar(562 - x, 58, 584 - x, 56);
	bar(565 - x, 56, 581 - x, 40);
    MoverRobot();
	/*2do*/
    setfillstyle(1,CYAN);
	bar(534 - x, 58, 556 - x, 56);
	bar(537 - x, 56, 553 - x, 40);
    MoverRobot();
	/* Cañones de Abajo*/
	/*1ro*/
    setfillstyle(1,CYAN);
	bar(53 + x, 422, 75 + x, 424);
	bar(56 + x, 424, 72 + x, 440);
    MoverRobot();
	/*2do*/
    setfillstyle(1,CYAN);
	bar(80 + x, 422, 102 + x, 424);
	bar(83 + x, 424, 99 + x, 440);
    MoverRobot();
}
void OcultarCaniones()
{   
    MoverRobot();
    /*ocultar Cañones izquierdos*/
	setfillstyle(1,DARKGRAY);
	/*1ro*/
	bar(30, 63 + y, 46, 79 + y);
	bar(46, 60 + y, 48, 82 + y);
    MoverRobot();
	/*2do*/
    setfillstyle(1,DARKGRAY);
	bar(30, 91 + y, 46, 107 + y);
	bar(46, 88 + y, 48, 110 + y);
    MoverRobot();

	/*ocultar Cañones derechos*/
	/*1ro*/
    setfillstyle(1,DARKGRAY);
	bar(593, 370 - y, 608, 386 - y);
	bar(593, 367 - y, 590, 389 - y);
    MoverRobot();
	/*2do*/
    setfillstyle(1,DARKGRAY);
	bar(593, 398 - y, 608, 414 - y);
	bar(593, 395 - y, 590, 417 - y);
    MoverRobot();

	/*ocultar Cañones de Arriba*/
	/*1ro*/
    setfillstyle(1,DARKGRAY);
	bar(562 - x, 58, 584 - x, 56);
	bar(565 - x, 56, 581 - x, 40);
    MoverRobot();
	/*2do*/
	setfillstyle(1,DARKGRAY);
	bar(534 - x, 58, 556 - x, 56);
	bar(537 - x, 56, 553 - x, 40);
    MoverRobot();

	/* Cañones de Abajo*/
	/*1ro*/
    setfillstyle(1,DARKGRAY);
	bar(53 + x, 422, 75 + x, 424);
	bar(56 + x, 424, 72 + x, 440);
    MoverRobot();
	/*2do*/
    setfillstyle(1,DARKGRAY);
	bar(80 + x, 422, 102 + x, 424);
	bar(83 + x, 424, 99 + x, 440);
    MoverRobot();
}
void VerProyectil(int x1, int y1)
{   
    MoverRobot();
    setcolor(WHITE);
	setfillstyle(1, RED);
	fillellipse(x1, y1, 5, 5);
	fillellipse(x1, y1, 5, 5);
    MoverRobot();
}
void EsconderProyectil(int x1, int y1)
{   
    MoverRobot();
    setcolor(WHITE);
	setfillstyle(1, WHITE);
	fillellipse(x1, y1, 5, 5);
	fillellipse(x1, y1, 5, 5);
    MoverRobot();
}
void Introduccion()
{
    int x = 0, x1 = 0, Bajar = 0, Subir = 0, Final = 0;
    int Triangulo [6] = {234,313,255,274,276,313};

    setfillstyle(SOLID_FILL,WHITE);
    bar(38,37,74,75);
    delay(300);

    for(x = 0; x <= 566; x++){
        x1 += 1;
        bar(38+x1,37,74,75);
    }

    if(x >= 566 ){
        x = 0;
        x1 = 0;

        for(x = 0 ;x <= 528; x++ ){
            x1 += 1;
            setfillstyle(SOLID_FILL,BLACK);
			bar(37+x1,37,74,75);
            Bajar = 1;
        }    
    }

    if(Bajar == 1){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 367; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
            bar(566,37+x1,605,75);
        }

        if(x >= 367){
            x = 0;
            x1 = 0;
            
            for(x = 0; x <= 329; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(566,36+x1,605,75);
                Bajar = 0;
            }
        }
    }

    if(Bajar == 0){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 511; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
            bar(566-x1,365,605,405);
        }

        if(x >= 367){
            x = 0;
            x1 = 0;

            for(x = 0; x <= 473; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(567-x1,365,605,405);
                Subir = 1;
            }   
        }
    }

    if(Subir == 1){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 240; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
            bar(54,365-x1,92,405);
        }

        if(x >= 240){
            x = 0;
            x1 = 0;

            for(x= 0; x <= 202; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(54,366-x1,92,405);
                Subir = 0;
            }
        }
    }

    if(Subir == 0){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 495; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
            bar(53+x1,124,90,164);
        }

        if(x >= 495){
            x = 0;
            x1 = 0;

            for(x = 0; x <= 457; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(52+x1,124,90,164);
                Bajar = 1;
            }
        }
    }

    if(Bajar == 1){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 250; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
            bar(509,124+x1,549,164);
        }

        if(x >= 250){
            x = 0;
            x1 = 0;

            for(x = 0; x <= 212; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(509,123+x1,549,164);
                Bajar = 0;
            }
        }
    }

    if(Bajar == 0){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 220; x++){
            x1 += 1;
            setfillstyle(SOLID_FILL,WHITE);
			bar(509-x1,335,549,375);
        }

        if(x >= 200){
            x = 0;
            x1 = 0;

            for(x = 0; x <= 182; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(509-x1,335,549,375);
                Subir = 1;
            }
        }
    }

    if(Subir == 1){
        x = 0;
        x1 = 0;

        for(x = 0; x <= 60; x++){
            x1 += 1;
			setfillstyle(SOLID_FILL,WHITE);
            bar(288,335-x1,327,375);
        }

        if(x >= 60){
            x = 0;
            x1 = 0;

            for(x = 0; x <= 22; x++){
                x1 += 1;
                setfillstyle(SOLID_FILL,BLACK);
                bar(288,336-x1,327,375);
                Subir = 0;
                Final = 1;
            }
        }
    }

    if(Final == 1){
        x = 0;
        x1 = 0;

        delay(100);

        for(x = 0; x <= 14; x++){
            setfillstyle(SOLID_FILL,1+x);
            rectangle(287,273,328,313);
            bar(288,274,327,312);

            circle(362,293,21);
            floodfill(362,293,WHITE);

            drawpoly(3, Triangulo);
            fillpoly(3,Triangulo);

            settextstyle(TRIPLEX_FONT,0,7);
	        outtextxy(135,180,"Povericklov");
            settextstyle(DEFAULT_FONT,0,1);
            outtextxy(487,232,"R");
	        circle(490,235,8);
            delay(300);
        }
    }

    delay(1000);
    cleardevice();
}
void PantallaCarga()
{
    int x = 0;

    setfillstyle(SOLID_FILL,WHITE);
    bar(0,0,640,480);

    for(x=0 ;x<11 ;x++){
        
        RobotI(x);

		delay(50);
		setlinestyle(0,0,3);
		setcolor(0);
		arc(320,240,0,90,20);
        arc(320,240,0,90,21);

        delay(50);
        setlinestyle(0,0,3);
		setcolor(255);
		arc(320,240,0,90,20);
        arc(320,240,0,90,21);

        setcolor(BLACK);
        settextstyle(SMALL_FONT,0,6);
        outtextxy(283,190,"Cargando");

        delay(50);
		setlinestyle(0,0,3);
		setcolor(0);
		arc(320,240,90,180,20);
        arc(320,240,90,180,21);

        delay(50);
        setlinestyle(0,0,3);
		setcolor(255);
		arc(320,240,90,180,20);
        arc(320,240,90,180,21);

        delay(50);
		setlinestyle(0,0,3);
		setcolor(0);
		arc(320,240,180,270,20);
        arc(320,240,180,270,21);

        delay(50);
        setlinestyle(0,0,3);
		setcolor(255);
		arc(320,240,180,270,20);
        arc(320,240,180,270,21);

        delay(50);
        setlinestyle(0,0,3);
        setcolor(0);
        arc(320,240,270,360,20);
        arc(320,240,270,360,21);

        delay(50);
        setlinestyle(0,0,3);
        setcolor(255);
        arc(320,240,270,360,20);
        arc(320,240,270,360,21);
	}

    cleardevice();
}
void RobotI(int i){
    /*Contorno*/
    setfillstyle(SOLID_FILL,BLACK);
    bar(273,56,372,62);
    bar(267,63,272,87);
    bar(261,88,266,105);
    bar(267,106,272,130);
    bar(273,131,291,136);
    bar(292,137,297,167);
    bar(298,168,304,180);
    bar(305,181,310,186);
    bar(311,175,316,180);
    bar(311,168,335,174);
    bar(329,175,335,180);
    bar(336,181,341,186);
    bar(342,180,347,168);
    bar(348,167,353,137);
    bar(354,136,372,131);
    bar(373,130,378,63);

    /*Internos*/
    setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
    bar(273,63,291,130);
    bar(305,137,347,167);
    bar(305,168,310,174);
    bar(336,168,341,174);
    setfillstyle(INTERLEAVE_FILL,DARKGRAY);
    bar(292,131,353,136);
    bar(267,88,278,105);
    bar(298,137,304,167);
    bar(311,143,316,161);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(298,68,366,124);
    setfillstyle(INTERLEAVE_FILL,CYAN);
    bar(298,69,366,74);
    bar(361,75,366,124);
    setfillstyle(SOLID_FILL,WHITE);
    bar(317,143,341,161);
    bar(279,87,285,105);
    /*Rostro*/
    setfillstyle(SOLID_FILL,i);
    /*Ojos*/
    bar(304,93,310,99);
    bar(354,93,360,99);
    /*Boca*/
    bar(317,100,322,106);
    bar(342,100,347,106);
    bar(317,107,347,111);
}
void RobotII(){
    /*Contorno*/
    setfillstyle(SOLID_FILL,BLACK);
    bar(273,56,372,62);
    bar(267,63,272,87);
    bar(261,88,266,105);
    bar(267,106,272,130);
    bar(273,131,291,136);
    bar(292,137,297,167);
    bar(298,168,304,180);
    bar(305,181,310,186);
    bar(311,175,316,180);
    bar(311,168,335,174);
    bar(329,175,335,180);
    bar(336,181,341,186);
    bar(342,180,347,168);
    bar(348,167,353,137);
    bar(354,136,372,131);
    bar(373,130,378,63);

    /*Internos*/
    setfillstyle(INTERLEAVE_FILL,LIGHTGRAY);
    bar(273,63,291,130);
    bar(305,137,347,167);
    bar(305,168,310,174);
    bar(336,168,341,174);
    setfillstyle(INTERLEAVE_FILL,DARKGRAY);
    bar(292,131,353,136);
    bar(267,88,278,105);
    bar(298,137,304,167);
    bar(311,143,316,161);
    setfillstyle(SOLID_FILL,LIGHTCYAN);
    bar(298,68,366,124);
    setfillstyle(INTERLEAVE_FILL,CYAN);
    bar(298,69,366,74);
    bar(361,75,366,124);
    setfillstyle(SOLID_FILL,WHITE);
    bar(317,143,341,161);
    bar(279,87,285,105);

    /*Rostro*/
    /*Ojos*/
    setfillstyle(SOLID_FILL,RED);
    setcolor(RED);
    settextstyle(DEFAULT_FONT,0,2);
    outtextxy(304,91,"X");
    outtextxy(348,91,"X");
    /*Boca*/
    bar(317,112,322,117);
    bar(342,112,347,117);
    bar(317,107,347,111);

    /*Roto Arriba*/
    setcolor(BLACK);
    putpixel(313,75,BLACK);
    putpixel(314,75,BLACK);
    putpixel(315,76,BLACK);
    putpixel(315,77,BLACK);
    line(316,77,316,82);
    line(315,82,315,87);
    putpixel(316,85,BLACK);
    putpixel(316,86,BLACK);
    putpixel(314,87,BLACK);
    putpixel(313,87,BLACK);
    putpixel(313,88,BLACK);
    putpixel(312,88,BLACK);
    putpixel(312,89,BLACK);
    putpixel(317,79,BLACK);
    putpixel(317,80,BLACK);
    putpixel(318,80,BLACK);
    putpixel(318,81,BLACK);
    putpixel(319,81,BLACK);
    putpixel(319,82,BLACK);
    line(320,82,320,86);
    line(321,86,321,89);
    putpixel(322,89,BLACK);
    putpixel(322,90,BLACK);
    putpixel(323,90,BLACK);
    putpixel(323,91,BLACK);
    putpixel(324,91,BLACK);
    putpixel(324,92,BLACK);
    putpixel(324,93,BLACK);
    putpixel(325,93,BLACK);
    putpixel(321,83,BLACK);
    putpixel(321,84,BLACK);
    putpixel(322,84,BLACK);
    putpixel(322,85,BLACK);
    putpixel(323,85,BLACK);
    putpixel(324,85,BLACK);
    putpixel(324,86,BLACK);
    putpixel(325,86,BLACK);
    putpixel(326,86,BLACK);
    line(327,87,330,87);
    line(330,86,334,86);
    line(334,87,333,87);

    /*Roto abajo*/
    line(359,124,359,120);
    putpixel(358,120,BLACK);
    line(358,119,351,119);
    line(354,119,354,115);
    line(351,120,348,120);
    putpixel(348,121,BLACK);
    putpixel(348,122,BLACK);
    putpixel(347,122,BLACK);
    putpixel(355,118,BLACK);
    putpixel(356,118,BLACK);
    putpixel(356,117,BLACK);
    putpixel(356,116,BLACK);
    putpixel(357,116,BLACK);
    putpixel(357,115,BLACK);
    putpixel(358,115,BLACK);
    putpixel(358,114,BLACK);
    putpixel(359,114,BLACK);
    putpixel(359,113,BLACK);
    putpixel(359,112,BLACK);
    putpixel(360,112,BLACK);
    putpixel(360,111,BLACK);
    putpixel(360,110,BLACK);

    /*Pecho Roto*/
    setfillstyle(HATCH_FILL,RED);
    circle(330,152,7);
    floodfill(330,152,BLACK);
}
int VentanaDerrota(){
    int seg = 1, temp = 10;
	char opc;
	int op = -1;
	
    setcolor(BLACK);
    setlinestyle(SOLID_LINE,0,THICK_WIDTH);
    rectangle(219,34,421,359);
    setfillstyle(SOLID_FILL,WHITE);
    bar(220,35,420,358);
    RobotII();

    setcolor(BLACK);
    settextstyle(SANS_SERIF_FONT,0,1);
    outtextxy(271,190,"Has Perdido!");
    /*BTN 1*/
    rectangle(264,251,376,291);
    setfillstyle(SOLID_FILL,RED);
    bar(265,252,375,290);
    outtextxy(280,255,"Reintentar");
    /*BTN 2*/
    rectangle(264,301,376,341);
    setfillstyle(SOLID_FILL,RED);
    bar(265,302,375,340);
    outtextxy(305,305,"Salir");

    Tiempo(temp,2);
    do{
        if (seg % 3 == 0)
		{
			temp--;
			Tiempo(temp,2);
		}
		
		if (kbhit())
		{
			opc = getch();
			
			op = ColorearBotones(opc);
		}
		
        seg++;
    }while (temp != 0 && op == -1);
	
	return op;
}
int ColorearBotones(char i)
{
    switch (i)
    {
    case 'r':
	case 'R':
        setcolor(BLACK);
        rectangle(264,251,376,291);
        setfillstyle(SOLID_FILL,RED);
        bar(265,252,375,290);
        outtextxy(280,255,"Reintentar");
        setcolor(WHITE);
        rectangle(266,253,374,289);

        setcolor(BLACK);
        rectangle(264,301,376,341);
        setfillstyle(SOLID_FILL,RED);
        bar(265,302,375,340);
        outtextxy(305,305,"Salir");
		return 1;
		
    case 's':
	case 'S':
        setcolor(BLACK);
        rectangle(264,301,376,341);
        setfillstyle(SOLID_FILL,RED);
        bar(265,302,375,340);
        outtextxy(305,305,"Salir");
        setcolor(WHITE);
        rectangle(266,303,374,340);
        
        setcolor(BLACK);
        rectangle(264,251,376,291);
        setfillstyle(SOLID_FILL,RED);
        bar(265,252,375,290);
        outtextxy(280,255,"Reintentar");
		return 0;
    }
	
	return -1;
}
void MostrarVida(){
	char vida[2];
	
	itoa(lifes, vida, 10);
	
	setfillstyle(1, BLACK);
	bar(479, 6, 510, 27);
	
	setcolor(WHITE);
	settextstyle(DEFAULT_FONT,0,2);
    outtextxy(480,11, vida);
}
int ComprobandoGps(int Sitio, int xM, int yM){
    /*Pizza*/
    if((Sitio == 0) && (xM > 249 && xM < 269 && yM > 281 && yM < 301)){
        return 1;
    /*Academia*/
    }else if((Sitio == 1) && (xM > 332 && xM < 359 && yM > 242 && yM < 269)){
        return 1;   
    /*Chaman*/
    }else if((Sitio == 2) && (xM > 344 && xM < 364 && yM > 359 && yM < 369)){
        return 1;
    /*Billar*/
    }else if((Sitio == 3) && (xM > 344 && xM < 364 && yM > 373 && yM < 381)){
        return 1;
    /*Estadio*/
    }else if((Sitio == 4) && (xM > 315 && xM < 324 && yM > 379 && yM < 393) || (xM > 190 && xM < 380 && yM > 225 && yM < 393)){
        return 1;
    /*Interlocales*/
    }else if((Sitio == 5) && (xM > 386 && xM < 440 && yM > 270 && yM < 283)){
        return 1;
    /*Autolotes*/
    }else if((Sitio == 6) && (xM > 486 && xM < 530 && yM > 236 && yM < 274)){
        return 1;
    /*Enel*/
    }else if((Sitio == 7) && (xM > 495 && xM < 534 && yM > 175 && yM < 200)){
        return 1;
    /*CasaPellas*/
    }else if((Sitio == 8) && (xM > 543 && xM < 584 && yM > 175 && yM < 215)){
        return 1;
    /*HospitalMilitar*/
    }else if((Sitio == 9) && (xM > 455 && xM < 550 && yM > 302 && yM < 365)){
        return 1;
    /*Pricesmart*/
    }else if((Sitio == 10) && (xM > 464 && xM < 490 && yM > 379 && yM < 400)){
        return 1;
    /*Banpro*/   
    }else if((Sitio == 11) && (xM > 380 && xM < 480 && yM > 399 && yM < 420)){
        return 1;
    /*ParisGrandAuto*/
    }else if((Sitio == 12) && (xM > 389 && xM < 458 && yM > 300 && yM < 345)){
        return 1;
    /*AutoHotelLuna*/
    }else if((Sitio == 13) && (xM > 450 && xM < 465 && yM > 365 && yM < 392)){
        return 1;
    /*Feria*/   
    }else if((Sitio == 14) && (xM > 110 && xM < 140 && yM > 245 && yM < 265)){
        return 1;
    /*Catedral*/
    }else if((Sitio == 15) && (xM > 165 && xM < 181 && yM > 316 && yM < 330)){
        return 1;
    /*DGI*/
    }else if((Sitio == 16) && (xM > 77 && xM < 110 && yM > 395 && yM < 405)){
        return 1;   
    /*Metrocentro*/   
    }else if((Sitio == 17) && (xM > 61 && xM < 75 && yM > 147 && yM < 182)){
        return 1;
    /*Intercontinental*/   
    }else if((Sitio == 18) && (xM > 61 && xM < 75 && yM > 81 && yM < 116)){
        return 1;
    /*PUMA*/   
    }else if((Sitio == 19) && (xM > 218 && xM < 243 && yM > 194 && yM < 205)){
        return 1;
    /*Hispamer*/
    }else if((Sitio == 20) && (xM > 249 && xM < 277 && yM > 96 && yM < 105)){
        return 1;
    /*UCA*/   
    }else if((Sitio == 21) && (xM > 324 && xM < 391 && yM > 195 && yM < 205)){
        return 1;
    /*Banco Lafise*/    
    }else if((Sitio == 22) && (xM > 489 && xM < 511 && yM > 116 && yM < 180)){
        return 1;
    /*************************************/
    /*HotelHolidayInn*/
    }else if((Sitio == 23) && (xM > 546 && xM < 568 && yM > 116 && yM < 180)){
        return 1;
    }else{
        return 0;
	}
}
/************************************************************************************************************************/
/* FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES         FUNCIONES        FUNCIONES */
/************************************************************************************************************************/
