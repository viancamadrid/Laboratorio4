#include <iostream>

using std::cout;
using std::cin;
using std::endl;
int*** crearCubo();
void eliminarCubo(int***);

int main(int argc, char*argv[]){

	return 0;
}

//funcion para crear el cubo
int*** crearcubo(){
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
