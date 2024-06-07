#include "header.h"

int main(int argc, char *argv[]) 
{
	string temp;
	int pilihan;
	
	do
	{
		system("cls");
        printf("_______________________________________________________________\n");
        printf("|                         Toko AdaMart                        |\n");
        printf("|_____________________________________________________________|\n");
        printf("|1 |                      Menu Kasir                          |\n");
        printf("|2 |                      Master Barang                       |\n");
        printf("|3 |                      History Transaksi                   |\n");
        printf("|4 |                      Laporan Keuangan                    |\n");
        printf("|5 |                      Tutup Program                       |\n");
        printf("|__|__________________________________________________________|\n");
        printf("|                                                             |\n");
        printf("|  Masukkan Nomor Untuk Masuk Ke Dalam Program Yang Dipilih   |\n");
        printf("|_____________________________________________________________|\n");
        printf("\nPilih : ");fflush(stdin);gets(temp);
		
		pilihan = atoi(temp);
		
        switch (pilihan)
        {
	        case 1: //Kasir
	       		menuKasir();
	        break;
	        
	        case 2: //Master Barang
	            masterBarang();
	        break;
	        
	        case 3: //History Transaksi
	            historyTransaksi();
	        break;
	        
	        case 4: //Laporan Keuangan
	            laporanKeuangan();
	        break;
	        
	        case 5: //Keluar
	        	printf("\nT E R I M A  K A S I H");
	        	exit(0);
			break;
			
	        default: //Error Handling
	            printf("\n\t Pilihan Tidak Ada !");
	        break;
        }
        getch();
	}
	while(pilihan != 5);
	
	return 0;
}
