#include "header.h"

string todo;
	
int a;
FILE *fBarang;
Barang barang[X];
Barang dataBarang;
int jumlah;
int cari;

int id;
string nama;
float hargaBeli;
float hargaJual;
int stok;
float modal;
float pendapatan;

string temp;
bool check;
float limit = 99999999;

void masterBarang()
{
	bool exit = false;
	
	do
	{
		system("cls");
		tampilBarang(1);
		
		exit = false;
		
		printf("\nApa Yang Ingin Anda Lakukan (Tambah/Stok/Edit/Hapus/Keluar) ?");
		printf("\nMasukkan Perintah : ");fflush(stdin);gets(todo);
		
		if(strcmpi(todo,"Tambah") == 0)
		{
			tambahBarang();
		}
		else if(strcmpi(todo,"Stok") == 0)
		{
			stokBarang();
		}
		else if(strcmpi(todo,"Edit") == 0)
		{
			editBarang();
		}
		else if(strcmpi(todo,"Hapus") == 0)
		{
			hapusBarang();
		}
		else if(strcmpi(todo,"Keluar") == 0)
		{
			printf("\n\tKembali Ke Menu Utama !");
			exit = true;
		}
		else
		{
			printf("\n\tPerintah Tidak Ditemukan !");
		}
		
		if(exit != true)
		{
			getch();
		}
	} 
	while(exit != true);
}

