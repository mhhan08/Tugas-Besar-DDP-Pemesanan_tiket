#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include"KlikTiket.h"
#include <windows.h> 
#include <string.h>

int main(){
	Tiket T;
	Biodata B;
	informasiPenerbangan I;
	const char *databaseFile = "DatabaseJadwal.txt";
	int pilihan;
	int loginStatus=0;
	int valid;
	
	while(loginStatus==0){
		pilihan = akun(&T, &pilihan); 
        system("cls");
        if (pilihan == 1) { 
            loginStatus=loginUser(&T);
        } else if (pilihan == 2) {
            registerUser(&T);
        } else {
            printf("Input yang Anda masukkan salah. Silakan pilih nomor yang valid.\n");
            Sleep(2000);
            system("cls");
        }
	}
	
	
   if ((strcmp(T.username, "zahwaNazalla") == 0 && strcmp(T.password, "241511030") == 0) ||
   		(strcmp(T.username, "MuhammadHanif") == 0 && strcmp(T.password, "241511018") == 0)) {
   			do{
   				printf("Selamat datang, Admin!\n");
			   menuUtama(&pilihan);
			   switch (pilihan){
			   		case 1 :pilihMaskapai(databaseFile); break;
   					case 2 :tambahJadwal(databaseFile); break;
   					case 3 :printf("keluar\n"); break;
   					default: printf("pilihan tidak valid.\n");
			   }
			}while (pilihan !=3);
        
        return 0;
	}
	pilihan=tampilanAwal(&pilihan,&valid);
	if (pilihan==2){
	    history(&T);
	}
	else if (pilihan==1){
		pilihan=pesanTiket(&T,&pilihan,&valid);
		switch(pilihan){
		case 1 : maskapai(&T,&valid);menampilkanTiket1(&T,&valid);break;
		case 2 : hari(&T,&valid);menampilkanTiket1(&T,&valid);break;
		case 3 : negaraTujuan(&T,&valid);menampilkanTiket1(&T,&valid);break;
		case 4 : wilayahAsal(&T,&valid);menampilkanTiket1(&T,&valid);break;
		case 5 : asalTujuan(&T,&valid);menampilkanTiket2(&T,&valid);break;
		default : printf("gagal");
		}
		validasiPesanan(&T,&valid);
		jumlahOrang(&T,&valid);
		scanTiket(&T,&I);
		dataDiri(&T,&B,&valid);
		bacaBangku(&I);
		pilihBangku(&I,&T);
		validasiTiket(&T,&B,&I);
		pembayaran(&I);
		cetakTiket(&T,&B,&I);
		buatHistory(&T,&B,&I);
	}
	return 0;
}
