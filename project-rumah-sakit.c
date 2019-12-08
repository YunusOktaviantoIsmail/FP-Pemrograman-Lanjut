#include <stdio.h>
#include <stdlib.h>

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

data_pasien data[50];

int i=0;

void input(int i){	
	printf("Masukan ID Pasien 				: ");
	scanf("%d", &data[i].id_pasien);
	printf("Masukan Nama Pasien 			: "); fflush(stdin);
	gets(data[i].nama_pasien); 
	printf("Masukan Jenis Penyakit Pasien 	: "); fflush(stdin);
	gets(data[i].jenis_penyakit); 
	printf("Masukan Jenis Kamar 			: ");
	scanf("%s", &data[i].kamar.jenis_kamar);
	printf("Masukan Nomor Kamar 			: ");
	scanf("%d", &data[i].kamar.nomor_kamar);
	printf("Masukan Tanggal 				: ");
	scanf("%d", &data[i].tanggal_masuk.tanggal);
	printf("Masukan Nama Bulan 				: ");
	scanf("%s", &data[i].tanggal_masuk.bulan);
	printf("Masukan Tahun 					: ");
	scanf("%d", &data[i].tanggal_masuk.tahun);
	
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
	scanf("%d", &id_update);
	
	for(k=0; k<i; k++){
		if(id_update == data[k].id_pasien){
			printf("ID Pasien 						: %d\n", data[k].id_pasien);
			printf("Masukan Nama Pasien 			: "); fflush(stdin);
			gets(data[k].nama_pasien); 
			printf("Masukan Jenis Penyakit Pasien 	: "); fflush(stdin);
			gets(data[k].jenis_penyakit); 
			printf("Masukan Jenis Kamar 			: ");
			scanf("%s", &data[k].kamar.jenis_kamar);
			printf("Masukan Nomor Kamar 			: ");
			scanf("%d", &data[k].kamar.nomor_kamar);
			printf("Masukan Tanggal 				: ");
			scanf("%d", &data[i].tanggal_masuk.tanggal);
			printf("Masukan Nama Bulan 				: ");
			scanf("%s", &data[i].tanggal_masuk.bulan);
			printf("Masukan Tahun 					: ");
			scanf("%d", &data[i].tanggal_masuk.tahun);
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
	
	printf("Masukan ID Pasien yang Dicari : "); fflush(stdin);
	scanf("%d", &cari_pasien);
			
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
	scanf("%d", &cari_kamar);
			
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
	
	printf("Masukan Nama yang Dicari : "); fflush(stdin);
	gets(cari_nama);
	
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
	scanf("%d", &cari);
	
	if(cari == 1){
		id(i);
	} else if(cari == 2){
		nama(i);	
	} else if(cari == 3){
		kamar(i);
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
		scanf("%d", &pilih);
	
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
		}
	} while(pilih != 1 || pilih != 2 || pilih != 3 || pilih != 4 || pilih != 5);
}

int main() {
	menu_utama(i);
	return 0;
}
