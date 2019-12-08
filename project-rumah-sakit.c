#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct kamar {
	char jenis_kamar[10];
	int nomor_kamar;
};

struct masuk {
	int tanggal;
	char bulan[10];
	int tahun;
};

struct pasien {
	int id_pasien;
	char nama_pasien[50];
	char jenis_penyakit[20];
	struct kamar kamar;
	struct masuk tanggal_masuk;
};
typedef struct pasien data_pasien;

data_pasien data[3];

int i=0;

void input(int i){	
	printf("Masukan ID Pasien 				: ");
	scanf("%d", &data[i].id_pasien); fflush(stdin);
	printf("Masukan Nama Pasien 			: "); 
	gets(data[i].nama_pasien); fflush(stdin);
	printf("Masukan Jenis Penyakit Pasien 	: "); 
	gets(data[i].jenis_penyakit); fflush(stdin);
	printf("Masukan Jenis Kamar 			: ");
	scanf("%s", &data[i].kamar.jenis_kamar); fflush(stdin);
	printf("Masukan Nomor Kamar 			: ");
	scanf("%d", &data[i].kamar.nomor_kamar); fflush(stdin);
	printf("Masukan Tanggal 				: ");
	scanf("%d", &data[i].tanggal_masuk.tanggal); fflush(stdin);
	printf("Masukan Nama Bulan 				: ");
	scanf("%s", &data[i].tanggal_masuk.bulan); fflush(stdin);
	printf("Masukan Tahun 					: ");
	scanf("%d", &data[i].tanggal_masuk.tahun); fflush(stdin);
	
	system("pause");
}

void view(int i){
	int k;
	for(k=0; k<i; k++){
		printf("ID Pasien 		: %d\n", data[k].id_pasien);
		printf("Nama Pasien 	: %s\n", data[k].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data[k].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data[k].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data[k].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data[k].tanggal_masuk.tanggal, data[k].tanggal_masuk.bulan, data[k].tanggal_masuk.tahun);
	}
}

void update(int i){
	int id_update, k;
	printf("Masukan ID Pasien : ");
	scanf("%d", &id_update); fflush(stdin);
	
	for(k=0; k<i; k++){
		if(id_update == data[k].id_pasien){
			printf("ID Pasien 						: %d\n", data[k].id_pasien);
			printf("Masukan Nama Pasien 			: "); 
			gets(data[k].nama_pasien); fflush(stdin);
			printf("Masukan Jenis Penyakit Pasien 	: "); 
			gets(data[k].jenis_penyakit); fflush(stdin);
			printf("Masukan Jenis Kamar 			: ");
			scanf("%s", &data[k].kamar.jenis_kamar); fflush(stdin);
			printf("Masukan Nomor Kamar 			: ");
			scanf("%d", &data[k].kamar.nomor_kamar); fflush(stdin);
			printf("Masukan Tanggal 				: ");
			scanf("%d", &data[i].tanggal_masuk.tanggal); fflush(stdin);
			printf("Masukan Nama Bulan 				: ");
			scanf("%s", &data[i].tanggal_masuk.bulan); fflush(stdin);
			printf("Masukan Tahun 					: ");
			scanf("%d", &data[i].tanggal_masuk.tahun); fflush(stdin);
		}
	}
}

int binary_id(int i, int awal, int akhir, int cari_pasien){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(data[tengah].id_pasien == cari_pasien){
		return tengah+1;
	} else if(data[tengah].id_pasien < cari_pasien){
		return binary_id(i, tengah+1, akhir, cari_pasien);
	} else {
		return binary_id(i, awal, tengah-1, cari_pasien);
	}
}

int binary_kamar(int i, int awal, int akhir, int cari_kamar){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(data[tengah].kamar.nomor_kamar == cari_kamar){
		return tengah+1;
	} else if(data[tengah].kamar.nomor_kamar < cari_kamar){
		return binary_kamar(i, tengah+1, akhir, cari_kamar);
	} else {
		return binary_kamar(i, awal, tengah-1, cari_kamar);
	}
}

//char binary_nama(int i, int awal, int akhir, char cari_nama[]){
//	int tengah = (awal + akhir) / 2;
//	
//	if(awal>akhir){
//		return -1;
//	} else if(strcmp(data[tengah].nama_pasien,cari_nama) == 0){
//		return tengah+1;
//	} else if(strcmp(data[tengah].nama_pasien,cari_nama) < 0){
//		return binary_nama(i, tengah+1, akhir, cari_nama);
//	} else {
//		return binary_nama(i, awal, tengah-1, cari_nama);
//	}
//}

//======================== SEDIKIT BENAR (DILARANG KERAS DIHAPUS) ========================
char binary_nama(int i, char cari_nama[]){
	int akhir, awal, tengah, ketemu, a;
    akhir = i; awal = 0; ketemu = -1; a = 0;
    while (ketemu == -1 && a < i) {   
        
		tengah = (awal+akhir)/2;

        if(strcmp(data[tengah].nama_pasien,cari_nama) == 0) {
            ketemu = tengah;
        } else {
        	if (strcmp(data[tengah].nama_pasien,cari_nama) < 0) {
                awal = tengah + 1;
            } else {
                akhir = tengah - 1;
            }
        }a++;
        
    }return ketemu;
}

void id(int i){
	int cari_pasien, hasil;
	
	printf("Masukan ID Pasien yang Dicari : ");
	scanf("%d", &cari_pasien); fflush(stdin);
			
	hasil = binary_id(i, 0, i, cari_pasien);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n\n", data[hasil-1].kamar.nomor_kamar);
    }
}

