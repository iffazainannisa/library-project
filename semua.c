#include<stdio.h>
#include<stdlib.h>
#include <time.h>
#include<string.h>
#include "buku.h"
#include "peminjam.h"
#include "peminjaman.h"
#include "tanggal.h"

/*TANGGAL*/

void SetDay(Tanggal *T,int D)
{
     (*T).DD=D;
}
void SetMonth(Tanggal *T,int M)
{
     (*T).MM=M;
}
void SetYear(Tanggal *T,int Y)
{
     (*T).YY=Y;
}

boolean IsKabisat (int Y){
  if (Y%400==0) return TRUE;
  else{
    if (Y%100==0) return FALSE;
    else{
      if (Y%4==0) return TRUE;
      else return FALSE;
    }
  }
}

boolean IsTanggalValid (int D, int M, int Y){
  if (D>=1 && D<=31 && (M==1||M==3||M==5||M==7||M==8||M==10||M==12) && Y>=1) return TRUE;
  else if (D>=1 && D<=30 && (M==4||M==6||M==9||M==11) && Y>=1) return TRUE;
  else if (D>=1 && D<=29 &&  M==2 && IsKabisat(Y)) return TRUE;
  else if (D>=1 && D<=28 && M==2 && !IsKabisat(Y)) return TRUE;
  else return FALSE;
}

Tanggal MakeTanggal (int D, int M, int Y){
  Tanggal T;
        SetDay(&T,D);
        SetMonth(&T,M);
        SetYear(&T,Y);
        return T;
}

void BacaTanggal (Tanggal *T){
  int D, M, Y, i;
  i=0;
  while (i==0)
    {
        printf("Masukkan Tanggal dengan format d m y (pisah dengan spasi) : ");
        scanf("%d %d %d", &D, &M, &Y);
        if(IsTanggalValid(D, M, Y))
        {
            *T = MakeTanggal(D, M, Y);
            TulisTanggal(*T);
            i++;
        }
        else
        {
            printf("inputan tanggal salah, coba lagi");
        }
    }
}

void TulisTanggal (Tanggal T){
  printf("%2d-%2d-%4d\n",T.DD,T.MM,T.YY);
}

int TanggalKeHari (Tanggal T){
  int D, i;
  i = Month(T);
  D=0;
  switch(i){
  case 1:
      D = 1 + (Day(T)-1);
      break;
  case 2:
      D = 32 + (Day(T)-1);
      break;
  case 3:
      D = 60 + (Day(T)-1);
      break;
  case 4:
      D = 91 + (Day(T)-1);
      break;
  case 5:
      D = 121 + (Day(T)-1);
      break;
  case 6:
      D = 152 + (Day(T)-1);
      break;
  case 7:
      D = 182 + (Day(T)-1);
      break;
  case 8:
      D = 213 + (Day(T)-1);
      break;
  case 9:
      D = 244 + (Day(T)-1);
      break;
  case 10:
      D = 274 + (Day(T)-1);
      break;
  case 11:
      D = 305 + (Day(T)-1);
      break;
  case 12:
      D = 335 + (Day(T)-1);
      break;
  }
  if(IsKabisat(Year(T)) && Month(T)>2) D = D+1;
  return D;
}

Tanggal HariKeTanggal (int H, int Y){
  Tanggal T;
  if (H>=1 && H<=366){
    if (IsKabisat(Y)){
      if(H<=31){
        Day(T)=H; Month(T)=1; Year(T)=Y;
      }
      else if(H>31 && H<=60){
        Day(T)=H-31; Month(T)=2; Year(T)=Y;
      }
      else if(H>60 && H<=91){
        Day(T)=H-60; Month(T)=3; Year(T)=Y;
      }
      else if(H>91 && H<=121){
        Day(T)=H-91; Month(T)=4; Year(T)=Y;
      }
      else if(H>121 && H<=152){
        Day(T)=H-121; Month(T)=5; Year(T)=Y;
      }
      else if(H>152 && H<=182){
        Day(T)=H-152; Month(T)=6; Year(T)=Y;
      }
      else if(H>182 && H<=213){
        Day(T)=H-182; Month(T)=7; Year(T)=Y;
      }
      else if(H>213 && H<=244){
        Day(T)=H-213; Month(T)=8; Year(T)=Y;
      }
      else if(H>244 && H<=274){
        Day(T)=H-244; Month(T)=9; Year(T)=Y;
      }
      else if(H>274 && H<=305){
        Day(T)=H-274; Month(T)=10; Year(T)=Y;
      }
      else if(H>305 && H<=335){
        Day(T)=H-305; Month(T)=11; Year(T)=Y;
      }
      else {
        Day(T)=H-335; Month(T)=12; Year(T)=Y;
      }
    }
    else{
      if(H<=31){
        Day(T)=H; Month(T)=1; Year(T)=Y;
      }
      else if(H>31 && H<=59){
        Day(T)=H-31; Month(T)=2; Year(T)=Y;
      }
      else if(H>59 && H<=90){
        Day(T)=H-59; Month(T)=3; Year(T)=Y;
      }
      else if(H>90 && H<=120){
        Day(T)=H-90; Month(T)=4; Year(T)=Y;
      }
      else if(H>120 && H<=151){
        Day(T)=H-120; Month(T)=5; Year(T)=Y;
      }
      else if(H>151 && H<=181){
        Day(T)=H-151; Month(T)=6; Year(T)=Y;
      }
      else if(H>181 && H<=212){
        Day(T)=H-181; Month(T)=7; Year(T)=Y;
      }
      else if(H>212 && H<=243){
        Day(T)=H-212; Month(T)=8; Year(T)=Y;
      }
      else if(H>243 && H<=273){
        Day(T)=H-243; Month(T)=9; Year(T)=Y;
      }
      else if(H>273 && H<=304){
        Day(T)=H-273; Month(T)=10; Year(T)=Y;
      }
      else if(H>304 && H<=334){
        Day(T)=H-304; Month(T)=11; Year(T)=Y;
      }
      else if(H>334 && H<=365){
        Day(T)=H-334; Month(T)=12; Year(T)=Y;
      }
      else {
        Day(T)=0; Month(T)=0; Year(T)=0;
      }
    }
  }
  else{
    Day(T)=0;
    Month(T)=0;
    Year(T)=0;
    }
  return T;
}

boolean IsEqT (Tanggal T1, Tanggal T2){
  return(Day(T1)==Day(T2) && Month(T1)==Month(T2) && Year(T1)==Year(T2));
}

