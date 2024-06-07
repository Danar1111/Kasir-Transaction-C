#include "header.h"

void tampilBarang(int index)
{
	int a = 0;
	FILE* fBarang;
	Barang barang;
	
	fBarang = fopen("barang.dat", "rb");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
	baris(0, index);
    judul("DATA BARANG", index);
    baris(0, index);
    
    if(index == 0)
    {
    	printf( "|  %-4s|  %-24s|  %-25s|  %-25s|  %-10s|\n", "ID", "NAMA BARANG","HARGA BELI", "HARGA JUAL", "STOK");
	} 
    else
    {
    	printf( "|  %-4s|  %-24s|  %-25s|  %-25s|  %-10s|  %-25s|  %-25s|  %-15s |\n", "ID", "NAMA BARANG", "HARGA BELI", "HARGA JUAL", "STOK", "MODAL", "PENDAPATAN", "JUMLAH TERBELI");
	}
        
    baris(0, index);
    
    while(fread(&barang, sizeof(Barang), 1, fBarang))
    {
    	if(barang.id != 0)
		{
            if(index == 0)
            {
            	printf( "|  %-4d|  %-24s|  %-25.0f|  %-25.0f|  %-10d|\n", barang.id, barang.nama, barang.hargaBeli, barang.hargaJual, barang.stok);
			}
            else
            {
            	printf( "|  %-4d|  %-24s|  %-25.0f|  %-25.0f|  %-10d|  %-25.0f|  %-25.0f|  %-15d |\n", barang.id, barang.nama, barang.hargaBeli, barang.hargaJual, barang.stok, barang.modal, barang.pendapatan, barang.jumlahTerbeli);
			}
                
            a++;
        }
	}
	
	if(a == 0)
    {
    	judul("DATA KOSONG", index);
	}
	
	baris(0, index);
        
    fclose(fBarang);
}

int jumlahBarang(Barang barang[])
{
	int a = 0;
	FILE* fBarang;
	Barang dataBarang;

	fBarang = fopen("barang.dat", "rb");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
    while(fread(&dataBarang, sizeof(Barang), 1, fBarang)) 
	{ 
		if(dataBarang.id != 0 ) 
		{
            barang[a].id = dataBarang.id;
            strcpy(barang[a].nama,dataBarang.nama);
            barang[a].hargaBeli = dataBarang.hargaBeli;
            barang[a].hargaJual = dataBarang.hargaJual;
            barang[a].stok = dataBarang.stok;
            barang[a].modal = dataBarang.modal;
            barang[a].pendapatan = dataBarang.pendapatan;
            barang[a].jumlahTerbeli = dataBarang.jumlahTerbeli;
            
            a++;
    	}
    }    
    
    fclose(fBarang);
    
    return a;
}

int cariBarang(Barang barang[], int id, int jumlah)
{
    int a;
    
    for(a = 0 ; a < jumlah ; a++)
	{
        if(barang[a].id == id)
		{
            return a;
        }
    }
    
    return -1;
}

void tampilRiwayat()
{
	int a = 0;
	FILE* fRiwayat;
	Riwayat riwayat;
	
	fRiwayat = fopen("riwayat.dat", "rb");
	
	if(fRiwayat == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
	baris(0,0);
    judul("RIWAYAT PEMBELIAN", 0);
    baris(0,0);
    
    printf( "|  %-4s|  %-24s|  %-10s| %-20s|  %-30s |\n", "ID", "NAMA BARANG","JUMLAH", "HARGA", "WAKTU");
        
    baris(0,0);
    
    while(fread(&riwayat, sizeof(Riwayat), 1, fRiwayat))
    {
    	if(riwayat.id != 0)
		{
            printf( "|  %-4d|  %-24s|  %-10d| %-20.0f|  %-30s |\n", riwayat.id, riwayat.nama, riwayat.jumlah, riwayat.harga, riwayat.waktu);
                
            a++;
        }
	}
	
	if(a == 0)
    {
    	judul("BELUM ADA RIWAYAT", 0);
	}
	
	baris(0,0);
        
    fclose(fRiwayat);
}

int jumlahRiwayat(Riwayat riwayat[])
{
	int a = 0;
	FILE* fRiwayat;
	Riwayat dataRiwayat;

	fRiwayat = fopen("riwayat.dat", "rb");
	
	if(fRiwayat == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
    
    while(fread(&dataRiwayat, sizeof(Riwayat), 1, fRiwayat)) 
	{ 
		if(dataRiwayat.id != 0 ) 
		{
            riwayat[a].id = dataRiwayat.id;
            strcpy(riwayat[a].nama,dataRiwayat.nama);
            riwayat[a].jumlah = dataRiwayat.jumlah;
            riwayat[a].harga = dataRiwayat.harga;
            strcpy(riwayat[a].waktu,dataRiwayat.waktu);
            
            a++;
    	}
    }    
    
    fclose(fRiwayat);
    
    return a;
}

int cariRiwayat(Riwayat riwayat[], int id, int jumlah)
{
    int a;
    
    for(a = 0 ; a < jumlah ; a++)
	{
        if(riwayat[a].id == id)
		{
            return a;
        }
    }
    
    return -1;
}

void cetakStruk(int index, string tempNama[], int tempStok[], float tempTotal[], float uang[])
{	
	int a;
	float total = 0;
    time_t t; 
    time(&t);
	FILE *struk;
    struk = fopen("struk.txt", "w");
    
    fprintf(struk,"----------------------------------------------------------\n");
    fprintf(struk,"|                          ADAMART                       |\n");
    fprintf(struk,"----------------------------------------------------------\n");
    fprintf(struk,"| %-20s | %-10s | %-18s |\n", "Nama", "Jumlah", "Harga");
    fprintf(struk,"----------------------------------------------------------\n");
    
    for(a = 0 ; a <= index ; a++)
	{
        fprintf(struk, "| %-20s | %-10d | %-18.0f |\n", tempNama[a], tempStok[a], tempTotal[a]);
        total += tempTotal[a];
    }
    
    fprintf(struk,"----------------------------------------------------------\n");
    fprintf(struk,"> 			    Total   : %.0f\n",total);
    fprintf(struk,"> 			    Uang    : %.0f\n",uang[0]);
    fprintf(struk,"> 			    Kembali : %.0f\n",uang[0] - total);
    fprintf(struk,"----------------------------------------------------------\n");
    fprintf(struk,"Transaksi Pada , %s",ctime(&t));
    fprintf(struk,"----------------------------------------------------------\n");
    fprintf(struk,"            TERIMAKASIH, SEKAMAT DATANG KEMBALI             ");
    
    fclose(struk);
}

bool isNumber(string temp)
{
	int a;
	char check[X];
	
	strcpy(check,temp);
	
	for(a = 0 ; a < strlen(temp) ; a++)
	{
		if(check[a] < 48 || check[a] > 57)
		{
			return false;
		}
	}
	
	return true;
}

char *trimwhitespace(char *str)
{
	char *end;
	
	while(isspace((unsigned char)*str)) str++;
	
	if(*str == 0)
	return str;
	
	end = str + strlen(str) - 1;
	while(end > str && isspace((unsigned char)*end)) end--;
	
	end[1] = '\0';
	
	return str;
}
