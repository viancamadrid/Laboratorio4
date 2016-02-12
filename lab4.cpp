#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int*** crearCubo();
void eliminarCubo(int***);
void llenarCubo(int***);
int Menu(int, int);
void Posiciones(int***);

int main(int argc, char*argv[]){
	bool ganador=false;
	int wave=3, expansive=3;
	int x,y,z;
	
	while(ganador==false){
		int menu = Menu(wave, expansive);
		if(menu == 1){
			cout<< "X: ";
			cin>>x;	
			cout<< "Y: ";
			cin>>y;
			cout<< "Z: ";
			cin>>z;
		}
		if((menu >1) && (menu < 5)){
			wave--;	
		}
		if(menu == 5){
			expansive--;
		}
		
							
	}
	return 0;
}

void Posiciones(int*** cubo){// Aqui lee el cubo e imprime las posiciones
	cout<< "--------------------MAPA DE SUBMARINOS-----------------------"<< endl;
        for(int i=0; i<12; i++){
                for(int j=0; j<12; j++){
                        for(int k=0; k<12; k++){
                                if(cubo[i][j][k]==1){
                                        cout << "("<<i<<", "<<j<<", "<< k<<")"<<endl;
                                }
                        }
                }
        }

}

int Menu(int wave,int expansive){	
	int menu;// aqui solamente lee e imprime el menu inicial
	cout<< "--------------------MENU DE ATAQUES-----------------------"<< endl;
	cout<< "1. Ataque Normal "<<endl;
	if(wave>0){
		cout<< "2. Ataque wave en XY";
		cout<< endl<< "3. Ataque wave en XZ";
		cout<< endl<< "4. Ataque wave en YZ";
	}
	if(wave>0){
		cout<< endl<< "5. Ataque Expansive"<< endl;
	}
	cout<< "WAVE DISPONIBLES: "<< wave << endl;
	cout<< "EXPANSIVE DISPONIBLES: "<< expansive << endl;
	cin >> menu;
	return menu;		
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


bool ataqueNormal (int*** cubo, int x, int y, int z){
	bool ataco=false;
	if(cubo[x][y][z]==1){
		ataco=true;
		return ataco;
	}
	else
		return ataco;
}


