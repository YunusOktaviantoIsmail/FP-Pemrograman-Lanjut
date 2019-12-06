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
	printf("Masukan ID Pasien : ");
	scanf("%d", &data[i].id_pasien);
	printf("Masukan Nama Pasien : "); fflush(stdin);
	gets(data[i].nama_pasien); 
	printf("Masukan Jenis Penyakit Pasien : "); fflush(stdin);
	gets(data[i].jenis_penyakit); 
	printf("Masukan Jenis Kamar : ");
	scanf("%s", &data[i].kamar.jenis_kamar);
	printf("Masukan Nomor Kamar : ");
	scanf("%d", &data[i].kamar.nomor_kamar);
	
	system("pause");
}

void view(int i){
	int k;
	for(k=0; k<i; k++){
		printf("ID Pasien : %d\n", data[k].id_pasien);
		printf("Nama Pasien : %s\n", data[k].nama_pasien);
		printf("Jenis Penyakit : %s\n", data[k].jenis_penyakit);
		printf("Jenis Kamar : %s\n", data[k].kamar.jenis_kamar);
		printf("Nomor Kamar : %d\n\n", data[k].kamar.nomor_kamar);
	}
}

void update(int i){
	int id_update, k;
	printf("Masukan ID Pasien : ");
	scanf("%d", &id_update);
	
	for(k=0; k<i; k++){
		if(id_update == data[k].id_pasien){
			printf("ID Pasien : %d\n", data[k].id_pasien);
			printf("Masukan Nama Pasien : "); fflush(stdin);
			gets(data[k].nama_pasien); 
			printf("Masukan Jenis Penyakit Pasien : "); fflush(stdin);
			gets(data[k].jenis_penyakit); 
			printf("Masukan Jenis Kamar : ");
			scanf("%s", &data[k].kamar.jenis_kamar);
			printf("Masukan Nomor Kamar : ");
			scanf("%d", &data[k].kamar.nomor_kamar);
		}
	}
}

void menu_utama(){
	int pilih, i;
	
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
			i+=1;
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
		}
	} while(pilih != 1 || pilih != 2 || pilih != 3 || pilih != 4 || pilih != 5);
}

int main() {
	menu_utama();
	return 0;
}
