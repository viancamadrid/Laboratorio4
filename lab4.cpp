#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int*** crearCubo();
void eliminarCubo(int***);
void llenarCubo(int***);
void Expensive(int***,int,int,int);
int Menu(int, int);
void Posiciones(int***);
bool Ganador(int***,int***);
int validacionVariable();
bool ataqueNormal(int***, int, int, int);
void ataqueWave(int, int, int***);
int contadorSubmarinos(int***);

int main(int argc, char*argv[]){
	bool ganador=false;
        int wave1=3, expansive1=3;
	int wave2=3, expansive2=3;
        int x,y,z;
	//creacion de los dos cubos
	int jugadorCont=1;
	int*** cubo1;
	int*** cubo2;
	cubo1=crearCubo();
	cubo2=crearCubo();
	llenarCubo(cubo1);
	llenarCubo(cubo2);
	int iterador=0;
	while(ganador==false){
		cout<<endl;
		if(iterador%2==0){
			cout<<"----------------------------------------Mapa de submarinos de Player 1--------------------------------"<<endl;
			cout<<"El numero de submarinos a destruir es:"<<contadorSubmarinos(cubo2)<<endl;
			Posiciones(cubo1);
			int menu = Menu(wave1, expansive1);
	                if(menu == 1){
        	                cout<< "X: ";
                	        x=validacionVariable();
                       		cout<< "Y: ";
                        	y=validacionVariable();
                        	cout<< "Z: ";
                        	z=validacionVariable();
				bool boom=ataqueNormal(cubo2,x,y,z);
				if(boom){
					cout<<"Submarino Destruido en ("<<x<<","<<y<<","<<z<<")"<<endl;
				}else{
					cout<<"Nada que Destruir"<<endl;
				}
               		}	
                	if((menu >1) && (menu < 5)){
				wave1--;
				int coor;
                        	if(menu==2){
					cout<<"Z: ";
					cin>>coor;
					ataqueWave(2,coor,cubo2); 
				}else if(menu==3){
					cout<<"Y: ";
                                        cin>>coor;
                                        ataqueWave(3,coor,cubo2);
				}else{
					cout<<"X: ";
                                        cin>>coor;
                                        ataqueWave(4,coor,cubo2);
				}
                	}
                	if(menu == 5){
				expansive1--;
				bool expa=false;
				while(expa==false){
					cout<< "X: ";
                                	cin>>x;
                                	cout<< "Y: ";
                                	cin>>y;
                                	cout<< "Z: ";
                                	cin>>z;
					if((x>=1&&x<=10)&&(y>=1&&y<=10)&&(z>=1&&z<=10)){
						expa=true;
						Expensive(cubo2,x,y,z);
					}else{
						cout<<"Posicion que ingreso no se puede hacer expansive"<<endl;
					}
				}
                	}
			
		}else{
			cout<<"----------------------------------------Mapa de submarinos de Player 2--------------------------------"<<endl;
			cout<<"El numero de submarinos a destruir es:"<<contadorSubmarinos(cubo1)<<endl;
			Posiciones(cubo2);
			int menu = Menu(wave2, expansive2);
			if(menu == 1){
				cout<< "X: ";
				cin>>x;	
				cout<< "Y: ";
				cin>>y;
				cout<< "Z: ";
				cin>>z;
				bool boom=ataqueNormal(cubo1,x,y,z);
                                if(boom){
                                        cout<<"Submarino Destruido en ("<<x<<","<<y<<","<<z<<")"<<endl;
                                }else{
                                        cout<<"Nada que Destruir"<<endl;
                                }

			}
			if((menu >1) && (menu < 5)){
				wave2--;
				int coor;
                                if(menu==2){
                                        cout<<"Z: ";
                                        cin>>coor;
                                        ataqueWave(2,coor,cubo1);
                                }else if(menu==3){
                                        cout<<"Y: ";
                                        cin>>coor;
                                        ataqueWave(3,coor,cubo1);
                                }else{
                                        cout<<"X: ";
                                        cin>>coor;
                                        ataqueWave(4,coor,cubo1);
                                }	
			}
			if(menu == 5){
				expansive2--;
				bool expa=false;
                                while(expa==false){
                                        cout<< "X: ";
                                        cin>>x;
                                        cout<< "Y: ";
                                        cin>>y;
                                        cout<< "Z: ";
                                        cin>>z;
                                        if((x>=1&&x<=10)&&(y>=1&&y<=10)&&(z>=1&&z<=10)){
                                                expa=true;
                                                Expensive(cubo1,x,y,z);
                                        }else{
                                                cout<<"Posicion que ingreso no se puede hacer expansive"<<endl;
                                        }
                             }
			}
		}
		iterador++;		
                ganador = Ganador(cubo1,cubo2);
	}
        if(contadorSubmarinos(cubo1)==0){
                cout<< "Jugador 1 GANADOR!";                                     
        }else{
                cout<< "Jugador 2 GANADOR!";
        }
	//parte de delete
        eliminarCubo(cubo1);
        eliminarCubo(cubo2);
        //fin delete
	return 0;
}

int validacionVariable(){
	int variable;
	cin >>variable;
	while(!((variable<12)&&(variable>=0))){
		cout << "Error, el numero debe estar entre el rango (0 - 11): ";
		cin >> variable;
	}
	return variable;
}

void Posiciones(int*** cubo){// Aqui lee el cubo e imprime las posiciones
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

int contadorSubmarinos (int*** cubo){// funcion que cuenta el numero de submarinos
        int contador=0;
	for(int i=0; i<12; i++){
                for(int j=0; j<12; j++){
                        for(int k=0; k<12; k++){
                                if(cubo[i][j][k]==1){
                                        contador++;
                                }
                        }
                }
        }
	return contador;
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
	cout<< "Ingrese su respuesta: "<<endl;
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
	return;
} 

void Expensive(int*** cubo,int x,int y,int z){
	for(int i=x-1;i<x+2;i++){
		for(int j=y-1;j<y+2;j++){
			for(int k=z-1;k<z+2;++k){
				if(cubo[i][j][k]==1){
					cubo[i][j][k]=0;
					cout<<"Submarino en {"<<i<<","<<j<<","<<k<<"} destruido"<<endl;
				}else{
					cout<<"Nada que destruir"<<endl;
				}
			}
		}
	}
	return;
}
//fin funcion para eliminar el cubo

bool Ganador(int*** cubo1,int*** cubo2){//Funcion que valida si hubo un ganador.
	bool ganador = true;
	for(int i=0; i<12; i++){
                for(int j=0; j<12; j++){
                        for(int k=0; k<12; k++){
                                if(cubo1[i][j][k]== 1){
                                        ganador = false;
                                }
                        }
                }
        }
	for(int i=0; i<12; i++){
                for(int j=0; j<12; j++){
                        for(int k=0; k<12; k++){
                                if(cubo2[i][j][k]== 1){
                                        ganador = false;
                                }
                        }
                }
        }

	return ganador;		
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
	if(ataque==2){//ataque en xy
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
	}else if(ataque==3){//ataque en xz
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


