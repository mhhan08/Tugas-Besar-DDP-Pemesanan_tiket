#ifndef KlikTiket_h
#define KlikTiket_h
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct{
	int jumlahTiket;
	char username[20];
	char password[20];
	char pilihan1[20];
	char pilihan2[20];
	char pesanan[100];
}Tiket;

typedef struct{
	char kodePenerbangan[20];
	char hari[20];
	char waktu[20];
	char asal[20];
	char tujuan[20];
	char maskapai[30];
	int totalHarga;
	char seat[10][10];
	char bangku[8][6][5];
}informasiPenerbangan;

typedef struct{
	char jenisKelamin[10][40];
	char tanggalLahir[10][40];
	char nama[10][40];
	char kewarganegaraan[10][40];
	char nomorTelepon[10][40];
}Biodata;

int akun(Tiket *T,int *pilihan);
void registerUser(Tiket *T);
int loginUser(Tiket *T);
int tampilanAwal(int *pilihan,int *valid);
int pesanTiket(Tiket *T,int *pilihan,int *valid);
void maskapai(Tiket *T,int *valid);
void hari(Tiket *T,int *valid);
void negaraTujuan(Tiket *T,int *valid);
void wilayahAsal(Tiket *T,int *valid);
void asalTujuan(Tiket *T,int *valid);
int menampilkanTiket1(Tiket *T,int *valid);
int menampilkanTiket2(Tiket *T,int *valid);
void validasiPesanan(Tiket *T,int *valid);
void jumlahOrang(Tiket *T,int *valid);
void scanTiket(Tiket *T,informasiPenerbangan *I);
void dataDiri(Tiket *T,Biodata *B,int *valid);
void validasiTiket(Tiket *T,Biodata *B,informasiPenerbangan *I);
void pembayaran(informasiPenerbangan *I);
void cetakTiket(Tiket *T,Biodata *B,informasiPenerbangan *I);
void buatHistory(Tiket *T,Biodata *B,informasiPenerbangan *I);
void history(Tiket *T);


int menuUtama(int *pilihan);
void editJadwal(const char *databaseFile, const char *maskapai);
void tampilkanJadwal(const char *jadwal, const char *maskapai);
void pilihMaskapai(const char *databaseFile);
void tambahJadwal(const char *databaseFile);
void bacaBangku(informasiPenerbangan *I);
void pilihBangku(informasiPenerbangan *I,Tiket *T);

#endif
