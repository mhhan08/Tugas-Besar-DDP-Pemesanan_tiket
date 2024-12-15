#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "KlikTiket.h"
#include <windows.h> 
#include<conio.h>


//muhammad hanif

int akun(Tiket *T,int *pilihan){
    printf("---------------------------------------\n");
    printf("Selamat Datang di Klik Ticket\n");
    printf("---------------------------------------\n");
    printf("Ikuti petunjuk yang telah kami berikan\n");
    printf("---------------------------------------\n");
    printf("Sudah punya akun?\n");
    printf("1. Login\n");
    printf("Belum punya akun?\n");
    printf("2. Register\n");
    printf("Masukkan pilihan Anda: ");
    scanf("%d",pilihan);  
    return *pilihan;
}

void registerUser(Tiket *T){
	FILE* file;
	printf("-----------------------------------------------\n");
	printf("Silahkan buat akun Klik Tiket anda \n");
	printf("-----------------------------------------------\n");
	printf("masukkan username anda : ");
	scanf("%s",T->username);
	printf("masukkan password : ");
	scanf("%s",T->password);
	file=fopen("DatabaseLogin.txt","a");
	fprintf(file,"\n%s %s",T->username,T->password);
	fclose(file);	
	Sleep(1000);
	printf("\nakun anda berhasil dibuat");
	Sleep(2000);
	system("cls");
}

int loginUser(Tiket *T){
	FILE* file;
	char registerUserName[40];
	char registerPassword[40];
	int loginBerhasil=0;
	printf("-----------------------------------------------\n");
	printf("Silahkan Login akun Klik Tiket anda \n");
	printf("-----------------------------------------------\n\n\n");
	printf("masukkan username : ");
	scanf("%s",T->username);
	printf("masukkan password : ");
	scanf("%s",T->password);
	file=fopen("DatabaseLogin.txt","r");
	while(fscanf(file ,"%s %s",registerUserName,registerPassword) !=EOF ){
		if (strcmp(T->username,registerUserName)==0 && strcmp(T->password,registerPassword)==0 ){
			loginBerhasil=1;
		}
	}
	fclose(file);
	if (loginBerhasil==1){
		printf("Login Berhasil");
		Sleep(1000);
		system("cls");
		return 1;
	}else{
		printf("Login Gagal Periksa kembali Username/password Anda");
		Sleep(1000);
		system("cls");
		return 0;
	}
}

int tampilanAwal(int *pilihan,int *valid){
	do{
		*valid=0;
		printf("========================================================\n");
	    printf("             Selamat Datang di Klik Tiket!              \n");
	    printf("========================================================\n\n");
	    printf("Aplikasi pemesanan tiket penerbangan terbaik yang akan\n");
	    printf("membantu Anda terbang ke 10 negara Eropa dari 5 wilayah\n");
	    printf("di Indonesia, dengan pilihan penerbangan dari 6 maskapai\n");
	    printf("terkemuka.\n\n");
	    printf("========================================================\n");
		printf("Silahkan Pilih Menu yang Anda Inginkan\n\n");
		printf("1.Pesan Tiket Penerbangan\n");
		printf("2.Cek Histroy Pesanan\n\n");
	    printf("========================================================\n\n");
	    printf(" Siap terbang ke Eropa? Temukan tiket impian Anda hanya\n");
	    printf(" di Klik Tiket! \n");
	    printf("========================================================\n\n");
		printf("Masukkan Angka Pilihan Anda : ");
		scanf("%d",pilihan);
		if (*pilihan==1 || *pilihan==2){
			*valid=1;
		} else{
			printf("Input yang Anda Masukkan Salah ");
			Sleep(2000);
			system("cls");
		}
	}while(!*valid);
	Sleep(1000);
	system("cls");
	return *pilihan;
}

