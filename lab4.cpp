#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int*** crearCubo();
void eliminarCubo(int***);
void llenarCubo(int***);
void expensive(int***,int,int,int);

int main(int argc, char*argv[]){
	int*** cubo1;
	int*** cubo2;
	cout<<"paso1"<<endl;
	cubo1=crearCubo();
	cubo2=crearCubo();
	cout<<"paso2"<<endl;
	llenarCubo(cubo1);
	llenarCubo(cubo2);
	cout<<"paso3"<<endl;
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			for(int k=0;k<12;k++){
				cout<<cubo1[i][j][k]<<"-";
			}
			cout<<endl;
		}	
		cout<<endl;
	}
	//parte de delete
	eliminarCubo(cubo1);
	eliminarCubo(cubo2);	
	return 0;
}

void llenarCubo (int*** cubo){
	for(int i=0; i<12; i++){
		for (int j=0; j<12; j++){
			for (int k=0; k<12; k++){
				cubo[i][j][k]=0;
			}
		}
	}
	int r1, r2, r3;
	srand(time(NULL));
	for (int i=0; i<15; i++){
		r1=1+rand()%(13-1);
		r2=1+rand()%(13-1);
		r3=1+rand()%(13-1);
		cubo[r1][r2][r3]=1;	
	}
	return;
}


//funcion para crear el cubo
int*** crearCubo(){
	int*** cubo= new int**[12];
	for(int i=0;i<12;i++){
		cubo[i]= new int*[12];
	}
	for(int i=0;i<12;i++){
		for(int j=0;j<12;j++){
			cubo[i][j]= new int[12];
		}	
	}
	return cubo;
}
//fin funcion para crear el cubo

//funcion para eliminar el cubo
void eliminarCubo(int*** cubo){
	for(int i=0;i<12;i++){
                for(int j=0;j<12;j++){
                    	delete[] cubo[i][j];
                } 
        }
	for(int i=0;i<12;i++){
               	delete[] cubo[i];
        }
	delete[] cubo;
}
//fin funcion para eliminar el cubo 

void expansive(int*** cubo,int x,int y,int z){
	for(int i=x-1;i<x+2;i++){
		for(int j=y-1;j<+2;j++){
			for(int k=z-1;k<z+2;++k){
				if(cubo[i][j][k]==1){
					cubo[i][j][k]=0;
					cout<<"Submarino en {"<<x<<","<<y<<","<<z<<"} destruido"<<endl;
				}else{
					cout<<"Nada que destruir"<<endl;
				}
			}
		}
	}
}
