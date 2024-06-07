#include "header.h"

void laporanKeuangan()
{
	int a;
	FILE *fBarang;
	Barang barang[X];
	Barang dataBarang;
	int jumlah;
	float modal = 0;
	float pendapatan = 0;
	float laba = 0;
	
	system("cls");
	tampilBarang(1);
	
	fBarang = fopen("barang.dat", "rb+");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
    jumlah = jumlahBarang(barang);
    
    for(a = 0 ; a < jumlah ; a++)
    {
    	modal += barang[a].modal;
    	pendapatan += barang[a].pendapatan;
	}
    
    laba = pendapatan - modal;
    
    printf("\n> Modal : %.0f",modal);
    printf("\n\n> Pendapatan : %0.f",pendapatan);
    printf("\n\n> Laba : %0.f",laba);
    printf("\n");
    
    if(laba < 0)
    {
    	printf("\nKesimpulan : Saat Ini Sedang Rugi !");
	}
	else if(laba == 0)
	{
		printf("\nKesimpulan : Saat Ini Sedang Seimbang !");
	}
	else
	{
		printf("\nKesimpulan : Saat Ini Sedang Untung !");
	}
	
	printf("\n\nKlik Enter Untuk Keluar.");
}
