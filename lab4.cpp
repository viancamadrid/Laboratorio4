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
bool ataqueNormal(int***, int, int, int);
void ataqueWave(int, int, int***);

int main(int argc, char*argv[]){
	int*** c1;
	int*** c2;
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
		r1=rand()%(12);
		r2=rand()%(12);
		r3=rand()%(12);
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

void ataqueWave (int ataque, int num, int*** cubo){
	if(ataque==1){//ataque en xy
		for(int i=0; i<12; i++){
			for(int j=0; j<12; j++){
				if(cubo[i][j][num]==1){
					cout<<"Submarino en ("<<i<<","<<j<<","<<num<<") destruido"<<endl;
					cubo[i][j][num]=0;
				}else{
					cout<<"Nada que destruir"<<endl;
				}
			}
		}
	}else if(ataque==2){//ataque en xz
		for(int i=0; i<12; i++){
                        for(int j=0; j<12; j++){
                                if(cubo[i][num][j]==1){
                                        cout<<"Submarino en ("<<i<<","<<num<<","<<j<<") destruido"<<endl;
					cubo[i][num][j]=0;
                                }else{
                                        cout<<"Nada que destruir"<<endl;
                                }
                        }
                }
	}else{//ataque en yz
		for(int i=0; i<12; i++){
                        for(int j=0; j<12; j++){
                                if(cubo[num][i][j]==1){
                                        cout<<"Submarino en ("<<num<<","<<i<<","<<j<<") destruido"<<endl;
					cubo[num][i][j]=0;
                                }else{
                                        cout<<"Nada que destruir"<<endl;
                                }
                        }
                }

	}
	return;
}
