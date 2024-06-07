#include "header.h"

void historyTransaksi()
{
	int a;
	FILE *fRiwayat;
	Riwayat riwayat[X];
	Riwayat dataRiwayat;
	int jumlah;
	
	system("cls");
	tampilRiwayat(1);
	
	fRiwayat = fopen("riwayat.dat", "rb+");
	
	if(fRiwayat == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
	
	printf("\n\nKlik Enter Untuk Keluar.");
}
