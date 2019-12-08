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

//--------------------------------------- INPUT DATA ---------------------------------------//

void input(int data_sekarang) {	
	printf("Masukan ID Pasien 				: "); fflush(stdin);
	scanf("%d", &data_pasien[data_sekarang].id_pasien);
	printf("Masukan Nama Pasien 			: "); fflush(stdin);
	scanf("%s", &data_pasien[data_sekarang].nama_pasien); 
	printf("Masukan Jenis Penyakit Pasien 	: "); fflush(stdin);
	scanf("%d", &data_pasien[data_sekarang].jenis_penyakit); 
	printf("Masukan Jenis Kamar 			: ");
	scanf("%d", &data_pasien[data_sekarang].kamar.jenis_kamar);
	printf("Masukan Nomor Kamar 			: ");
	scanf("%d", &data_pasien[data_sekarang].kamar.nomor_kamar);
	printf("Masukan Tanggal 				: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tanggal);
	printf("Masukan Nama Bulan 				: ");
	scanf("%s", &data_pasien[data_sekarang].tanggal_masuk.bulan);
	printf("Masukan Tahun 					: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tahun);
	
	system("pause");
}

//--------------------------------------- VIEW DATA ---------------------------------------//

void view(int data_sekarang){
	int i;
	for(i=0; i<data_sekarang; i++){
		printf("ID Pasien 		: %d\n", data_pasien[i].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[i].nama_pasien);
		printf("Jenis Penyakit 	: %d\n", data_pasien[i].jenis_penyakit);
		printf("Jenis Kamar 	: %d\n", data_pasien[i].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[i].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[i].tanggal_masuk.tanggal, data_pasien[i].tanggal_masuk.bulan, data_pasien[i].tanggal_masuk.tahun);
	}
}

//--------------------------------------- UPDATE DATA ---------------------------------------//

void update(int data_sekarang){
	int id_update, i;
	
	printf("Masukan ID Pasien : ");
	scanf("%d", &id_update);
	
	for(i=0; i<data_sekarang; i++){
		if(id_update == data_pasien[i].id_pasien){
			printf("ID Pasien 						: %d\n", data_pasien[i].id_pasien);
			printf("Masukan Nama Pasien 			: "); fflush(stdin);
			scanf("%s", &data_pasien[i].nama_pasien); 
			printf("Masukan Jenis Penyakit Pasien 	: "); fflush(stdin);
			scanf("%d", &data_pasien[i].jenis_penyakit); 
			printf("Masukan Jenis Kamar 			: "); fflush(stdin);
			scanf("%d", &data_pasien[i].kamar.jenis_kamar);
			printf("Masukan Nomor Kamar 			: "); fflush(stdin);
			scanf("%d", &data_pasien[i].kamar.nomor_kamar);
			printf("Masukan Tanggal 				: "); fflush(stdin);
			scanf("%d", &data_pasien[i].tanggal_masuk.tanggal);
			printf("Masukan Nama Bulan 				: "); fflush(stdin);
			scanf("%s", &data_pasien[i].tanggal_masuk.bulan);
			printf("Masukan Tahun 					: "); fflush(stdin);
			scanf("%d", &data_pasien[i].tanggal_masuk.tahun);
		}
	}
}

//--------------------------------------- BINARY SEARCH ID ---------------------------------------//

int binary_id(struct pasien data_pasien[], int awal, int akhir, int cari_pasien){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(data_pasien[tengah].id_pasien == cari_pasien){
		return tengah+1;
	} else if(data_pasien[tengah].id_pasien < cari_pasien){
		return binary_id(data_pasien, tengah+1, akhir, cari_pasien);
	} else {
		return binary_id(data_pasien, awal, tengah-1, cari_pasien);
	}
}

//--------------------------------------- BINARY SEARCH NOMOR KAMAR ---------------------------------------//

int binary_kamar(struct pasien data_pasien[], int awal, int akhir, int cari_kamar){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(data_pasien[tengah].kamar.nomor_kamar == cari_kamar){
		return tengah+1;
	} else if(data_pasien[tengah].kamar.nomor_kamar < cari_kamar){
		return binary_kamar(data_pasien, tengah+1, akhir, cari_kamar);
	} else {
		return binary_kamar(data_pasien, awal, tengah-1, cari_kamar);
	}
}

//--------------------------------------- BINARY SEARCH NAMA PASIEN ---------------------------------------//

char binary_nama(struct pasien data_pasien[], int awal, int akhir, char cari_nama[]){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(strcmp(data_pasien[tengah].nama_pasien,cari_nama) == 0){
		return tengah+1;
	} else if(strcmp(data_pasien[tengah].nama_pasien,cari_nama) < 0){
		return binary_nama(data_pasien, tengah+1, akhir, cari_nama);
	} else {
		return binary_nama(data_pasien, awal, tengah-1, cari_nama);
	}
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH ID ---------------------------------------//

void id(int data_sekarang){
	int cari_pasien, hasil;
	
	printf("Masukan ID Pasien yang Dicari : "); fflush(stdin);
	scanf("%d", &cari_pasien);
			
	hasil = binary_id(data_pasien, 0, data_sekarang, cari_pasien);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %d\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %d\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NOMOR KAMAR ---------------------------------------//

void kamar(int data_sekarang){
	int cari_kamar, hasil;
	
	printf("Masukan Nomor Kamar yang Dicari : ");
	scanf("%d", &cari_kamar);
			
	hasil = binary_kamar(data_pasien, 0, data_sekarang, cari_kamar);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %d\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %d\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NAMA PASIEN ---------------------------------------//

void nama(int data_sekarang){
	char cari_nama[20];
	int hasil;
	
	printf("Masukan Nama yang Dicari : "); fflush(stdin);
	scanf("%s", &cari_nama);
	
	hasil = binary_nama(data_pasien, 0, data_sekarang, cari_nama);
	
    if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	//printf("%d", i);
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data_pasien[hasil].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil].nama_pasien);
		printf("Jenis Penyakit 	: %d\n", data_pasien[hasil].jenis_penyakit);
		printf("Jenis Kamar 	: %d\n", data_pasien[hasil].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil].kamar.nomor_kamar);
    	printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil].tanggal_masuk.tanggal, data_pasien[hasil].tanggal_masuk.bulan, data_pasien[hasil].tanggal_masuk.tahun);
	}
}

//--------------------------------------- SUB MENU CARI DATA ---------------------------------------//

void sub_cari(int data_sekarang){
	int cari;
	
	printf("Cari Data Berdasarkan : \n");
	printf("1. ID Pasien\n");
	printf("2. Nama Pasien\n");
	printf("3. Nomor Kamar\n");
	printf("Masukan Pilihan Anda : ");
	scanf("%d", &cari);
	
	if(cari == 1){
		id(data_sekarang);
	} else if(cari == 2){
		nama(data_sekarang);	
	} else if(cari == 3){
		kamar(data_sekarang);
	}
}

//////////////////////////////////////////////////////////

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
			input(data_sekarang);
			data_sekarang = data_sekarang + 1;
		}
		else if(pilih == 2)
		{
			view(data_sekarang);
			system("pause");
		}
		else if(pilih == 3)
		{
			update(data_sekarang);
			system("pause");
		}
		else if(pilih == 4)
		{
			sub_cari(data_sekarang);
			system("pause");
		}
		else if(pilih == 5)
		{

		}
		else if(pilih == 6)
		{
			
		}
	}
}
