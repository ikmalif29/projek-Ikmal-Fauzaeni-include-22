void home_admin(){
          char input;
          int pilih;
          int tarik_saldo;
          gambar();
          pilih = chose3();
          switch(pilih){

                    case 1 :
                    bingkai(0,0,90,31,8,14);
                    tambah_barang();
                    Sleep(5000);
                    break;

                    case 2 :
                    bingkai(0,0,90,31,8,14);
                    hapus_barang();
                    Sleep(5000);
                    break;

                    case 3 :
                    bingkai(0,0,90,31,8,14);
                    edit_barang();
                    Sleep(5000);
                    break;

                    case 4 :
                    bingkai(0,0,90,31,8,14);
                    tarik_salmin(tarik_saldo);
                    break;

                    case 5 :
                    chose();
                    break;

                    case 6 :
                    bingkai(0,0,90,31,8,14);
                    tampil_barang(0,20);
                    gotoxy(30,30); set(40,14);printf("TEKAN [ESC] UNTUK KEMBALI");
                    char t;
                    while((t = getch())){
                              if(t==27){
                                        home_admin();
                              }
                    }
                    break;


                    case 7 :
                    bingkai(0,0,90,31,8,14);
                    tampil_saldo_admin();
                    break;
                    
                    case 8 :
                    bingkai(0,0,90,31,8,14);
                    riwayat_pembelian();
                    break;
          }
}



