#include <iostream>
#include <cstdlib>

using std::cout;
using std::cin;
using std::endl;

int main(int argc, char*argv[]){
		
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
