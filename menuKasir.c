#include "header.h"
	
void menuKasir()
{
	string todo;
	bool exit = false;
	
	do
	{
		system("cls");
		tampilBarang(1);
		
		exit = false;
		
		printf("\nApa Yang Ingin Anda Lakukan (Beli/Keluar) ?");
		printf("\nMasukkan Perintah : ");fflush(stdin);gets(todo);
		
		if(strcmpi(todo,"Beli") == 0)
		{
			beliBarang();
		}
		else if(strcmpi(todo,"Keluar") == 0)
		{
			printf("\n\tKembali Ke Menu Utama !");
			getch();
			main();
			return;
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

void beliBarang()
{
	int a;
	FILE *fBarang;
	FILE *fRiwayat;
	Barang barang[X];
	Barang dataBarang;
	Riwayat riwayat[X];
	Riwayat dataRiwayat;
	int jumlah;
	int cari ;
	
	int indexRiwayat;
	
	int id;
	int stok;
	
	string temp;
	bool check;
	float limit = 99999999;
	
	int index = 0;
	float total = 0;
	int tempStok[X];
	float tempTotal[X];
	float uang;
	
	string tempNama[X];
	float tempHarga[X];
	
	string konfirmasi;
    
	do
	{
		fBarang = fopen("barang.dat", "rb+");
	
		if(fBarang == NULL)
		{
	        printf("File Tidak Bisa Dibuka !");
	        return;
	    }
    
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
							printf("\nMasukkan Banyak Barang : ");fflush(stdin);gets(temp);
							
							stok = atoi(temp);
							check = isNumber(temp);
							
							if(!check)
							{
								printf("\n\tInput Tidak Valid !\n");
							}
							
							if(stok > barang[cari].stok)
							{
								printf("\n\tStok Barang Tidak Mencukupi !\n");
							}
							
							if(check && stok == 0)
							{
								printf("\n\tBarang Tidak Boleh Nol !\n");
								return;
							}
						}
						while(!check || stok > barang[cari].stok || stok == 0);
						
						dataBarang.id = barang[cari].id;
						strcpy(dataBarang.nama,barang[cari].nama);
						dataBarang.hargaBeli = barang[cari].hargaBeli;
						dataBarang.hargaJual = barang[cari].hargaJual; 
						dataBarang.stok = barang[cari].stok - stok;
						dataBarang.modal = barang[cari].modal;
				        dataBarang.pendapatan = (float) barang[cari].pendapatan + (barang[cari].hargaJual * stok);
				        dataBarang.jumlahTerbeli = barang[cari].jumlahTerbeli + stok;
									        
				        fseek(fBarang,(dataBarang.id) * sizeof(Barang),SEEK_SET);
				        fwrite(&dataBarang,sizeof(Barang),1,fBarang);
				        
				        if(fwrite != 0)
				        {
				        	strcpy(tempNama[index],barang[cari].nama);
				        	tempHarga[index] = barang[cari].hargaJual;
				        	tempStok[index] = stok;
				        	tempTotal[index] = barang[cari].hargaJual * stok;
							total += tempTotal[index];
							
							fRiwayat = fopen("riwayat.dat", "rb+");
	
							if(fRiwayat == NULL)
							{
						        printf("File Tidak Bisa Dibuka !");
						        return;
						    }
					    
					    	indexRiwayat = 0;
					    	
					    	while(fread(&dataRiwayat, sizeof(Riwayat), 1, fRiwayat)) 
							{ 
								if(dataRiwayat.id != 0 ) 
								{
						            indexRiwayat++;
						    	}
						    }    
						    
						    time_t t;
    						time(&t);
						
					    	dataRiwayat.id = indexRiwayat + 1;
							strcpy(dataRiwayat.nama,tempNama[index]);
							dataRiwayat.jumlah = tempStok[index];
							dataRiwayat.harga = tempHarga[index]; 		
							strcpy(dataRiwayat.waktu,trimwhitespace(ctime(&t)));
								        
					        fseek(fRiwayat,(dataRiwayat.id) * sizeof(Riwayat),SEEK_SET);
					        fwrite(&dataRiwayat,sizeof(Riwayat),1,fRiwayat);
					        
					        fclose(fRiwayat);
							
							do
							{
								printf("\nIngin Pesan Barang Lagi ? (Y/N) : ");fflush(stdin);gets(konfirmasi);
								
								if((strcmpi(konfirmasi,"N") != 0) && (strcmpi(konfirmasi,"Y") != 0))
								{
									printf("\n\tInput Tidak Valid !\n");
								}
							}
							while((strcmpi(konfirmasi,"N") != 0) && (strcmpi(konfirmasi,"Y") != 0));
							

							if(strcmpi(konfirmasi,"N") == 0)
							{
								system("cls");
								
								for(a = 0 ; a <= index ; a++)
								{
									printf("\n-------------------------------------------");
									printf("\nPembelian Ke - %d", a + 1);
									printf("\nNama Barang : %s",tempNama[a]);
									printf("\nBarang Yang Dibeli : %d",tempStok[a]);
									printf("\nHarga Satu Barang : %.0f",tempHarga[a]);
									printf("\nTotal Harga Barang : %.0f",tempTotal[a]);
									printf("\n-------------------------------------------\n");
								}
								
								printf("\n-------------------------------------------");
								printf("\nTotal Keseluruhan : %.0f",total);
								printf("\n-------------------------------------------\n");
								
								do
								{
									printf("\nMasukkan Uang : ");fflush(stdin);gets(temp);
									
									uang = atof(temp);
									check = isNumber(temp);
									
									if(!check)
									{
										printf("\n\tInput Tidak Valid !\n");
									}
									
									if(uang > limit)
									{
										printf("\n\tUang Terlalu Mahal !\n");
									}
									
									if(check && uang == 0)
									{
										printf("\n\tUang Tidak Boleh Nol !\n");
									}
									else if(check && uang < total)
									{
										printf("\n\tUang Tidak Cukup !\n");
									}
								}
								while(!check || uang > limit || uang == 0 || uang < total);
								
								printf("Kembali : %.0f",uang - total);
								printf("\n\n\tTerimakasih Telah Berbelanja Di AdaMart !\n");
								
								float tempUang[1];
								tempUang[0] = uang;
								cetakStruk(index,tempNama,tempStok,tempTotal,tempUang);
	    
								fclose(fBarang);
								break;
							}
							else
							{
								fclose(fBarang);
								system("cls");
								tampilBarang(1);
								
								for(a = 0 ; a <= index ; a++)
								{
									printf("\n-------------------------------------------");
									printf("\nPembelian Ke - %d", a + 1);
									printf("\nNama Barang : %s",tempNama[a]);
									printf("\nBarang Yang Dibeli : %d",tempStok[a]);
									printf("\nHarga Satu Barang : %.0f",tempHarga[a]);
									printf("\nTotal Harga Barang : %.0f",tempTotal[a]);
									printf("\n-------------------------------------------\n");
								}
								
								printf("\n-------------------------------------------");
								printf("\nTotal Keseluruhan : %.0f",total);
								printf("\n-------------------------------------------\n");
								
								index++;
							}
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
		
		fclose(fBarang);
	}
	while(!check || strlen(temp) == 0 || id == 0 || strcmpi(konfirmasi,"Y") == 0);
}
						
						
						
						
					

