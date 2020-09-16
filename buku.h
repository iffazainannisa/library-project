#ifndef buku_H
#define buku_H
#include <stdio.h>


typedef struct{
    int Rak;
    int Baris;
    int Kolom;
}Posisi;

typedef struct{
	char ISBN[50];
	char Judul[50];
	char Pengarang[50];
	char Penerbit[50];
	int Stock;
	Posisi Letak;
}Buku;

typedef struct{
    Buku T[50];
    int Neff;
}TabelBuku;

TabelBuku B;
void MakeBuku(TabelBuku *B);
void TulisBukuKe(TabelBuku B, int i);
void TulisSemua(TabelBuku B);
void TambahBuku(TabelBuku *B);
void CariISBN (TabelBuku B);
void CariJudul (TabelBuku B);
void CariPengarang (TabelBuku B);
void CariPenerbit (TabelBuku B);
void CariLetak (TabelBuku B);
void SetJudul(TabelBuku *B);
void SetPengarang(TabelBuku *B);
void SetPenerbit(TabelBuku *B);
void TambahStock (TabelBuku *B, int newST);
void KurangiStock (TabelBuku *B, int newST);
void TotalStockBuku (TabelBuku B);

#endif // buku_H
