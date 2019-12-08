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
	char jenis_kamar[10];
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
	char jenis_penyakit[50];
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
	printf("Masukan ID Pasien 				: ");
	scanf("%d", &data_pasien[data_sekarang].id_pasien);
	fflush(stdin);
	
	printf("Masukan Nama Pasien 			: ");
	scanf("%s", &data_pasien[data_sekarang].nama_pasien);
	fflush(stdin); 
	
	printf("Masukan Jenis Penyakit Pasien 	: ");
	scanf("%s", &data_pasien[data_sekarang].jenis_penyakit); 
	fflush(stdin);

	printf("Masukan Jenis Kamar 			: ");
	scanf("%s", &data_pasien[data_sekarang].kamar.jenis_kamar);
	fflush(stdin);

	printf("Masukan Nomor Kamar 			: ");
	scanf("%d", &data_pasien[data_sekarang].kamar.nomor_kamar);
	fflush(stdin);

	printf("Masukan Tanggal 				: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tanggal);
	fflush(stdin);

	printf("Masukan Nama Bulan 				: ");
	scanf("%s", &data_pasien[data_sekarang].tanggal_masuk.bulan);
	fflush(stdin);

	printf("Masukan Tahun 					: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tahun);
	fflush(stdin);
}

//--------------------------------------- VIEW DATA ---------------------------------------//

void view(int data_sekarang){
	int i;
	for(i=0; i<data_sekarang; i++){
		printf("ID Pasien 		: %d\n", data_pasien[i].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[i].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[i].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[i].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[i].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[i].tanggal_masuk.tanggal, data_pasien[i].tanggal_masuk.bulan, data_pasien[i].tanggal_masuk.tahun);
	}
}

//--------------------------------------- UPDATE DATA ---------------------------------------//

void update(int data_sekarang){
	int id_update, i;

	printf("Masukan ID Pasien : ");
	scanf("%d", &id_update);
	fflush(stdin);
	
	for(i=0; i<data_sekarang; i++){
		if(id_update == data_pasien[i].id_pasien){
			printf("ID Pasien 						: %d\n", data_pasien[i].id_pasien);
			printf("Masukan Nama Pasien 			: ");
			scanf("%s", &data_pasien[i].nama_pasien); 
			fflush(stdin);

			printf("Masukan Jenis Penyakit Pasien 	: ");
			scanf("%s", &data_pasien[i].jenis_penyakit); 
			fflush(stdin);

			printf("Masukan Jenis Kamar 			: ");
			scanf("%s", &data_pasien[i].kamar.jenis_kamar);
			fflush(stdin);

			printf("Masukan Nomor Kamar 			: ");
			scanf("%d", &data_pasien[i].kamar.nomor_kamar);
			fflush(stdin);

			printf("Masukan Tanggal 				: ");
			scanf("%d", &data_pasien[i].tanggal_masuk.tanggal);
			fflush(stdin);

			printf("Masukan Nama Bulan 				: ");
			scanf("%s", &data_pasien[i].tanggal_masuk.bulan);
			fflush(stdin);

			printf("Masukan Tahun 					: ");
			scanf("%d", &data_pasien[i].tanggal_masuk.tahun);
			fflush(stdin);
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
	
	printf("Masukan ID Pasien yang Dicari : ");
	scanf("%d", &cari_pasien);
	fflush(stdin);
			
	hasil = binary_id(data_pasien, 0, data_sekarang, cari_pasien);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 		: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NOMOR KAMAR ---------------------------------------//

void kamar(int data_sekarang){
	int cari_kamar, hasil;
	
	printf("Masukan Nomor Kamar yang Dicari : ");
	scanf("%d", &cari_kamar);
	fflush(stdin);
			
	hasil = binary_kamar(data_pasien, 0, data_sekarang, cari_kamar);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 		: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NAMA PASIEN ---------------------------------------//

void nama(int data_sekarang){
	char cari_nama[20];
	int hasil;
	
	printf("Masukan Nama yang Dicari : ");
	scanf("%s", &cari_nama);
	fflush(stdin);
	
	hasil = binary_nama(data_pasien, 0, data_sekarang, cari_nama);
	
    if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	//printf("%d", i);
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data_pasien[hasil].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil].kamar.jenis_kamar);
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
	fflush(stdin);
	
	if(cari == 1){
		id(data_sekarang);
	} else if(cari == 2){
		nama(data_sekarang);	
	} else if(cari == 3){
		kamar(data_sekarang);
	}
}

//--------------------------------------- MERGE SORT ID PASIEN ---------------------------------------//
void merging_id(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(data_pasien[i].id_pasien < data_pasien[j].id_pasien)
        {
        	temp[k++] = data_pasien[i++];
        }
        else
        {
        	temp[k++] = data_pasien[j++];
        }
    }

    while(i<= mid)
    {
    		temp[k++] = data_pasien[i++];
    }

    while(j<= high)
    {
            temp[k++] = data_pasien[j++];
    }

    for(i = low; i <= high; i++)
    {
    	data_pasien[i] = temp[i];
    }
}

void sort_id(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_id(low, mid);
        sort_id(mid+1, high);

        merging_id(low, mid, high);
    } else { 
        return;
    }
};

//--------------------------------------- SUB MENU SORT DATA ---------------------------------------//

void sub_sort(){
	int pilihan;
	int banyak_data = sizeof(data_pasien) / sizeof(data_pasien[0]);

	printf("Urutkan Data Berdasarkan : \n");
	printf("1. ID Pasien\n");
	printf("2. Nama Pasien\n");
	printf("3. Jenis Penyakit\n");
	printf("4. Jenis Kamar\n");
	printf("5. Nomor Kamar\n");
	printf("Masukan Pilihan Anda : ");
	scanf("%d", &pilihan);
	fflush(stdin);

	if(pilihan == 1)
	{
		
	}
	else if(pilihan == 2)
	{

	}
	else if(pilihan == 3)
	{

	}
	else if(pilihan == 4)
	{

	}
	else if(pilihan == 5)
	{

	}
	else
	{
		printf("\n");
		printf("Pilihan anda tidak valid! \n");
		printf("Silahkan pilih kembali \n");
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
		system("cls");
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
			system("cls");
			input(data_sekarang);
			data_sekarang = data_sekarang + 1;
			system("pause");
		}
		else if(pilih == 2)
		{
			system("cls");
			view(data_sekarang);
			system("pause");
		}
		else if(pilih == 3)
		{
			system("cls");
			update(data_sekarang);
			system("pause");
		}
		else if(pilih == 4)
		{
			system("cls");
			sub_cari(data_sekarang);
			system("pause");
		}
		else if(pilih == 5)
		{
			system("cls");
			sub_sort();
			system("pause");
		}
		else if(pilih == 6)
		{
			break;
		}
	}
}
