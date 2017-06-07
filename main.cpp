#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fstream>
#include <vector>
//-------------------------------Funciones----------------------------------
int filtro (char dato);
int lexico ();
void token(int salida);
//-------------------------------Funciones----------------------------------

using namespace std;
int cont=0;
int estado=0;
int salida=0;
int codigo=0;

int M_salida[25][17];
int M_tran[25][17];
vector<char> datos;
vector<char> letras;

int main(int argc, char** argv) {
	fstream fp;
	fstream fp2;
	fp.open("Tran.txt", ios::in | ios::binary);
	fp2.open("Salida.txt", ios::in | ios::binary);
	char temp;
	for (int x=0;x<17;x++){
		fp>>temp;
		//cout<<temp<<endl;
		fp2>>temp;
		letras.push_back(temp);
	}
	for (int y=0;y<25;y++){
		for (int x=0;x<17;x++){
			fp>>M_tran[y][x];
			fp2>>M_salida[y][x];
		}
	}
	fp.close();
	fp2.close();
	cout<<"Matrices Cargadas correctamente";
//	for (int y=0;y<25;y++){
//		for (int x=0;x<17;x++){
//			cout<<M_tran[y][x];
//		}
//	}
//	getchar();
//	
		fp.open("texto.txt", ios::in | ios::binary);
	char d=fp.get();
	while(!fp.eof()){
		datos.push_back(d);
		d=fp.get();
	}
	fp.close();
	cout<<"Texto Cargado correctamente"<<endl;
	cout<<datos.size();
	getchar();
	while(cont<datos.size()){
		token(lexico());	
	}
	cout<<"Termine";
	getchar();
	return 0;
}

int lexico(){
//	cout<<"Entre en Lexico";
//		getchar();
	estado=0;
	salida=0;
	while (salida==0){
		codigo=filtro(datos[cont]);
		cont++;
		salida=M_salida[estado][codigo];
		estado=M_tran[estado][codigo];
//		cout<<estado<<" "<<codigo;
//		getchar();
//		cout<<codigo;
//		getchar();
	}
	if (salida!=18){
		cont--;
	}
	
	return salida;
	
}

void token(int final){
	switch (final){
		case 1:
			cout<<"IDE"<<endl;
			break;
		case 2:
			cout<<"ERROR 1: Se Esperaba un Numero"<<endl;
			break;
		case 3:
			cout<<"ENTERO"<<endl;
			break;
		case 4:
			cout<<"ERROR 1: Se Esperaba un Numero"<<endl;
			break;
		case 5:
			cout<<"REAL"<<endl;
			break;
		case 6:
			cout<<"ERROR 1: Se Esperaba un Numero"<<endl;
			break;
		case 7:
			cout<<"ERROR 1: Se Esperaba un Numero"<<endl;
			break;
		case 8:
			cout<<"CIENTIFICO"<<endl;
			break;
		case 9:
			cout<<"MENOR"<<endl;
			break;
		case 10:
			cout<<"MENROIGUAL"<<endl;
			break;
		case 11:
			cout<<"MAYOR"<<endl;
			break;
		case 12:
			cout<<"MAYOROIGUAL"<<endl;
			break;
		case 13:
			cout<<"ASIG"<<endl;
			break;
		case 14:
			cout<<"IGUALDAD"<<endl;
			break;
		case 15:
			cout<<"ERROR 2: No soporto negacion"<<endl;
			break;
		case 16:
			cout<<"DIFERENCIA"<<endl;
			break;
		case 17:
			cout<<"OTRO"<<endl;
			break;
		case 18:
			cout<<"PUNTO"<<endl;
			break;
		case 19:
			cout<<"COMENTARIO ERRADO"<<endl;
			break;
		case 22:
			cout<<"COMENTARIO MULTILINEA"<<endl;
			break;
		case 24:
			cout<<"COMENTARIO LINEA"<<endl;
			break;
	}
//	getchar();
	
}

int filtro(char dato){
		if (isalpha(dato)){
			if (dato=='E'){
				return 5;
			}else{
				if (dato=='e'){
					return 6;
				}else{
					return 0;
					
				}
			
			}
		}
		if (isdigit(dato)&& dato!='.'){
			return 7;
		}
		if (dato=='_'){
			return 1;
		}
		if (dato=='-'){
			return 2;
		}
		if (dato=='+'){
			return 3;
		}
		if (dato=='.'){
			//cout<<dato<<endl;
			return 4;
		}
		if (dato=='>'){
			return 8;
		}
		if (dato=='='){
			return 9;
		}
		if (dato=='!'){
			return 10;
		}
		if (dato==' '||dato==13){
			return 11;
		}
		if (dato=='<'){
			return 13;
		}
		//dato==10
		if (dato==47){
			return 14;
		}
		if (dato=='*'){
			return 15;
		}
		if(dato==10){
			return 16;
		}else{
			return 12;
		}
	
}