int pesanTiket(Tiket *T,int *pilihan,int *valid){
	do{
		*valid=1;
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("|                            Silahkan Pilih Kriteria Pencarian                                   |\n");
		printf("|  Kami menyediakan 5 Kriteria Pencarian Tiket Untuk Anda, Silahkan Pilih Sesuai Kebutuhan anda  |\n");
		printf("-------------------------------------------------------------------------------------------------\n");
		printf("1.Maskapai penerbangan\n");
		printf("Cari Tiket Berdasarkan Maskapai Favorit Anda\n\n");
		printf("2.Hari Keberangkatan\n");
		printf("Cari Tiket Berdasarkan Hari Perjalan Anda\n\n");
		printf("3.Negara Tujuan\n");
		printf("Cari Tiket Berdasarkan Negara Eropa Tujuan Anda\n\n");
		printf("4.Wilayah Asal\n");
		printf("Cari Tiket Berdasarkan Wilayah Keberangkatan Anda\n\n");	
		printf("5.Wilayah Asal -> Negara Tujuan\n");
		printf("Cari Tiket Berdasarkan Wilayah Asal dan Negara Tujuan Anda\n\n\n");
		printf("masukkan pilihan anda : ");
		scanf("%d",pilihan);
		if(*pilihan!=1 && *pilihan!=2 && *pilihan!=3 && *pilihan!=4 && *pilihan!=5){
			printf("Input yang Anda Masukkan Salah (Masukkan nomor pilihan anda) \n");
			*valid=0;
			Sleep(2000);
			system("cls");
		}
	}
	while(!*valid);
	Sleep(1000);
	system("cls");	
	return *pilihan;

}

void maskapai(Tiket *T,int *valid) {
    const char *isiMaskapai[] = {"ET", "RF", "CP", "SS", "DA", "OD"};
    int i;
    do {
        *valid = 0; 
        i = 0; 
        printf("-----------------------------------------------------------------------\n");
        printf("Silahkan Masukkan Maskapai Yang Ingin Anda Cek Jadwal Penerbangan-nya \n");
        printf("-----------------------------------------------------------------------\n\n");
        printf("1. Eurofighter Typhoon [ET]\n");
        printf("2. Stratofortress [RF]\n");
        printf("3. Oceanic Path [CP]\n");
        printf("4. Sapphire Sky [SS]\n");
        printf("5. DeslizaAire [DA]\n");
        printf("6. Odyssey [OD]\n\n");
        printf("Masukkan Kode Maskapai Pilihan Anda : ");
        scanf("%s", T->pilihan1);
        while (i < 6) {
            if (strcmp(T->pilihan1, isiMaskapai[i]) == 0) {
                *valid = 1; 
                break;
            }
            i++;
        }
        if (!*valid) {
            printf("Error: Maskapai yang Anda Masukkan Tidak Valid(Periksa kembali Kode).\n");
            Sleep(2000);
            system("cls");
        }
    } while (!*valid);
    Sleep(1000);
    system("cls");
}

void hari(Tiket *T,int *valid){
	int i;
	const char *isiHari[]={"Senin","Selasa","Rabu","Kamis","Jumat","Sabtu","Minggu"};
	
	do{
		*valid=0;
		i=0;
		printf("-----------------------------------------------------------------------\n");
		printf("Silahkan Masukkan Hari Yang Ingin Anda Cek Jadwal Penerbangan-nya \n");
		printf("-----------------------------------------------------------------------\n\n");
		printf("1.Senin\n");
		printf("2.Selasa\n");
		printf("3.Rabu\n");
		printf("4.Kamis\n");
		printf("5.Jumat\n");
		printf("6.Sabtu\n");
		printf("7.Minggu\n\n");
		printf("Masukkan Hari Pilihan Anda : ");
		scanf("%s",T->pilihan1);
		while(i<7){
			if(strcmp(T->pilihan1,isiHari[i])==0){
				*valid=1;
				break;
			}
			i++;
		}
		if(!*valid){
            printf("Error: Hari yang Anda Masukkan Tidak Valid(Perhatikan Huruf Besar)");
		Sleep(2000);
		system("cls");
		}
	}while(!*valid);
	Sleep(1000);
	system("cls");
}