void tambahBarang()
{
	fBarang = fopen("barang.dat", "rb+");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
	
	do
	{
		printf("\nMasukkan ID Barang : ");fflush(stdin);gets(temp);
		
		check = isNumber(temp);
		
		if(check)
		{
			if(strlen(temp) != 0)
			{
				id = atoi(temp);
				
				if(id != 0)
				{
					jumlah = jumlahBarang(barang);
					cari = cariBarang(barang,id,jumlah);
					
					if(cari < 0)
					{
						do
						{
							printf("\nMasukkan Nama Barang : ");fflush(stdin);gets(nama);
							
							if(strlen(nama) == 0)
							{
								printf("\n\tNama Barang Tidak Boleh Kosong !\n");
							}
						}
						while(strlen(nama) == 0);
						
						do
						{
							printf("\nMasukkan Harga Beli Barang : ");fflush(stdin);gets(temp);
							
							hargaBeli = atof(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(hargaBeli > limit)
							{
								printf("\n\tHarga Beli Barang Terlalu Mahal !\n");
							}
							
							if(check && hargaBeli == 0)
							{
								printf("\n\tHarga Beli Tidak Boleh Nol !\n");
							}
						}
						while(!check || hargaBeli > limit || hargaBeli == 0);
						
						do
						{
							printf("\nMasukkan Harga Jual Barang : ");fflush(stdin);gets(temp);
							
							hargaJual = atof(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(hargaJual > limit)
							{
								printf("\n\tHarga Jual Barang Terlalu Mahal !\n");
							}
							
							if(check && hargaJual == 0)
							{
								printf("\n\tHarga Jual Tidak Boleh Nol !\n");
							}
						}
						while(!check || hargaJual > limit || hargaJual == 0);
						
						do
						{
							printf("\nMasukkan Stok Barang : ");fflush(stdin);gets(temp);
							
							stok = atoi(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(stok > limit)
							{
								printf("\n\tStok Barang Terlalu Banyak !\n");
							}
							
							if(check && stok == 0)
							{
								printf("\n\tStok Tidak Boleh Nol !\n");
							}
						}
						while(!check || stok > limit || stok == 0);
						
						dataBarang.id = id;
						strcpy(dataBarang.nama,nama);
						dataBarang.hargaBeli = hargaBeli;
						dataBarang.hargaJual = hargaJual; 
						dataBarang.stok = stok;
						dataBarang.modal = (float) hargaBeli * stok;
				        dataBarang.pendapatan = 0;
				        dataBarang.jumlahTerbeli = 0;
				        
				        fseek(fBarang,(dataBarang.id) * sizeof(Barang),SEEK_SET);
				        fwrite(&dataBarang,sizeof(Barang),1,fBarang);
				        
				        if(fwrite != 0)
				        {
				        	printf("\n\tTambah Barang Berhasil !");
						}
						else
						{
							printf( "\n\tTambah Barang Gagal !");
						}
					}
					else
					{
						printf("\n\tID Barang Sudah Digunakan ! \n");
					}
				}
				else
				{
					printf("\n\tID Tidak Boleh Nol !\n");
				}
			}
			else
			{
				printf("\n\tID Tidak Boleh Kosong !\n");
			}
		}
		else
		{
			printf("\n\tInput Tidak Valid !\n");
		}
	}
	while(!check || strlen(temp) == 0 || id == 0);
	
	fclose(fBarang);
}

void stokBarang()
{
	fBarang = fopen("barang.dat", "rb+");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
	
	do
	{
		printf("\nMasukkan ID Barang : ");fflush(stdin);gets(temp);
		
		check = isNumber(temp);
		
		if(check)
		{
			if(strlen(temp) != 0)
			{
				id = atoi(temp);
				
				if(id != 0)
				{
					jumlah = jumlahBarang(barang);
					cari = cariBarang(barang,id,jumlah);
					
					if(cari >= 0)
					{	
						do
						{
							printf("\nTambah Berapa Stok Barang : ");fflush(stdin);gets(temp);
							
							stok = atoi(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(stok > limit)
							{
								printf("\n\tStok Barang Terlalu Banyak !\n");
							}
							
							if(check && stok == 0)
							{
								printf("\n\tStok Barang Tidak Jadi Ditambah !\n");
								return;
							}
						}
						while(!check || stok > limit || stok == 0);
						
						dataBarang.id = barang[cari].id;
						strcpy(dataBarang.nama,barang[cari].nama);
						dataBarang.hargaBeli = barang[cari].hargaBeli;
						dataBarang.hargaJual = barang[cari].hargaJual; 
						dataBarang.stok = barang[cari].stok + stok;
						dataBarang.modal = (float) barang[cari].modal + (barang[cari].hargaBeli * stok);
				        dataBarang.pendapatan = barang[cari].pendapatan;
				        dataBarang.jumlahTerbeli = barang[cari].jumlahTerbeli;
				        
				        modal = barang[cari].modal;
				        
				        fseek(fBarang,(dataBarang.id) * sizeof(Barang),SEEK_SET);
				        fwrite(&dataBarang,sizeof(Barang),1,fBarang);
				        
				        if(fwrite != 0)
				        {
				        	printf("\nModal Sebelum Tambah Stok : %.0f",modal);
				        	printf("\nModal Sesudah Tambah Stok : %.0f",dataBarang.modal);
				        	printf("\n\n\tTambah Stok Barang Berhasil !");
						}
						else
						{
							printf( "\n\tTambah Stok Barang Gagal !");
						}
					}
					else
					{
						printf("\n\tID Barang Tidak Ditemukan ! \n");
					}
				}
				else
				{
					printf("\n\tID Tidak Boleh Nol !\n");
				}
			}
			else
			{
				printf("\n\tID Tidak Boleh Kosong !\n");
			}
		}
		else
		{
			printf("\n\tInput Tidak Valid !\n");
		}
	}
	while(!check || strlen(temp) == 0 || id == 0);
	
	fclose(fBarang);
}

void editBarang()
{
	fBarang = fopen("barang.dat", "rb+");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
	
	do
	{
		printf("\nMasukkan ID Barang : ");fflush(stdin);gets(temp);
		
		check = isNumber(temp);
		
		if(check)
		{
			if(strlen(temp) != 0)
			{
				id = atoi(temp);
				
				if(id != 0)
				{
					jumlah = jumlahBarang(barang);
					cari = cariBarang(barang,id,jumlah);
					
					if(cari >= 0)
					{
						do
						{
							printf("\nMasukkan Nama Barang : ");fflush(stdin);gets(nama);
							
							if(strlen(nama) == 0)
							{
								printf("\n\tNama Barang Tidak Boleh Kosong !\n");
							}
						}
						while(strlen(nama) == 0);
						
						do
						{
							printf("\nMasukkan Harga Beli Barang : ");fflush(stdin);gets(temp);
							
							hargaBeli = atof(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(hargaBeli > limit)
							{
								printf("\n\tHarga Beli Barang Terlalu Mahal !\n");
							}
							
							if(check && hargaBeli == 0)
							{
								printf("\n\tHarga Beli Tidak Boleh Nol !\n");
							}
						}
						while(!check || hargaBeli > limit || hargaBeli == 0);
						
						do
						{
							printf("\nMasukkan Harga Jual Barang : ");fflush(stdin);gets(temp);
							
							hargaJual = atof(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(hargaJual > limit)
							{
								printf("\n\tHarga Jual Barang Terlalu Mahal !\n");
							}
							
							if(check && hargaJual == 0)
							{
								printf("\n\tHarga Jual Tidak Boleh Nol !\n");
							}
						}
						while(!check || hargaJual > limit || hargaJual == 0);
						
						dataBarang.id = id;
						strcpy(dataBarang.nama,nama);
						dataBarang.hargaBeli = hargaBeli;
						dataBarang.hargaJual = hargaJual; 
						dataBarang.stok = barang[cari].stok;
						dataBarang.modal = barang[cari].modal;
				        dataBarang.pendapatan = barang[cari].pendapatan;
				        dataBarang.jumlahTerbeli = barang[cari].jumlahTerbeli;
				        
				        fseek(fBarang,(dataBarang.id) * sizeof(Barang),SEEK_SET);
				        fwrite(&dataBarang,sizeof(Barang),1,fBarang);
				        
				        if(fwrite != 0)
				        {
				        	printf("\n\tEdit Barang Berhasil !");
						}
						else
						{
							printf( "\n\tEdit Barang Gagal !");
						}
					}
					else
					{
						printf("\n\tID Barang Tidak Ditemukan ! \n");
					}
				}
				else
				{
					printf("\n\tID Tidak Boleh Nol !\n");
				}
			}
			else
			{
				printf("\n\tID Tidak Boleh Kosong !\n");
			}
		}
		else
		{
			printf("\n\tInput Tidak Valid !\n");
		}
	}
	while(!check || strlen(temp) == 0 || id == 0);
	
	fclose(fBarang);
}

void hapusBarang()
{
	fBarang = fopen("barang.dat", "rb+");
	
	if(fBarang == NULL)
	{
        printf("File Tidak Bisa Dibuka !");
        return;
    }
	
	do
	{
		printf("\nMasukkan ID Barang : ");fflush(stdin);gets(temp);
		
		check = isNumber(temp);
		
		if(check)
		{
			if(strlen(temp) != 0)
			{
				id = atoi(temp);
				dataBarang.id = atoi(temp);
				
				if(dataBarang.id != 0)
				{
					jumlah = jumlahBarang(barang);
					cari = cariBarang(barang,dataBarang.id,jumlah);
					
					if(cari >= 0)
					{
						fseek(fBarang,(dataBarang.id) * sizeof(Barang),SEEK_SET);  
						       
					    dataBarang.id = 0;
					    strcpy(dataBarang.nama,"");
					    dataBarang.hargaBeli = 0;
					    dataBarang.hargaJual = 0;
					    dataBarang.modal = 0;
					    dataBarang.pendapatan = 0;
					    dataBarang.stok = 0;
					    dataBarang.jumlahTerbeli = 0;
				
					    fwrite(&dataBarang,sizeof(Barang),1,fBarang);
					    
				    	if(fwrite != 0)
				        {
				        	printf("\n\tHapus Barang Berhasil !");
						}
						else
						{
							printf( "\n\tHapus Barang Gagal !");
						}
					}
					else
					{
						printf("\n\tID Barang Tidak Ditemukan ! \n");
					}
				}
				else
				{
					printf("\n\tID Tidak Boleh Nol !\n");
				}
			}
			else
			{
				printf("\n\tID Tidak Boleh Kosong !\n");
			}
		}
		else
		{
			printf("\n\tInput Tidak Valid !\n");
		}
	}
	while(!check || strlen(temp) == 0 || id == 0);
	
	fclose(fBarang);
}
