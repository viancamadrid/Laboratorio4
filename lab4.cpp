#include <iostream>

using std::cout;
using std::cin;
using std::endl;

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