void negaraTujuan(Tiket *T,int *valid){
    const char *isiNegara[] = {"Swiss", "Jerman", "Swedia", "Prancis", "Rusia","Italia", "Portugal", "Belanda", "Inggris", "Spanyol"};
    int i; 
    do{
    	i=0;
    	*valid=0;
    	printf("-----------------------------------------------------------------------\n");
		printf("Silahkan Masukkan Negara Tujuan Yang Ingin Anda Cek Jadwal Penerbangan-nya \n");
		printf("-----------------------------------------------------------------------\n\n");
		printf("1.Swiss\n");
		printf("2.Jerman\n");
		printf("3.Swedia\n");
		printf("4.Prancis\n");
		printf("5.Rusia\n");
		printf("6.Italia\n");
		printf("7.Portugal\n");
		printf("8.Belanda\n");
		printf("9.Inggris\n");
		printf("10.Spanyol\n\n");
		printf("Masukkan Negara Tujuan Anda : ");
		scanf("%s",T->pilihan1);
		while(i<10){
			if(strcmp(T->pilihan1,isiNegara[i])==0){
				*valid=1;
				break;
			}
			i++;
		}
		if(!*valid){
            printf("Error: Negara Tujuan yang Anda Masukkan Tidak Valid(Perhatikan Huruf Besar).\n");
		Sleep(2000);
		system("cls");
		}
	}while(!*valid);
	Sleep(1000);
	system("cls");	
}
void wilayahAsal(Tiket *T,int *valid){
	const char *isiWilayah[] = {"Jakarta","Bali","Palembang","Balikpapan","Makassar"};
	int i;
	do{
		i=0;
		*valid=0;
		printf("-----------------------------------------------------------------------\n");
		printf("Silahkan Masukkan WIlayah Asal Yang Ingin Anda Cek Jadwal Penerbangan-nya \n");
		printf("-----------------------------------------------------------------------\n\n");
		printf("1.Jakarta\n");
		printf("2.Bali\n");
		printf("3.Palembang\n");
		printf("4.Balikpapan\n");
		printf("5.Makassar\n\n");
		printf("Masukkan Wilayah Asal Anda: ");
		scanf("%s",T->pilihan1);
		while(i<5){
			if(strcmp(T->pilihan1,isiWilayah[i])==0){
				*valid=1;
				break;
			}
			i++;
		}
		if(!*valid){
            printf("Error: Wilayah Asal yang Anda Masukkan Tidak Valid(Perhatikan Huruf Besar).\n");
			Sleep(2000);
			system("cls");
		}
	}while(!*valid);
	Sleep(1000);
	system("cls");
}

void asalTujuan(Tiket *T,int *valid){
	const char *isiWilayah[] = {"Jakarta", "Bali","Palembang","Balikpapan","Makassar"};
	const char *isiNegara[] = {"Swiss","Jerman","Swedia","Prancis", "Rusia","Italia","Portugal","Belanda","Inggris","Spanyol"};
	int i;
	do{
		*valid=0;
		i=0;
		printf("---------------------------------------------------------------------------------------------------\n");
		printf("Silahkan Masukkan Negara Tujuan Dan Wilayah Asal Anda Yang Ingin Anda Cek Jadwal Penerbangan-nya \n");
		printf("---------------------------------------------------------------------------------------------------\n\n");
		printf("Daftar Negara Tujuan : \n");
		printf("1.Swiss\n");
		printf("2.Jerman\n");
		printf("3.Swedia\n");
		printf("4.Prancis\n");
		printf("5.Rusia\n");
		printf("6.Italia\n");
		printf("7.Portugal\n");
		printf("8.Belanda\n");
		printf("9.Inggris\n");
		printf("10.Spanyol\n\n");
		printf("Daftar Wilayah Asal : \n");
		printf("1.Jakarta\n");
		printf("2.Bali\n");
		printf("3.Palembang\n");
		printf("4.Balikpapan\n");
		printf("5.Makassar\n\n");
		printf("Masukkan Negara Tujuan Anda : ");
		scanf("%s",T->pilihan1);
		printf("Masukkan Wilayah Asal Anda : ");
		scanf("%s",T->pilihan2);
		while (i<10){
			if(strcmp(T->pilihan1,isiNegara[i])==0){
				(*valid)++;
				break;
			}
			i++;
		}
		i=0;
		while(i<5){
			if(strcmp(T->pilihan2,isiWilayah[i])==0){
				(*valid)++;
				break;
			}
			i++;
		}
		if(*valid!=2){
            printf("Error: Negara Tujuan atau Wilayah Asal yang Anda Masukkan Tidak Valid(Perhatikan Huruf Besar).\n");
			Sleep(2000);
			system("cls");		
		}
	}while(*valid!=2);
	Sleep(1000);
	system("cls");
}

