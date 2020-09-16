#ifndef peminjaman_H
#define peminjaman_H
#include <stdio.h>
#include "tanggal.h"
#include "buku.h"
#include "peminjam.h"

int Neff3;
typedef struct{
    int Nomor;
    char Nama[50];
    char NIM[50];
    char ISBN[50];
    char Judul[50];
    Tanggal Mulai;
    Tanggal Akhir;
    Tanggal Kembali;
    int Denda;
    char Status;
    }Peminjaman;

typedef struct{
    Peminjaman T[50];
    int Neff;
    }TabelPeminjaman;

TabelPeminjaman M;

void MakeTransaksi(TabelPeminjaman *M);
int iNIM(TabelPeminjam T, char nama[50]);
void GetNama(TabelPeminjam T, int N);
int iISBN(TabelBuku B, char isbn[50]);
void GetJudul(TabelBuku B, int N);
void TambahPeminjaman (TabelPeminjaman *M);
Peminjaman MakePeminjaman (int No, char NIM[50], char Nama[50], char ISBN[50], char Judul[50], Tanggal U);

#endif
