#ifndef peminjam_H
#define peminjam_H
#include <stdio.h>

typedef struct{
 char Nama[50];
 char NIM[50];
 char Departemen[20];
 char Fakultas[20];
 char NoHP[13];
 char Alamat[100];
}Peminjam;

typedef struct{
    Peminjam T[50];
    int Neff;
}TabelPeminjam;

TabelPeminjam T;
void MakeAnggota(TabelPeminjam *T);
Peminjam makePeminjam (char Nama[50], char NIM[50], char Departemen[20], char Fakultas[20], char NoHP[12], char Alamat[100]);
void TambahPeminjam (TabelPeminjam *T);
void TulisPeminjamKe(TabelPeminjam T, int i);
void TulisAll(TabelPeminjam T);
void CariNama (TabelPeminjam T);
void CariNIM (TabelPeminjam T);
void CariDepartemen (TabelPeminjam T);
void CariFakultas (TabelPeminjam T);
void SetNIM (TabelPeminjam *T);
void SetNama (TabelPeminjam *T);
void SetDepartemen (TabelPeminjam *T);
void SetFakultas (TabelPeminjam *T);
void SetHp (TabelPeminjam *T);
void SetAlamat (TabelPeminjam *T);
void DelDatPem (TabelPeminjam *T);
#endif