int menampilkanTiket1(Tiket *T,int *valid){
	FILE* file;
	char jadwal[100];
	char kode[20];
	printf("jadwal penerbangan yang tersedia");
	do{
		*valid=0;
		int nomor=1;
		file=fopen("DatabaseJadwal.txt","r");
	    while (fgets(jadwal, sizeof(jadwal),file)) {
	         if (strstr(jadwal,T->pilihan1) != NULL) {
	         	printf("\n%d.%s\n",nomor,jadwal);
	         	nomor++;
	        }
	    }
	    fclose(file);
	    
	    printf("masukkan kode penerbangan yang ingin anda pesan : ");
	    scanf("%s",T->pilihan1);	
	    
	    file=fopen("DatabaseKode.txt","r");
		while(fgets(kode,sizeof(kode),file)){
			if(strstr(kode,T->pilihan1)!=NULL){
				break;
			}
		}
		fclose(file);
		
		file=fopen("DatabaseJadwal.txt","r");
		while(fgets(T->pesanan,sizeof(T->pesanan),file)){
			if(strstr(T->pesanan,T->pilihan1)!=NULL){
				*valid=1;
				break;
			}
		}
		fclose(file);
		
		if(strstr(T->pesanan,T->pilihan1)==NULL){
			printf("Error : Kode Penerbangan yang Anda Masukkan Salah(Cek kembali Kode Anda)\n");
		}
		Sleep(1000);
	}while(!*valid);
	Sleep(1000);
	system("cls");
	return 0;
}

int menampilkanTiket2(Tiket *T,int *valid){
	FILE* file;
	char jadwal[100];
	char kode[20];
	do{
		*valid=0;
		int nomor=1;
		file=fopen("DatabaseJadwal.txt","r");
		printf("jadwal penerbangan yang tersedia");
  		while (fgets(jadwal, sizeof(jadwal),file)) {
         	if (strstr(jadwal,T->pilihan1) != NULL) {
         		if (strstr(jadwal,T->pilihan2) != NULL){
         			printf("\n%d.%s\n",nomor,jadwal);
         			nomor++;
					}
        		}
    		}
    	fclose(file);
    
		printf("masukkan kode penerbangan yang ingin anda pesan : ");
	    scanf("%s",T->pilihan1);
	    
		file=fopen("DatabaseKode.txt","r");
		while(fgets(kode,sizeof(kode),file)){
			if(strstr(kode,T->pilihan1)!=NULL){
				break;
			}
		}
		fclose(file);
		
		file=fopen("DatabaseJadwal.txt","r");
		while(fgets(T->pesanan,sizeof(T->pesanan),file)){
			if(strstr(T->pesanan,T->pilihan1)!=NULL){
				*valid=1;
				break;
			}
		}
		fclose(file);
		
		if(strstr(T->pesanan,T->pilihan1)==NULL){
		printf("Error : Kode Penerbangan yang Anda Masukkan Salah(Cek kembali Kode Anda)\n");
		}
		Sleep(1000);
	}while(!*valid);	  
	Sleep(1000);
	system("cls");
	return 0;
}

void validasiPesanan(Tiket *T,int *valid){
	FILE* file;
	char validasiTiket;
	do{
		*valid=0;
		printf("anda akan membeli Tiket penerbangan : \n%s",T->pesanan);			
		printf("lanjutkan pembelian(Y) atau Batal(N)? :");
		getchar(); 
		scanf("%c",&validasiTiket);
		if (validasiTiket == 'Y' || validasiTiket == 'y') {
			printf("\nmelanjutkan pembelian\n");
			*valid=1;
	    } else if(validasiTiket == 'N' || validasiTiket == 'n') {
	        printf("Pembelian dibatalkan.\n");
	        exit(0);
	    }else{
	    	*valid=0;
	    	printf("\nError : Input yang Anda Masukkan Salah ");
	    	Sleep(2000);
	    	system("cls");
		}		
	}while(!*valid);
}

