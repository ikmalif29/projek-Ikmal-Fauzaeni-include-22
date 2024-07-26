#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<windows.h>
#include<string.h>
#include<conio.h>
#include"admin.c"
#include"user.c"
#include"validasi.c"
#define handle GetStdHandle(STD_OUTPUT_HANDLE)

int pilih;
char admin[20],username[20],admin_buff[20],user_buff[20];
char pasword[20],pasword1[20],pass_buff[20];
char nomor[20];

// kusus untuk menampung data user dari notepade
char nama[100][100],sandi[100][100],number[100][100];

// kusus untuk menambah barang
char tam_barang[100][100];
int harga[100],stok_barang[100];
int uang[100],id_barang[100];

 
// untuk menampilkan riwayat pembelian
int tamid[100],tam_total[100],tamjum_barang[100];
char tamnama_barang[100][100];
int total;

// untuk warna
int text = 7, background = 0 ;


int tam;
int id;
int cari;
int saldo;
int index;
int sal_min;

void cek_data();
void note_take();
void login_admin();
void login_user();
void tambah_saldo();
void saldo_admin();
void update_not();
void home_admin();
void home_user();
void sign_user();
void tampil_profil();
void cek_barang();
void cek_id();
void tambah_barang();
void hapus_barang();
void pindah();
// void tampil_barang();
void beli_barang();
void tampil_saldo_admin();
void pindah();
void pindah_barang();
void pindah_user();
void riwayat_pembelian();
void val_notelp();
void gotoxy();
void set();
void bingkai();
void logo_admin();
void chose();

void gotoxy(int x,int y){
    COORD c = {x,y};
    SetConsoleCursorPosition(handle, c);
}
void set(int text,int bg){
    SetConsoleTextAttribute(handle,bg * 16 + text);
}
void bingkai(int x,int y,int panjang,int lebar,int text,int bg){
    for(int i = 0; i <= panjang; i++){
        for(int j = 0; j <= lebar; j++){
            if(i == 0 || j == 0 || i == panjang || j == lebar){
                gotoxy(x+i,y+j);set(text,text);printf("%c",219);
            }
            else{
                gotoxy(x+i,y+j);set(bg,bg);printf(" ");
            }
        }
    }
}

