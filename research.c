#include <stdio.h>
#include <string.h>

int data[] = {4,7,1,2,9,5,11,21,15,10,3,42,12,53,20,18,60,1};

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
    /*
        Jenis Penyakit : 
            1. Demam Berdarah
            2. Kecelakaan
            3. Lain-lain
    */
};

//Data seluruh struct menjadi satu kesatuan
struct rumah_sakit
{
    struct pasien pasien;
    struct masuk masuk;
    struct kamar kamar;
};
typedef rumah_sakit;

merging(int low, int mid, int high) 
{  
    int temp[high + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high)
    {
        if (data[i] <= data[j])
            temp[k++] = data[i++];
        else
            temp[k++] = data[j++];
    }
    while (i <= mid)
        temp[k++] = data[i++];
    while (j <= high)
        temp[k++] = data[j++];
    k--;
    while (k >= 0)
    {
        data[k + low] = temp[k];
        k--;
    }
}

void sort(int low, int high) 
{
    int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging(low, mid, high);
    } else { 
        return;
    }   
}

main()
{
    struct rumah_sakit data_sakit[3];
    int banyak_string, banyak_data;
    int a,b;

    data_sakit[0].pasien.id_pasien = 0;
    strcpy(data_sakit[0].pasien.nama_pasien, "Rehan");
    strcpy(data_sakit[0].kamar.jenis_kamar, "REG");
    

    strcpy(data_sakit[1].kamar.jenis_kamar, "VIP");

    banyak_data = sizeof(data_sakit) / sizeof(data_sakit[0]);
    banyak_string = sizeof(data_sakit[0].kamar.jenis_kamar) / sizeof(data_sakit[0].kamar.jenis_kamar);
    
    printf("%d \n", banyak_string);
    printf("%d \n", banyak_data);

    printf("Data asli : \n");
    for(a = 0; a < banyak_data; a++)
        printf("[%d] ", data[a]);

    sort(0, banyak_data);
    printf("\n\n");

    printf("Data setelah Merge sort :  \n");
    for(a = 0; a < banyak_data; a++)
        printf("[%d] ", data[a]);
}