boolean IsBeforeT (Tanggal T1, Tanggal T2){
  if (Year(T1)<Year(T2)) return TRUE;
  else if (Year(T1)==Year(T2) && Month(T1)<Month(T2)) return TRUE;
  else if (Year(T1)==Year(T2) && Month(T1)==Month(T2) && Day(T1)<Day(T2)) return TRUE;
  else return FALSE;
}

boolean IsAfterT (Tanggal T1, Tanggal T2){
  if (Year(T1)>Year(T2)) return TRUE;
  else if (Year(T1)==Year(T2) && Month(T1)>Month(T2)) return TRUE;
  else if (Year(T1)==Year(T2) && Month(T1)==Month(T2) && Day(T1)>Day(T2)) return TRUE;
  else return FALSE;
}

int BerapaHari (Tanggal T1, Tanggal T2){
  int i, J;
  J=0;
  if(IsEqT(T1, T2)){
    return 0;
  }
  else if(IsBeforeT(T1, T2)){
    if(Year(T1)==Year(T2)){
      return TanggalKeHari(T2)-TanggalKeHari(T1);
    }
    else{
      if(IsKabisat(Year(T1))){
        J=366-TanggalKeHari(T1);
      }
      else{
        J=365-TanggalKeHari(T1);
      }
      for(i=Year(T1)+1;i<Year(T2);i++){
        if(IsKabisat(i)){
          J=J+366;
        }
        else{
          J=J+365;
        }
      }
      J=J+TanggalKeHari(T2);
      return J;
    }
  }
  else{
    return -999;
  }
}

Tanggal NextDay (Tanggal T){
  if (Day(T)==31 && (Month(T)==1 || Month(T)==3 || Month(T)==5 || Month(T)==7 || Month(T)==8 || Month(T)==10)){
    Day(T)=1;
    Month(T)=Month(T)+1;
  }
  else if (Day(T)==30 && (Month(T)==4 || Month(T)==6 || Month(T)==9 || Month(T)==11)){
    Day(T)=1;
    Month(T)=Month(T)+1;
  }
  else if (Day(T)==29 && Month(T)==2 && IsKabisat(Year(T))){
    Day(T)=1;
    Month(T)=3;
  }
  else if (Day(T)==28 && Month(T)==2 && !IsKabisat(Year(T))){
    Day(T)=1;
    Month(T)=3;
  }
  else if (Day(T)==31 && Month(T)==12){
    Day(T)=1;
    Month(T)=1;
    Year(T)=Year(T)+1;
  }
  else{
    Day(T)=Day(T)+1;
  }
  return T;
}

Tanggal NextNDay (Tanggal T, int N){
  int H;
  H = TanggalKeHari(T) + N;
  while(H>366){
    if(IsKabisat(Year(T))){
      H = H-366;
    }
    else{
      H = H-365;
    }
    Year(T)=Year(T)+1;
  }
  if (H==366 && !IsKabisat(Year(T))){
    Day(T)=1;
    Month(T)=1;
    Year(T)=Year(T)+1;
  }
  else{
    T = HariKeTanggal(H, Year(T));
  }
  return T;
}

Tanggal PrevDay (Tanggal T){
  if (Day(T)==1 && (Month(T)==2 || Month(T)==4 || Month(T)==6 || Month(T)==8 || Month(T)==9 || Month(T)==11)){
    Day(T)=31;
    Month(T)=Month(T)-1;
  }
  else if (Day(T)==1 && (Month(T)==5 || Month(T)==7 || Month(T)==10 || Month(T)==12)){
    Day(T)=30;
    Month(T)=Month(T)-1;
  }
  else if (Day(T)==1 && Month(T)==3 && IsKabisat(Year(T))){
    Day(T)=29;
    Month(T)=2;
  }
  else if (Day(T)==1 && Month(T)==3 && !IsKabisat(Year(T))){
    Day(T)=28;
    Month(T)=2;
  }
  else if (Day(T)==1 && Month(T)==1){
    Day(T)=31;
    Month(T)=12;
    Year(T)=Year(T)-1;
  }
  else{
    Day(T)=Day(T)-1;
  }
  return T;
}

Tanggal PrevNDay (Tanggal T, int N){
  int H;
  H = TanggalKeHari(T) - N;
  while(H<0){
    if(IsKabisat(Year(T)-1)){
      H = H+366;
    }
    else{
      H = H+365;
    }
    Year(T)=Year(T)-1;
  }
  if (H==0){
    Day(T)=31;
    Month(T)=12;
    Year(T)=Year(T)-1;
  }
  else{
    T = HariKeTanggal(H, Year(T));
  }
  return T;
}

Tanggal Sekarang()
    {
        Tanggal T;
        struct tm *Sys_T;
        time_t Tval;
        Tval = time(NULL);
        Sys_T = localtime(&Tval);

        T.DD = Sys_T->tm_mday;
        T.MM = Sys_T->tm_mon+1;
        T.YY = 1900+Sys_T->tm_year;

        return T;
    }


/*BUKU*/

void MakeBuku(TabelBuku *B){
    //BUKU 1
    strcpy((*B).T[1].ISBN, "1234");
    strcpy((*B).T[1].Judul, "STRUKTUR DATA");
    strcpy((*B).T[1].Pengarang, "SOEKARNO");
    strcpy((*B).T[1].Penerbit, "IFJAYA");
    (*B).T[1].Stock = 3;
    (*B).T[1].Letak.Rak = 1;
    (*B).T[1].Letak.Baris = 1;
    (*B).T[1].Letak.Kolom = 1;
    //BUKU 2
    strcpy((*B).T[2].ISBN, "5678");
    strcpy((*B).T[2].Judul, "ALGORITMA PEMROGRAMAN");
    strcpy((*B).T[2].Pengarang, "SOEKARNO");
    strcpy((*B).T[2].Penerbit, "UNDIPJAYA");
    (*B).T[2].Stock = 4;
    (*B).T[2].Letak.Rak = 1;
    (*B).T[2].Letak.Baris = 1;
    (*B).T[2].Letak.Kolom = 2;
    //BUKU 3
    strcpy((*B).T[3].ISBN, "4321");
    strcpy((*B).T[3].Judul, "DASAR PEMROGRAMAN");
    strcpy((*B).T[3].Pengarang, "SOEHARTO");
    strcpy((*B).T[3].Penerbit, "JAWAPOS");
    (*B).T[3].Stock = 2;
    (*B).T[3].Letak.Rak = 1;
    (*B).T[3].Letak.Baris = 2;
    (*B).T[3].Letak.Kolom = 1;
    //BUKU 4
    strcpy((*B).T[4].ISBN, "7432");
    strcpy((*B).T[4].Judul, "BASIS DATA");
    strcpy((*B).T[4].Pengarang, "MEGAWATI");
    strcpy((*B).T[4].Penerbit, "GRAMEDIA");
    (*B).T[4].Stock = 1;
    (*B).T[4].Letak.Rak = 1;
    (*B).T[4].Letak.Baris = 2;
    (*B).T[4].Letak.Kolom = 2;
    //BUKU 5
    strcpy((*B).T[5].ISBN, "8742");
    strcpy((*B).T[5].Judul, "PANCASILA");
    strcpy((*B).T[5].Pengarang, "JOKOWI");
    strcpy((*B).T[5].Penerbit, "TOTEM");
    (*B).T[5].Stock = 5;
    (*B).T[5].Letak.Rak = 2;
    (*B).T[5].Letak.Baris = 1;
    (*B).T[5].Letak.Kolom = 1;
}

