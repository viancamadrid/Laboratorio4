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

int main(int argc, char*argv[]){
	bool ganador=false;
        int wave=3, expansive=3;
        int x,y,z;
	
	//creacion de los dos cubos
	int*** cubo1;
	int*** cubo2;
	cubo1=crearCubo();
	cubo2=crearCubo();
	llenarCubo(cubo1);
	llenarCubo(cubo2);
	int iterador=0;
	while(ganador==false){
		if(iterador%2==0){
			cout<<"----------------------------------------Mapa de submarinos de Player 1--------------------------------"<<endl;
			Posiciones(cubo1);
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
                        	expansive--;
                	}

		}else{
			cout<<"----------------------------------------Mapa de submarinos de Player 2--------------------------------"<<endl;
			Posiciones(cubo2);
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
				expansive--;
			}
		}
		iterador++;	
		ganador=true;				
	}
	//parte de delete
        eliminarCubo(cubo1);
        eliminarCubo(cubo2);
        //fin delete
	return 0;
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