void sign_user(){
           char username2[20], pasword2[20];
           char a=219;
           bingkai(0,0,90,31,8,14);
           gotoxy(20,5);  set(4,14);printf("%c%c%c%c%c%c%c %c%c  %c%c%c%c%c%c  %c%c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
           gotoxy(20,6);  set(4,14);printf("%c%c      %c%c %c%c       %c%c%c%c   %c%c     %c%c    %c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
           gotoxy(20,7);  set(4,14);printf("%c%c%c%c%c%c%c %c%c %c%c   %c%c%c %c%c %c%c  %c%c     %c%c    %c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
           gotoxy(20,8);  set(4,14);printf("     %c%c %c%c %c%c    %c%c %c%c  %c%c %c%c     %c%c    %c%c %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
           gotoxy(20,9);  set(4,14);printf("%c%c%c%c%c%c%c %c%c  %c%c%c%c%c%c  %c%c   %c%c%c%c      %c%c%c%c%c%c  %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);                                                  

          bingkai(26,16,37,4,4,14);
          gotoxy(28,18); set(10,14); printf("USERNAME: "); 
          bingkai(26,20,37,4,4,14);
          gotoxy(28,22); set(10,14); printf("PASWORD : ");
          gotoxy(39,18); set(10,14); val_user(&username2);

          int dex=0;
          FILE * conetc=fopen("akun.txt","r");
          while(fscanf(conetc,"%[^#]#%[^#]#%[^#]#%d\n",&nama[dex],&sandi[dex],&number[dex],&uang[dex])!=EOF){
                    if(strcmp(username2,nama[dex])==0  ){
                        for(int z=0; z < 15 ; z++){
                            if(z%2==0){
                                 gotoxy(39,18); set(4,14); printf("USERNAME SUDAH DI PAKAI");
                                 gotoxy(40,26); set(4,14); printf("INVALID DATA");
                                 Sleep(500);
                            }
                            else{
                                 gotoxy(39,18); set(4,14); printf("                        ");
                                 gotoxy(40,26); set(4,14); printf("              ");
                                 Sleep(500);
                            }
                            }
                            gotoxy(35,28); set(0,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                            gotoxy(29,29); set(4,14);printf("[BACKSPACE] UNTUK MELANJUTKAN DAFTAR");
                            char e;
                            while((e =getch ())){
                            if(e == 27){
                                chose2();
                            }else if(e==8){
                                sign_user();
                            }
                        }
                    }
                    dex++;
          }
          fclose(conetc);
          gotoxy(39,22); set(10,14); val_pass(&pasword2);


          FILE * buff=fopen("akun.txt","a");
          fprintf(buff,"%s#%s#-#0\n",username2,pasword2);
          fclose(buff);
          for(int z = 0 ; z < 15; z++){
                if(z%2==0){
                    gotoxy(37,26); set(10,14); printf("SIGN UP BERHASIL");
                    Sleep(500);
                }
                else{
                    gotoxy(37,26); set(10,14); printf("                 ");
                    Sleep(500);
                }
          }
          gotoxy(32,29); set(10,14); printf("TEKAN [ESC] UNTUK KEMBALI");
          char e;
          while((e =getch ())){
            if(e == 27){
                chose2();
            }
          }
}

void note_take(){
          cari = 0;
          int index=0;
          FILE* buff= fopen("akun.txt","r");
          while(fscanf(buff,"%[^#]#%[^#]#%[^#]#%d\n",&user_buff,&pass_buff,&nomor,&saldo)!=EOF){
                    if(strcmp(username,user_buff)==0 && strcmp(pasword,pass_buff)==0)
                    {
                              index++;
                                gotoxy(41,26);set(0,14);printf("LOGIN BERHASIL");
                                gotoxy(29,28);set(0,14);printf("LOADING...");
                                for(int i=0;i<25;i++){
                                gotoxy(39+i,28);set(10,14);printf("%c",219);
                                Sleep(70);
                    }
                              home_user();

                    }
                    cari ++;
            }
            if(index==0){
                for(int a = 0 ; a < 15 ; a ++ ){
                    if(a%2==0){
                        gotoxy(41,26); set(4,14); printf("LOGIN GAGAL");
                        Sleep(400);
                    }
                    else{
                        gotoxy(41,26); set(4,14); printf("           ");
                        Sleep(400);
                    }
                }
                gotoxy(35,28); set(0,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                gotoxy(33,29); set(4,14);printf("[BACKSPACE] UNTUK MENGULANGI");
                char e;
                while((e =getch())){
                if(e == 27){
                    chose2();
                }else if(e==8){
                   login_user();
                }
            }
            }
          fclose(buff);
}

void login_admin(){
          logo_admin();

          bingkai(32,15,30,4,4,14);
          bingkai(32,19,30,4,4,14);

          gotoxy(35,17);set(0,14); printf("USERNAME : ");
          gotoxy(35,21);set(0,14); printf("PASWORD  : "); 
          gotoxy(46,17);set(0,14); valmin(&admin);
          gotoxy(46,21);set(0,14); valpasmin(&pasword1);
          if(strcmp(admin,"Ikmal fauzaeni")==0 && strcmp(pasword1,"290904")==0)
          {
                    gotoxy(41,25);set(0,14);printf("LOGIN BERHASIL");
                    gotoxy(29,28);set(0,14);printf("LOADING...");
                    for(int i=0;i<25;i++){
                    gotoxy(39+i,28);set(10,14);printf("%c",219);
                    Sleep(70);
                    }
                    home_admin();
          }
          else{
            for(int a=0; a< 11; a++){
                if(a%2==0){
                    gotoxy(41,25);set(4,14);printf("LOGIN GAGAL");
                    Sleep(400);
                }else{
                    gotoxy(41,25);set(0,14);printf("           ");
                    Sleep(400);
                }
                }
                gotoxy(35,28); set(0,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                gotoxy(33,29); set(4,14);printf("[BACKSPACE] UNTUK MENGULANGI");
                char e;
                while((e =getch ())){
                if(e == 27){
                    chose();
                }else if(e==8){
                   login_admin();
                }
            }
          }
}

void login_user(){
          logo_login_user();
          bingkai(31,16,30,4,0,14);
          bingkai(31,20,30,4,0,14);
          gotoxy(33,18); set(0,14); printf("USAERNAME : "); 
          gotoxy(33,22); set(0,14); printf("PASWORD   : "); 
          gotoxy(45,18); set(0,14); val_userlog(&username);
          gotoxy(45,22); set(0,14); val_paslog(&pasword);
          note_take();
}

void cek_data(){
          index=0;
          FILE* buff= fopen("akun.txt","r");
          while(fscanf(buff,"%[^#]#%[^#]#%[^#]#%d\n",&nama[index],&sandi[index],&number[index],&uang[index])!=EOF){
                    index++;
          }
          fclose(buff);
         
}

void tambah_saldo(int sal){
        if(uang[cari] + sal <= 5000000 ){
          uang[cari]+=sal;
        }
        else{
        for( int x = 0 ; x < 11 ; x ++){
            if( x %2==0){
                gotoxy(36,21); set(4,14);printf("MOHON MAAF SALDO LIMITED!");
                Sleep(400);
            }else{
                gotoxy(36,21); set(4,14);printf("                         ");
                Sleep(400);
            }
          }
                    gotoxy(99,12); set(4,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                    gotoxy(93,13); set(4,15);printf("TEKAN [BACKSPACE] UNTUK MENGUBAH NOMINAL");
                char w;
                while((w = getch())){
                if(w == 27){
                    home_user();
                }
                else if(w==8){
                   sal = val_saldo();
                   tambah_saldo(sal);
                }
                }
        }
        for( int q = 0 ; q < 11 ; q ++){
            if( q %2==0){
                gotoxy(36,21); set(9,14);printf("SUKSES TOP UP SALDO !");
                Sleep(400);
            }else{
                gotoxy(36,21); set(9,14);printf("                      ");
                Sleep(400);
            }
          }
}

int val_saldo(){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 5 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(47+i,17); set(10,14);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 7 && (  idx >='0' && idx<='9' )){
                        gotoxy(47+i,17); set(10,14);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(47+i,17); set(14,14);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          return atoi(tam);
}

int val_saldo_admin(){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 5 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(47+i,17); set(10,14);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 7 && (  idx >='0' && idx<='9' )){
                        gotoxy(47+i,17); set(10,14);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(47+i,17); set(14,14);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          return atoi(tam);
}
void tarik_salmin(int tarik_saldo){
          bingkai(13,8,65,20,4,14);  
          FILE* hubung1 = fopen("min.txt","r");
          fscanf(hubung1,"%d",&sal_min);
          fclose(hubung1);

        if(sal_min <= 200000){
              gotoxy(32,11); set(0,14);printf("SALDO ADMIN SAAT INI : %d",sal_min);
              gotoxy(25,14); set(9,14);printf("MOHON MAAF SALDO ADMIN TIDAK BISA DI TARIK ");
              gotoxy(27,15); set(9,14);printf("KARENA SALDO DI BAWAH BATAS PENARIKAN");
              gotoxy(31,26); set(4,14);printf("SILAHKAN KEMBALI KE MENU ADMIN");
              gotoxy(33,27); set(4,14);printf("TEKAN [ESC] UNTUK KEMBALI");
              char e;
              while((e =getch ())){
                if(e == 27){
                   home_admin();
                }
            }
        } 

          gotoxy(30,11); set(0,14);printf("SALDO ADMIN SAAT INI : RP.%d",sal_min);
          gotoxy(10,2); set(10,14);printf("TARIK SLDO");

          gotoxy(45,15); set(10,14);printf("INPUT ");  
          gotoxy(30,16); set(10,14);printf("NOMINAL SALDO YANG INGIN DI TARIK  ");
          gotoxy(43,17); set(10,14);printf("RP.");
          gotoxy(19,18); set(10,14);printf("______________________________________________________");
          gotoxy(30,26); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,27); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_admin();
                }
                else if(in==13){
                    break;
                }
            }
          gotoxy(30,26); set(0,14);printf("                                  ");
          gotoxy(30,27); set(0,14);printf("                                  ");
          gotoxy(47,17); set(10,14);
          tarik_saldo = val_saldo_admin();
          
          FILE* hubung = fopen("min.txt","r");
          fscanf(hubung,"%d",&sal_min);
          sal_min-=tarik_saldo;
          fclose(hubung);

        if(sal_min - tarik_saldo < 200000){
            for(int x = 0 ; x < 11 ; x ++){
              if(x%2==0){  
                gotoxy(25,20); set(9,14);printf("MOHON MAAF SALDO ADMIN TIDAK BISA DI TARIK ");
                gotoxy(27,21); set(9,14);printf("KARENA NOMINAL PENARIKAN TERLALU BANYAK");
                gotoxy(33,26); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                gotoxy(26,27); set(4,14);printf("TEKAN [BACKSPACE] UNTUK MENGUBAH NOMINAL");
                Sleep(400);
              }else{
                gotoxy(25,20); set(9,14);printf("                                            ");
                gotoxy(27,21); set(9,14);printf("                                            ");
                Sleep(400);
              }
            }
              char e;
              while((e =getch ())){
                if(e == 27){
                    home_admin();
                }else if(e==8){
                   tarik_salmin(tarik_saldo);
                }
            }
        } 
          FILE * hub=fopen("min.txt","w");
          fprintf(hub,"%d",sal_min);
          fclose(hub);
          for( int q = 0 ; q < 11 ; q ++){
            if( q %2==0){
                gotoxy(36,21); set(9,14);printf("SUKSES MENARIK SALDO !");
                Sleep(400);
            }else{
                gotoxy(36,21); set(9,14);printf("                      ");
                Sleep(400);
            }
          }
          FILE* conetc = fopen("min.txt","r");
          fscanf(conetc,"%d",&sal_min);
          gotoxy(32,23); set(0,14);printf("SALDO ADMIN SEKARANG : %d ",sal_min);
          fclose(conetc);

          gotoxy(33,29); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
          char e;
          while((e =getch ())){
            if(e == 27){
                home_admin();
            }
          }
}

void update_not(){
          int a =0 ;
          FILE* buff=fopen("akun.txt","w");
          while(a<index){
                    fprintf(buff,"%s#%s#%s#%d\n",nama[a],sandi[a],number[a],uang[a]);
                    a++;
          }
          fclose(buff);
}

void tampil_profil(){
          cek_data();
          bingkai(10,11,70,13,4,14);
          gotoxy(13,16); set(10,14); printf("USERNAME\t\tPASWORD");
          gotoxy(48,16); set(10,14); printf("  NO HP\t\t   SALDO");
          gotoxy(13,18); set(10,14); printf("%s",nama[cari]);
          gotoxy(31,18); set(10,14); printf("%s",sandi[cari]);
          gotoxy(48,18); set(10,14); printf("%s\t  RP.%d",number[cari],uang[cari]);

          gotoxy(32,29); set(40,14); printf("TEKAN [ESC] UNTUK KEMBALI ");

          char klik;
          while((klik  = getch ())){
                    if(klik==27){
                              home_user();
                    }
          }
}

void edit_profil(){
          char nomor[12];
          char userbaru[100],passbaru[100];

          gotoxy(30,14); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,15); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_user();
                }
                else if(in==13){
                    break;
                }
            }
          gotoxy(30,14); set(0,14);printf("                                  ");
          gotoxy(30,15); set(0,14);printf("                                  ");

          bingkai(13,11,65,13,4,14);  
          gotoxy(16,14); set(10,14); printf("NEW USERNAME       : ");
          gotoxy(16,15); set(10,14); printf("__________________________________________________________ ");
          gotoxy(16,16); set(10,14); printf("NEW PASWORD        : ");
          gotoxy(16,17); set(10,14); printf("__________________________________________________________ ");
          gotoxy(16,18); set(10,14); printf("NEW PHONE NUMBER   : ");
          gotoxy(16,19); set(10,14); printf("__________________________________________________________ ");
          gotoxy(40,14); set(10,14); val_usernew(&userbaru); 
          gotoxy(40,16); set(10,14); val_sandibaru(&passbaru); 
          gotoxy(40,18); set(10,14); val_notelp(&nomor);
          index=0;
          FILE* buff= fopen("akun.txt","r");
          while(fscanf(buff,"%[^#]#%[^#]#%[^#]#%d\n",&nama[index],&sandi[index],&number[index],&uang[index])!=EOF){
                    if(strcmp(userbaru,nama[index]) == 0){
                            if(index!=cari){
                                for(int d = 0 ; d < 11 ; d++){
                                    if(d%2==0){
                                        gotoxy(25,22); set(4,14);printf("USERNAME INI SUDAH TERDAFTAR DI AKUN LAIN ");
                                        Sleep(400);
                                    }else{
                                        gotoxy(25,22); set(0,14);printf("                                          ");
                                        Sleep(400);
                                    }
                                }
                                        gotoxy(38,26); set(0,14);printf("[ESC] UNTUK KE MENU");
                                        gotoxy(31,27); set(0,14);printf("[BACKSPACE] UNTUK LANJUT MENGEDIT");

                                char p ; 
                                while((p = getch())){
                                    if(p == 27){
                                        home_user();
                                    }
                                    else if(p == 8){
                                        edit_profil();
                                    }
                                }
                              }
                              else{
                                for(int g = 0 ; g < 11 ; g ++){
                                    if(g%2==0){
                                        gotoxy(25,22); set(4,14);printf("ANDA SUDAH MENGGUNAKAN USERNAME INI ");
                                        Sleep(400);
                                    }else{
                                        gotoxy(25,22); set(0,14);printf("                                    ");
                                        Sleep(400);
                                    }
                                }
                                        gotoxy(38,26); set(4,14);printf("[ESC] UNTUK KE MENU");
                                        gotoxy(31,27); set(4,14);printf("[BACKSPACE] UNTUK LANJUT MENGEDIT");

                                char l ; 
                                while((l = getch())){
                                    if(l == 27){
                                        home_user();
                                    }
                                    else if(l == 8){
                                        edit_profil();
                                    }
                                }
                              }
                    }
                    else if(strcmp(nomor,number[index])==0){
                              if(index!=cari){
                                for(int h = 0 ; h < 11 ; h ++){
                                    if(h%2==0){
                                        gotoxy(10,19); set(4,14);printf("NOMOR TRLRPON INI SUDAH TERDAFTAR DI AKUN LAIN ");
                                        Sleep(400);
                                    }else{
                                        gotoxy(10,19); set(10,14);printf("                                              ");
                                        Sleep(400);
                                    }
                                }
                                        gotoxy(38,26); set(0,14);printf("[ESC] UNTUK KE MENU");
                                        gotoxy(31,27); set(0,14);printf("[BACKSPACE] UNTUK LANJUT MENGEDIT");

                                char y ; 
                                while((y = getch())){
                                    if(y == 27){
                                        home_user();
                                    }
                                    else if(y == 8){
                                        edit_profil();
                                    }
                                }
                              }
                              else{
                                for(int s = 0 ; s < 11 ; s++){
                                    if(s%2==0){
                                        gotoxy(10,19); set(0,14);printf("ANDA SUDAH MENGGUNAKAN NO TELEPON INI ");
                                        Sleep(400);
                                    }else{
                                        gotoxy(10,19); set(0,14);printf("                                      ");
                                        Sleep(400);
                                    }
                                }
                                        gotoxy(38,26); set(0,14);printf("[ESC] UNTUK KE MENU");
                                        gotoxy(31,27); set(0,14);printf("[BACKSPACE] UNTUK LANJUT MENGEDIT");

                                char g ; 
                                while((g = getch())){
                                    if(g == 27){
                                        home_user();
                                    }
                                    else if(g == 8){
                                        edit_profil();
                                    }
                                }
                              }
                    }
                    index++;
          }
          fclose(buff);
          cek_data();
          strcpy(nama[cari],userbaru);
          strcpy(sandi[cari],passbaru);
          strcpy(number[cari],nomor);
          update_not();

          for(int v = 0 ; v < 12; v++){
            if(v%2==0){
                gotoxy(35,22); set(10,14);printf("DATA BERHASIL DIUPDATE");
                Sleep(400);
            }
            else{
                gotoxy(35,22); set(10,14);printf("                       ");
                Sleep(400);
            }
          }  
          char klik;
          int dex=0;
          gotoxy(31,27); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
          while(((klik = getch())!= 13) ){
                    if(klik==27){
                              home_user();
                    }
          }
}

void tampil_saldo_admin(){
          FILE* hubung = fopen("min.txt","r");
          fscanf(hubung,"%d",&sal_min);
          fclose(hubung);
          bingkai(15,10,60,10,4,14);
          gotoxy(28,15); set(0,14);printf("SALDO ADMIN SAAT INI : RP.%d",sal_min);
          gotoxy(30,29); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                    char klik;
                    while((klik  = getch ())){
                              if(klik==27){
                                        home_admin();
                              }
                    }
}

void saldo_admin(){
          FILE* hubung = fopen("min.txt","r");
          fscanf(hubung,"%d",&sal_min);
          fclose(hubung);
          
}

void tambah_barang(){
          char nama_barang[100];
          int harga_barang,stok;
          char  a = 201,b = 187,c = 205,d = 203,e = 204,f = 185,g = 202,h = 200,i = 188,j = 186, k = 220, l=223  ;

          gotoxy(99,3);set(9,15);printf("%c%c%c%c%c%c%c%c%c  %c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c",a,c,b,a,d,b,a,d,b,a,b,a,c,b,d,c,b,a,c,b,a,b,a,a,c,b);
          gotoxy(99,4);set(9,15);printf("%c%c%c %c%c %c%c  %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c",e,c,f,j,j,j,j,e,g,b,e,c,f,e,d,i,e,c,f,j,j,j,j,d);
          gotoxy(99,5);set(9,15);printf("%c %c%c%c%c%c%c%c  %c%c%c%c %c%c%c%c%c %c%c%c%c%c%c%c ",g,g,c,g,i,c,g,i,h,c,i,g,g,g,h,c,g,g,i,h,i,h,c,i);
          

          bingkai(13,8,65,20,4,14);
          gotoxy(16,13); set(10,14);printf("NAMA BARANG     : "); 
          gotoxy(16,14); set(10,14);printf("___________________________________________________________");
          gotoxy(16,16); set(10,14);printf("HARGA BARANG    : ");
          gotoxy(16,17); set(10,14);printf("___________________________________________________________");
          gotoxy(16,19); set(10,14);printf("STOK BARANG     : ");
          gotoxy(16,20); set(10,14);printf("___________________________________________________________");

          gotoxy(30,26); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,27); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_admin();
                }
                else if(in==13){
                    break;
                }
            }
          gotoxy(30,26); set(0,14);printf("                                  ");
          gotoxy(30,27); set(0,14);printf("                                  ");

          gotoxy(37,13); set(10,14);val_namabarang(&nama_barang);
          int batas=0;
          FILE * hubungan = fopen("barang.txt","r");
          while(fscanf(hubungan,"%d#%[^#]#%d#%d\n",&id_barang[batas],&tam_barang[batas],&harga[batas],&stok_barang[batas])!=EOF){
                    if(strcmp(nama_barang,tam_barang[batas])==0){
                        for(int g = 0 ; g < 11 ; g ++){
                            if(g %2==0){
                                gotoxy(37,15); set(4,14); printf("BARANG SUDAH ADA");
                                Sleep(400);
                            }
                            else{
                                gotoxy(37,15); set(4,14); printf("                 ");
                                Sleep(400);
                            }
                        }
                        tambah_barang();
                    }
                    batas++;
          }
          fclose(hubungan);

          gotoxy(37,16); set(10,14);
          harga_barang = val_hargabarang();
          gotoxy(37,19); set(10,14);
          stok = val_stokbarang();

          cek_barang();
          cek_id();
          FILE* hubung=fopen("barang.txt","a");
          fprintf(hubung,"%d#%s#%d#%d\n",tam,nama_barang,harga_barang,stok);
          fclose(hubung);

         for(int a = 0 ; a < 10 ; a++){
            if(a %2==0){
                gotoxy(32,10); set(4,14); printf("BARANG BERHASIL DI TAMBAHKAN");
                Sleep(500);
            }
            else{
                gotoxy(32,10); set(10,14); printf("                             ");
                Sleep(500);
            }
         }   
        gotoxy(33,27); set(40,14); printf("TEKAN [ESC] UNTUK KEMBALI   ");

          char klik;
          while(((klik = getch())) ){
                    if(klik==27){
                              home_admin();
                    }
          }
}

