#include "header.h"

void baris(int tipe, int index)
{
	if(tipe == 0)
	{
		if(index == 0)
		{
			printf( "--------------------------------------------------------------------------------------------------------\n");
		}
		else
		{
			printf( "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		}
	}
	else
	{
		if(index == 0)
		{
			printf( "========================================================================================================\n");
		}
		else
		{
			printf( "=====================================================================================\n");
		}
	}
}

void judul(string text, int index)
{
	if(index == 0)
	{
		printf( "|                                          %-60s|\n", text);
	}
	else
	{
		printf( "|                                                                                  %-95s|\n", text);
	}
}