void kamar(int i){
	int cari_kamar, hasil;
	
	printf("Masukan Nomor Kamar yang Dicari : ");
	scanf("%d", &cari_kamar); fflush(stdin);
			
	hasil = binary_kamar(i, 0, i, cari_kamar);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n\n", data[hasil-1].kamar.nomor_kamar);
    }
}

void nama(int i){
	char cari_nama[20];
	int hasil;
	
	printf("Masukan Nama yang Dicari : ");
	gets(cari_nama); fflush(stdin);
	
	//hasil = binary_nama(i, 0, i, cari_nama);
	hasil = binary_nama(i, cari_nama);
	
    if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	//printf("%d", i);
    	printf("===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data[hasil].id_pasien);
		printf("Nama Pasien 	: %s\n", data[hasil].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data[hasil].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data[hasil].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n\n", data[hasil].kamar.nomor_kamar);
    }
}

void sub_cari(int i){
	int cari, k;
	int cari_pasien, cari_kamar, hasil;
	char cari_nama[20];
	
	printf("Cari Data Berdasarkan : \n");
	printf("1. ID Pasien\n");
	printf("2. Nama Pasien\n");
	printf("3. Nomor Kamar\n");
	printf("Masukan Pilihan Anda : ");
	scanf("%d", &cari);fflush(stdin);
	
	if(cari == 1){
		id(i);
	} else if(cari == 2){
		nama(i);	
	} else if(cari == 3){
		kamar(i);
	}
}

/*
	FORMAT DATA
		struct kamar {
			char jenis_kamar[10];
			int nomor_kamar;
		};

		struct masuk {
			int tanggal;
			char bulan[10];
			int tahun;
		};

		struct pasien {
			int id_pasien;
			char nama_pasien[50];
			char jenis_penyakit[20];
			struct kamar kamar;
			struct masuk tanggal_masuk;
		};
*/

merging_id(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    struct pasien temp[high+1];

    while(i<=mid && j<= high)
    {
        if(data[i].id_pasien < data[j].id_pasien)
        {
            temp[k++] = data[i++];
        }
        else
        {
            temp[k++] = data[j++];
        }
    }

    while(i<= mid)
    {
        temp[k++] = data[i++];
    }

    while(j<= high)
    {
        temp[k++] = data[j++];
    }

    for(i = low; i <= high; i++)
    {
        data[i] = temp[i];
    }
}

sort_id(int low, int high) 
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
}

void urutkan_id(int i, int banyak_data)
{
	int a;
	for(a = 0; a < banyak_data; a++)
	{
		printf("[%d] ", data[a].id_pasien);
	}
}

void urutkan_nama(int i);
void urutkan_penyakit(int i);
void urutkan_jenis_kamar(int i);
void urutkan_nomor_kamar(int i);

void urutkan(int i)
{
	int low = 0;
	int banyak_data = sizeof(data) / sizeof(data[0]);
	int urutkan;

	printf("Urutkan Data berdasarkan : \n");
	printf("1. ID Pasien \n");
	printf("2. Nama Pasien \n");
	printf("3. Jenis Penyakit \n");
	printf("4. Jenis Kamar \n");
	printf("5. Nomor Kamar \n");
	printf("Masukkan pilihan Anda : ");
	scanf("%d", &urutkan); 
	fflush(stdin);

	if(urutkan == 1)
	{
		system("cls");
		sort_id(low, banyak_data-1);
		urutkan_id(i, banyak_data);
	}
	else if(urutkan == 2)
	{
		system("cls");
		printf("Nama Pasien \n");
		// urutkan_nama(i);
	}
	else if(urutkan == 3)
	{
		system("cls");
		printf("Penyakit Pasien \n");
		// urutkan_penyakit(i);
	}
	else if(urutkan == 4)
	{
		system("cls");
		printf("Jenis Kamar \n");
		// urutkan_jenis_kamar(i);
	}
	else if(urutkan == 5)
	{
		system("cls");
		printf("Nomor Kamar \n");
		// urutkan_nomor_kamar(i);
	}
	else
	{
		system("cls");
		printf("Pilihan anda tidak valid! \n");
		printf("Silahkan pilih kembali \n");
	}
}

void menu_utama(int i){
	int pilih;
	
	do{
		printf("===== SISTEM INFORMASI RUMAH SAKIT =====\n");
		printf("1. Daftarkan Pasien\n");
		printf("2. Lihat Data Pasien\n");
		printf("3. Update Data Pasien\n");
		printf("4. Cari Data\n");
		printf("5. Urutkan Data\n");
		printf("Masukan Pilihan Anda : ");
		scanf("%d", &pilih); fflush(stdin);
	
		if(pilih == 1){
			system("cls");
			input(i);
			i++;
			system("cls");
		} else if(pilih == 2){
			system("cls");
			view(i);
			system("pause");
			system("cls");
		} else if(pilih == 3){
			system("cls");
			update(i);
			system("pause");
			system("cls");
		} else if(pilih == 4){
			system("cls");
			sub_cari(i);
			system("pause");
			system("cls");
		} else if(pilih == 5){
			system("cls");
			urutkan(i);
			system("pause");
			system("cls");
		}
	} while(pilih != 1 || pilih != 2 || pilih != 3 || pilih != 4 || pilih != 5);
}

int main() {
	menu_utama(i);
	return 0;
}
