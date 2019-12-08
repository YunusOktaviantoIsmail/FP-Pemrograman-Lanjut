#include <stdio.h>
#include <string.h>

int data[] = {4,7,1,2,9,5,11,21,15,10,3,42,12,53,20,18,60,1};

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

//Data seluruh struct menjadi satu kesatuan
struct rumah_sakit
{
    struct kamar kamar;
    struct masuk masuk;
    struct pasien pasien;
};
typedef rumah_sakit;

// merging_char(int low, int mid, int high) 
// {  
//     int temp[high + 1];
//     int i = low;
//     int j = mid + 1;
//     int k = 0;

//     while (i <= mid && j <= high)
//     {
//         if (data[i] <= data[j])
//             temp[k++] = data[i++];
//         else
//             temp[k++] = data[j++];
//     }
//     while (i <= mid)
//         temp[k++] = data[i++];
//     while (j <= high)
//         temp[k++] = data[j++];
//     k--;
//     while (k >= 0)
//     {
//         data[k + low] = temp[k];
//         k--;
//     }
// }

sort_char(rumah_sakit data, int low, int high) 
{
    int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort(low, mid);
        sort(mid+1, high);
        merging_char(low, mid, high);
    } else { 
        return;
    }   
}

main()
{
    struct rumah_sakit data[5];
    int banyak_string, banyak_data;
    int a,b;

    strcpy(data[0].kamar.jenis_kamar, "REG");
    strcpy(data[1].kamar.jenis_kamar, "VIP");

    banyak_data = sizeof(data) / sizeof(data[0]);
    banyak_string = sizeof(data[0].kamar.jenis_kamar) / sizeof(data[0].kamar.jenis_kamar[0]);
    
    printf("%d \n", banyak_string);
    printf("%d \n", banyak_data);

    printf("Data asli : \n");
    for(a = 0; a < banyak_data; a++)
    {
        printf("[%s] ", data[a].kamar.jenis_kamar);
    }

    sort(0);
    // sort(0, banyak_data);
    // printf("\n\n");

    // printf("Data setelah Merge sort :  \n");
    // for(a = 0; a < banyak_data; a++)
    // printf("[%d] ", data[a]);
}