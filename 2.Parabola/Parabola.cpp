/*
-------------------------------------------------------------------------------------------------------------------
Instituto Politecnico Nacional. ESIME Z.
Materia: Analisis numerico.
Autor: Addi Trejo | Alfredo Trejo.
Programa: 02. Grafica de la parabola.
Creado: Dic 18 
Descripcion: Graficar una parabola en el plano dada por el usuario. 
----------------------------------------------------------------------------------------------------------
*/

#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int ANCHO = 720, ALTO = 720;

//Variables
float h, k, p;
int  tipo;
    
/*****************************************************************************************************************************/    
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int textoX, int textoY, char *nombre ) {
    moveto   ( moverX, moverY );
    setcolor ( color );
    lineto   ( dibujarX, dibujarY );
    outtextxy( textoX, textoY, nombre );
}
/*****************************************************************************************************************************/  
void dibujarParabolaVertical ( float h, float k, float p ){
	int x , y ;
	for ( float x = -360; x <= 360; x += 0.01 ) {
		y = ( pow ( (x - h),2 ) / ( 4 * p ) + k );
		putpixel( 360 + x, 360 - y, YELLOW );
	}
}
/*****************************************************************************************************************************/  
void dibujarParabolaHorizontal ( float h, float k, float p ){
	int x , y ;
	for ( float y = -360; y <= 360; y += 0.01 ) {
		x =	( pow ( (y - k),2 ) / ( 4 * p ) + h );
		putpixel( 360 + x, 360 - y, YELLOW );
	}
}
/*****************************************************************************************************************************/
int eligeTipo ( ){
	int tipo;
	do {
		cout << "\n\t\t\t Elija el tipo de parabola que desea graficar : " << endl;
		cout << "\t\t\t [1]Vertical " << endl;
		cout << "\t\t\t [2]Horizontal " << endl << "\t\t\t  ";
		cin  >> tipo;
		if ( ! ( tipo == 1 || tipo == 2) ) {
			cout << "\t\t\t Error, Ingrese una opcion correcta " << endl;
			system ( " pause " );
			system ( " cls " );
		}
	}
	while ( ! ( tipo == 1 || tipo == 2) );

}
float ingresarH ( ) {
	float h;
	cout << "\n\t\t\t Ingrese valor de h : ";
	cin  >> h;
	return h;
		
}
/*****************************************************************************************************************************/  
float ingresarK ( ) {
	float k;
	cout << "\t\t\t Ingrese valor de k : ";
	cin  >> k;
	return k;
}
/*****************************************************************************************************************************/  
float ingresarP(  ) {
	//Nota: Para determinar si va hacia arriba, abajo, izquierda o derecha el valor de p puede ser negativo
	float p;
	cout << "\n\t\t\t Ingrese valor de p : ";
	cin  >> p;
	return p;
}
/*****************************************************************************************************************************/  
void vizualizar () {
	cout << "\n\n\t\t\t\t\t Grafica de la Parabola " << endl;
	system ( " color f0 " );
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
	
	printf("\t\t\t\t\tInstituto Politecnico Nacional\n"); 
	printf("\t\t\t\t\tAlumno:  Addi Trejo | Alfredo Trejo \n");
	printf("\t\t\t\t\t\      Fecha:  Dic 2018\n");
	printf("\t\t\t\t\t\      Analisis numerico \n");
	printf("\t\t\t\t\tPrograma: Grafica de la parabola\n");
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	//Titulo
	vizualizar();
	
	//Peticion de datos
	tipo = eligeTipo( );
	h = ingresarH();
	k = ingresarK();
	p = ingresarP();
	
	pintarPlano();
	
    //Pinta la parabola con los valores ingresados
	if ( tipo == 1 ){
		dibujarParabolaVertical ( h, k, p );
	}
	if ( tipo == 2 ){
		dibujarParabolaHorizontal( h, k ,p );
	}
	getch();
	closegraph();
}