void jumlahOrang(Tiket *T,int *valid){
	do{
		*valid=1;
		printf("----------------------------------------------------------------------------\n");
		printf("Masukkan Jumlah Tiket\n");
		printf("----------------------------------------------------------------------------\n");
		printf("\nUntuk 1 kali Pemesanan Anda Hanya Bisa Memasan Maksimal 10 Tiket\n");
		printf("----------------------------------------------------------------------------\n");
		printf("Berapa Banyak Tiket yang Ingin Anda Pesan?\n");
		printf("jumlah Tiket : ");
		if (scanf("%d", &T->jumlahTiket) != 1 || T->jumlahTiket < 1 || T->jumlahTiket > 10) {
            printf("\nError: Input yang Anda Masukkan Salah (Masukkan Angka 1-10).\n");
            while (getchar() != '\n');
            *valid = 0; 
            Sleep(2000);
			system("cls"); 
        }
	}while(!*valid);
	Sleep(1000);
	system("cls");
}

void scanTiket(Tiket *T, informasiPenerbangan *I) {
    FILE *file;
    int total; 
    int x = 0, y = 0;
	char harga[50];
    char penampungHarga[30];
    
    sscanf(T->pesanan,"%[^|] | %[^|] | %[^|] | %[^-] -> %[^|] | %[^|] | %[^\n]",I->kodePenerbangan, I->hari, I->waktu, I->asal, I->tujuan, I->maskapai,penampungHarga);
    while (x < strlen(penampungHarga)) {
        if (penampungHarga[x] >= '0' && penampungHarga[x] <= '9') {
            harga[y]= penampungHarga[x];
            y++;
        }
        x++;
    }
    harga[y] = '\0';
    total = atoi(harga); 
    I->totalHarga = total * T->jumlahTiket;
}

void dataDiri(Tiket *T, Biodata *B, int *valid) {
    int pengulangan;
    int validasi;

    do {
        pengulangan = 0;
        *valid = 0;

        while (pengulangan < T->jumlahTiket) {
            printf("==============================================================================\n");
            printf("                               Masukkan Data Diri                             \n");
            printf("==============================================================================\n\n");
            printf("Silahkan Masukkan Informasi Pribadi Anda\n");
            printf("----------------------------------------------------------------------------\n");

            printf("Nama (masukkan sesuai Kartu Identitas)  : ");
            scanf("%49s", B->nama[pengulangan]);
            printf("Jenis kelamin (Laki-Laki/Perempuan)     : ");
            scanf("%19s", B->jenisKelamin[pengulangan]);
            printf("Tanggal lahir (Tanggal/Bulan/Tahun)     : ");
            scanf("%19s", B->tanggalLahir[pengulangan]);
            printf("Kewarganegaraan                         : ");
			scanf("%19s", B->kewarganegaraan[pengulangan]);
            printf("Nomor Telepon Aktif                     : ");
			scanf("%19s", B->nomorTelepon[pengulangan]);
            printf("----------------------------------------------------------------------------\n");
            pengulangan++;
        }
        do {
            printf("Apakah Data diri yang Anda masukkan sudah benar?\n");
            printf("1. Sudah.\n");
            printf("2. Belum, Saya Ingin Mengulang.\n");
            printf("Masukkan Pilihan Anda : ");
            if (scanf("%d", &validasi) != 1) {
                printf("Input tidak valid! Masukkan angka 1 atau 2.\n");
                continue;
            }

            if (validasi == 1) {
                *valid = 1;
            } else if (validasi == 2) {
                printf("Lakukan Pengisian Data Diri Ulang...\n");
                Sleep(2000);
                system("cls");
            } else {
                printf("Pilihan tidak valid. Silahkan masukkan 1 atau 2.\n");
            }
        } while (validasi != 1 && validasi != 2);

    } while (!*valid);

    printf("Data diri berhasil disimpan!\n");
    Sleep(1000);
}


