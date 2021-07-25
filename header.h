#define stack_H
#include <stdio.h>
#include "boolean.h"
#define Nil 0 /* Nil adalah stack dengan elemen kosong */
#define MaxEl 10
typedef int infotype;
typedef int address;

/* indeks tabel */
/* Versi I : dengan menyimpan tabel dan alamat top secara eksplisit */
typedef struct { 
	infotype T[MaxEl+1]; /* tabel penyimpan elemen */
	address TOP;
/* alamat TOP: elemen puncak */
} Stack;


void FillSrc(Stack *S);
/* T.S. sembarang; */
/* F.S. Membuat sebuah stack S yang kosonq berkapasitas MaxEl */
/* jadi indeksnya antara 1.. MaxEl+l karena O tidak dipakai */
/* Ciri stack kosong : TOP bernilai Nil */
/*********** Predikat Untuk test keadaan KOLEKSI **/
boolean IsEmpty (Stack S);
/* Mengirim true jika Stack kosong: lihat definisi di atas */
boolean IsFull(Stack S);
/* Mengirim true jika tabel penampung nilai elemen stack penuh */
/*********** Menambahkan sebuah elemen ke Stack **********/
void Push (Stack *S, infotypeStack X);
/* Menambahkan X sebagai elemen Stack S. */
/* T.S. S mungkin kosong, tabel penampung elemen stack TTDAK penuh */
/* F.S. X menjadi TOP yang baru,TOP bertambah 1 */
/*********** Menqhapus sebuah elemen Stack **********/
void Pop (Stack *S, infotypeStack *X);
/* Menghapus X dari Stack S. */
/* T.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen TOP yang lama, TOP berkurang l */
void displaylevel(int level);
/* Menampilan level X dari Stack S. */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen level */
void display();
/* Menampilan function displaylevel yang telah dipanggil */
/* I.S. S tidak mungkin kosong */
/* F.S. X adalah nilai elemen level */
int gameWinCondition();
/* T.S. S tidak mungkin kosong
/* F.S. menampilkan kondisi akhir permainan*/

#endif