void TulisBukuKe(TabelBuku B, int i){
    printf("--------------------------------------------------\n");
    printf("Data Buku Ke-%d \n", i);
    printf("--------------------------------------------------\n");
    printf("\nISBN Buku \t= %s \n", B.T[i].ISBN);
    printf("\nJudul Buku \t= %s \n", B.T[i].Judul);
    printf("\nPengarang Buku \t= %s \n", B.T[i].Pengarang);
    printf("\nPenerbit Buku \t= %s \n", B.T[i].Penerbit);
    printf("\nStock Buku \t= %d \n", B.T[i].Stock);
    printf("\nLetak Buku (Rak, baris, kolom) = (%d, %d, %d) \n", B.T[i].Letak.Rak, B.T[i].Letak.Baris, B.T[i].Letak.Kolom);
}

void TulisSemua(TabelBuku B){
    int j;
    for (j=1; j<=(B.Neff); j++){
        TulisBukuKe(B,j);
    }
}

void TambahBuku(TabelBuku *B){
    int j;
    (*B).Neff=(*B).Neff + 1;
    printf("Data Buku Ke-%d \n", (*B).Neff);
    printf("--------------------------------------------------\n");
    printf("Masukkan ISBN \t\t: ");
    scanf("%s",&((*B).T[(*B).Neff].ISBN));
    printf("\n");
    for(j=1;j<(*B).Neff;j++){
        if (!(strcmp((*B).T[j].ISBN,(*B).T[(*B).Neff].ISBN))){
        printf("ISBN Tidak Valid \n");
        printf("Masukkan ISBN \t\t: ");
        scanf("%s",&((*B).T[(*B).Neff].ISBN));
        printf("\n");
        }
    }
    fgets ((*B).T[(*B).Neff].Judul, 100, stdin);
    printf("Masukkan judul \t\t: ");
    scanf("%[^\n]s",&(*B).T[(*B).Neff].Judul);
    printf("\n");
    fgets ((*B).T[(*B).Neff].Pengarang, 100, stdin);
    printf("Masukkan pengarang \t: ");
    scanf("%[^\n]s",&((*B).T[(*B).Neff].Pengarang));
    printf("\n");
    fgets ((*B).T[(*B).Neff].Penerbit, 100, stdin);
    printf("Masukkan penerbit \t: ");
    scanf("%[^\n]s",&((*B).T[(*B).Neff].Penerbit));
    printf("\n");
    printf("Masukkan stock \t\t: ");
    scanf(" %d", &((*B).T[(*B).Neff].Stock));
    printf("\n");
    printf("Masukkan nomor rak \t: ");
    scanf(" %d", &((*B).T[(*B).Neff].Letak.Rak));
    printf("\n");
    if (((*B).T[(*B).Neff].Letak.Rak)<0 || ((*B).T[(*B).Neff].Letak.Rak) > 20){
        printf("No. rak tidak ada \n");
        printf("Masukkan nomor rak \t: ");
        scanf(" %d", &((*B).T[(*B).Neff].Letak.Rak));
        printf("\n");
    }
    printf("Masukkan nomor baris \t: ");
    scanf(" %d", &((*B).T[(*B).Neff].Letak.Baris));
    printf("\n");
    if (((*B).T[(*B).Neff].Letak.Baris)<0 || ((*B).T[(*B).Neff].Letak.Baris) > 6){
        printf("No. baris tidak ada \n");
        printf("Masukkan nomor baris \t: ");
        scanf(" %d", &((*B).T[(*B).Neff].Letak.Baris));
        printf("\n");
    }
    printf("Masukkan nomor kolom \t: ");
    scanf(" %d", &((*B).T[(*B).Neff].Letak.Kolom));
    printf("\n");
    if (((*B).T[(*B).Neff].Letak.Kolom)<0 || ((*B).T[(*B).Neff].Letak.Kolom) > 4){
        printf("No. kolom tidak ada \n");
        printf("Masukkan nomor kolom \t: ");
        scanf(" %d", &((*B).T[(*B).Neff].Letak.Kolom));
        printf("\n");
    }
}