void validasiTiket(Tiket *T,Biodata *B,informasiPenerbangan *I){
	int validasiTiket;
	int pengulangan=0;
		printf("=======================================================\n");
		printf("                     Validasi Tiket                    \n");
		printf("=======================================================\n\n");
		printf("Berikut Adalah Rincian Tiket Yang Anda Pilih\n");
		printf("-------------------------------------------------------\n");
		printf("Maskapai Penerbangan : %s\n",I->maskapai);
		printf("Hari Keberangkatan   : %s\n",I->hari);
		printf("Jam Keberangkatan    : %s\n",I->waktu);
		printf("Lokasi Keberangkatan : %s\n",I->asal);
		printf("Negara Tujuan        : %s\n",I->tujuan);
		printf("Total Pesanan        : %d\n",T->jumlahTiket);
		printf("Total Pembayaran     : Rp %d\n",I->totalHarga);
		printf("-------------------------------------------------------\n");
		printf("Berikut Adalah Rincian Informasi Data Diri Pemesan : \n");
	while(pengulangan<T->jumlahTiket){
		printf("--------------------------------------------------------------\n");
		printf("Nama             : %s\n",B->nama[pengulangan]);
		printf("Jenis Kelamin    : %s\n",B->jenisKelamin[pengulangan]);
		printf("Tanggal Lahir    : %s\n",B->tanggalLahir[pengulangan]);
		printf("Kewarganegaraan  : %s\n",B->kewarganegaraan[pengulangan]);
		printf("Nomor Telepon    : %s\n",B->nomorTelepon[pengulangan]);		
		printf("--------------------------------------------------------------\n\n");
		pengulangan++;
	}
	printf("Anda Yakin Ingin melanjutkan Pembayaran Ini ? \n");
	printf("1.YA Lanjutkan\n");
	printf("2.Batalkan Pesanan\n");
	printf("-------------------------------------------------------\n");
	printf("Masukkan pilihan Anda : ");	
	scanf("%d",&validasiTiket);
	if (validasiTiket == 1 ) {
		printf("\nMelanjutkan Pembayaran \n");
    } else if (validasiTiket == 2) {
        printf("Pembelian dibatalkan.\n");
        exit(0);
    } else if(validasiTiket!=1 && validasiTiket!=2){
    	printf("Error : Input yang Anda Masukkan Salah ");
	}
    Sleep(2000);
    system("cls");
}

void pembayaran(informasiPenerbangan *I){
	char bank[30];
	char rekening[30];
	char pw[30];
	printf("============================================================\n");
	printf("                         Pembayaran                         \n");
	printf("============================================================\n\n");
	printf("Silahkan lakukan pembayaran dengan jumlah : Rp %d\n",I->totalHarga);
	printf("------------------------------------------------------------\n");
	printf("metode pembayaran :\n");
	printf("1.Bank BRI\n");
	printf("2.Bank BCA\n");
	printf("3.Bank Mandiri\n");
	printf("4.Bank BSI\n");
	printf("5.Bank BNI\n");
	printf("-------------------------------------------------------------\n");
	printf("Masukkan BAnk Pilihan Anda:");scanf("%s",bank);
	printf("pembayaran melalui Bank %s : ",bank);
	printf("masukkan nomor rekening anda :");
	scanf("%s",rekening);
	printf("masukkan password rekening anda : ");
	scanf("%s",pw);
	Sleep(3000);
	printf("pembayaran berhasil");
	Sleep(2000);
	system("cls");
}

void cetakTiket(Tiket *T,Biodata *B,informasiPenerbangan *I){
	int pengulangan=0;
	while(pengulangan<T->jumlahTiket){
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-20s                         Boarding Pass                                      %-20s |\n", I->maskapai, I->maskapai);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("| %-20s : %-40s | %-20s : %-20s        |\n", "Nama", B->nama[pengulangan], "From",I->asal );
        printf("| %-20s : %-40s | %-20s : %-20s        |\n", "Seat", I->seat[pengulangan], "To",I->tujuan);
        printf("| %-20s : %-40s | %-20s : %-20s        |\n", "Maskapai",I->maskapai, "Day", I->hari);
        printf("| %-20s : %-40s | %-20s : %-20s        |\n", "Flight Code",I->kodePenerbangan , "Time", I->waktu);
        printf("------------------------------------------------------------------------------------------------------------------------\n");
        printf("                  Penumpang Wajib Hadir 1 Jam sebelum Penerbangan                 \n");
        printf("------------------------------------------------------------------------------------------------------------------------\n");        
        pengulangan++;
    }
}

