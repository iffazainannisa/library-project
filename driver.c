
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include "semua.c"


int main (){
    //LOGIN
    char userid[]="sukses",password[]="123",p[15],u[15], v[1];
   	int n=1;
   	//BUKU
//    TabelBuku B;
    int cari, pil, i, j, a, b, c;
    //PEMINJAM
//    TabelPeminjam T;

    B.Neff = 5; //buku
    T.Neff = 4; //peminjam
    Neff3 = 2; //Peminjaman
    M.Neff = 2;

    //MENU LOGIN
    MakeBuku(&B);
    MakeAnggota(&T);
    MakeTransaksi(&M);
    home :
    system("cls");
    printf("+=========================================================+\n");
    printf("|                     W E L C O M E   T O                 |\n");
    printf("+=========================================================+\n");
    printf("|     +----+  +-----  +----+   +----+  +    +  +-----     |\n");
    printf("|     |    |  |       |     |  |    |  |    |  |          |\n");
    printf("|     +----+  +-----  |----+   +----+  |    |  +----+     |\n");
    printf("|     |       |       |    |   |       |    |       |     |\n");
    printf("|     |       +-----  |     |  |       +----+  -----+     |\n");
    printf("|       U N I V E R S I T A S  D I P O N E G O R O        |\n");
    printf("+=========================================================+\n");
    printf("|                     M E N U  U T A M A                  |\n");
    printf("+=========================================================+\n");
    printf("|                     [1]. LOGIN                          |\n");
    printf("|                     [2]. KELUAR                         |\n");
    printf("+=========================================================+\n");
    printf("\n");
    printf("Pilihan Anda \t: ");
    scanf("%d",&pil);
    switch(pil){
        case 1 :
            system("cls");
                while(n<=3){
                    printf("+========================================================+\n");
                    printf("|                     M E N U  L O G I N                 |\n");
                    printf("+========================================================+\n");
                    printf("|               Masukkan USER ID dan PASSWORD :          |\n");
                    printf("+========================================================+\n");
                    printf("\n");
                    printf("USER ID \t: ");
                    scanf("%s",u);
                    printf("\nPASSWORD \t: ");
                    scanf("%s",p);
                    a=strcmp(u,userid);
                    b=strcmp(p,password);
                        if(a==0&&b==0){
                            system("cls");
                            printf("+========================================================+\n");
                            printf("|               L O G I N   B E R H A S I L              |\n");
                            printf("|                   T E K A N  E N T E R                 |\n");
                            printf("+========================================================+\n");
                            getch();
                            menu0 :
                                system("cls");
                                printf("+-----------------------------------+\n");
                                printf("|       Y O U  A R E  A D M I N     |\n");
                                printf("+-----------------------------------+\n");
                                printf("|           M A I N  M E N U        |\n");
                                printf("+-----------------------------------+\n");
                                printf("|[1]. Buku                          |\n");
                                printf("|[2]. Peminjam                      |\n");
                                printf("|[3]. Peminjaman                    |\n");
                                printf("|[4]. LogOut                        |\n");
                                printf("+-----------------------------------+\n");
                                printf("\n");
                                printf("Pilihan Anda \t: "); scanf("%d",&pil);
                                switch(pil){
                                    case 1 :
                                        menu1 :
                                            system("cls");
                                            printf("+-----------------------------------+\n");
                                            printf("|         M E N U  B U K U          |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("|[1]. Tulis Semua Buku              |\n");
                                            printf("|[2]. Tulis Buku Ke-                |\n");
                                            printf("|[3]. Tambahkan Buku                |\n");
                                            printf("|[4]. Cari Buku                     |\n");
                                            printf("|[5]. Edit Isi Buku                 |\n");
                                            printf("|[6]. Total stock Buku              |\n");
                                            printf("|[7]. Kembali ke Menu Utama         |\n");
                                            printf("|[8]. LogOut                        |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("Neff = %d", B.Neff);
                                            printf("\n");
                                            printf("Masukkan pilihan \t: ");scanf("%d", &pil);
                                            switch(pil){
                                                case 1 :
                                                    printf("--------------------------------------------------\n");
                                                    printf("|               MENU DATA SEMUA BUKU             |\n");
                                                    printf("--------------------------------------------------\n");
                                                    TulisSemua(B);
                                                    getch(); goto menu1;
                                                case 2 :
                                                    printf("Tampilkan buku ke- : "); scanf("%d",&i);
                                                    printf("\n");
                                                    TulisBukuKe(B, i);
                                                    getch(); goto menu1;
                                                case 3 :
                                                    printf("--------------------------------------------------\n");
                                                    printf("|                 MENU TAMBAH BUKU               |\n");
                                                    printf("--------------------------------------------------\n");
                                                    TambahBuku(&B);
                                                    getch(); goto menu1;
                                                case 4 :
                                                    cari1 :
                                                        system("cls");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|           MENU CARI BUKU          |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|[1]. ISBN                          |\n");
                                                        printf("|[2]. Judul                         |\n");
                                                        printf("|[3]. Pengarang                     |\n");
                                                        printf("|[4]. Penerbit                      |\n");
                                                        printf("|[5]. Letak                         |\n");
                                                        printf("|[6]. Kembali ke Menu Buku          |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("Cari buku berdasarkan \t: ");scanf("%d", &cari);
                                                            switch(cari){
                                                                case 1 :
                                                                    CariISBN(B);
                                                                    getch(); goto cari1;
                                                                case 2 :
                                                                    CariJudul(B);
                                                                    getch(); goto cari1;
                                                                case 3 :
                                                                    CariPengarang(B);
                                                                    getch(); goto cari1;
                                                                case 4 :
                                                                    CariPenerbit(B);
                                                                    getch(); goto cari1;
                                                                case 5 :
                                                                    CariLetak(B);
                                                                    getch(); goto cari1;
                                                                case 6 :
                                                                    goto menu1;
                                                                default :
                                                                    exit(0);
                                                            }
                                                case 5 :
                                                    edit1 :
                                                        system("cls");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|            MENU EDIT              |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|[1]. Tambah Stock                  |\n");
                                                        printf("|[2]. Kurangi Stock                 |\n");
                                                        printf("|[3]. Edit Judul                    |\n");
                                                        printf("|[4]. Edit Pengarang                |\n");
                                                        printf("|[5]. Edit Penerbit                 |\n");
                                                        printf("|[6]. Edit Letak                    |\n");
                                                        printf("|[7]. Kembali ke Menu Buku          |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("Menu yang dipilih \t: ");scanf("%d", &cari);
                                                        switch(cari){
                                                            case 1 :
                                                                TambahStock(&B,a);
                                                                getch(); goto edit1;
                                                            case 2 :
                                                                KurangiStock(&B,b);
                                                                getch(); goto edit1;
                                                            case 3:
                                                                SetJudul(&B);
                                                                getch(); goto edit1;
                                                            case 4 :
                                                                SetPengarang(&B);
                                                                getch(); goto edit1;
                                                            case 5 :
                                                                SetPenerbit(&B);
                                                                getch(); goto edit1;
                                                            case 6 :
                                                                SetLetak(&B, a, b, c);
                                                                getch(); goto edit1;
                                                            case 7 :
                                                                goto menu1;
                                                            default :
                                                                exit(0);
                                                        }
                                                case 6 :
                                                    TotalStockBuku(B);
                                                    getch(); goto menu1;
                                                case 7 :
                                                    goto menu0;
                                                case 8 :
                                                    goto keluar;
                                                default :
                                                    exit(0);
                                            }
                                    case 2:
                                        menu2 :
                                            system("cls");
                                            printf("+-----------------------------------+\n");
                                            printf("|   M E N U  K E A N G G O T A A N  |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("|[1]. Data Semua Anggota            |\n");
                                            printf("|[2]. Tulis Anggota Ke-             |\n");
                                            printf("|[3]. Tambahkan Anggota             |\n");
                                            printf("|[4]. Edit Anggota                  |\n");
                                            printf("|[5]. Cari Anggota                  |\n");
                                            printf("|[6]. Delete Data Anggota           |\n");
                                            printf("|[7]. Kembali ke Menu Utama         |\n");
                                            printf("|[8]. LogOut                        |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("Neff = %d", T.Neff);
                                            printf("\n");
                                            printf("Masukkan pilihan \t: ");scanf("%d", &pil);
                                            switch(pil){
                                                case 1 :
                                                    printf("--------------------------------------------------\n");
                                                    printf("|               MENU DATA SEMUA PEMINJAM         |\n");
                                                    printf("--------------------------------------------------\n");
                                                    TulisAll(T);
                                                    getch(); goto menu2;
                                                case 2 :
                                                    printf("Tampilkan anggota ke- : "); scanf("%d",&i);
                                                    printf("\n");
                                                    TulisPeminjamKe(T, i);
                                                    getch(); goto menu2;
                                                case 3 :
                                                    printf("--------------------------------------------------\n");
                                                    printf("|                 MENU TAMBAH PEMINJAM           |\n");
                                                    printf("--------------------------------------------------\n");
                                                    TambahPeminjam(&T);
                                                    getch(); goto menu2;
                                                case 4 :
                                                    edit2:
                                                    system("cls");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|           MENU EDIT ANGGOTA       |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|[1]. Nama                          |\n");
                                                    printf("|[2]. NIM                           |\n");
                                                    printf("|[3]. Departemen                    |\n");
                                                    printf("|[4]. Fakultas                      |\n");
                                                    printf("|[5]. NoHP                          |\n");
                                                    printf("|[6]. Alamat                        |\n");
                                                    printf("|[7]. Kembali ke Menu Peminjam      |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("\n");
                                                    printf("Edit anggota berdasarkan \t: ");scanf("%d", &pil);
                                                        switch(pil){
                                                            case 1 :
                                                                SetNama(&T);
                                                                getch();goto edit2;
                                                            case 2 :
                                                                SetNIM(&T);
                                                                getch();goto edit2;
                                                            case 3 :
                                                                SetDepartemen(&T);
                                                                getch();goto edit2;
                                                            case 4 :
                                                                SetFakultas(&T);
                                                                getch();goto edit2;
                                                            case 5 :
                                                                SetHp(&T);
                                                                getch();goto edit2;
                                                            case 6 :
                                                                SetAlamat(&T);
                                                                getch();goto edit2;
                                                            case 7 :
                                                                goto menu2;
                                                            default :
                                                                exit(0);
                                                        }
                                                case 5 :
                                                    cari2 :
                                                        system("cls");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|           MENU CARI ANGGOTA       |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("|[1]. Nama                          |\n");
                                                        printf("|[2]. NIM                           |\n");
                                                        printf("|[3]. Departemen                    |\n");
                                                        printf("|[4]. Fakultas                      |\n");
                                                        printf("|[5]. Kembali ke Menu Peminjam      |\n");
                                                        printf("+-----------------------------------+\n");
                                                        printf("\n");
                                                        printf("Cari anggota berdasarkan \t: ");scanf("%d", &pil);
                                                        switch(pil){
                                                            case 1 :
                                                                CariNama(T);
                                                                getch(); goto cari2;
                                                            case 2 :
                                                                CariNIM(T);
                                                                getch(); goto cari2;
                                                            case 3 :
                                                                CariDepartemen(T);
                                                                getch(); goto cari2;
                                                            case 4 :
                                                                CariFakultas(T);
                                                                getch(); goto cari2;
                                                            case 5 :
                                                                goto menu2;
                                                            default :
                                                                exit(0);
                                                        }
                                                case 6:
                                                    DelDatPem(&T);
                                                    getch();goto menu2;
                                                case 7:
                                                    goto menu0;
                                                case 8:
                                                    goto keluar;
                                                default :
                                                    exit(0);
                                            }
                                    case 3:
                                        menu3 :
                                            system("cls");
                                            printf("+-----------------------------------+\n");
                                            printf("|   M E N U    P E M I N J A M A N  |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("|[1]. Tambahkan Peminjaman          |\n");
                                            printf("|[2]. Tampilkan Daftar Peminjaman   |\n");
                                            printf("|[3]. Pengembalian Buku             |\n");
                                            printf("|[4]. Edit Data Peminjaman          |\n");
                                            printf("|[5]. Cari Peminjaman               |\n");
                                            printf("|[7]. Kembali ke Menu Utama         |\n");
                                            printf("|[8]. LogOut                        |\n");
                                            printf("+-----------------------------------+\n");
                                            printf("Total = %d \n", M.Neff);
                                            printf("Tanggal Sekarang : "); TulisTanggal(Sekarang());
                                            printf("\nMasukkan pilihan \t: ");scanf("%d", &pil);
                                            switch(pil){
                                                case 1 :
                                                    TambahPeminjaman (&M);
                                                    getch(); goto menu3;
                                                case 2 :
                                                    printf("--------------------------------------------------\n");
                                                    printf("|               DATA SEMUA PEMINJAMAN             |\n");
                                                    printf("--------------------------------------------------\n");
                                                    TulisSemuaTransaksi(M);
                                                    getch(); goto menu3;
                                                case 3 :
                                                    i=0;
                                                    while (i<1){
                                                        printf("Masukkan nomor Transaksi : ");
                                                        scanf("%d", &b);
                                                        TulisTransaksiKe(M, b);
                                                        printf("Apakah Data Transaksi Yang Anda Maksud?(1/0)");
                                                        scanf("%d", &a);
                                                            if (a==1){
                                                                if (M.T[b].Status == 'Y'){
                                                                    printf("Maaf, Sebelumnya Transaksi Sudah Selesai, Silahkan Coba Transaksi Lain");
                                                                    getch(); goto menu3;
                                                                }
                                                                else{
                                                                    Kembalikan(&M, b);
                                                                    i=i+1;
                                                                    goto menu3;
                                                                }
                                                            }
                                                            else if (a==0){
                                                                goto menu3;
                                                            }
                                                            else{
                                                                printf("Inputan Salah, Silahkan Coba Lagi");
                                                            }
                                                        }
                                                case 4 :
                                                	set :
                                                    system("cls");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|        MENU EDIT PEMINJAMAN       |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|[1]. Buku                          |\n");
                                                    printf("|[2]. Peminjam                      |\n");
                                                    printf("|[3]. Tanggal                       |\n");
                                                    printf("|[4]. Kembali ke Menu Peminjaman    |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("Cari berdasarkan \t: ");scanf("%d", &pil);
                                                    switch(pil){
                                                        case 1:
                                                            SetBukup(&M);
                                                            getch(); goto set;
                                                        case 2:
                                                            SetPeminjam(&M);
                                                            getch(); goto set;
                                                        case 3:
                                                            SetTanggal(&M);
                                                            getch(); goto set;
                                                        case 4:
                                                            goto menu3;
                                                    }
                                                case 5 :
                                                    cari3 :
                                                    system("cls");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|        MENU CARI PEMINJAMAN       |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("|[1]. Nomor Transaksi               |\n");
                                                    printf("|[2]. Nama                          |\n");
                                                    printf("|[3]. NIM                           |\n");
                                                    printf("|[4]. ISBN                          |\n");
                                                    printf("|[5]. Judul                         |\n");
                                                    printf("|[6]. Tanggal                       |\n");
                                                    printf("|[7]. Denda                         |\n");
                                                    printf("|[8]. Status                        |\n");
                                                    printf("|[9]. Kembali ke Menu Peminjaman    |\n");
                                                    printf("+-----------------------------------+\n");
                                                    printf("Cari berdasarkan \t: ");scanf("%d", &pil);
                                                    switch(pil){
                                                        case 1:
                                                            CariNoTrans(M);
                                                            getch(); goto cari3;
                                                        case 2:
                                                            CariNamaTrans(M);
                                                            getch(); goto cari3;
                                                        case 3:
                                                            CariNIMTrans(M);
                                                            getch(); goto cari3;
                                                        case 4:
                                                            CariISBNTrans(M);
                                                            getch(); goto cari3;
                                                        case 5:
                                                            CariJudulTrans(M);
                                                            getch(); goto cari3;
                                                        case 6:
                                                            CariTanggal(M);
                                                            getch(); goto cari3;
                                                        case 7:
                                                            CariDenda(M);
                                                            getch(); goto cari3;
                                                        case 8:
                                                            CariStatus(M);
                                                            getch(); goto cari3;
                                                        case 9:
                                                            goto menu3;
                                                        default:
                                                            exit(0);
                                                    }
                                                case 7:
                                                    goto menu0;
                                                case 8:
                                                    keluar :
                                                        system("cls");
                                                        printf("Are you sure? \n");
                                                        printf("[1] YES\n[2] NO\n");
                                                        printf("\nPilihan Anda : \n");
                                                        scanf("%d",&pil);
                                                        switch(pil){
                                                            case 1 :
                                                                system("cls");
                                                                printf("+========================================================+\n");
                                                                printf("|               L O G O U T   B E R H A S I L            |\n");
                                                                printf("|                   T E K A N  E N T E R                 |\n");
                                                                printf("+========================================================+\n");
                                                                getch();goto home;
                                                            case 2 :
                                                                goto menu0;
                                                        }
                                            }
                                        }
                                    case 4:
                                        goto keluar;
                                }
                        else {
                            system("cls");
                            printf("+========================================================+\n");
                            printf("|     P A S S W O R D  D A N  U S E R  I D  S A L A H    |\n");
                            printf("|               S I S A  K E S E M P A T A N  = %d        |\n", 3-n);
                            printf("+========================================================+\n");
                        }
                        n++;
                    }
                    if(n==4){
                        exit(0);
                    }
        case 2 :
            metu:
            system("cls");
            printf("+========================================================+\n");
            printf("|                     T H A N K   Y O U                  |\n");
            printf("|           -Copyright : KELOMPOK 3 KELAS D 2018-        |\n");
            printf("| 1. IFFA ZAINAN NISA       (24060117130062)             |\n");
            printf("| 2. CHORFIA NIJE MELIANTHA (24060117130061)             |\n");
            printf("| 3. ANNISA FADHILAH        (24060117130066)             |\n");
            printf("| 4. SLAMET FEBRYANTO       (24060117140098)             |\n");
            printf("| 5. RAIHAN HILMY YUSUP     (24060117140086)             |\n");
            printf("| 6. ABRAHAM IMANUEL K.     (24060117130079)             |\n");
            printf("| 7. RICKY RIVALDO          (24060117140054)             |\n");
            printf("| 8. ANGGITA MUNTAZ FATHAYA (24060117130074)             |\n");
            printf("| 9. ENDAR DANANG SUPRAYOGO (24060117130072)             |\n");
            printf("| 10. MICHAEL YEREMIA P.S   (24060117140080)             |\n");
            printf("| 11. MICHAEL AXEL PANGESTU (24060117130081)             |\n");
            printf("| 12. AZHARI BAIDHOWI       (24060117140095)             |\n");
            printf("+========================================================+\n");
            exit(0);
            default :
            exit(0);
    }
}
