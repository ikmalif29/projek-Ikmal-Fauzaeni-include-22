void val_user(char *username2){
    char idx;
    char tam[100]={};
    int i =0;
    while((idx=getch())!=13||i<3){
                     if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9'  )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i != 0 && i > 2 &&  i != 12 && idx== 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(username2,tam);
}
void val_pass(char *pasword2){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<5){
         if( i <= 9 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9' )){
                              printf("*");
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(pasword2,tam);
}

char * val_userlog(char *username){
    char idx;
    char tam[100]={};
    int i =0;
    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13  && ( idx >='a' && idx<='z' && idx != tam[i-1] || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m')  || idx >='0' && idx<='9'  )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if( i != 0 && idx== 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
        tam[i]=NULL;
        strcpy(username,tam);
}
char *val_paslog(char *pasword){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<4){
         if( i <= 9 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9' )){
                              printf("*");
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(pasword,tam);
}

void val_notelp(char *nomor){

int dex=0;
    char ch;
    char nohp[50]={};
    char nohp1[50]={};
    while((ch=getch())!=13||dex<11)
    {
       
        if(ch>='0'&&ch<='9'&&dex<13)
        {
            if(dex==0&&ch=='0'||dex==1&&ch=='8')
            {
                printf("%c",ch);
                nohp[dex]=ch;
                dex++;
            }
            else if (dex == 2 && (ch == '1' || ch == '2' || ch == '3' || ch == '5' || ch == '7' || ch == '8' || ch == '9'))
            {
                printf("%c", ch);
                nohp[dex] = ch;
                dex++;
            }
            else if (dex > 2 && ch != nohp[dex-4] )
            {
                printf("%c", ch);
                nohp[dex] = ch;
                dex++;
            }
        }
        else if (ch == 8 && dex != 0)
        {
            printf("\b \b");
            dex -= 1;
            nohp[dex] =NULL;
        }
    }
    for (int a = 0; a < dex; a++)
    {
        nohp1[a] = nohp[a];
    }

      strcpy(nomor,nohp1);
}
void valmin(char * admin){
    char idx;
    char tam[100]={};
    int i =0;

    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13 && ( idx >='a' && idx<='z' && idx != tam[i-1] || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m') || idx >='0' && idx<='9'  )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if( i != 0 &&idx== 32 && tam[i-1] !=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(admin,tam);
}
void valpasmin(char *pasword1){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<4){
         if( i <= 9 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9' )){
                              printf("*");
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(pasword1,tam);
}

void val_namabarang(char *nama_barang){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13  && ( idx >='a' && idx<='z' && idx != tam[i-1]  || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m') || idx >='0' && idx<='9')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx== 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
        tam[i]=NULL;
        strcpy(nama_barang,tam);
}

int val_hargabarang(){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<4){
         if( i <= 6 && ( idx >='1' && idx<='9' )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 6 && ( idx >='0' && idx<='9')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          return atoi(tam); 
}

int val_stokbarang(){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<1){
         if( i <= 2 && ( idx >='1' && idx<='9' )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 2 && ( idx >='0' && idx<='9')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          return atoi(tam); 
}
int val_ditbar(){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<1){
         if( i <= 2 && ( idx >='1' && idx<='9' )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 2 && ( idx >='0' && idx<='9')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          return atoi(tam); 
}
void val_usernew(char *userbaru){
    char idx;
    char tam[100]={};
    int i =0;

    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13  && ( idx >='a' && idx<='z' && idx != tam[i-1]  || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m') || idx >='0' && idx<='9')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i != 0 && i > 2 &&  i != 13 && idx == 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(userbaru,tam);
}

void val_sandibaru(char *passbaru){
    char idx;
    char tam[100];
    int i =0;
    while((idx=getch())!=13||i<4){
         if( i <= 9 && ( idx >='a' && idx<='z' || idx >='0' && idx<='9' )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(passbaru,tam);
}

int val_beliid(int id_beli){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 1 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(125+i,2); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 3 && (  idx >='0' && idx<='9' )){
                        gotoxy(125+i,2); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(125+i,2); set(10,15);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          return atoi(tam);
}

int val_belijumlah(int jumlah){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 1 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(110+i,4); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 3 && (  idx >='0' && idx<='9' )){
                        gotoxy(110+i,4); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(110+i,4); set(10,15);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          atoi(tam);
}

int val_hapusid(int cari){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 1 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(115+i,4); set(0,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 3 && (  idx >='0' && idx<='9' )){
                        gotoxy(115+i,4); set(0,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(115+i,4); set(0,15);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          atoi(tam);
}

void val_barangnew(char *nambar){
    char idx;
    char tam[100]={};
    int i =0;

    while((idx=getch())!=13||i<3){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 13 &&  ( idx >='a' && idx<='z' && idx != tam[i-1]  || tam[i-2] != idx &&(idx == 'n' || idx=='g' || idx=='m') || idx >='0' && idx<='9' )){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i != 0 && i > 2 &&  i != 13 && idx == 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          strcpy(nambar,tam);
}

int val_harganew(int harbar){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 5 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(111+i,8); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 7 && (  idx >='0' && idx<='9' )){
                        gotoxy(111+i,8); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(111+i,8); set(10,15);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          return atoi(tam);
}

int val_stoknew(int stokbar){
    char idx;
    int i=0;
    char tam[100];
    while((idx=getch())!=13 || i < 1 ){
        if(idx>='0' && idx<='9'||idx ==8){
            if(i==0 && idx !='0' && idx !=8 ){
                        gotoxy(111+i,10); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && i <= 3 && (  idx >='0' && idx<='9' )){
                        gotoxy(111+i,10); set(10,15);printf("%c",idx);
                        tam[i]=idx;
                        i++;
            }
            else if(i !=0 && idx == 8 ){
                        gotoxy(111+i,10); set(10,15);printf("\b \b");
                        i--;
                        tam[i]=NULL;
            }
        }
    }
          tam[i]=NULL;
          return atoi(tam);
}

void val_alamat(char *alamat){
    char idx;
    char tam[100]={};
    int i =0;

    while((idx=getch())!=13||i<4){
                    if(i==0 && (idx >='A' && idx<='Z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && i <= 18 &&  ( idx >='a' && idx<='z')){
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i != 0 && i > 2 &&  i != 13 && idx == 32 && tam[i-1]!=32 && tam[i-2]!=32 && tam[i-3]!=32 ){
                              
                              printf("%c",idx);
                              tam[i]=idx;
                              i++;
                    }
                    else if(i !=0 && idx == 8 ){
                              i--;
                              printf("\b \b");
                              tam[i]=NULL;
                    }
          }
          tam[i]=NULL;
          if(strcmp(tam,"Arjuna") == 0 || strcmp(tam,"Pasirkaliki") == 0 ||strcmp(tam,"Pamoyan") == 0 ||strcmp(tam,"Husen sastranegara") == 0 ||strcmp(tam,"Pajajaran") == 0 ||strcmp(tam,"Sukaraja") == 0 )
          {
                strcpy(alamat,tam);
          }
          else{
          int id_beli,jumlah;
            for(int k = 0 ; k < 10 ; k++){
                if(k%2==0){
                    gotoxy(96,11); set(4,15);printf("NAMA KELURAHAN TIDAK TERDAFTAR");
                    Sleep(400);
                }else{
                    gotoxy(96,11); set(4,15);printf("                              ");
                    Sleep(400);
                }
            }
                gotoxy(100,13); set(0,15);printf("TEKAN [ESC] UNTUK KEMBALI");
                gotoxy(93,14); set(0,15);printf("[BACKSPACE] UNTUK MENGULANGI PEMBELIAN");
                    char az;
                    while((az =getch ())){
                        if(az == 27){
                            home_user();
                        }else if(az==8){
                            beli_barang(id_beli,jumlah);
                    }
                }
          }
}