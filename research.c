#include <stdio.h>
#include <string.h>

//Kamar pasien
struct kamar 
{
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
	char jenis_penyakit[20];
};

struct rumah_sakit
{
    struct kamar kamar;
    struct masuk masuk;
    struct pasien pasien;
}

main()
{
    struct rumah_sakit data[5];

    strcpy(data[0].kamar.jenis_kamar, "REG");
    strcpy(data[1].kamar.jenis_kamar, "VIP");

    printf("%d", strcmp(data[1].kamar.jenis_kamar, data[0].kamar.jenis_kamar));
    if(strcmp(data[0].kamar.jenis_kamar, data[1].kamar.jenis_kamar) !=0 && strcmp(data[0].kamar.jenis_kamar, data[1].kamar.jenis_kamar) !=0  )
    {
        printf("Ga sama");
    }
    else 
    {
        printf("Sama lur");
    }
}