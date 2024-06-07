#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>
#define X 100

typedef char string[100];
typedef struct
{
	int id;
	string nama;
	float hargaBeli;
	float hargaJual;
	int stok;
	float modal;
	float pendapatan;
	int jumlahTerbeli;
}
Barang;

typedef struct
{
	int id;
	string nama;
	int jumlah;
	float harga;
	string waktu;
}
Riwayat;

void baris(int tipe, int index);
void judul(string text, int index);

void historyTransaksi();
void historyRiwayat();

void laporanKeuangan();

void masterBarang();
void tambahBarang();
void stokBarang();
void editBarang();
void hapusBarang();

void beliBarang();
void menuKasir();

void tampilBarang(int index);
int jumlahBarang(Barang barang[]);
int cariBarang(Barang barang[], int id, int jumlah);
void tampilRiwayat();
int jumlahRiwayat(Riwayat riwayat[]);
int cariRiwayat(Riwayat riwayat[], int id, int jumlah);

void cetakStruk(int index, string tempNama[], int tempStok[], float tempTotal[], float uang[]);
bool isNumber(string temp);
char *trimwhitespace(char *str);
