#include <stdio.h>
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
	int bulan;
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
///////////////////////////////////////////////////////////////////

void merging_id(struct rumah_sakit data_sakit[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

    int temp[high+1];
    char temp2[high+1][50];
	struct rumah_sakit temp3[high+1];
	
    while(i<=mid && j<= high)
    {
        if(data_sakit[i].pasien.id_pasien < data_sakit[j].pasien.id_pasien)
        {
        	temp3[k++] = data_sakit[i++];
        }
        else
        {
        	temp3[k++] = data_sakit[j++];
        }
    }

    while(i<= mid)
    {
    		temp3[k++] = data_sakit[i++];
    }

    while(j<= high)
    {
            temp3[k++] = data_sakit[j++];
    }

    for(i = low; i <= high; i++)
    {
    	data_sakit[i] = temp3[i];
    }
}

void merging_nama(struct rumah_sakit data_sakit[], int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct rumah_sakit temp3[high+1];
	
    while(i<=mid && j<= high)
    {
        if(strcmp(data_sakit[i].pasien.nama_pasien, data_sakit[j].pasien.nama_pasien) <= 0)
        {
            temp3[k++] = data_sakit[i++];
        }
        else if(strcmp(data_sakit[i].pasien.nama_pasien, data_sakit[j].pasien.nama_pasien) >= 0)
        {
        	temp3[k++] = data_sakit[j++];
        }
    }

    while(i<= mid)
    {
    		temp3[k++] = data_sakit[i++];
    }

    while(j<= high)
    {
            temp3[k++] = data_sakit[j++];
    }

    for(i = low; i <= high; i++)
    {
    	data_sakit[i] = temp3[i];
    }
}

void sort_id(struct rumah_sakit data_sakit[], int low, int high) 
{
    int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_id(data_sakit, low, mid);
        sort_id(data_sakit, mid+1, high);

        merging_id(data_sakit, low, mid, high);
    } else { 
        return;
    }   
}

void sort_nama(struct rumah_sakit data_sakit[], int low, int high) 
{
    int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_nama(data_sakit, low, mid);
        sort_nama(data_sakit, mid+1, high);

        merging_nama(data_sakit, low, mid, high);
    } else { 
        return;
    }   
}
/////////////////////////////////////////////////////////////////

void main()
{
    struct rumah_sakit data_sakit[3];
    int banyak_string, banyak_data;
    int a,b;

    data_sakit[0].pasien.id_pasien = 3;
    strcpy(data_sakit[0].pasien.nama_pasien, "Yunus");
    data_sakit[0].pasien.jenis_penyakit = 1;
    data_sakit[0].kamar.jenis_kamar = 1;
    data_sakit[0].kamar.nomor_kamar = 21;
    data_sakit[0].masuk.tanggal = 8;
    data_sakit[0].masuk.bulan = 8;
    data_sakit[0].masuk.tahun = 1999;

    data_sakit[1].pasien.id_pasien = 1;
    strcpy(data_sakit[1].pasien.nama_pasien, "Rehan");
    data_sakit[1].pasien.jenis_penyakit = 2;
    data_sakit[1].kamar.jenis_kamar = 2;
    data_sakit[1].kamar.nomor_kamar = 22;
    data_sakit[1].masuk.tanggal = 9;
    data_sakit[1].masuk.bulan = 9;
    data_sakit[1].masuk.tahun = 1999;

    data_sakit[2].pasien.id_pasien = 3;
    strcpy(data_sakit[2].pasien.nama_pasien, "Yunus");
    data_sakit[2].pasien.jenis_penyakit = 3;
    data_sakit[2].kamar.jenis_kamar = 3;
    data_sakit[2].kamar.nomor_kamar = 23;
    data_sakit[2].masuk.tanggal = 10;
    data_sakit[2].masuk.bulan = 10;
    data_sakit[2].masuk.tahun = 1999;

    banyak_data = sizeof(data_sakit) / sizeof(data_sakit[0]);
    
    printf("Data asli : \n");
    for(a = 0; a < banyak_data; a++)
    {
        printf("[%d] ", data_sakit[a].pasien.id_pasien);
    }
    
    sort_id(data_sakit,0,banyak_data-1);
    printf("\n\n");

    printf("Data setelah Merge sort ID :  \n");
    for(a = 0; a < banyak_data; a++)
    {
        printf("[%d]\n", data_sakit[a].pasien.id_pasien);
        printf("[%s]\n", data_sakit[a].pasien.nama_pasien);
        printf("\n");
    }
    printf("\n");

    sort_nama(data_sakit, 0, banyak_data-1);
    printf("Data setelah Merge sort Nama :  \n");
    for(a = 0; a < banyak_data; a++)
    {
        printf("[%d]\n", data_sakit[a].pasien.id_pasien);
        printf("[%s]\n", data_sakit[a].pasien.nama_pasien);
        printf("\n");
    }
}
