#include <iostream>
#include <fstream>
using namespace std;

//provisionar la matriz de chars para el laberinto
char** provisionarMatriz(int);

//liberar memoria de la matriz
void liberar(char**&,int);

//imprimir la matriz
void imprimir(char**,int );

//salir del laberinto: lab,size,x,y (columna,fila)
bool salir(char**,int,int,int);

int main(){
	//abrir el archivo
	ifstream file("laberinto.txt");

	int size=0;
	char** labMatrix=NULL;
	//si el archivo existe
	if(file.is_open()){
		//leer el tamano
		file>>size;

		//inicializar matriz nxn
		labMatrix=provisionarMatriz(size);	
		//leer la matriz del archivo
		for(int i=0;i<size;i++){
			for(int j=0;j<size;j++){
				file>>labMatrix[i][j];
			}
		}
		file.close();

		//imprimir laberinto
		imprimir(labMatrix,size);
		
		//salir del laberinto
		salir(labMatrix,size,1,0);
		imprimir(labMatrix,size);
		cout<<endl;
		
		//liberar matriz
		liberar(labMatrix,size);
	}
	return 0;
}//fin del main

//provisionar matriz size x size
char** provisionarMatriz(int size){
	char** temporal=new char*[size];
	for(int i=0;i<size;i++){
		temporal[i]=new char[size];
	}
	return temporal;

}

//liberar memoria de la matriz
void liberar(char**& matriz,int size){
	for(int i=0;i<size;i++){
		delete[]  matriz[i];
		matriz[i]=NULL;
	}
	delete[] matriz;
	matriz=NULL;
}

//imprimir matriz
void imprimir(char** matriz,int size){
	for(int i=0;i<size;i++){
		for(int j=0;j<size;j++){
			cout<<matriz[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}

//salir del laberinto
bool salir(char** matriz,int size,int x,int y){
	bool salio=false;
	if(x>=0 && x<size&& y>=0 && y<size){
	
		if(/*y== size-1*/matriz[x][y]=='@'){
			matriz[x][y]='@';
			return true;
		}else{
			matriz[x][y]='*';
			//arriba
			if(x>0 && !salio){
				if(matriz[x-1][y]== '.'||matriz[x-1][y]=='@'){
					salio=salir(matriz,size,x-1,y);
				}
			}
			//abajo
			if(x<size-1 && !salio){
				if(matriz[x+1][y]=='.'||matriz[x+1][y]=='@'){
					salio=salir(matriz,size,x+1,y);
				}
			}
			//derecha
			if(y<size-1 && !salio){
				if(matriz[x][y+1]== '.'||matriz[x][y+1]=='@'){
					salio=salir(matriz,size,x,y+1);
				}
			}
			//izquierda
			if(y>0 && !salio){
				if(matriz[x][y-1]=='.'||matriz[x][y-1]=='@'){
					salio=salir(matriz,size,x,y-1);	
				}
			}
			//marca la salida
			if(salio){
				matriz[x][y]= '@';
			}
			return salio;
		}
		
	}else{
		return false;
	}
}
	