void buatHistory(Tiket *T,Biodata *B,informasiPenerbangan *I){
	FILE* file;	
	char namaFile[50];
	int i=0;
	snprintf(namaFile,sizeof(namaFile),"%s%s.txt",T->username,T->password);
	file=fopen(namaFile,"a+");
	if(file==NULL){
		printf("Error : Gagal Menambahkan Ke History");
	}
	fputs("========================================================\n",file);
	fputs("                     Riwayat pesanan                    \n",file);
	fputs("========================================================\n",file);
	while(i<T->jumlahTiket){
		fprintf(file,"Nama : %s\n",B->nama[i]);
		fprintf(file,"Jenis Kelamin : %s\n",B->jenisKelamin[i]);
		fprintf(file,"Maskapai : %s\n",I->maskapai);
		fprintf(file,"Flight Code : %s",I->kodePenerbangan);
		fprintf(file,"Seat : %s",I->seat[i]);
		fprintf(file,"Hari : %s",I->hari);
		fprintf(file,"Waktu : %s\n",I->waktu);
		fprintf(file,"From : %s\n",I->asal);
		fprintf(file,"To : %s\n",I->tujuan);
		fputs("======================================================\n\n",file);
		i++;
	}
    fclose(file);
}

void history(Tiket *T){
	FILE* file;
	char namaFile[70];
	char riwayat[100];
	snprintf(namaFile,sizeof(namaFile),"%s%s.txt",T->username,T->password);	
	file=fopen(namaFile,"r");
	while(fgets(riwayat,sizeof(riwayat),file)){
		printf("%s",riwayat);
	}	
	fclose(file);
}


//zahwaNazalla

int menuUtama(int *pilihan) {
    do {
        system("cls");
        printf("========== MENU UTAMA ==========\n");
        printf("1. Edit Jadwal\n");
        printf("2. Tambah Jadwal\n");
        printf("3. Keluar\n");
        printf("Masukkan pilihan: ");
        scanf("%d", pilihan);
    } while (*pilihan != 1 && *pilihan != 2 && *pilihan != 3);
    return *pilihan;
}

void pilihMaskapai(const char *databaseFile) {
    const char *maskapai[] = {
        "Sapphire Sky", "Oceanic Path", "Odyssey",
        "Desliza Aire", "Strato fortress", "Eurofighter Typhoon"
    };

    int pilihan;
    do {
        system("cls");
        printf("========== PILIH MASKAPAI ==========\n");
        for (int i = 0; i < 6; i++) {
            printf("%d. %s\n", i + 1, maskapai[i]);
        }
        printf("7. Back");
        printf("Pilih maskapai : ");
        scanf("%d", &pilihan);
        if(pilihan == 7) return;
    } while (pilihan < 1 || pilihan > 6);
     	Sleep(1000);

	tampilkanJadwal(databaseFile, maskapai[pilihan - 1]);
    editJadwal(databaseFile, maskapai[pilihan - 1]);
}

void tampilkanJadwal(const char *databaseFile, const char *maskapai) {
    system("cls");
	FILE *dataFile = fopen(databaseFile, "r");
    if (dataFile == NULL) {
        printf("Gagal membuka file.\n");
        printf("ENTER untuk kembali");
        getchar(); getchar();
        return;
    }

    char line[300];
    int no = 1;
    printf("========== DATA JADWAL %s ==========\n", maskapai);
    while (fgets(line, sizeof(line), dataFile)) {
        if (strstr(line, maskapai) != NULL) {
            printf("%d. %s", no, line);
            no++;
        }
    }
    fclose(dataFile);
    if (no == 1) {
        printf("Tidak ada jadwal untuk maskapai %s.\n", maskapai);
    }
}

void editJadwal(const char *databaseFile,  const char *maskapai) {
    system("cls");
	char kode[20], line[300];
    int ditemukan = 0;

    printf("Masukkan kode penerbangan yang akan diedit: ");
    scanf("%s", kode);

    FILE *dataFile = fopen(databaseFile, "r");
    FILE *tempFile = fopen("TempJadwal.txt", "w");

    if (dataFile == NULL || tempFile == NULL) {
        printf("Gagal membuka file.\n");
        printf("ENTER untuk kembali");
        getchar(); getchar();
        return;
    }

    while (fgets(line, sizeof(line), dataFile)) {
        if (strstr(line, kode) != NULL && strstr(line, maskapai) != NULL) {
            ditemukan = 1;
            informasiPenerbangan jadwalBaru;

            printf("Masukkan data baru untuk jadwal:\n");
            printf("Hari: ");
            scanf("%s", jadwalBaru.hari);
            printf("Waktu (HH:MM): ");
            scanf("%s", jadwalBaru.waktu);
            printf("Asal kota: ");
            scanf("%s", jadwalBaru.asal);
            printf("Tujuan kota: ");
            scanf("%s", jadwalBaru.tujuan);
            printf("Maskapai: ");
            scanf("%s", jadwalBaru.maskapai);
            printf("Harga tiket: ");
            scanf("%d", &jadwalBaru.totalHarga);

            fprintf(tempFile, "%s | %s | %s | %s -> %s | %s | Rp %d\n",
                    kode, jadwalBaru.hari, jadwalBaru.waktu, jadwalBaru.asal,
                    jadwalBaru.tujuan, jadwalBaru.maskapai, jadwalBaru.totalHarga);
        } else {
            fputs(line, tempFile);
        }
    }

    fclose(dataFile);
    fclose(tempFile);

    if (ditemukan) {
        remove(databaseFile);
        rename("TempJadwal.txt", databaseFile);
        printf("Data berhasil diedit.\n");
    } else {
        remove("TempJadwal.txt");
        printf("Kode penerbangan tidak ditemukan.\n");
    }
    getchar(); getchar();
}

