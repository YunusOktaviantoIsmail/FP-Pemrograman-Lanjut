#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Kamar pasien
struct kamar 
{
	/*
        Jenis Kamar : 
            1.VIP
            2.III
            3.II
            4.I
    */
	int jenis_kamar;
	int nomor_kamar;
};

//Tanggal masuk pasien
struct masuk 
{
	int tanggal;
	char bulan[10];
	int tahun;
};

//Data pasien
struct pasien 
{
	int id_pasien;
	char nama_pasien[50];
	int jenis_penyakit;
	struct kamar kamar;
	struct masuk tanggal_masuk;
    /*
        Jenis Penyakit : 
            1. Demam Berdarah
            2. Kecelakaan
            3. Lain-lain
    */
}; struct pasien data_pasien[5];
/////////////////////////////////////////////

/*



Tempat fungsi





*/

///////////////////////////////////////////////
void main() {
	//Inisialisasi variabel
	int data_sekarang = 0;
	int pilih;
	int loop;

	for(loop = 1; loop > 0;)
	{
		fflush(stdin);
		printf("===== SISTEM INFORMASI RUMAH SAKIT =====\n");
		printf("1. Daftarkan Pasien\n");
		printf("2. Lihat Data Pasien\n");
		printf("3. Update Data Pasien\n");
		printf("4. Cari Data\n");
		printf("5. Urutkan Data\n");
		printf("Masukan Pilihan Anda : ");
		scanf("%d", &pilih);
		fflush(stdin);

		if(pilih == 1)
		{
			/*
				Lakukan sesuatu disini
			*/
			data_sekarang = data_sekarang + 1;
		}
		else if(pilih == 2)
		{
			
		}
		else if(pilih == 3)
		{

		}
		else if(pilih == 4)
		{
			
		}
		else if(pilih == 5)
		{

		}
		else if(pilih == 6)
		{
			
		}
	}
}