void hapus_barang(){
          int cari;
          gambar();
          cek_barang();
          gotoxy(30,14); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,15); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_admin();
                }
                else if(in==13){
                    break;
                }
            }

          gotoxy(30,14); set(0,14);printf("                                  ");
          gotoxy(30,15); set(0,14);printf("                                  ");
          gotoxy(93,4); set(0,15);printf("MASUKAN ID BARANG   : ");
          gotoxy(93,5); set(0,15);printf("_____________________________________"); 
          gotoxy(93,6); set(0,15);printf("_____________________________________");
          gotoxy(93,7); set(0,15);printf("_____________________________________");
          gotoxy(93,8); set(0,15);printf("_____________________________________");
          show_barang(0,20,"HAPUS");
          gotoxy(115,4); set(0,15); cari = val_hapusid(cari);
          cek_barang();

          for(int o = 0 ; o < id ; o++){
            if(cari == id_barang[o]){
                    pindah(cari);
            }
          }
          for(int z = 0 ; z < id ; z++){
            if(cari != id_barang[z]){
                for(int y = 0 ; y < 10 ; y++){
                    if(y %2 ==0){
                        gotoxy(97,10); set(4,15);printf("MOHON MAAF BARANG TIDAK TERSEDIA");
                        Sleep(500);
                    }else{
                        gotoxy(97,10); set(4,15);printf("                                ");
                        Sleep(500);
                    }
                }
                    gotoxy(100,12); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                    gotoxy(94,13); set(4,15);printf("[BACKSPACE] UNTUK MENGUBAH ID BARANG");
                char e;
                while((e =getch ())){
                if(e == 27){
                    home_admin();
                }else if(e==8){
                   hapus_barang();
                }
                }
            }
          }
}
void edit_barang(){
    int dit;
    char nambar[100];
    int harbar,stokbar;
    gambar();
    
    bingkai(0,0,90,31,8,14);
    gotoxy(95,4);set(0,15);printf("NO BARANG YANG AKAN DI UPDATE : ");
    gotoxy(95,5); set(0,15);printf("___________________________________");
    gotoxy(95,6); set(10,15);printf("NAMA BARANG  : ");
    gotoxy(95,7); set(0,15);printf("___________________________________"); 
    gotoxy(95,8); set(10,15);printf("HARGA BARANG : "); 
    gotoxy(95,9); set(0,15);printf("___________________________________");
    gotoxy(95,10); set(10,15);printf("STOK BARANG  : ");
    gotoxy(95,11); set(0,15);printf("___________________________________");
          gotoxy(30,14); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,15); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_admin();
                }
                else if(in==13){
                    break;
                }
            }
          gotoxy(30,14); set(0,14);printf("                                  ");
          gotoxy(30,15); set(0,14);printf("                                  ");

    show_barang(0,20,"UPDATE");
    gotoxy(127,4); set(0,15);
    dit = val_ditbar();
    cek_barang();
    int idx = - 1;
    for(int i = 0; i < id; i++){
        if(dit == id_barang[i]){
            idx = i;
        }
    }
    if(idx != -1){
        
        gotoxy(111,6); set(10,15);val_barangnew(&nambar);
        for(int x = 0 ; x < id ; x ++){
            if(strcmp(tam_barang[x],nambar)==0 && (id_barang[x] != dit)){
                for(int y = 0 ; y < 12 ; y ++ ){
                    if(y %2==0){
                        gotoxy(95,13);  set(4,15);printf("MAAF BARANG TERSEBUT SUDAH TERSEDIA");
                        Sleep(400);
                    }
                    else{
                        gotoxy(95,13);  set(4,15);printf("                                   ");
                        Sleep(400);
                    }
                }

                gotoxy(90,15); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                gotoxy(93,15); set(0,15);printf("[BACKSPACE] UNTUK MENGUBAH NAMA BARANG");
                char w;
                while((w =getch ())){
                if(w == 27){
                    home_admin();
                }else if(w==8){
                    edit_barang();
                }
              }
            }
        }
        gotoxy(111,8); set(10,15); harbar = val_harganew(harbar);
        gotoxy(111,10); set(10,15);stokbar = val_stoknew(stokbar);
    }
    else{
        for(int y = 0 ; y < 10 ; y++){
            if(y %2 ==0){
                gotoxy(96,13);  set(4,15);printf("MOHON MAAF BARANG TIDAK TERSEDIA");
                Sleep(400);
            }else{
                gotoxy(96,13);  set(4,15);printf("                                ");
                Sleep(400);
            }
        }
            gotoxy(99,14); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
            gotoxy(94,15); set(0,15);printf("[BACKSPACE] UNTUK MENGUBAH ID BARANG");
        char e;
        while((e =getch ())){
        if(e == 27){
            home_admin();
        }else if(e==8){
            edit_barang();
        }
        }
    }
    harga[idx]=harbar;
    stok_barang[idx]=stokbar;
    strcpy(tam_barang[idx],nambar);
    pindah_barang();
    for(int c = 0 ; c < 11 ; c++){
        if(c%2==0){
            gotoxy(99,13);  set(10,15);printf("BARANG BERHASIL DI UPDATE");
            Sleep(400);
        }
        else{
            gotoxy(99,13);  set(10,15);printf("                          ");
            Sleep(400);
        }
    }
    
    gotoxy(33,28); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
    char klik;
    while((klik = getch ())){
        if(klik == 27 ){
            home_admin();
        }
    }
}
void show_barang(int start, int batas,char string[]){
        int back = start - 20;
        int z = 0 ;
        int x = 0;
       
    cek_barang();
    gotoxy(7,2); set(0,14);printf("NO\tID\t\tNAMA_BARANG\t\tHARGA\t\tSTOK");
    if(id < 20 && start == 0){
            for(int i = start; i < id; i++){
            gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",i+1,id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
            x++;
        }
        gotoxy(30,29); set(0,14);printf("TEKAN [SPACE]  UNTUK %s BARANG",string);
        char input;
        while((input = getch()) != 32){
        }
    }
    else if(batas < id){
        for(int i = start; i < batas; i++){
            gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",i+1,id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
            x++;
        }
        gotoxy(30,29); set(0,14);printf("TEKAN [SPACE]  UNTUK %s BARANG",string);
        char input;
        if(start == 0){
            gotoxy(12,28); set(0,14);printf("TEKAN >>> UNTUK SLIDE BERIKUTNYA");
        }
        else if(batas < id && start > 0){
            gotoxy(12,28); set(0,14);printf("TEKAN >>> UNTUK SLIDE BERIKUTNYA");
            gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
        }
        else{
            gotoxy(48,28); set(0,14);printf("                                ");
            gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
        }
        while((input = getch()) != 32){
            if(input == 77 && batas < id){
                if(batas+batas > id){
                    bingkai(0,0,90,31,8,14);
                    show_barang(batas,batas+20,string);
                }
                else{
                    bingkai(0,0,90,31,8,14);
                    show_barang(batas,batas+20,string);
                }
                break;
            }
            else if(input == 75 && start > 0){
                bingkai(0,0,90,31,8,14);
                show_barang(start-20,batas-20,string);
                break;
            }
        }
    }
    else{ 
        while(start < id){
            gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",start+1,id_barang[start],tam_barang[start],harga[start],stok_barang[start]);
            start++;
            x++;
        }        
        if(batas <= id && batas % 20 < 10){
            gotoxy(30,29); set(0,14);printf("TEKAN [SPACE]  UNTUK %s BARANG",string);
            char input;
            gotoxy(48,28); set(0,14);printf("                                ");
            gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
            while((input = getch()) != 32){
                if(input == 75 && start > 0){
                    int jumlah = 0;
                    jumlah = id % 20;
                    bingkai(0,0,90,31,8,14);
                    show_barang(back,batas-jumlah,string);
                    break;
                }
            }
        }
        else{
            gotoxy(30,29); set(0,14);printf("TEKAN [SPACE]  UNTUK %s BARANG",string);
            char input;
            gotoxy(48,28); set(0,14);printf("                                ");
            gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
            while((input = getch()) != 32){
                if(input == 75 && start > 0){
                    bingkai(0,0,90,31,8,14);
                    show_barang(back,batas-20,string);
                    break;
                }
            }
        }
    }
}
// memindahkan data barang dari notepade ke array
void pindah(int cari){
          int i = 0 ;
          FILE* hubungan=fopen("barang.txt","w");
          fclose(hubungan);
          FILE* hubung=fopen("barang.txt","a");
          
          while(i < id ){
                    if(cari != id_barang[i]){
                              fprintf(hubung,"%d#%s#%d#%d\n",id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
                    }
                    i++;
          }
          fclose(hubung);
            for(int z = 0 ; z < 15 ; z ++){
                if(z%2==0){
                gotoxy(99,11); set(10,15);printf("BARANG BERHASIL DI HAPUS ");
                Sleep(500);
                }
                else{
                gotoxy(99,11); set(10,15);printf("                         ");
                Sleep(500);
                }
            }
          gotoxy(99,13); set(40,15);printf("TEKAN [ESC] UNTUK KEMBALI");
          char klik;
          while((klik = getch ())){
                    if(klik==27){
                              home_admin();
                    }
          }
}

void pindah_barang(){
          int i = 0 ;
          FILE* hubungan=fopen("barang.txt","w");
          fclose(hubungan);
          FILE* hubung=fopen("barang.txt","a");
          while(i < id ){
                    
                              fprintf(hubung,"%d#%s#%d#%d\n",id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
                    
                    i++;
          }
          fclose(hubung);
}

void pindah_user(){
          int i = 0 ;
          FILE* hubungan=fopen("akun.txt","w");
          fclose(hubungan);
          FILE* hubung=fopen("akun.txt","a");
          while(i < index ){
                    
                              fprintf(hubung,"%s#%s#%s#%d\n",nama[i],sandi[i],number[i],uang[i]);
                    
                    i++;
          }
          fclose(hubung);
}

void cek_barang(){
          id = 0 ;
          FILE * hubung= fopen("barang.txt","r");
          while(fscanf(hubung,"%d#%[^#]#%d#%d\n",&id_barang[id],&tam_barang[id],&harga[id],&stok_barang[id])!=EOF){
            id++;
          }
          fclose(hubung);
}

void tampil_barang(int start, int batas){
        int back = start - 20;
        int z = 0 ;
        int x = 0;
        gotoxy(32,29); set(0,14);printf("TEKAN [SPACE]  UNTUK KEMBALI");
        cek_barang();
        gotoxy(7,2); set(0,14);printf("NO\tID\t\tNAMA_BARANG\t\tHARGA\t\tSTOK");
        if(start ==0 && id < 20){
            for(int i = start ; i < id ; i++){
                gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",i+1,id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
                x++;
            }
                    char input;
                    while((input = getch()) != 32){
                    }
                }
        else if(batas < id){
            for(int i = start; i < batas; i++){
                gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",i+1,id_barang[i],tam_barang[i],harga[i],stok_barang[i]);
                x++;
            }
            char input;
            if(start == 0){
                gotoxy(12,28); set(0,14);printf("TEKAN >>> UNTUK SLIDE BERIKUTNYA");
            }
            else if(batas < id && start > 0){
                gotoxy(12,28); set(0,14);printf("TEKAN >>> UNTUK SLIDE BERIKUTNYA");
                gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
            }
            else{
                gotoxy(48,28); set(0,14);printf("                                ");
                gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
            }
            while((input = getch()) != 32){
                if(input == 77 && batas < id){
                    if(batas+batas > id){
                        bingkai(0,0,90,31,8,14);
                        tampil_barang(batas,batas+20);
                    }
                    else{
                        bingkai(0,0,90,31,8,14);
                        tampil_barang(batas,batas+20);
                    }
                    break;
                }
                else if(input == 75 && start > 0){
                    bingkai(0,0,90,31,8,14);
                    tampil_barang(start-20,batas-20);
                    break;
                }
            }
            home_admin();
        }
        else{ 
            while(start < id){
                gotoxy(7,4+x); set(0,14);printf("%d\t%d\t\t%s\t\t%d\t\t%d",start+1,id_barang[start],tam_barang[start],harga[start],stok_barang[start]);
                start++;
                x++;
            }        
            if(batas <= id && batas % 20 < 10){
                char input;
                gotoxy(48,28); set(0,14);printf("                                ");
                gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
                while((input = getch()) != 32){
                    if(input == 75 && start > 0){
                        int jumlah = 0;
                        jumlah = id % 20;
                        bingkai(0,0,90,31,8,14);
                        tampil_barang(back,batas-jumlah);
                        break;
                    }
                }
                home_admin();
            }
            else{
                char input;
                gotoxy(48,28); set(0,14);printf("                                ");
                gotoxy(48,28); set(0,14);printf("TEKAN <<< UNTUK SLIDE SEBELUMNYA");
                while((input = getch()) != 32){
                    if(input == 75 && start > 0){
                        bingkai(0,0,90,31,8,14);
                        tampil_barang(back,batas-20);
                        break;
                    }
                }
                home_admin();   
            }

        }

}

void cek_id(){
          int a = 0 ;
          tam = 0;
          while(a < id ){
                    if(id_barang[a] >= tam ){
                              tam = id_barang[a];
                              
                    }
                    a++;
          }
          tam++;  
}

void beli_barang(int id_beli, int jumlah){
          char alamat[100];
          gambar();
          cek_barang();
          cek_data();
          saldo_admin();
          gotoxy(30,14); set(0,14);printf("TEKAN [ENTER]  UNTUK  MELANJUTKAN");
          gotoxy(30,15); set(0,14);printf("TEKAN [BACKSPACE]  UNTUK  KEMBALI");

            char in;
            while((in = getch())){
                if(in==8){
                    home_user();
                }
                else if(in==13){
                    break;
                }
            }
          gotoxy(30,14); set(0,14);printf("                                  ");
          gotoxy(30,15); set(0,14);printf("                                  ");

                    gotoxy(93,2); set(0,15);printf("ID BARANG YANG INGIN DI BELI : ");
                    gotoxy(93,3); set(0,15);printf("_____________________________________");
                    gotoxy(93,4); set(10,15);printf("JUMLAH BARANG : ");
                    gotoxy(93,5); set(0,15);printf("_____________________________________");
                    gotoxy(93,6); set(10,15);printf("ALAMAT KELURAHAN PENGIRIMAN  ");
                    gotoxy(93,7); set(0,15);printf("_____________________________________");
                    gotoxy(93,9); set(0,15);printf("_____________________________________");

                    show_barang(0,20,"BELI");
                    gotoxy(125,2); set(10,15); id_beli = val_beliid(id_beli);
                    gotoxy(110,4); set(10,15); jumlah = val_belijumlah(jumlah);
                    gotoxy(93,8); set(10,15); val_alamat(&alamat);

        int z = 0;            
        int tam;
        while(z < id){
            if(id_beli == id_barang[z]){
                z=100;
                tam=z;
            }
            z++;
        }
        if(tam !=100){
                for(int y = 0 ; y < 11 ; y++){
                    if(y %2 ==0){
                        gotoxy(95,11); set(4,15);printf("MOHON MAAF BARANG TIDAK TERSEDIA");
                        Sleep(500);
                    }else{
                        gotoxy(95,11); set(4,15);printf("                                ");
                        Sleep(500);
                    }
                }
                    gotoxy(99,13); set(40,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                    gotoxy(94,14); set(4,15);printf("[BACKSPACE] UNTUK MENGUBAH ID BARANG");
                char e;
                while((e =getch ())){
                if(e == 27){
                    home_user();
                }else if(e==8){
                   beli_barang(id_beli,jumlah);
                }
                }
            }
          int i = 0 ;
          while(i < id ){
                    if(id_beli == id_barang[i]){
                        if(stok_barang[i] <= 0){
                        for(int f = 0 ; f < 11 ; f++){
                    if(f %2 ==0){
                        gotoxy(93,11); set(4,15);printf("MOHON MAAF STOK BARANG TIDAK MENCUKUPI");
                        Sleep(500);
                    }else{
                        gotoxy(93,11); set(4,15);printf("                                      ");
                        Sleep(500);
                    }
                }
                        gotoxy(99,13); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                        gotoxy(93,14); set(4,15);printf("[BACKSPACE] UNTUK MENGUBAH JUMLAH BELI");
                        char u;
                        while((u =getch ())){
                        if(u == 27){
                            home_user();
                        }else if(u==8){
                        beli_barang(id_beli,jumlah);
                        }
                }

                        }else{
                            cek_data();
                             stok_barang[i]-=jumlah;
                             uang[cari]-=harga[i] * jumlah;
                             sal_min+=harga[i] * jumlah;
                             total=harga[i] * jumlah;
                        }
                    }
                    i++;
          }
            
                  
        if(stok_barang[id_beli] == 0 || stok_barang[id_beli] - jumlah < 0){
            for(int k = 0 ; k < 11 ; k++){
                    if(k %2 ==0){
                        gotoxy(93,11); set(4,15);printf("MOHON MAAF STOK BARANG TIDAK MENCUKUPI");
                        Sleep(500);
                    }else{
                        gotoxy(93,11); set(4,15);printf("                                      ");
                        Sleep(500);
                    }
                }
                    gotoxy(99,13); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                    gotoxy(93,14); set(4,15);printf("[BACKSPACE] UNTUK MENGUBAH JUMLAH BELI");
                char w;
                while((w =getch ())){
                if(w == 27){
                    home_user();
                }else if(w==8){
                   beli_barang(id_beli,jumlah);
                }
                }
            }
            else if(uang[cari] < total){
                for(int t = 0 ; t < 11 ; t++){
                    if(t %2 ==0){
                        gotoxy(94,11); set(4,15);printf("MOHON MAAF SALDO ANDA TIDAK MENCUKUPI");
                        Sleep(500);
                    }else{
                        gotoxy(94,11); set(4,15);printf("                                      ");
                        Sleep(500);
                    }
                }
                    gotoxy(100,13); set(0,12);printf("TEKAN [ESC] UNTUK KEMBALI");
                   gotoxy(93,14); set(4,15);printf("[BACKSPACE] UNTUK MENGUBAH JUMLAH BELI");
                    char r;
                    while((r =getch ())){
                        if(r == 27){
                            home_user();
                        }else if(r==8){
                            beli_barang(id_beli,jumlah);
                    }
                }
            }
        

        for(int v = 0 ; v < 12 ; v++){
            if(v%2==0){
                gotoxy(96,11); set(10,15);printf("PEMBELIAN ANDA SEDANG DI PROSES");
                Sleep(400);
            }
            else{
                gotoxy(96,11); set(10,15);printf("                                ");
                Sleep(400);
            }
          }
          gotoxy(40,9); set(50,14);printf("LANNJUT BAYAR?");
          int poss;
          poss = chose5();
          if(poss==2){
            for(int n = 0 ; n < 12 ; n++){
            if(n%2==0){
                 gotoxy(96,11); set(4,15);printf("     PEMBELIAN  DIBATALKAN    ");
                Sleep(400);
            }
            else{
                 gotoxy(96,11); set(10,15);printf("                                 ");
                Sleep(400);
            }
          }
                    gotoxy(100,13); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                    gotoxy(93,14); set(0,15);printf("[BACKSPACE] UNTUK MENGULAGI PEMBELIAN");
                    char r;
                    while((r =getch ())){
                        if(r == 27){
                            home_user();
                        }else if(r==8){
                            bingkai(0,0,90,31,8,14);
                            beli_barang(id_beli,jumlah);
                    }
                }
          }  
        
          pindah_barang();
          pindah_user();
          FILE* hubung = fopen("min.txt","w");
          fprintf(hubung,"%d",sal_min);
          fclose(hubung);
          int j = 0 ;
          FILE * conetc=fopen("riwayat.txt","a");
          while(j < id ){
                    if(id_beli == id_barang[j]){
                    fprintf(conetc,"%d#%s#%d#%d\n",id_beli,tam_barang[j],jumlah,total);
                    }
                    j++;
          }
          fclose(conetc);
          for(int d = 0 ; d < 11 ; d++){
            if(d%2==0){
                gotoxy(96,11); set(10,15);printf("      PEMBAYARAN    BERHASIL   ");
                Sleep(400);
            }
            else{
                gotoxy(96,11); set(10,15);printf("                                ");
                Sleep(400);
            }
          }
           gotoxy(98,14); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI ");
          char klik; 
          while((klik  = getch ())){
            if(klik == 27){
                home_user();
            }
          }
}

void riwayat_pembelian(){
          int tam1,tam2,tam3;
          char tam4[100];
          int i=0;  
          bingkai(2,2,86,27,4,14);
          gotoxy(6,3); set(10,14);          printf("ID BARANG\t\tNAMA BARANG\t\t  JUMLAH BARANG\t    TOTAL HARGA ");
          FILE * hub=fopen("riwayat.txt","r");
          while(fscanf(hub,"%d#%[^#]#%d#%d\n",&tam1,&tam4,&tam2,&tam3)!=EOF){
                 gotoxy(8,5+i); set(0,14); printf("%d\t\t %s\t\t    %d\t\t\t%d ",tam1,tam4,tam2,tam3);
                 i++;
          }
          fclose(hub);

          gotoxy(33,30); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI ");
          char klik; 
          while((klik  = getch ())){
            if(klik == 27 ){
                home_admin();
            }
          }
          
}

void animasi(){
    bingkai(0,0,90,31,8,14);
    bingkai(5,3,80,25,4,14);
    gotoxy(39,5); set(10,14);  printf("WELCOME TO THE");
    gotoxy(34,6); set(10,14);  printf("IKMAL COMPUTER EQUIPMENT");
    gotoxy(44,7); set(10,14);  printf("SHOP");
    gotoxy(32,11); set(0,14);  printf("BISMILLAH HIROHMAN NIROHIM");
    gotoxy(16,12); set(0,14); printf("PERTAMA TAMA DAN YANG PALING UTAMA, MARILAH KITA PANJATKAN");
    gotoxy(16,13); set(0,14); printf("PUJA DAN PUJI SYUKUR KEHADIRAT ALLAH SWT YANG MANA TELAH");
    gotoxy(16,14); set(0,14); printf("MEMBERIKAN HIDAYAH SERTA INAYAH NYA KEPADA KITA SEHINGGA");
    gotoxy(16,15); set(0,14); printf("KITA BISA BERKUMPUL DI RUANGAN INI DALAM RANGKA PERSENTASI");
    gotoxy(32,16); set(0,14); printf("PROJEKAN ATAU UAS BAHASA C");
    gotoxy(16,19); set(0,14); printf("YANG KEDUA,SHOLAWAT BERIRING SALAM KITA SANJUNGKAN KEPADA");
    gotoxy(16,20); set(0,14); printf("BAGINDA NABI MUHAMMAD SAW YANG TELAH MEMBAWA KITA DARI ZAMAN");
    gotoxy(16,21); set(0,14); printf("KEGELAPAN MENUJU ZAMAN TERANG BENERANG DENGAN CAHAYA ISLAM");

    char klik;
    gotoxy(30,27); set(10,14); printf("TEKAN [ENTER] UNTUK MASUK PROGRAM ");
    while((klik=getch())){
        if(klik==13){
            chose();
        }
    }
}

void chose(){
 int posisi=1;
 char klik;
 char a=219;

  bingkai(0,0,90,31,8,14);
  bingkai(34,13,22,4,4,0);
  gotoxy(43,15);set(10,0); printf("ADMIN");
  bingkai(34,17,22,4,4,14);
  gotoxy(43,19);set(10,14); printf("USER");
  bingkai(34,21,22,4,4,14);
  gotoxy(43,23);set(10,14); printf("ABOUT");
  bingkai(34,25,22,4,4,14);
  gotoxy(43,27);set(10,14); printf("EXIT");


gotoxy(9,5);set(0,14);    printf("%c%c%c    %c%c%c  %c%c%c%c%c  %c%c %c%c%c    %c%c     %c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(9,6);set(0,14);    printf("%c%c%c%c  %c%c%c%c %c%c   %c%c %c%c %c%c%c%c   %c%c     %c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(9,7);set(0,14);    printf("%c%c %c%c%c%c %c%c %c%c%c%c%c%c%c %c%c %c%c %c%c  %c%c     %c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(9,8);set(0,14);    printf("%c%c  %c%c  %c%c %c%c   %c%c %c%c %c%c  %c%c %c%c     %c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
gotoxy(9,9);set(0,14);    printf("%c%c      %c%c %c%c   %c%c %c%c %c%c   %c%c%c%c     %c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

while((klik = getch ()) !=13){
    if(klik==80){
        if(posisi==1){
            posisi=2;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,0);
            gotoxy(43,19);set(10,0);  printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
        else if(posisi==2){
            posisi=3;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,0);
            gotoxy(43,23);set(10,0); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
        else if(posisi==3){
            posisi=4;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,0);
            gotoxy(43,27);set(10,0); printf("EXIT");
        }
        else if(posisi==4){
            posisi=1;
            bingkai(34,13,22,4,4,0);
            gotoxy(43,15);set(10,0); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
    }
    else if(klik==72){
            if(posisi==1){
            posisi=4;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,0);
            gotoxy(43,27);set(10,0); printf("EXIT");
            
        }
        else if(posisi==2){
            posisi=1;
            bingkai(34,13,22,4,4,0);
            gotoxy(43,15);set(10,0); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
        else if(posisi==3){
            posisi=2;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,0);
            gotoxy(43,19);set(10,0); printf("USER");
            bingkai(34,21,22,4,4,14);
            gotoxy(43,23);set(10,14); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
        else if(posisi==4){
            posisi=3;
            bingkai(34,13,22,4,4,14);
            gotoxy(43,15);set(10,14); printf("ADMIN");
            bingkai(34,17,22,4,4,14);
            gotoxy(43,19);set(10,14); printf("USER");
            bingkai(34,21,22,4,4,0);
            gotoxy(43,23);set(10,0); printf("ABOUT");
            bingkai(34,25,22,4,4,14);
            gotoxy(43,27);set(10,14); printf("EXIT");
        }
    }
}
if(posisi==1){
    login_admin();
}
else if(posisi==2){
    chose2();
}
else if(posisi==3){
    about();
}
else if(posisi==4){
    exit(0);
}
}

int chose2(){
          char klik;
          int posisi=1;
          bingkai(0,0,90,31,8,14);
          logo_user();

          bingkai(34,16,22,4,0,10);
          gotoxy(43,18); set(0,10); printf("LOGIN");
          bingkai(34,20,22,4,0,14);
          gotoxy(42,22); set(0,14); printf("SIGN UP");
          bingkai(34,24,22,4,0,14);
          gotoxy(43,26); set(0,14); printf("BACK");

          while((klik = getch ()) != 13){
            if(klik==80){
                if(posisi==1){
                    posisi=2;
                    bingkai(34,16,22,4,0,14);
                    gotoxy(43,18); set(0,14); printf("LOGIN");
                    bingkai(34,20,22,4,0,10);
                    gotoxy(42,22); set(0,10); printf("SIGN UP");
                    bingkai(34,24,22,4,0,14);
                    gotoxy(43,26); set(0,14); printf("BACK");
                    
                }
                else if(posisi==2){
                    posisi=3;
                    bingkai(34,16,22,4,0,14);
                    gotoxy(43,18); set(0,14); printf("LOGIN");
                    bingkai(34,20,22,4,0,14);
                    gotoxy(42,22); set(0,14); printf("SIGN UP");
                    bingkai(34,24,22,4,0,10);
                    gotoxy(43,26); set(0,10); printf("BACK");
                    
                }
                else if(posisi==3){
                    posisi=1;
                    bingkai(34,16,22,4,0,10);
                    gotoxy(43,18); set(0,10); printf("LOGIN");
                    bingkai(34,20,22,4,0,14);
                    gotoxy(42,22); set(0,14); printf("SIGN UP");
                    bingkai(34,24,22,4,0,14);
                    gotoxy(43,26); set(0,14); printf("BACK");
                    
                }
            }
            else if(klik==72){
                if(posisi==1){
                    posisi=3;
                    bingkai(34,16,22,4,0,14);
                    gotoxy(43,18); set(0,14); printf("LOGIN");
                    bingkai(34,20,22,4,0,14);
                    gotoxy(42,22); set(0,14); printf("SIGN UP");
                    bingkai(34,24,22,4,0,10);
                    gotoxy(43,26); set(0,10); printf("BACK");
                }
                else if(posisi==2){
                    posisi=1;
                    bingkai(34,16,22,4,0,10);
                    gotoxy(43,18); set(0,10); printf("LOGIN");
                    bingkai(34,20,22,4,0,14);
                    gotoxy(42,22); set(0,14); printf("SIGN UP");
                    bingkai(34,24,22,4,0,14);
                    gotoxy(43,26); set(0,14); printf("BACK");
                }
                else if(posisi==3){
                    posisi=2;
                    bingkai(34,16,22,4,0,14);
                    gotoxy(43,18); set(0,14); printf("LOGIN");
                    bingkai(34,20,22,4,0,10);
                    gotoxy(42,22); set(0,10); printf("SIGN UP");
                    bingkai(34,24,22,4,0,14);
                    gotoxy(43,26); set(0,14); printf("BACK");
                }
            }
          }
        if(posisi==1){
            login_user();
        }
        else if(posisi==2){
            sign_user();
        }
        else if(posisi==3){
            chose();
        }
}

int chose3(){
    int posisi=1;
    char klik;
    char a=219;

  bingkai(0,0,90,31,8,14);
    gotoxy(5,3);set(2,14);printf("%c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c      %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c    %c%c%c %c%c %c%c%c    %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(5,4);set(2,14);printf("%c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c     %c%c   %c%c %c%c   %c%c %c%c%c%c  %c%c%c%c %c%c %c%c%c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(5,5);set(2,14);printf("%c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c     %c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c%c%c %c%c %c%c %c%c %c%c  %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(5,6);set(2,14);printf("%c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c     %c%c   %c%c %c%c   %c%c %c%c  %c%c  %c%c %c%c %c%c  %c%c %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(5,7);set(2,14);printf("%c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c      %c%c   %c%c %c%c%c%c%c%c  %c%c      %c%c %c%c %c%c   %c%c%c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
  bingkai(8,13,17,4,0,1);
        gotoxy(10,15);set(4,1); printf("TAMBAH BARANG");
        bingkai(8,19,17,4,0,14);
        gotoxy(10,21);set(4,14); printf("HAPUS BARANG");
        bingkai(8,25,17,4,0,14);
        gotoxy(10,27);set(4,14); printf("UPDATE BARANG");
        bingkai(65,13,17,4,0,14);
        gotoxy(67,15);set(4,14); printf("LIHAT BARANG");
        bingkai(65,19,17,4,0,14);
        gotoxy(67,21);set(4,14); printf("TAMPIL SALDO");
        bingkai(65,25,17,4,0,14);
        gotoxy(68,27);set(4,14); printf("HISTORY");
        bingkai(34,13,22,4,0,14);
        gotoxy(40,15);set(4,14); printf("TARIK SALDO");
        bingkai(34,25,22,4,0,14);
        gotoxy(42,27);set(4,14); printf("LOG OUT");

    while((klik = getch ()) !=13 ){
        if(klik == 80){
            if(posisi==1){
                posisi=2;
                bingkai(8,13,17,4,0,14);
                gotoxy(10,15);set(4,14); printf("TAMBAH BARANG");
                bingkai(8,19,17,4,0,1);
                gotoxy(10,21);set(4,1); printf("HAPUS BARANG");
            }
            else if(posisi==2){
                posisi=3;
                bingkai(8,19,17,4,0,14);
                gotoxy(10,21);set(4,14); printf("HAPUS BARANG");
                bingkai(8,25,17,4,0,1);
                gotoxy(10,27);set(4,1); printf("UPDATE BARANG");
            }
            else if(posisi==3){
                posisi=4;
                bingkai(34,13,22,4,0,1);
                gotoxy(40,15);set(4,1); printf("TARIK SALDO");
                bingkai(8,25,17,4,0,14);
                gotoxy(10,27);set(4,14); printf("UPDATE BARANG");
            }
            else if(posisi==4){
                posisi=5;
                bingkai(34,13,22,4,0,14);
                gotoxy(40,15);set(4,14); printf("TARIK SALDO");
                bingkai(34,25,22,4,0,1);
                gotoxy(42,27);set(4,1); printf("LOG OUT");
            }
            else if(posisi==5){
                posisi=6;
                bingkai(34,25,22,4,0,14);
                gotoxy(42,27);set(4,14); printf("LOG OUT");
                bingkai(65,13,17,4,0,1);
                gotoxy(67,15);set(4,1); printf("LIHAT BARANG");
            }
            else if(posisi==6){
                posisi=7;
                bingkai(65,13,17,4,0,14);
                gotoxy(67,15);set(4,14); printf("LIHAT BARANG");
                bingkai(65,19,17,4,0,1);
                gotoxy(67,21);set(4,1); printf("TAMPIL SALDO");
            }
            else if(posisi==7){
                posisi=8;
                bingkai(65,19,17,4,0,14);
                gotoxy(67,21);set(4,14); printf("TAMPIL SALDO");
                bingkai(65,25,17,4,0,1);
                gotoxy(68,27);set(4,1); printf("HISTORY");
            }
            else if(posisi==8){
                posisi=1;
                bingkai(8,13,17,4,0,1);
                gotoxy(10,15);set(4,1); printf("TAMBAH BARANG");
                bingkai(65,25,17,4,0,14);
                gotoxy(68,27);set(4,14); printf("HISTORY");
            }
        }
        else if(klik==72){
            if(posisi==1){
                posisi=8;
                bingkai(65,25,17,4,0,1);
                gotoxy(68,27);set(4,1); printf("HISTORY");
                bingkai(8,13,17,4,0,14);
                gotoxy(10,15);set(4,14); printf("TAMBAH BARANG");
            }
            else if(posisi==2){
                posisi=1;
                bingkai(8,13,17,4,0,1);
                gotoxy(10,15);set(4,1); printf("TAMBAH BARANG");
                bingkai(8,19,17,4,0,14);
                gotoxy(10,21);set(4,14); printf("HAPUS BARANG");
            }
            else if(posisi==3){
                posisi=2;
                bingkai(8,19,17,4,0,1);
                gotoxy(10,21);set(4,1); printf("HAPUS BARANG");
                bingkai(8,25,17,4,0,14);
                gotoxy(10,27);set(4,14); printf("UPDATE BARANG");
            }
            else if(posisi==4){
                posisi=3;
                bingkai(8,25,17,4,0,1);
                gotoxy(10,27);set(4,1); printf("UPDATE BARANG");
                bingkai(34,13,22,4,0,14);
                gotoxy(40,15);set(4,14); printf("TARIK SALDO");
            }
            else if(posisi==5){
                posisi=4;
                bingkai(34,13,22,4,0,1);
                gotoxy(40,15);set(4,1); printf("TARIK SALDO");
                bingkai(34,25,22,4,0,14);
                gotoxy(42,27);set(4,14); printf("LOG OUT");
            }
            else if(posisi==6){
                posisi=5;
                bingkai(34,25,22,4,0,1);
                gotoxy(42,27);set(4,1); printf("LOG OUT");
                bingkai(65,13,17,4,0,14);
                gotoxy(67,15);set(4,14); printf("LIHAT BARANG");
            }
            else if(posisi==7){
                posisi=6;
                bingkai(65,13,17,4,0,1);
                gotoxy(67,15);set(4,1); printf("LIHAT BARANG");
                bingkai(65,19,17,4,0,14);
                gotoxy(67,21);set(4,14); printf("TAMPIL SALDO");
            }
            else if(posisi==8){
                posisi=7;
                bingkai(65,19,17,4,0,1);
                gotoxy(67,21);set(4,1); printf("TAMPIL SALDO");
                bingkai(65,25,17,4,0,14);
                gotoxy(68,27);set(4,14); printf("HISTORY");
            }
        }
        else if(klik==77){
            if(posisi==1){
               posisi=4;
               bingkai(34,13,22,4,0,1);
               gotoxy(40,15);set(4,1); printf("TARIK SALDO");
               bingkai(8,13,17,4,0,14);
               gotoxy(10,15);set(4,14); printf("TAMBAH BARANG");
            }
            else if(posisi==2){
                posisi=7;
                bingkai(65,19,17,4,0,1);
                gotoxy(67,21);set(4,1); printf("TAMPIL SALDO");
                bingkai(8,19,17,4,0,14);
                gotoxy(10,21);set(4,14); printf("HAPUS BARANG");
            }
            else if(posisi==3){
                posisi=5;
                bingkai(34,25,22,4,0,1);
                gotoxy(42,27);set(4,1); printf("LOG OUT");
                bingkai(8,25,17,4,0,14);
                gotoxy(10,27);set(4,14); printf("UPDATE BARANG");
            }
            else if(posisi==4){
                posisi=6;
                bingkai(65,13,17,4,0,1);
                gotoxy(67,15);set(4,1); printf("LIHAT BARANG");
                bingkai(34,13,22,4,0,14);
                gotoxy(40,15);set(4,14); printf("TARIK SALDO");
            }
            else if(posisi==5){
                posisi=8;
                bingkai(65,25,17,4,0,1);
                gotoxy(68,27);set(4,1); printf("HISTORY");
                bingkai(34,25,22,4,0,14);
                gotoxy(42,27);set(4,14); printf("LOG OUT");
            }
            else if(posisi==6){
                posisi=1;
                bingkai(8,13,17,4,0,1);
                gotoxy(10,15);set(4,1); printf("TAMBAH BARANG");
                bingkai(65,13,17,4,0,14);
                gotoxy(67,15);set(4,14); printf("LIHAT BARANG");
            }
            else if(posisi==7){
                posisi=2;
                bingkai(8,19,17,4,0,1);
                gotoxy(10,21);set(4,1); printf("HAPUS BARANG");
                bingkai(65,19,17,4,0,14);
                gotoxy(67,21);set(4,14); printf("TAMPIL SALDO");
            }
            else if(posisi==8){
                posisi=3;
                bingkai(8,25,17,4,0,1);
                gotoxy(10,27);set(4,1); printf("UPDATE BARANG");
                bingkai(65,25,17,4,0,14);
                gotoxy(68,27);set(4,14); printf("HISTORY");
            }
        }
        else if(klik==75){
            if(posisi==1){
                posisi=6;
                bingkai(65,13,17,4,0,1);
                gotoxy(67,15);set(4,1); printf("LIHAT BARANG");
                bingkai(8,13,17,4,0,14);
                gotoxy(10,15);set(4,14); printf("TAMBAH BARANG");
            }
            else if(posisi==2){
                posisi=7;
                bingkai(65,19,17,4,0,1);
                gotoxy(67,21);set(4,1); printf("TAMPIL SALDO");
                bingkai(8,19,17,4,0,14);
                gotoxy(10,21);set(4,14); printf("HAPUS BARANG");
            }
            else if(posisi==3){
                posisi=8;
                bingkai(65,25,17,4,0,1);
                gotoxy(68,27);set(4,1); printf("HISTORY");
                bingkai(8,25,17,4,0,14);
                gotoxy(10,27);set(4,14); printf("UPDATE BARANG");
            }
            else if(posisi==4){
                posisi=1;
                bingkai(8,13,17,4,0,1);
                gotoxy(10,15);set(4,1); printf("TAMBAH BARANG");
                bingkai(34,13,22,4,0,14);
                gotoxy(40,15);set(4,14); printf("TARIK SALDO");
            }
            else if(posisi==5){
                posisi=3;
                bingkai(8,25,17,4,0,1);
                gotoxy(10,27);set(4,1); printf("UPDATE BARANG");
                bingkai(34,25,22,4,0,14);
                gotoxy(42,27);set(4,14); printf("LOG OUT");
            }
            else if(posisi==6){
                posisi=4;
                bingkai(34,13,22,4,0,1);
                gotoxy(40,15);set(4,1); printf("TARIK SALDO");
                bingkai(65,13,17,4,0,14);
                gotoxy(67,15);set(4,14); printf("LIHAT BARANG");
            }
            else if(posisi==7){
                posisi=2;
                bingkai(65,19,17,4,0,14);
                gotoxy(67,21);set(4,14); printf("TAMPIL SALDO");
                bingkai(8,19,17,4,0,1);
                gotoxy(10,21);set(4,1); printf("HAPUS BARANG");
            }
            else if(posisi==8){
                posisi=5;
                bingkai(34,25,22,4,0,1);
                gotoxy(42,27);set(4,1); printf("LOG OUT");
                bingkai(65,25,17,4,0,14);
                gotoxy(68,27);set(4,14); printf("HISTORY");
            }
        }
    }
    return posisi;
}

int chose4(){
          int posisi=1;  
          char klik,a=219;

          bingkai(0,0,90,31,8,14);  
          gotoxy(9,4);set(4,14);printf("%c%c%c    %c%c%c %c%c%c%c%c%c%c %c%c%c    %c%c %c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
          gotoxy(9,5);set(4,14);printf("%c%c%c%c  %c%c%c%c %c%c      %c%c%c%c   %c%c %c%c    %c%c     %c%c    %c%c %c%c      %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
          gotoxy(9,6);set(4,14);printf("%c%c %c%c%c%c %c%c %c%c%c%c%c   %c%c %c%c  %c%c %c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
          gotoxy(9,7);set(4,14);printf("%c%c  %c%c  %c%c %c%c      %c%c  %c%c %c%c %c%c    %c%c     %c%c    %c%c      %c%c %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
          gotoxy(9,8);set(4,14);printf("%c%c      %c%c %c%c%c%c%c%c%c %c%c   %c%c%c%c  %c%c%c%c%c%c       %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
          bingkai(10,15,20,4,0,9); 
          gotoxy(15,17);set(10,9); printf("BELI BARANG");
          bingkai(10,23,20,4,0,14); 
          gotoxy(15,25);set(10,14); printf("LIHAT PROFIL");
          bingkai(36,15,20,4,0,14); 
          gotoxy(41,17);set(10,14); printf("EDIT PROFIL");
          bingkai(36,23,20,4,0,14); 
          gotoxy(40,25);set(10,14); printf("TAMPIL BARANG ");
          bingkai(62,15,20,4,0,14); 
          gotoxy(67,17);set(10,14); printf("TAMBAH SALDO");
          bingkai(62,23,20,4,0,14); 
          gotoxy(69,25);set(10,14); printf("LOG OUT ");

          while((klik = getch()) != 13){
            if(klik==80){
                if(posisi==1){
                    posisi=2;
                    bingkai(10,23,20,4,0,9); 
                    gotoxy(15,25);set(10,9); printf("LIHAT PROFIL");
                    bingkai(10,15,20,4,0,14); 
                    gotoxy(15,17);set(10,14); printf("BELI BARANG");
                }
                else if(posisi==2){
                    posisi=3;
                    bingkai(36,15,20,4,0,9); 
                    gotoxy(41,17);set(10,9); printf("EDIT PROFIL");
                    bingkai(10,23,20,4,0,14); 
                    gotoxy(15,25);set(10,14); printf("LIHAT PROFIL");
                }
                else if(posisi==3){
                    posisi=4;
                    bingkai(36,23,20,4,0,9); 
                    gotoxy(40,25);set(10,9); printf("TAMPIL BARANG ");
                    bingkai(36,15,20,4,0,14); 
                    gotoxy(41,17);set(10,14); printf("EDIT PROFIL");
                }
                else if(posisi==4){
                    posisi=5;
                    bingkai(62,15,20,4,0,9); 
                    gotoxy(67,17);set(10,9); printf("TAMBAH SALDO");
                    bingkai(36,23,20,4,0,14); 
                    gotoxy(40,25);set(10,14); printf("TAMPIL BARANG ");
                }
                else if(posisi==5){
                    posisi=6;
                    bingkai(62,23,20,4,0,9); 
                    gotoxy(69,25);set(10,9); printf("LOG OUT ");
                    bingkai(62,15,20,4,0,14); 
                    gotoxy(67,17);set(10,14); printf("TAMBAH SALDO");
                }
                else if(posisi==6){
                    posisi=1;
                    bingkai(10,15,20,4,0,9); 
                    gotoxy(15,17);set(10,9); printf("BELI BARANG");
                    bingkai(62,23,20,4,0,14); 
                    gotoxy(69,25);set(10,14); printf("LOG OUT ");
                }
            }
            else if(klik==72){
                if(posisi==1){
                    posisi=6;
                    bingkai(62,23,20,4,0,9); 
                    gotoxy(69,25);set(10,9); printf("LOG OUT ");
                    bingkai(10,15,20,4,0,14); 
                    gotoxy(15,17);set(10,14); printf("BELI BARANG");
                }
                else if(posisi==2){
                    posisi=1;
                    bingkai(10,15,20,4,0,9); 
                    gotoxy(15,17);set(10,9); printf("BELI BARANG");
                    bingkai(10,23,20,4,0,14); 
                    gotoxy(15,25);set(10,14); printf("LIHAT PROFIL");
                }
                else if(posisi==3){
                    posisi=2;
                    bingkai(10,23,20,4,0,9); 
                    gotoxy(15,25);set(10,9); printf("LIHAT PROFIL");
                    bingkai(36,15,20,4,0,14); 
                    gotoxy(41,17);set(10,14); printf("EDIT PROFIL");
                }
                else if(posisi==4){
                    posisi=3;
                    bingkai(36,15,20,4,0,9); 
                    gotoxy(41,17);set(10,9); printf("EDIT PROFIL");
                    bingkai(36,23,20,4,0,14); 
                    gotoxy(40,25);set(10,14); printf("TAMPIL BARANG ");
                }
                else if(posisi==5){
                    posisi=4;
                    bingkai(36,23,20,4,0,9); 
                    gotoxy(40,25);set(10,9); printf("TAMPIL BARANG ");
                    bingkai(62,15,20,4,0,14); 
                    gotoxy(67,17);set(10,14); printf("TAMBAH SALDO");
                }
                else if(posisi==6){
                    posisi=5;
                    bingkai(62,15,20,4,0,9); 
                    gotoxy(67,17);set(10,9); printf("TAMBAH SALDO");
                    bingkai(62,23,20,4,0,14); 
                    gotoxy(69,25);set(10,14); printf("LOG OUT ");
                }
            }
            else if(klik==77){
                if(posisi==1){
                    posisi=3;
                    bingkai(36,15,20,4,0,9); 
                    gotoxy(41,17);set(10,9); printf("EDIT PROFIL");
                    bingkai(10,15,20,4,0,14); 
                    gotoxy(15,17);set(10,14); printf("BELI BARANG");
                }
                else if(posisi==2){
                    posisi=4;
                    bingkai(36,23,20,4,0,9); 
                    gotoxy(40,25);set(10,9); printf("TAMPIL BARANG ");
                    bingkai(10,23,20,4,0,14); 
                    gotoxy(15,25);set(10,14); printf("LIHAT PROFIL");
                }
                else if(posisi==3){
                    posisi=5;
                    bingkai(62,15,20,4,0,9); 
                    gotoxy(67,17);set(10,9); printf("TAMBAH SALDO");
                    bingkai(36,15,20,4,0,14); 
                    gotoxy(41,17);set(10,14); printf("EDIT PROFIL");
                }
                else if(posisi==4){
                    posisi=6;
                    bingkai(62,23,20,4,0,9); 
                    gotoxy(69,25);set(10,9); printf("LOG OUT ");
                    bingkai(36,23,20,4,0,14); 
                    gotoxy(40,25);set(10,14); printf("TAMPIL BARANG ");
                }
                else if(posisi==5){
                    posisi=2;
                    bingkai(10,23,20,4,0,9); 
                    gotoxy(15,25);set(10,9); printf("LIHAT PROFIL");
                    bingkai(62,15,20,4,0,14); 
                    gotoxy(67,17);set(10,14); printf("TAMBAH SALDO");
                }
                else if(posisi==6){
                    posisi=1;
                    bingkai(10,15,20,4,0,9); 
                    gotoxy(15,17);set(10,9); printf("BELI BARANG");
                    bingkai(62,23,20,4,0,14); 
                    gotoxy(69,25);set(10,14); printf("LOG OUT ");
                }
            }
            else if(klik==75){
                if(posisi==1){
                    posisi=6;
                    bingkai(62,23,20,4,0,9); 
                    gotoxy(69,25);set(10,9); printf("LOG OUT ");
                    bingkai(10,15,20,4,0,14); 
                    gotoxy(15,17);set(10,14); printf("BELI BARANG");
                }
                else if(posisi==2){
                    posisi=5;
                    bingkai(62,15,20,4,0,9); 
                    gotoxy(67,17);set(10,9); printf("TAMBAH SALDO");
                    bingkai(10,23,20,4,0,14); 
                    gotoxy(15,25);set(10,14); printf("LIHAT PROFIL");
                }
                else if(posisi==3){
                    posisi=1;
                    bingkai(10,15,20,4,0,9); 
                    gotoxy(15,17);set(10,9); printf("BELI BARANG");
                    bingkai(36,15,20,4,0,14); 
                    gotoxy(41,17);set(10,14); printf("EDIT PROFIL");
                }
                else if(posisi==4){
                    posisi=2;
                    bingkai(10,23,20,4,0,9); 
                    gotoxy(15,25);set(10,9); printf("LIHAT PROFIL");
                    bingkai(36,23,20,4,0,14); 
                    gotoxy(40,25);set(10,14); printf("TAMPIL BARANG ");
                }
                else if(posisi==5){
                    posisi=3;
                    bingkai(36,15,20,4,0,9); 
                    gotoxy(41,17);set(10,9); printf("EDIT PROFIL");
                    bingkai(62,15,20,4,0,14); 
                    gotoxy(67,17);set(10,14); printf("TAMBAH SALDO");
                }
                else if(posisi==6){
                    posisi=4;
                    bingkai(36,23,20,4,0,9); 
                    gotoxy(40,25);set(10,9); printf("TAMPIL BARANG ");
                    bingkai(62,23,20,4,0,14); 
                    gotoxy(69,25);set(10,14); printf("LOG OUT ");
                }
            }
          }
          return posisi;  
}

int chose5(){
    char klik;
    int posisi=1;
    bingkai(22,12,22,4,0,9);
    gotoxy(30,14);set(0,9);printf("BOWLEHHH");
    bingkai(48,12,22,4,0,14);
    gotoxy(55,14);set(0,14);printf("GAJADI AH");

    while((klik = getch ()) !=13){
        if(klik == 77){
            if(posisi==1){
                posisi=2;
                bingkai(22,12,22,4,0,14);
                gotoxy(30,14);set(0,14);printf("BOWLEHHH");
                bingkai(48,12,22,4,0,9);
                gotoxy(55,14);set(0,9);printf("GAJADI AH");
            }
            else if(posisi==2){
                posisi=1;
                bingkai(22,12,22,4,0,9);
                gotoxy(30,14);set(0,9);printf("BOWLEHHH");
                bingkai(48,12,22,4,0,14);
                gotoxy(55,14);set(0,14);printf("GAJADI AH");
            }
        }
        else if(klik == 75){
            if(posisi==1){
                posisi=2;
                bingkai(22,12,22,4,0,14);
                gotoxy(30,14);set(0,14);printf("BOWLEHHH");
                bingkai(48,12,22,4,0,9);
                gotoxy(55,14);set(0,9);printf("GAJADI AH");
            }
            else if(posisi==2){
                posisi=1;
                bingkai(22,12,22,4,0,9);
                gotoxy(30,14);set(0,9);printf("BOWLEHHH");
                bingkai(48,12,22,4,0,14);
                gotoxy(55,14);set(0,14);printf("GAJADI AH");
            }
        }
    }
    return posisi;
}

void about(){
   bingkai(0,0,90,31,8,14);
   bingkai(5,3,80,25,4,14);

    char a=219;
    gotoxy(25,5);   set(9,14);printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c      %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
    gotoxy(25,6);   set(9,14);printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c          %c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
    gotoxy(25,7);   set(9,14);printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
    gotoxy(25,8);   set(9,14);printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c           %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);  
    gotoxy(25,9);   set(9,14);printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c      %c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

   gotoxy(25,12); set(4,14);   printf("SELAMAT DATANG DI APLIKASI SAYA YANG BERNAMA");
   gotoxy(32,13); set(10,14);  printf("IKMAL COMPUTER EQUPMENT SHOP");
   gotoxy(13,15);  set(4,14);  printf("[ PENJELASAN APLIKASI ]");
   gotoxy(13,16); set(5,14);   printf("ALIKASI INI DIBUAT UNTUK MEMPERMUDAH ORANG LAIN MEMBELI PERALATAN");
   gotoxy(13,17); set(6,14);   printf("ATAU AKSESORIS KOMPUTER,DAN SAYA BERHARAP APLIKASI INI BISA ");
   gotoxy(13,18); set(1,14);   printf("BERGUNA UNTUK ORANG BANYAK............");
   gotoxy(13,19); set(12,14);  printf("DAN SAYA JUGA BERHARAP DARI PROJEK APLIKASI SEDERHANA SAYA BISA");
   gotoxy(13,20); set(13,14);  printf("MENDAPATKAN NILAI YANG MEUMUASKAN........AAMIIN...........");
   
    char klik;
    gotoxy(48,27); set(10,14); printf("TEKAN >>>> UNTUK KE SLIDE BERIKUTNYA");
    while((klik=getch())){
        if(klik==77){
            about2();
        }
    }
}

void about2(){

    char a=219;
    bingkai(0,0,90,31,8,14);
    bingkai(5,3,80,25,4,14);
    gotoxy(23,5);   set(4,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,6);   set(4,14); printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,7);   set(4,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,8);   set(4,14); printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c          %c%c      ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,9);   set(4,14); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
                        
    gotoxy(13,12);  set(2,14);  printf("APLIKASI INI  MENYEDIAKAN BEBERAPA BARANG ATAU AKSESORIS KOMPUTER");   
    gotoxy(14,13);  set(10,14); printf("KARENA PADA ZAMAN SEPERTI SEKARANG YANG SERBA DIGITAL AKSESORIS"); 
    gotoxy(19,14);  set(0,14);  printf("SEPERTI INI SANGAT DIPERLUKAN OLEH MASYARAKAT BANYAK");
    char klik;
    gotoxy(48,27); set(10,14); printf("TEKAN >>>> UNTUK KE SLIDE BERIKUTNYA ");
    gotoxy(6,27); set(10,14); printf("TEKAN <<<< UNTUK KE SLIDE SEBELUMNYA ");
    while((klik=getch())){
        if(klik==77){
            about3();
        }else if(klik==75){
            about();
        }
    }
}

void about3(){
    char a=219;

    bingkai(0,0,90,31,8,14);
    bingkai(5,3,80,25,4,14);
    gotoxy(23,5);   set(6,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,6);   set(6,14); printf("%c%c      %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,7);   set(6,14); printf("%c%c%c%c%c%c%c %c%c      %c%c %c%c   %c%c %c%c%c%c%c        %c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,8);   set(6,14); printf("     %c%c %c%c      %c%c %c%c   %c%c %c%c               %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(23,9);   set(6,14); printf("%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c %c%c%c%c%c%c  %c%c%c%c%c%c%c     %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);

    gotoxy(17,12);  set(0,14);  printf("NIKMATI KEMUDAHAN BERBELANJA MELALUI APLIKASI IKMAL SHOP");
    gotoxy(30,13);  set(11,14);  printf("BELANJA LEBIH AMAN DAN HEMAT");
    gotoxy(37,14);  set(4,14);  printf("SELAMAT MENCOBA");
    gotoxy(38,20); set(4,14);   printf("[  CATATAN  ]");
    gotoxy(13,21); set(4,14);   printf("APLIKASI INI DUAT / DIKODING OLEH TANGAN YANG TIDAK PERNAH ENGKAU");
    gotoxy(40,22); set(4,14);   printf("GENGGAM !!");

    char klik;
    gotoxy(25,25); set(0,12); printf("TEKAN [@] UNTUK MENGUNJINGI PROFIL IG @_IMALS");
    gotoxy(17,26); set(40,14); printf("TEKAN [#] UNTUK MENGUNJINGI PROFIL TIK TOK SI IMAL BAIK HATI");
    gotoxy(59,27); set(10,14); printf("TEKAN [ESC] UNTUK KEMBALI ");
    gotoxy(6,27); set(10,14); printf("TEKAN <<<< UNTUK KE SLIDE SEBELUMNYA ");
    while((klik=getch())){
        if(klik == 27){
            chose();
        }
        else if(klik == 75){
            about2();
        }
        else if(klik == 64){
            system("START https://www.instagram.com/_imals/");
        }else if(klik == 35){
            system("START https://www.tiktok.com/@imalbaikhati");
        }
    }
}

void logo_user(){
    char a=219;
    bingkai(0,0,90,31,8,14);
    gotoxy(29,3);set(4,14);printf("%c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(29,4);set(4,14);printf("%c%c    %c%c %c%c      %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(29,5);set(4,14);printf("%c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(29,6);set(4,14);printf("%c%c    %c%c      %c%c %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(29,7);set(4,14);printf(" %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
                        
}

void logo_login_user(){
char a =219;
    bingkai(0,0,90,31,8,14);
    gotoxy(8,3);set(4,14);printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c%c    %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(8,4);set(4,14);printf("%c%c      %c%c    %c%c %c%c       %c%c %c%c%c%c   %c%c     %c%c    %c%c %c%c      %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(8,5);set(4,14);printf("%c%c      %c%c    %c%c %c%c   %c%c%c %c%c %c%c %c%c  %c%c     %c%c    %c%c %c%c%c%c%c%c%c %c%c%c%c%c   %c%c%c%c%c%c  ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(8,6);set(4,14);printf("%c%c      %c%c    %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c     %c%c    %c%c      %c%c %c%c      %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
    gotoxy(8,7);set(4,14);printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c      %c%c%c%c%c%c  %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c   %c%c ",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a);
}

void logo_admin(){
          char a =219;
          bingkai(0,0,90,31,8,14);
          gotoxy(5,3);set(2,14); printf("%c%c       %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c%c    %c%c      %c%c%c%c%c  %c%c%c%c%c%c  %c%c%c    %c%c%c %c%c %c%c%c    %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 
          gotoxy(5,4);set(2,14); printf("%c%c      %c%c    %c%c %c%c       %c%c %c%c%c%c   %c%c     %c%c   %c%c %c%c   %c%c %c%c%c%c  %c%c%c%c %c%c %c%c%c%c   %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 
          gotoxy(5,5);set(2,14); printf("%c%c      %c%c    %c%c %c%c   %c%c%c %c%c %c%c %c%c  %c%c     %c%c%c%c%c%c%c %c%c   %c%c %c%c %c%c%c%c %c%c %c%c %c%c %c%c  %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 
          gotoxy(5,6);set(2,14); printf("%c%c      %c%c    %c%c %c%c    %c%c %c%c %c%c  %c%c %c%c     %c%c   %c%c %c%c   %c%c %c%c  %c%c  %c%c %c%c %c%c  %c%c %c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 
          gotoxy(5,7);set(2,14); printf("%c%c%c%c%c%c%c  %c%c%c%c%c%c   %c%c%c%c%c%c  %c%c %c%c   %c%c%c%c     %c%c   %c%c %c%c%c%c%c%c  %c%c      %c%c %c%c %c%c   %c%c%c%c",a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a,a); 
}

void welcome(){
char m=219;
int a=0;
bingkai(0,0,90,31,8,14);

while(a < 6){
    if(a==0){
    gotoxy(15,12);   set(4,14); printf("%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c      %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c",m,m,187,m,m,187,m,m,m,m,m,m,m,187,m,m,187,m,m,m,m,m,m,187,m,m,m,m,m,m,187,m,m,m,187,m,m,m,187,m,m,m,m,m,m,m,187);
        Sleep(500);
    }
    else if(a==1){
    gotoxy(15,13);   set(4,14); printf("%c%c%c    %c%c%c%c%c%c%c%c%c%c%c%c%c%c     %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c",m,m,186,m,m,186,m,m,201,205,205,205,205,188,m,m,186,m,m,201,205,205,205,205,188,m,m,201,205,205,205,m,m,187,m,m,m,m,187,m,m,m,m,186,m,m,201,205,205,205,205,188);
        Sleep(500);
    }
    else if(a==2){
        gotoxy(15,14);   set(1,14); printf("%c%c%c %c%c %c%c%c%c%c%c%c%c%c  %c%c%c     %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  ",m,m,186,m,187,m,m,186,m,m,m,m,m,187,m,m,186,m,m,186,m,m,186,m,m,186,m,m,201,m,m,m,m,201,m,m,186,m,m,m,m,m,187);
        Sleep(500); 
    }
    else if(a==3){
    gotoxy(15,15);   set(1,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  %c%c%c     %c%c%c     %c%c%c   %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c  ",m,m,186,m,m,m,187,m,m,186,m,m,201,205,205,188,m,m,186,m,m,186,m,m,186,m,m,186,m,m,186,200,m,m,201,188,m,m,186,m,m,201,205,205,188);
        Sleep(500);
    }
    else if(a==4){
    gotoxy(15,16);   set(8,14); printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c %c%c%c%c%c%c%c%c%c%c%c",200,m,m,m,201,m,m,m,201,188,m,m,m,m,m,m,m,187,m,m,m,m,m,m,m,187,200,m,m,m,m,m,m,187,200,m,m,m,m,m,m,201,188,m,m,186, 200,205,188, m,m,186,m,m,m,m,m,m,m,187);
        Sleep(500);
    }
    else if(a==5){
    gotoxy(15,17);  set(8,14); printf(" %c%c%c%c%c%c%c%c %c%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c%c%c%c%c %c%c%c     %c%c%c%c%c%c%c%c%c%c%c",200,205,205,188,200,205,205,188, 200,205,205,205,205,205,205,188,200,205,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,205,205,205,205,188, 200,205,188,200,205,188,200,205,205,205,205,205,205,188);
    Sleep(500);
    }
    a++;
}
                    gotoxy(33,28);set(0,14);printf("SEDANG MENGUNDUH KONTEN");
                    for(int i=0;i<27;i++){
                    gotoxy(31+i,29);set(0+i,14);printf("%c",219);
                    Sleep(70);
                    }
                    Sleep(2000);
}   

void gambar(){
    bingkai(91,0,41,31,4,15);
    gotoxy(95,19);    set(0,15);printf("            IMALS FAO        ");
    gotoxy(95,20);    set(12,15);printf("                __           ");
    gotoxy(95,21);    set(12,15);printf("              _|  |_         ");
    gotoxy(95,22);    set(12,15);printf("            _|      |_       ");
    gotoxy(95,23);    set(12,15);printf("           |  _    _  |      ");
    gotoxy(95,24);    set(12,15);printf("           | |_|  |_| |      ");
    gotoxy(95,25);    set(12,15);printf("        _  |  _    _  |  _   ");
    gotoxy(95,26);    set(12,15);printf("       |_|_|_| |__| |_|_|_|  ");
    gotoxy(95,27);    set(12,15);printf("         |_|_        _|_|    ");
    gotoxy(95,28);    set(12,15);printf("           |_|      |_|      ");
    gotoxy(95,29);    set(12,15);printf("                             ");
    gotoxy(95,30);    set(0,15);printf("       USERNAME IG :  _imals "); 
}

void main(){
    gambar();
    welcome();
    animasi();
}