void tambahJadwal(const char *databaseFile) {
	system("cls");
    FILE *dataFile = fopen(databaseFile, "a");
    if (dataFile == NULL) {
        printf("Gagal membuka file.\n");
        return;
    }
    
    informasiPenerbangan jadwalBaru;
    printf("Masukkan kode penerbangan: ");
    scanf("%s", jadwalBaru.kodePenerbangan);
    if(strcmp(jadwalBaru.kodePenerbangan, "back")==0){
    	fclose(dataFile);
    	return;
	}
    printf("Masukkan hari: ");
    scanf("%s", jadwalBaru.hari);
    printf("Masukkan waktu (HH:MM): ");
    scanf("%s", jadwalBaru.waktu);
    printf("Masukkan asal kota: ");
    scanf("%s", jadwalBaru.asal);
    printf("Masukkan tujuan kota: ");
    scanf("%s", jadwalBaru.tujuan);
    printf("Masukkan maskapai: ");
    scanf("%s", jadwalBaru.maskapai);
    printf("Masukkan harga: ");
    scanf("%d", &jadwalBaru.totalHarga);

    fprintf(dataFile, "%s | %s | %s | %s -> %s | %s | Rp %d\n",
            jadwalBaru.kodePenerbangan, jadwalBaru.hari, jadwalBaru.waktu,
            jadwalBaru.asal, jadwalBaru.tujuan, jadwalBaru.maskapai, jadwalBaru.totalHarga);

    fclose(dataFile);
    printf("Jadwal berhasil ditambahkan.\n");
    getchar(); getchar();
}

void bacaBangku(informasiPenerbangan *I) {
    FILE *file = fopen("TampilanBangku.txt", "r");
    if (!file) {
        printf("File TampilanBangku.txt tidak ditemukan, periksa kembali!\n");
    } else {
        for (int i = 0; i < 8; i++) {
            for (int j = 0; j < 6; j++) {
                fscanf(file, "%s",I->bangku[i][j]); 
            }
        }
        fclose(file);
    }
}


void pilihBangku(informasiPenerbangan *I,Tiket *T){
    int z=0,x = 0, y = 0, key;
	while(z < T->jumlahTiket){
	        system("cls");
	        printf("Gunakan tombol panah untuk memilih bangku. Tekan ENTER untuk memilih.\n\n");
	        printf("pilih Bangku %d\n",z+1);
	        for (int i = 0; i < 8; i++) {
	            for (int j = 0; j < 6; j++) {
	                if (i == x && j == y) {
	                    printf(">%s<",I->bangku[i][j]); 
	                } else {
	                    printf("  %s",I->bangku[i][j]);
	                }
	            }
	            printf("\n");
	        }
			key=getch();
	        if (key == 224) { 
	        key=getch();
	            switch (key) {
	                case 72: if (x > 0) x--; break; 
	                case 80: if (x < 7) x++; break; 
	                case 75: if (y > 0) y--; break; 
	                case 77: if (y < 5) y++; break; 
	            }
	        } else if (key == 13) { 
	            system("cls");
	            printf("Anda memilih bangku %s!\n",I->bangku[x][y]);
	            printf("Tekan sembarang tombol untuk kembali ke pemilihan selanjutnya...\n");
				getch();
				strcpy(I->seat[z],I->bangku[x][y]);
				z++;
	        }
	}
}

   



