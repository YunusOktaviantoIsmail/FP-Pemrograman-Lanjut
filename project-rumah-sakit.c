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

int input(){
	int i;
	i=0;
	
	data_pasien data[i];
	
	printf("Masukan Nama Pasien : ");
	scanf("%s", &data[i].nama_pasien); fflush(stdin);
	printf("Masukan Jenis Penyakit Pasien : ");
	scanf("%s", &data[i].jenis_penyakit); fflush(stdin);
	printf("Masukan Jenis Kamar : ");
	scanf("%s", &data[i].kamar.jenis_kamar);
	printf("Masukan Nomor Kamar : ");
	scanf("%d", &data[i].kamar.nomor_kamar);
	
	i=i+1;
	printf("%d", i);
}

int main() {
	int pilih;
	
	printf("===== SISTEM INFORMASI RUMAH SAKIT =====\n");
	printf("1. Daftarkan Pasien\n");
	printf("2. Lihat Data Pasien\n");
	printf("3. Update Data Pasien\n");
	printf("4. Cari Data\n");
	printf("5. Urutkan Data\n");
	printf("Masukan Pilihan Anda : ");
	scanf("%d", &pilih);
	
	if(pilih == 1){
		input();
	}else{
		return 0;
	}
	
	return 0;
}
