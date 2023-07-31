/*
-------------------------------------------------------------------------------------------------------------------
Instituto Politecnico Nacional. ESIME Z.
Materia: Analisis numerico.
Autor: Addi Trejo | Alfredo Trejo.
Programa: 01.  Grafica de la circunferencia
Creado Diciembre 2018 16:32:23 
Descripcion: Graficar una circunferenca en el plano dada por el usuario,
----------------------------------------------------------------------------------------------------------
*/
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int ANCHO = 720, ALTO = 720;

//Variables
float h, k, r;
/*****************************************************************************************************************************/    
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int textoX, int textoY, char *nombre ) {
    moveto   ( moverX, moverY );
    setcolor ( color );
    lineto   ( dibujarX, dibujarY );
    outtextxy( textoX, textoY, nombre );
}
/*****************************************************************************************************************************/  
void dibujarCircunferencia ( float h, float k, float r ){
	float x, y1, y2 ;
	for ( float x = -360; x <= 360; x += 0.01 ) {
		y1 =  ( + sqrt ( pow ( r, 2 ) - ( pow ( x - h , 2 ) ) ) + k );
		y2 =  ( - sqrt ( pow ( r, 2 ) - ( pow ( x - h , 2 ) ) ) + k );
		putpixel( 360 + x, 360 - y1, YELLOW );
		putpixel( 360 + x, 360 - y2, YELLOW );
	}
	outtextxy( 360 + h, 360 - k, "h,k" );
	line( 360, 360 - k, 360 + h, 360 - k );
	line( 360 + h, 360, 360 + h, 360 - k );
}
/*****************************************************************************************************************************/  
void pintarPlano ( ) {
	//Inicia la ventana
	initwindow( ANCHO, ALTO );
	
	//Pinta los ejes en la ventana
    dibujarLinea( 0, ALTO / 2, ANCHO, ALTO / 2, WHITE, ANCHO - 20, ALTO / 2 + 10, "X" );
    dibujarLinea( ANCHO / 2, 0, ANCHO / 2, ALTO, WHITE, ANCHO / 2 + 10, 0, "Y" );
}
/*****************************************************************************************************************************/  
int main() {
	
	cout<<"\t\t\t\t\tInstituto Politecnico Nacional\n"<<endl;
	cout<<"\t\t\t\t\tAlumnos:  Addi Trejo | Alfredo Trejo \n"<<endl;
	cout<<"\t\t\t\t\t\      Fecha:  Dic 2018\n"<<endl;
	cout<<"\t\t\t\t\t\      Analisis numerico \n"<<endl;
	cout<<"\t\t\t\t\tPrograma: Grafica de una circunferencia\n"<<endl;
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	
	
	
	cout << " Grafica de la circunferencia " << endl;
	cout << " Ingrese radio : ";
	cin  >> r;
	cout << " Ingrese h : ";
	cin  >> h;
	cout << " Ingrese k : ";
	cin  >> k;
	pintarPlano();
	dibujarCircunferencia( h, k , r );
	getch();
	closegraph();
}

