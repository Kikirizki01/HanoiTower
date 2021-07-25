#include "Header.h"
#include <stdio.h>
#include <stdlib.h>

int main(){
	system("cls");
	Stack S;
	
	int option;
	
	do{
		puts("Menu Utama");
		puts("[1] Play Game");
		puts("[2] How To Play");
		puts("[3] About");
		puts("[4] Exit");
		
		printf("Pilihan : "); scanf("%d", &option);
		
		if(option == 1){
			main();
		}else if(option == 2){
			HowToPlay();
		}else if(option == 3)
			About();
		}else if(option == 4){
			exit(0);
		}else{
			printf("Maaf, yang Anda masukkan salah. Silahkan coba lagi.");
		}
		
	}while(option != 4);
	
	return 0;
}
