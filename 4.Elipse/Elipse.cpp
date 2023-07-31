/*
-------------------------------------------------------------------------------------------------------------------
Instituto Politecnico Nacional. ESIME Z.
Materia: Analisis numerico.
Autor: Addi Trejo | Alfredo Trejo.
Programa: 04.  Grafica del elipse
Creado Diciembre 2018 
Descripcion: Graficar un elipse en el plano dada por el usuario.
----------------------------------------------------------------------------------------------------------
*/
#include <graphics.h>
#include <math.h>
#include <conio.h>
#include <iostream>
using namespace std;
const int ANCHO = 720, ALTO = 720;

/*****************************************************************************************************************************/    
void dibujarLinea( int moverX, int moverY, int dibujarX, int dibujarY, int color, int textoX, int textoY, char *nombre ) {
    moveto   ( moverX, moverY );
    setcolor ( color );
    lineto   ( dibujarX, dibujarY );
    outtextxy( textoX, textoY, nombre );
}
/*****************************************************************************************************************************/  
void dibujarElipseHorizontal( float h, float k, float a, float b ){
	float x, y1, y2;
	for ( x = -360; x <= 360; x += 0.01 ) {
		y1 = ( (  sqrt ( ( pow ( a, 2 ) * pow ( b, 2 ) - pow ( b ,2 ) * pow ( x - h , 2 ) ) / pow ( a, 2 )  ) + k ) );
		y2 = ( (- sqrt ( ( pow ( a, 2 ) * pow ( b, 2 ) - pow ( b ,2 ) * pow ( x - h , 2 ) ) / pow ( a, 2 )  ) + k ) );
		putpixel( 360 + x , 360 - y1 , YELLOW );
		putpixel( 360 + x , 360 - y2 , YELLOW );
	}
}
/*****************************************************************************************************************************/  
void dibujarElipseVertical( float h, float k, float a, float b ){
	float x, y1, y2;
	for ( x = -360; x <= 360; x += 0.01 ) {
		y1 = ( (  sqrt ( ( pow ( a, 2 ) * pow ( b, 2 ) - pow ( a ,2 ) * pow ( x - h , 2 ) ) / pow ( b, 2 )  ) + k ) );
		y2 = ( (- sqrt ( ( pow ( a, 2 ) * pow ( b, 2 ) - pow ( a ,2 ) * pow ( x - h , 2 ) ) / pow ( b, 2 )  ) + k ) );
		putpixel( 360 + x , 360 - y1 , YELLOW );
		putpixel( 360 + x , 360 - y2 , YELLOW );
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
	float a, b, h, k;
	int tipo;
	
	cout<<"\t\t\t\t\tInstituto Politecnico Nacional\n"<<endl;
	cout<<"\t\t\t\t\tAlumnos:  Addi Trejo | Alfredo Trejo \n"<<endl;
	cout<<"\t\t\t\t\t\      Fecha:  Dic 2018\n"<<endl;
	cout<<"\t\t\t\t\t\      Analisis numerico \n"<<endl;
	cout<<"\t\t\t\t\tPrograma: Grafica de una recta\n"<<endl;
	printf("-----------------------------------------------------------------------------------------------------------------------\n");
	
	
	cout << " Grafica de la Elipse" << endl;
	cout << " Ingrese h : ";
    cin  >> h;
    cout << " Ingrese k : ";
    cin  >> k;
    cout << " [1].Vertical " << endl;
    cout << " [2].Horizontal " << endl;
    cin  >> tipo;
    switch ( tipo ){
    	case 1:
    		cout << " Ingrese a : ";
    		cin  >> a;
    		do {
    			cout << " Ingrese b : ";
    			cin  >> b;
    			if ( b >= a ){
    				cout << " Error. b debe ser menor que a " << endl;
				}
			}
			while ( b >= a );
			pintarPlano();
    		dibujarElipseVertical  ( h, k, a, b );
    		break;
		case 2:
			cout << " Ingrese a : ";
    		cin  >> a;
    		do {
    			cout << " Ingrese b : ";
    			cin  >> b;
    			if ( b >= a ){
    				cout << " Error. b debe ser menor que a " << endl;
				}
			}
			while ( b >= a );
			pintarPlano();
			dibujarElipseHorizontal( h, k, a, b );
			break;	
	}
	getch();
	closegraph();
}