//CARI BUKU
void CariISBN (TabelBuku B){
    char a[50];
    int i;
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=B.Neff;i++){
        if (!(strcmp(B.T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            printf("Buku yang dicari adalah : \n");
            TulisBukuKe(B,i);
          sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariJudul (TabelBuku B){
    char b[50];
    int i;
    int sum;
    sum = 0;
    fgets (B.T[0].Judul, 100, stdin);
    printf("Masukkan Judul : \n");
    scanf("%[\n]s",&b);
    strupr(b);
    gets(b);
    for(i=1;i<=B.Neff;i++){
        if (!(strcmpi(B.T[i].Judul, b))){
            printf("--------------------------------------------------\n");
            printf("Buku yang dicari adalah : \n");
            TulisBukuKe(B,i);
            sum = sum + 1;
        }
    }
    if (sum == 0){
        printf("\n");
        printf("notfound");
    }
}

void CariPengarang (TabelBuku B){
    char b[50];
    int i;
    int sum;
    sum = 0;
    fgets (B.T[0].Pengarang, 100, stdin);
    printf("Masukkan Pengarang: \n");
    scanf("%[^\n]s",&b);
    strupr (b);
    for(i=1;i<=B.Neff;i++){
        if (!(strcmpi(B.T[i].Pengarang, b))){
            printf("--------------------------------------------------\n");
            printf("Buku yang dicari adalah : \n");
            TulisBukuKe(B,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariPenerbit (TabelBuku B){
    char b[50];
    int i;
    int sum;
    sum = 0;
    fgets (B.T[0].Penerbit, 100, stdin);
    printf("Masukkan Penerbit: \n");
    scanf("%[^\n]s",&b);
    strupr (b);
    for(i=1;i<=B.Neff;i++){
        if (!(strcmpi(B.T[i].Penerbit, b))){
            printf("--------------------------------------------------\n");
            printf("Buku yang dicari adalah : \n");
            TulisBukuKe(B,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariLetak (TabelBuku B){
    int x, y, z;
    int i;
    int sum;
    sum = 0;
    printf("Masukkan nomor rak : \n");
    scanf("%d",&x);
    printf("Masukkan nomor baris : \n");
    scanf("%d",&y);
    printf("Masukkan nomor kolom : \n");
    scanf("%d",&z);
    for(i=1;i<=B.Neff;i++){
        if ((B.T[i].Letak.Rak == x)&&(B.T[i].Letak.Baris == y)&&(B.T[i].Letak.Kolom == z)){
            printf("--------------------------------------------------\n");
            printf("Buku yang dicari adalah : \n");
            TulisBukuKe(B,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

//EDIT BUKU
void SetISBN (TabelBuku *B){
    int i;
    char a[50];
    printf("Masukkan Indeks Buku : \n");
    scanf("%d",&i);
    printf("Masukkan ISBN baru : \n");
    scanf("%s",&a);
    strcpy((*B).T[i].ISBN, a);
}

void SetJudul(TabelBuku *B){
    int i;
    char a[50];
    char b[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            fgets ((*B).T[0].Judul, 100, stdin);
            printf("Masukkan Judul Buku baru :\n");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*B).T[i].Judul, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}
void SetPengarang(TabelBuku *B){
    int i;
    char a[50];
    char b[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            fgets ((*B).T[0].Pengarang, 100, stdin);
            printf("Masukkan Nama Pengarang baru :\n");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*B).T[i].Pengarang, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetPenerbit(TabelBuku *B){
    int i;
    char a[50];
    char b[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            fgets ((*B).T[0].Penerbit, 100, stdin);
            printf("Masukkan Nama Penerbit baru :\n");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*B).T[i].Penerbit, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetLetak (TabelBuku *B, int A, int C, int D){
    int i;
    char a[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            printf("Masukkan nomor rak : ");
            scanf("%d", &A);
            printf("\n");
            if (A<0 || A > 20){
                printf("No. rak tidak ada \n");
                printf("Masukkan nomor rak : ");
                scanf("%d", &A);
                printf("\n");
            }
            printf("Masukkan nomor baris : ");
            scanf(" %d", &C);
            printf("\n");
            if (C<0 || C>6){
                printf("No. baris tidak ada \n");
                printf("Masukkan nomor baris : ");
                scanf("%d", &C);
                printf("\n");
            }
            printf("Masukkan nomor kolom : ");
            scanf("%d", &D);
            printf("\n");
            if (D<0 || D>4){
                printf("No. kolom tidak ada \n");
                printf("Masukkan nomor kolom : ");
                scanf("%d", &D);
                printf("\n");
            }
            printf("--------------------------------------------------\n");
            (*B).T[i].Letak.Rak = A;
            (*B).T[i].Letak.Baris = C;
            (*B).T[i].Letak.Kolom = D;
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void TambahStock (TabelBuku *B, int newST){
    int i;
    char a[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            printf("Jumlah stock yang ingin ditambahkan :\n");
            scanf("%d", &newST);
            printf("--------------------------------------------------\n");
            (*B).T[i].Stock +=  newST;
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void KurangiStock (TabelBuku *B, int newST){
    int i;
    char a[50];
    int sum;
    sum = 0;
    printf("Masukkan ISBN : \n");
    scanf("%s",&a);
    for(i=1;i<=(*B).Neff;i++){
        if(!(strcmp((*B).T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            printf("Jumlah stock yang ingin diambil :\n");
            scanf("%d", &newST);
            printf("--------------------------------------------------\n");
            (*B).T[i].Stock -= newST;
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void TotalStockBuku (TabelBuku B){
    int i;
    int total;
    total = 0;
    for(i=1;i<=B.Neff;i++){
        total = total + B.T[i].Stock;
    }
    printf("--------------------------------------------------\n");
    printf("Total stock buku adalah %d \n", total);
    printf("--------------------------------------------------\n");
}



/* PEMINJAM */

void MakeAnggota(TabelPeminjam *T){
    //Anggota indeks 1
    strcpy((*T).T[1].Nama, "JONI UPIN");
    strcpy((*T).T[1].NIM, "38994");
    strcpy((*T).T[1].Departemen, "TEKNIK MESIN");
    strcpy((*T).T[1].Fakultas, "FT");
    strcpy((*T).T[1].NoHP, "081280802322");
    strcpy((*T).T[1].Alamat, "JALAN JAMBU");

    //Anggota indeks 2
    strcpy((*T).T[2].Nama, "JINI OH");
    strcpy((*T).T[2].NIM, "39948");
    strcpy((*T).T[2].Departemen, "ILMU GIZI");
    strcpy((*T).T[2].Fakultas, "FK");
    strcpy((*T).T[2].NoHP, "08128883746");
    strcpy((*T).T[2].Alamat, "JALAN MEKAR");

    //Anggota indeks 3
    strcpy((*T).T[3].Nama, "JON LIN");
    strcpy((*T).T[3].NIM, "99283");
    strcpy((*T).T[3].Departemen, "INFORMATIKA");
    strcpy((*T).T[3].Fakultas, "FSM");
    strcpy((*T).T[3].NoHP, "08273732232");
    strcpy((*T).T[3].Alamat, "JALAN NANAS");

    //Anggota indeks 4
    strcpy((*T).T[4].Nama, "MASFUFAH");
    strcpy((*T).T[4].NIM, "99836");
    strcpy((*T).T[4].Departemen, "TEKNIK KIMIA");
    strcpy((*T).T[4].Fakultas, "FT");
    strcpy((*T).T[4].NoHP, "0812773642");
    strcpy((*T).T[4].Alamat, "JALAN SUKAMAJU");
}

Peminjam makePeminjam (char Nama[50], char NIM[50], char Departemen[20], char Fakultas[20], char NoHP[12], char Alamat[100]){
	Peminjam P;
	strcpy (P.Nama, Nama);
	strcpy (P.NIM, NIM);
	strcpy (P.Departemen, Departemen);
	strcpy (P.Fakultas, Fakultas);
	strcpy (P.NoHP, NoHP);
	strcpy (P.Alamat, Alamat);
	return P;
}

void TambahPeminjam (TabelPeminjam *T)
{
	int j;
	char nama[50], nim[50], dep[20], fak[20], np[12], alm[100];
	Peminjam P;
	fgets (nama, 100, stdin);
	printf("Masukkan Nama \t\t: ");
    scanf("%[^\n]s", &nama);
	printf("\n");
	printf("Masukkan NIM \t\t: ");
	scanf("%s",&nim);
	printf("\n");
	for(j=1;j<((*T).Neff);j++){
        if (!(strcmp((*T).T[j].NIM, nim))){
        printf("NIM Tidak Valid \n");
        printf("Masukkan NIM \t\t: ");
        scanf("%s",&nim);
        printf("\n");
        }
    }
    fgets (dep, 100, stdin);
	printf ("Masukkan Departemen \t: ");
	scanf("%[^\n]s",&dep);
	printf("\n");
	fgets (fak, 100, stdin);
	printf ("Masukkan Fakultas \t: ");
	scanf("%[^\n]s",&fak);
	printf("\n");
	printf ("Masukkan Nomor HP \t: ");
	scanf("%s",&np);
	printf("\n");
	fgets (alm, 100, stdin);
	printf ("Masukkan Alamat \t: ");
	scanf("%[^\n]s",&alm);
	printf("\n");
	P = makePeminjam (nama, nim, dep, fak, np, alm);
	(*T).T[((*T).Neff) + 1] = P;
	(*T).Neff+=1;
}

void TulisPeminjamKe(TabelPeminjam T, int i){
    printf("--------------------------------------------------\n");
    printf("Peminjam ke-%d \n",i);
    printf("--------------------------------------------------\n");
    printf("\nNama \t\t= %s \n", T.T[i].Nama);
    printf("\nNIM \t\t= %s \n", T.T[i].NIM);
    printf("\nDepartemen \t= %s \n", T.T[i].Departemen);
    printf("\nFakultas \t= %s \n", T.T[i].Fakultas);
    printf("\nNomor HP \t= %s \n", T.T[i].NoHP);
    printf("\nAlamat \t\t= %s \n", T.T[i].Alamat);
}

void TulisAll(TabelPeminjam T){
    int j;
    for (j=1; j<=(T.Neff); j++){
        TulisPeminjamKe(T,j);
    }
}

//Cari
void CariNama (TabelPeminjam T){
    char nama[50];
    int i;
    int sum;
    sum =0;
    fgets(T.T[0].Nama, 100, stdin);
    printf("Masukkan Nama \t: \n");
    scanf("%[^\n]s",&nama);
    strupr(nama);
    for(i=1;i<=(T.Neff);i++){
        if (!(strcmpi(T.T[i].Nama, nama))){
            printf("--------------------------------------------------\n");
            printf("Anggota yang dicari adalah : \n");
            TulisPeminjamKe(T,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariNIM (TabelPeminjam T){
    char nim[50];
    int i;
    int sum;
    sum = 0;
    printf("Masukkan NIM \t:");
    scanf ("%s", &nim);
    for(i=1;i<=(T.Neff);i++){
        if (!(strcmpi(T.T[i].NIM, nim))){
            printf("--------------------------------------------------\n");
            printf("Anggota yang dicari adalah : \n");
            TulisPeminjamKe(T,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound");
    }
}

void CariDepartemen (TabelPeminjam T){
    char dep[50];
    int i;
    int sum;
    sum = 0;
    fgets (T.T[0].Departemen, 100, stdin);
    printf("Masukkan Departemen \t:");
    scanf("%[^\n]s",&dep);
    strupr(dep);
    for(i=1;i<=(T.Neff);i++){
        if (!(strcmpi(T.T[i].Departemen, dep))){
            printf("--------------------------------------------------\n");
            printf("Anggota yang dicari adalah : \n");
            TulisPeminjamKe(T,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("notfound");
    }
}

void CariFakultas (TabelPeminjam T){
    char fak[50];
    int i;
    int sum;
    sum = 0;
    fgets (T.T[0].Fakultas, 100, stdin);
    printf("Masukkan Fakultas \t:");
    scanf("%[^\n]s",&fak);
    strupr(fak);
    for(i=1;i<=(T.Neff);i++){
        if (!(strcmpi(T.T[i].Fakultas, fak))){
            printf("--------------------------------------------------\n");
            printf("Anggota yang dicari adalah : \n");
            TulisPeminjamKe(T,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("notfound");
    }
}

// Menu Edit
void SetNIM (TabelPeminjam *T){
    int i;
    char a[50];
    printf("Masukkan Indeks Peminjam : \n");
    scanf("%d",&i);
    printf("--------------------------------------------------\n");
    printf("Masukkan NIM baru \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<((*T).Neff);i++){
        if (!(strcmp((*T).T[i].NIM, a))){
        printf("NIM Tidak Valid \n");
        printf("Masukkan NIM \t: ");
        scanf("%s",&a);
        printf("\n");
        }
    }
    strcpy((*T).T[i].NIM, a);
    printf("--------------------------------------------------\n");
}

void SetNama (TabelPeminjam *T){
	int i;
	char a[50];
	char b[50];
	int sum;
    sum = 0;
    printf("Masukkan NIM \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<=((*T).Neff);i++){
        if(!(strcmp((*T).T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            fgets (b, 100, stdin);
            printf("Masukkan Nama Baru : ");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*T).T[i].Nama, b);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetDepartemen (TabelPeminjam *T){
	int i;
	char a[50];
	char b[50];
	int sum;
    sum = 0;
    printf("Masukkan NIM \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<=((*T).Neff);i++){
        if(!(strcmp((*T).T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            fgets (b, 100, stdin);
            printf("Masukkan Nama Departemen Baru : ");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*T).T[i].Departemen, b);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetFakultas (TabelPeminjam *T){
	int i;
	char a[50];
	char b[50];
	int sum;
    sum = 0;
    printf("Masukkan NIM \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<=((*T).Neff);i++){
        if(!(strcmp((*T).T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            fgets (b, 100, stdin);
            printf("Masukkan Nama Fakultas Baru : ");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*T).T[i].Fakultas, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetHp (TabelPeminjam *T){
	int i; int Nef;
	char a[50];
	char b[50];
	int sum;
    sum = 0;
    printf("Masukkan NIM \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<=((*T).Neff);i++){
        if(!(strcmp((*T).T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            printf("Masukkan Nomor HP Baru : ");
            scanf("%s", &b);
            printf("--------------------------------------------------\n");
            strcpy((*T).T[i].NoHP, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void SetAlamat (TabelPeminjam *T){
	int i; int Nef;
	char a[50];
	char b[50];
	int sum;
    sum = 0;
    printf("Masukkan NIM \t: ");
    scanf("%s",&a);
    printf("\n");
    for(i=1;i<=((*T).Neff);i++){
        if(!(strcmp((*T).T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            fgets (b, 100, stdin);
            printf("Masukkan Alamat Baru : ");
            scanf("%[^\n]s", &b);
            strupr(b);
            printf("--------------------------------------------------\n");
            strcpy((*T).T[i].Alamat, b);
        sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("notfound\n");
    }
}

void DelDatPem (TabelPeminjam *T)
{
	Peminjam temp;
	int i, idx;

	printf ("Masukkan Indeks Peminjam yang akan dihapus : "); scanf ("%d", &idx);
	printf ("Data Sudah di Hapus, Tekan <Enter> Sekali Lagi!");
	if (idx > 50 || idx < 0)
		printf ("--- indeks (1 - 50) ---");
	else
	{
		for (i=idx;i<=((*T).Neff-idx);i++)
		{
			(*T).T[i] = (*T).T[i+1];
		}
		(*T).Neff-=1;
	}

}


/*PEMINJAMAN*/

void MakeTransaksi(TabelPeminjaman *M){
    //Transaksi indeks 1
    (*M).T[1].Nomor = 1;
    strcpy((*M).T[1].NIM, "38994");
    strcpy((*M).T[1].Nama, T.T[iNIM(T,"38994")].Nama);
    strcpy((*M).T[1].ISBN, "1234");
    strcpy((*M).T[1].Judul, B.T[iISBN(B,"1234")].Judul);
    (*M).T[1].Mulai = MakeTanggal(1,10,2018);
    (*M).T[1].Akhir = NextNDay((MakeTanggal(1,10,2018)), 7);
    (*M).T[1].Kembali = MakeTanggal(9,10,2018);
    (*M).T[1].Denda = Denda((*M).T[1].Akhir, (*M).T[1].Kembali);
    (*M).T[1].Status = 'Y';

    //Transaksi indeks 2
    (*M).T[2].Nomor = 2;
    strcpy((*M).T[2].NIM, "99836");
    strcpy((*M).T[2].Nama, T.T[iNIM(T,"99836")].Nama);
    strcpy((*M).T[2].ISBN, "8742");
    strcpy((*M).T[2].Judul, B.T[iISBN(B,"8742")].Judul);
    (*M).T[2].Mulai = MakeTanggal(30,9,2018);
    (*M).T[2].Akhir = NextNDay((MakeTanggal(30,9,2018)), 7);
    (*M).T[2].Denda = Denda((*M).T[2].Akhir, (*M).T[2].Kembali);
    (*M).T[2].Status = 'N';

}

int Denda(Tanggal A, Tanggal B){
    if ((B.DD == 0)||(B.MM == 0)||(B.YY == 0)){
        B = Sekarang();
        if ((BerapaHari (A,B)) == -999){
            return 0;
        }
        else{
            return ((BerapaHari (A,B))*1000);
        }
    }
    else{
        if ((BerapaHari (A,B)) == -999){
            return 0;
        }
        else{
            return ((BerapaHari (A,B))*1000);
        }
    }
}

int iNIM(TabelPeminjam T, char nim[50]){
    int i;
    i = 1;
    while ((i>0)&&(i<=T.Neff)){
        if (!(strcmp(T.T[i].NIM, nim))){
            return i;
        }
        else{
            i++;
        }
    }
}

int iISBN(TabelBuku B, char isbn[50]){
    int i;
    i = 1;
    while ((i>0)&&(i<=B.Neff)){
        if (!(strcmp(B.T[i].ISBN, isbn))){
            return i;
        }
        else{
            i++;
        }
    }
}

void TulisTransaksiKe(TabelPeminjaman M, int i){
    printf("--------------------------------------------------\n");
    printf("Data Transaksi Ke-%d \n", i);
    printf("--------------------------------------------------\n");
    printf("\nNomor Transaksi   \t= %d \n", M.T[i].Nomor);
    printf("\nNama Peminjam     \t= %s \n", M.T[i].Nama);
    printf("\nNIM Peminjam      \t= %s \n", M.T[i].NIM);
    printf("\nISBN Buku         \t= %s \n", M.T[i].ISBN);
    printf("\nJudul Buku        \t= %s \n", M.T[i].Judul);
    printf("\nTanggal Mulai Pinjam\t="); TulisTanggal(M.T[i].Mulai);
    printf("\nTanggal Batas Pinjam\t="); TulisTanggal(M.T[i].Akhir);
    printf("\nTanggal Pengembalian\t="); TulisTanggal(M.T[i].Kembali);
    printf("\nDenda             \t= %d \n", Denda((M).T[i].Akhir, (M).T[i].Kembali));
    printf("\nStatus(Y/N)       \t= %c \n", M.T[i].Status);
}

void TulisSemuaTransaksi(TabelPeminjaman M){
    int j;
    for (j=M.Neff; j>=1; j--){
        TulisTransaksiKe(M,j);
    }
}


void TambahPeminjaman (TabelPeminjaman *M){
	int j, k, Dd, Mm, Yy;
	int a;
	int b;
	char c;
    Tanggal U;
	char nama[50], nim[50], isbn[50];
	Peminjaman P1;
	NIM :
        j=1;
        system("cls");
        printf("--------------------------------------------------\n");
        printf("|                 MENU TAMBAH TRANSAKSI           |\n");
        printf("--------------------------------------------------\n");
        printf("\nMasukkan NIM \t\t: ");
        scanf("%s",&nim);
        printf("\n");
        while(j<=T.Neff){
            if (!(strcmp(T.T[j].NIM, nim))){
                printf("\nNIM  : %s", nim);
                printf("\nNAMA : %s", T.T[j].Nama);
                break;
            }
            else{
                j++;
            }
        }
        if (j>T.Neff){
            printf("\nNIM Tidak Ditemukan, Coba Lagi");
            getch();goto NIM;
        }
        b=0;
        while (b<1){
            printf("\nApakah NIM dan Nama Peminjam Benar?[1]YES [2]NO = ");
            scanf("%d", &a);
            if ((a) == 1){
                b++;
            }
            else if ((a) == 2){
                goto NIM;
            }
            else{
                printf("Inputan Salah");
                getch();
            }
        }

    ISBN :
        k=1;
        system("cls");
        printf("--------------------------------------------------\n");
        printf("|                MENU TAMBAH TRANSAKSI           |\n");
        printf("--------------------------------------------------\n");
        printf("\nMasukkan ISBN Buku Dipinjam \t: ");
        scanf("%s",&isbn);
        printf("\n");
        while(k<=B.Neff){
            if (!(strcmp(B.T[k].ISBN , isbn))){
                printf("\nISBN  : %s", isbn);
                printf("\nJudul : %s", B.T[k].Judul);
                break;
            }
            else{
                k++;
            }
        }
        if (k>B.Neff){
            printf("ISBN Tidak Ditemukan, Coba Lagi");
            getch();goto ISBN;
        }
        b=0;
        while (b<1){
            printf("\nApakah ISBN dan Judul Buku sudah Benar?[1]YES [2]NO = ");
            scanf("%d", &a);
            if ((a) == 1){
                b++;
            }
            else if ((a) == 2){
                goto ISBN;
            }
            else{
                printf("Inputan Salah");
                getch();
            }
        }

    Tanggal :
        system("cls");
        printf("--------------------------------------------------\n");
        printf("|                 MENU TAMBAH TRANSAKSI           |\n");
        printf("--------------------------------------------------\n");
        printf("\nMasukkan Tanggal Mulai Pinjam : \n");
        printf("\n[1] Tanggal Sekarang ");
		TulisTanggal(Sekarang());
        printf("\n[2] Set Tanggal");
        printf("\nMasukkan Pilihan Anda(1/2) : ");
        scanf("%d", &a);
        if (a == 1 ){
            U = Sekarang();
        }
        else if (a == 2){
            printf ("\nMasukkan Tanggal Mulai Pinjam (1-31) \t: ");
            scanf("%d",&Dd);
            printf("\n");
            printf ("\nMasukkan Bulan Mulai Pinjam (1-12) \t: ");
            scanf("%d",&Mm);
            printf("\n");
            printf ("\nMasukkan Tahun Mulai Pinjam  \t: ");
            scanf("%d",&Yy);
            printf("\n");
            if (IsTanggalValid (Dd, Mm, Yy)){
                U = MakeTanggal(Dd,Mm,Yy);
            }
            else{
                printf("\n\nFormat Tanggal Salah, Coba Lagi");
                getch();goto Tanggal;
            }
        }

    system("cls");
	printf("--------------------------------------------------\n");
    printf("|                 MENU TAMBAH TRANSAKSI           |\n");
    printf("--------------------------------------------------\n");
	printf ("\nNIM Peminjam \t: %s", T.T[j].NIM);
    printf("\nNAMA Peminjam \t: %s", T.T[j].Nama);
    printf("\nISBN Buku dipinjam \t: %s", B.T[k].ISBN);
    printf("\nJudul Buku dipinjam \t: %s", B.T[k].Judul);
    printf("\nTanggal Mulai Pinjam : "); TulisTanggal(U);

    b=0;
    while (b<1){
        printf("\nApakah Data Di Atas Sudah Benar?(Y/N) : ");
        printf("\nTekan C untuk Cancel Transaksi\n");
        printf("\nPilihan Anda(Y/N/C) : ");
        scanf("%s", &c);
        if (c == 'Y' || c == 'y' ){
            (*M).Neff+=1;
            (*M).T[(*M).Neff].Nomor = (*M).Neff;
            strcpy((*M).T[(*M).Neff].NIM, T.T[j].NIM);
            strcpy((*M).T[(*M).Neff].Nama, T.T[j].Nama);
            strcpy((*M).T[(*M).Neff].ISBN, B.T[k].ISBN);
            strcpy((*M).T[(*M).Neff].Judul, B.T[k].Judul);
            (*M).T[(*M).Neff].Mulai = U;
            (*M).T[(*M).Neff].Akhir = NextNDay(U, 7);
            (*M).T[(*M).Neff].Kembali = MakeTanggal(0,0,0);
            (*M).T[(*M).Neff].Denda = Denda((*M).T[(*M).Neff].Akhir, (*M).T[(*M).Neff].Kembali);
            (*M).T[(*M).Neff].Status = 'N';
            B.T[k].Stock = B.T[k].Stock - 1;
            printf("\n\nTransaksi berhasil dibuat!");
            getch();
            break;
            }
        else if (c == 'N' || c == 'n'){
            b=0;
            while (b<1){
                printf("\n\nData yang ingin di Edit :");
                printf("\n[1] NIM\n[2]ISBN\n[3]Tanggal");
                printf("\nPilihan Anda : ");
                scanf("%d", &a);
                if ((a) == 1){
                    goto NIM;
                }
                else if ((a)==2){
                    goto ISBN;
                }
                else if ((a)==3){
                    goto Tanggal;
                }
                else{
                    printf("Inputan Salah, Coba lagi");
                    getch();
                }
            }
        }
        else if (c == 'c' || c == 'C' ){
            break;
        }
        else{
            printf("Inputan Salah");
            getch();
        }

    }
}

Peminjaman MakePeminjaman (int No, char NIM[50], char Nama[50], char ISBN[50], char Judul[50], Tanggal U){
	Peminjaman P;
	P.Nomor =No;
	strcpy (P.Nama, Nama);
	strcpy (P.NIM, NIM);
	strcpy (P.ISBN, ISBN);
	strcpy (P.Judul, Judul);
	P.Mulai = U;
	P.Akhir = NextNDay(U, 7);
	P.Kembali = MakeTanggal(0,0,0);
	P.Denda = 0;
	P.Status ='N';

	return P;
    }

void Kembalikan (TabelPeminjaman *M, int nomor){
    int Dd, Mm, Yy, i;
    char a;
    Tanggal U;
    i = 0;
    while(i<1){
        printf("\n[1] Tanggal Sekarang ");TulisTanggal(Sekarang());
        printf("\n[2] Set Tanggal");
        printf("\n\nMasukkan Pilihan Anda(1/2) :");
        scanf("%d", &a);
        if (a == 1){
            U = Sekarang();
            i = i+1;
        }
        else if (a == 2){
            printf ("\nMasukkan Tanggal Kembali (1-31) \t: ");
            scanf("%d",&Dd);
            printf("\n");
            printf ("\nMasukkan Bulan Kembali (1-12) \t: ");
            scanf("%d",&Mm);
            printf ("\nMasukkan Tahun Kembali  \t: ");
            scanf("%d",&Yy);
            printf("\n");
            if (IsTanggalValid (Dd, Mm, Yy)){
                U = MakeTanggal(Dd,Mm,Yy);
                i = i+1;
            }
            else{
                printf("\nFormat Tanggal Salah, Coba Lagi");
                getch();
            }
        }
        else{
            printf("\nInputan Salah, Coba lagi");
        }
    }
    (*M).T[nomor].Kembali = U;
    (*M).T[nomor].Denda = Denda((*M).T[nomor].Akhir, (*M).T[nomor].Kembali);
    TulisTransaksiKe((*M), nomor);
    printf("\nApakah Anda akan menyelesaikan Transaksi ini dengan denda %d ? (Y / N) ", (*M).T[nomor].Denda);
    scanf("%s", &a);
    if ((a) == 'y' || a == 'Y'){
        B.T[iISBN(B,(*M).T[nomor].ISBN)].Stock = B.T[iISBN(B,(*M).T[nomor].ISBN)].Stock + 1;
        (*M).T[nomor].Status = 'Y';
    }
    else if ((a) == 'n' || a == 'N'){
        (*M).T[nomor].Kembali = MakeTanggal(0,0,0);
    }
}

//EDIT

void SetBukup (TabelPeminjaman *M){
    int i; int j; int sum;
    char a[50];
    sum = 0;
    printf("Masukkan Nomor Transaksi \t: ");
    scanf("%d",&i);
    printf("\n");
    printf("Masukkan ISBN baru \t: ");
    scanf("%s",&a);
    for (j=1; j<=(B.Neff); j++){
        if(!(strcmp(B.T[j].ISBN,a))){
            strcpy((*M).T[i].ISBN, a);
            strcpy((*M).T[i].Judul, B.T[j].Judul);
            sum = sum +1;
        }
    }
    if (sum == 0){
        printf("\n");
        printf("Buku tidak ada \n");
    }
    else{
        printf("\nISBN  : %s", (*M).T[i].ISBN);
        printf("\nJudul : %s", (*M).T[i].Judul);
        printf("\n");
        printf("Buku sudah diedit \n");
    }
}

void SetPeminjam (TabelPeminjaman *M){
    int i; int j; int sum;
    char a[50];
    sum = 0;
    printf("Masukkan Nomor Transaksi \t: ");
    scanf("%d",&i);
    printf("\n");
    printf("Masukkan NIM baru \t: ");
    scanf("%s",&a);
    for (j=1; j<=(T.Neff); j++){
        if(!(strcmp(T.T[j].NIM,a))){
            strcpy((*M).T[i].NIM, a);
            strcpy((*M).T[i].Nama, T.T[j].Nama);
            sum = sum +1;
        }
    }
    if (sum == 0){
        printf("\n");
        printf("Peminjam tidak ada \n");
    }
    else{
        printf("\nNIM  : %s", (*M).T[i].NIM);
        printf("\nNama : %s", (*M).T[i].Nama);
        printf("\n");
        printf("Peminjam sudah diedit \n");
    }
}

void SetTanggal (TabelPeminjaman *M){
    int i; int j; int sum;
    int x; int y; int z;
    printf("Masukkan Nomor Transaksi \t: ");
    scanf("%d",&i);
    printf("\n");
    printf("Masukkan Tanggal (1-31) \t: \n");
    scanf("%d",&x);
    printf("Masukkan Bulan (1-12) \t: \n");
    scanf("%d",&y);
    printf("Masukkan Tahun \t\t: \n");
    scanf("%d",&z);
    if (IsTanggalValid(x,y,z)){
        (*M).T[i].Mulai.DD = x;
        (*M).T[i].Mulai.MM = y;
        (*M).T[i].Mulai.YY = z;
        (*M).T[i].Akhir = NextNDay((*M).T[i].Mulai , 7);
        (*M).T[i].Denda = Denda((*M).T[i].Akhir, (*M).T[i].Kembali);
        printf("\n");
        printf("Tanggal sudah diedit \n");
    }
    else{
        printf("\n");
        printf("Tanggal tidak valid \n");
    }
}

//CARI
void CariNoTrans (TabelPeminjaman M){
    int no;
    int i;
    int sum;
    sum = 0;
    printf("Masukkan Nomor Transaksi : \n");
    scanf("%d",&no);
    for(i=1;i<=(M.Neff);i++){
        if ( M.T[i].Nomor == no){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariNamaTrans (TabelPeminjaman M){
    char nama[50];
    int i;
    int sum;
    sum = 0;
    fgets(M.T[0].Nama, 100, stdin);
    printf("Masukkan Nama \t: \n");
    scanf("%[^\n]s",&nama);
    strupr(nama);
    for(i=1;i<=(M.Neff);i++){
        if (!(strcmp(M.T[i].Nama, nama))){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariNIMTrans (TabelPeminjaman M){
    char a[50];
    int i;
    int sum;
    sum = 0;
    printf("Masukkan NIM \t: \n");
    scanf("%s",&a);
    for(i=1;i<=(M.Neff);i++){
        if (!(strcmp(M.T[i].NIM, a))){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariISBNTrans (TabelPeminjaman M){
    char a[50];
    int i;
    int sum;
    sum = 0;
    printf("Masukkan ISBN \t: \n");
    scanf("%s",&a);
    for(i=1;i<=(M.Neff);i++){
        if (!(strcmp(M.T[i].ISBN, a))){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariJudulTrans (TabelPeminjaman M){
    char a[50];
    int i;
    int sum;
    sum = 0;
    fgets(M.T[0].Judul, 100, stdin);
    printf("Masukkan Judul \t: \n");
    scanf("%[^\n]s",&a);
    strupr(a);
    for(i=1;i<=(M.Neff);i++){
        if (!(strcmp(M.T[i].Judul, a))){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum +1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariTanggal (TabelPeminjaman M){
    int x, y, z;
    int i;
    int sum;
    sum = 0;
    printf("Masukkan Tanggal (1-31) \t: \n");
    scanf("%d",&x);
    printf("Masukkan Bulan (1-12) \t: \n");
    scanf("%d",&y);
    printf("Masukkan Tahun \t\t: \n");
    scanf("%d",&z);
    for(i=1;i<=(M.Neff);i++){
        if ((M.T[i].Mulai.DD == x)&&(M.T[i].Mulai.MM == y)&&(M.T[i].Mulai.YY == z)){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariDenda (TabelPeminjaman M){
    int i;
    int sum;
    sum = 0;
    for(i=1;i<=(M.Neff);i++){
        if (M.T[i].Denda != 0){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}

void CariStatus (TabelPeminjaman M){
    char a;
    int i;
    int sum;
    sum = 0;
    printf("Masukkan Status (Y/N) \t: \n");
    scanf("%s",&a);
    for(i=1;i<=(M.Neff);i++){
        if (M.T[i].Status == a){
            printf("--------------------------------------------------\n");
            printf("Peminjaman yang dicari adalah : \n");
            TulisTransaksiKe(M,i);
            sum = sum + 1;
        }
    }
    if (sum == 0) {
        printf("\n");
        printf("notfound");
    }
}
