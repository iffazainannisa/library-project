#ifndef tanggal_H
#define tanggal_H
#include "boolean.h"


#define Day(T) (T).DD
#define Month(T) (T).MM
#define Year(T) (T).YY

typedef struct
{
  int DD;
  int MM;
  int YY;
}Tanggal;

void SetDay(Tanggal *T,int D);
void SetMonth (Tanggal *T, int M);
void SetYear (Tanggal *T, int Y);
Tanggal MakeTanggal (int D, int M, int Y);
void BacaTanggal (Tanggal *T);
void TulisTanggal (Tanggal T);
boolean IsTanggalValid (int D, int M, int Y);
boolean IsKabisat (int Y);
int TanggalKeHari (Tanggal T);
Tanggal HariKeTanggal (int H, int Y);
boolean IsEqT (Tanggal T1, Tanggal T2);
boolean IsBeforeT (Tanggal T1, Tanggal T2);
boolean IsAfterT (Tanggal T1, Tanggal T2);
int BerapaHari (Tanggal T1, Tanggal T2);
Tanggal NextDay (Tanggal T);
Tanggal NextNDay (Tanggal T, int N);
Tanggal PrevDay (Tanggal T);
Tanggal PrevNDay (Tanggal T, int N);
Tanggal sekarang();


#endif
