/*
-------------------------------------------------------------------------------------------------------------------
Instituto Politecnico Nacional. ESIME Z.
Materia: Analisis numerico.
Autor: Addi Trejo | Alfredo Trejo.
Programa: 12.Grafica de la funcion exponente
Creado Diciembre 2018 
Descripcion: Graficar una funcion exponencial.
----------------------------------------------------------------------------------------------------------
*/
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int ANCHO = 720, ALTO = 720;

//Variables
int e;
/*****************************************************************************************************************************/    
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int textoX, int textoY, char *nombre ) {
    moveto   ( moverX, moverY );
    setcolor ( color );
    lineto   ( dibujarX, dibujarY );
    outtextxy( textoX, textoY, nombre );
}
/*****************************************************************************************************************************/  
void dibujarExponente ( int e ){
	float x, y;
	for ( x = -360 ; x <= 360; x += 0.01 ) {
		y = pow ( x ,  e ) / 100;
		putpixel( 360 + x ,360 - y , YELLOW );
	}
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
	cout<<"\t\t\t\t\tPrograma: Grafica de una funcion exponencial\n"<<endl;
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	
	cout << " Grafica de la funcion Exponente" << endl;
	cout << " Ingrese exponente : ";
	cin  >> e;
	pintarPlano();
	dibujarExponente( e );
	getch();
	closegraph();
}

