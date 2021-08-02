#include<stdio.h>
#include<stdlib.h>
#include "Header.h"

void playGame();
void fillSrc();
void displaylevel(int level);
void display();
void push(int x);
void HowToPlay();
void RuleOfGame();
void About();
int main();
int pop();
int gameWinCondition();

struct pole
{
    int stack[3];
};

struct pole p[3];

int top[3];

//Progam Utama
int main(){
	int mainmenuoption;
	printf("===========================================\n");
	printf(" 	WELCOME TO HANOI TOWER GAME		     	\n");
	printf("===========================================\n");
	printf("[1] Play Game\n");
	printf("[2] How To Play\n");
	printf("[3] Rule of Game\n");
	printf("[4] About\n");
	printf("[5] Exit\n");
	printf("===========================================\n");
	printf("Enter a number : "); scanf("%d", &mainmenuoption);
	
	//Kondisi saat memilih pilihan menu
	if(mainmenuoption == 1){
		playGame(); //Mulai permainan
	}else if(mainmenuoption == 2){
		HowToPlay(); //Masuk ke help
	}else if(mainmenuoption == 3){
		RuleOfGame(); //Masuk ke Rule of game
	}else if(mainmenuoption == 4){
		About(); //Masuk ke about
	}else{
		
	}
	
	return 0;
}
 
void playGame()
{
	system("cls");
    top[2] = top [1] = -1;
    int win = 0;
    int x;
    fillSrc();
    display();
    printf("Tower of Hanoi\n");
    while(win != 1) {
        x = pop();
        push(x);
        win = gameWinCondition();
        display();
    }
    printf("Congratulations, you win!\n");
}

//fill the source pole according to the number of disks
void fillSrc()
{
    p[0].stack[0] = 3;
    p[0].stack[1] = 2;
    p[0].stack[2] = 1;
    top[0] = 2;
}


//push to stack 
void push(int x)
{
	int pl; 
    chooseWhereToPush:
    printf("Choose pole to push to: ");
    scanf("%d", &pl);
    printf("\n");
    if(p[pl].stack[top[pl]] > x || p[pl].stack[top[pl]]==0) { 
        top[pl]++;
        p[pl].stack[top[pl]] = x;
    }
    else {
        printf("Cannot push here. Try again.\n");
        goto chooseWhereToPush;
    }
}

int pop() {
    int pl, x;
    chooseWhereToPop:
    printf("Choose pole to pop from: ");
    scanf("%d", &pl);
    printf("\n");
    if(p[pl].stack[top[pl]] == -1) {
        printf("Pole empty, cannot pop. Try again.\n");
        goto chooseWhereToPop;
    }
    
    x = p[pl].stack[top[pl]];
    p[pl].stack[top[pl]] = 135;
    top[pl]--;
    return x;
}

//printing a single level (function is called by display())
void displaylevel(int level)
{
    int i;
    for(i=0; i<3; i++)
    {
        if(p[i].stack[level] == 135 || p[i].stack[level] == 0) {
        	printf("[ ]\t");
        }
        else {
        	printf("[%d]\t",p[i].stack[level]);
        }
    }
    printf("\n");         
}    

//printing the stacks by calling displaylevel()
void display()
{
    
    int i;
    for(i=2; i>=0; i--)
    {
        displaylevel(i);
    }
}    


int gameWinCondition() {
    if(p[2].stack[0]==3 && p[2].stack[1]==2 && p[2].stack[2]==1) {
        return;
    }
    else {
        return 0;
    }
}

//Printing How To Play
void HowToPlay(){
	system("cls");
		printf("====================== How To Play ======================\n");
		printf("[1] Permainan ini terdiri dari tiga tiang dan sejumlah\n");
		printf("    cakram 3 cakram dengan ukuran yang berbeda-beda yang\n");
		printf("    dapat dimasukan ke tiang mana saja.\n");
		printf("[2] Permainan dimulai dengan cakram-cakram yang tertumpuk\n");
		printf("    berurutan berdasarkan ukuran dalam tiang yang paling\n");
		printf("    kiri, cakram terbesar diletakkan terbawah dan cakram\n");
		printf("    terkecil diletakkan teratas, sehingga membentuk\n");
		printf("    kerucut.\n");
		printf("[3] Pemain harus memindahkan cakram ke tiang lain, baik\n");
		printf("    tiang tengah atau tiang kanan, sampai susunan cakram\n");
		printf("    tersusun di tiang lain.\n\n");
		printf("==========================================================\n");
		
		int HelpOption;
	
	printf("\n");
	printf("[1] Kembali\n");
	printf("[2] Keluar\n");
	
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &HelpOption);
		
		switch(HelpOption){
			case 1:
				system("cls");
				main();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while(HelpOption < 1 || HelpOption > 2);
}

//printing rule of game
void RuleOfGame(){
	system("cls");
		printf("========================= Rule Of Game ==================================\n");
		printf(" [1] Hanya satu cakram yang boleh dipindahkan dalam satu waktu.\n");
		printf(" [2] Setiap perpindahan berupa pengambilan cakram teratas dari satu tiang\n");
		printf("     dan memasukannya ke tiang lain, di atas cakram lain yang mungkin sudah\n");
		printf("     ada di tiang tersebut.\n");
		printf(" [3] Tidak boleh meletakan cakram di atas cakram lain yang lebih kecil.\n\n");
		printf("=========================================================================\n");
		
		
		int HelpOption;
	
	printf("\n");
	printf("[1] Kembali\n");
	printf("[2] Keluar\n");
	
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &HelpOption);
		
		switch(HelpOption){
			case 1:
				system("cls");
				main();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while(HelpOption < 1 || HelpOption > 2);
}
		
//Printing About
void About(){
	system("cls");
		printf("=========================== About ============================\n");
		printf("Permainan ini ditujukan untuk memenuhi Tugas Besar mata kuliah\n"); 
		printf("Struktur Data Algoritma dan dibuat dengan menggunakan bahasa C\n\n");
		printf("Author : \n");
		printf("[1] Kiki Rizki Amelia (201524048)\n");
		printf("[2] Rusyda Jasmine Rachmat (201524059)\n");
		printf("================================================================\n");
		
		
		int HelpOption;
	
	printf("\n");
	printf("[1] Kembali\n");
	printf("[2] Keluar\n");
	
	do{
		printf("Masukkan pilihan : ");
		scanf("%d", &HelpOption);
		
		switch(HelpOption){
			case 1:
				system("cls");
				main();
				break;
			case 2:
				exit(0);
				break;
			default:
				printf("Maaf, masukan Anda tidak valid. Silahkan coba lagi");
		}
	}while(HelpOption < 1 || HelpOption > 2);
}
