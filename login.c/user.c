void home_user(){
          int sal;
          int pilih;
          int id_beli,jumlah;
          
          gambar();
          pilih = chose4();
          switch(pilih){
                    case 1 :
                    bingkai(0,0,90,31,8,14);
                    beli_barang(id_beli,jumlah);
                    break;

                    case 2 :
                    bingkai(0,0,90,31,8,14);
                    tampil_profil();
                    break;

                    case 3 :
                    bingkai(0,0,90,31,8,14);
                    edit_profil();
                    break;

                    case 4 :
                    bingkai(0,0,90,31,8,14);
                    show_barang(0,20,"DATA");
                    char klik;
                    gotoxy(33,26); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                    while((klik = getch())){
                              if(klik==27){
                                        home_user();
                              }
                    }
                    break;

                    case 5 :
                    bingkai(0,0,90,31,8,14);
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
                    bingkai(13,8,65,20,4,14); 
                    gotoxy(45,15); set(10,14);printf("INPUT ");  
                    gotoxy(30,16); set(10,14);printf("NOMINAL SALDO [KELIPATAN 50.000]  ");
                    gotoxy(43,17); set(10,14);printf("RP.");
                    gotoxy(19,18); set(10,14);printf("______________________________________________________");
                    cek_data();
                    int a=0;
                    while(a<3){ 
                    sal = val_saldo();
                    if(sal %50000 == 0 ){
                              tambah_saldo(sal);
                              a+=3;
                    }
                    else{
                         if(a==2){
                                   gotoxy(28,24); set(4,14);printf("MOHON MAAF KESEMPATAN ANDA TELAH HABIS");
                              }
                              for( int q = 0 ; q < 10 ; q ++){
                                  if(q %2==0){
                                        gotoxy(32,21); set(9,14);printf("INPUTKAN SALDO KELIPATAN [50.000]");
                                        Sleep(400);
                                   }else{
                                        gotoxy(32,21); set(9,14);printf("                                 ");
                                        Sleep(400);
                                        }
                              }
                                        gotoxy(47,17); set(10,14);printf("                       ");
                                        Sleep(1000);
                              a++;
                    }
                    }

                    update_not();
                    gotoxy(35,27); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                    char h;
                    while((h = getch()) !=13){
                              if(h==27){
                                        home_user();
                              }
                    }
                    break;

                    case 6 :
                    chose();
                    break;
          }
          }
