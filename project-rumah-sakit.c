#include <stdio.h>
#include <stdlib.h>
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
	char jenis_penyakit[50];
	struct kamar kamar;
	struct masuk tanggal_masuk;
}; 
struct pasien data_pasien[50];
int data_sekarang = 0;

//--------------------------------------- INPUT DATA ---------------------------------------//

void input() {
	int input_nomor_kamar,input_tanggal, input_tahun;
	char input_nama[50];
	char input_jenis_penyakit[50];
	char input_jenis_kamar[10];
	char input_bulan[10];
	
	printf("\t\t\t\t\t Masukan Nama Pasien 		: ");
	gets(input_nama);
	strcpy(data_pasien[data_sekarang].nama_pasien, input_nama);
	fflush(stdin); 
	
	printf("\t\t\t\t\t Masukan Jenis Penyakit Pasien 	: ");
	gets(input_jenis_penyakit);
	strcpy(data_pasien[data_sekarang].jenis_penyakit, input_jenis_penyakit);
	fflush(stdin);

	printf("\t\t\t\t\t Masukan Jenis Kamar 		: ");
	gets(input_jenis_kamar);
	strcpy(data_pasien[data_sekarang].kamar.jenis_kamar, input_jenis_kamar);
	fflush(stdin);

	printf("\t\t\t\t\t Masukan Nomor Kamar 		: ");
	scanf("%d", &data_pasien[data_sekarang].kamar.nomor_kamar);
	fflush(stdin);

	printf("\t\t\t\t\t Masukan Tanggal 		: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tanggal);
	fflush(stdin);

	printf("\t\t\t\t\t Masukan Nama Bulan 		: ");
	gets(input_bulan);
	strcpy(data_pasien[data_sekarang].tanggal_masuk.bulan, input_bulan);
	fflush(stdin);

	printf("\t\t\t\t\t Masukan Tahun 			: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tahun);
	fflush(stdin);
	
	printf("\n\t\t\t\t\t ========== DATA BERHASIL DISIMPAN ==========\n\n");
}

//--------------------------------------- PENENTUAN ID ---------------------------------------//

int tentukan_id(){
	system("color 0B");
	printf("\t\t\t\t\t ========= [ MASUKAN DATA PASIEN ] =========\n\n");
	printf("\t\t\t\t\t Masukan ID Pasien 	: "); fflush(stdin);
	scanf("%d", &data_pasien[data_sekarang].id_pasien);
	fflush(stdin);
	
	if(data_pasien[data_sekarang].id_pasien == data_pasien[data_sekarang-1].id_pasien){
		printf("\n\t\t\t\t\t ===== ID SUDAH DIGUNAKAN =====\n\n");
		system("pause");
		system("cls");
	} else {
		printf("\n");
		printf("\t\t\t\t\t ID Pasien 			: %d\n", data_pasien[data_sekarang].id_pasien);
		input(data_sekarang);
	}
}

//--------------------------------------- VIEW DATA ---------------------------------------//

void view(){
	fflush(stdin);
	int i;
	for(i=0; i<data_sekarang; i++){
		system("color 0C");
		printf("\t\t\t\t\t ========== [HASIL RECORD] ==========\n");
		printf("\t\t\t\t\t ID Pasien 	: %d\n", data_pasien[i].id_pasien);
		printf("\t\t\t\t\t Nama Pasien 	: %s\n", data_pasien[i].nama_pasien);
		printf("\t\t\t\t\t Jenis Penyakit : %s\n", data_pasien[i].jenis_penyakit);
		printf("\t\t\t\t\t Jenis Kamar 	: %s\n", data_pasien[i].kamar.jenis_kamar);
		printf("\t\t\t\t\t Nomor Kamar 	: %d\n", data_pasien[i].kamar.nomor_kamar);
		printf("\t\t\t\t\t Tanggal Masuk 	: %d %s %d\n", data_pasien[i].tanggal_masuk.tanggal, data_pasien[i].tanggal_masuk.bulan, data_pasien[i].tanggal_masuk.tahun);
		printf("\t\t\t\t\t ------------------------------------\n\n");
	}
}

//--------------------------------------- BINARY UPDATE DATA ---------------------------------------//

int binary_id_update(struct pasien data_pasien[], int awal, int akhir, int id_update){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(data_pasien[tengah].id_pasien == id_update){
		return tengah+1;
	} else if(data_pasien[tengah].id_pasien < id_update){
		return binary_id_update(data_pasien, tengah+1, akhir, id_update);
	} else {
		return binary_id_update(data_pasien, awal, tengah-1, id_update);
	}
}

//--------------------------------------- UPDATE DATA ---------------------------------------//

void update(){
	int id_update, i, hasil;
	char input_nama[50];
	char input_jenis_penyakit[50];
	char input_jenis_kamar[10];
	char input_bulan[10];
	
	system("color 0D");
	printf("\t\t\t\t\t ========== [ UPDATE DATA ] ==========\n\n");
	printf("\t\t\t\t\t Masukan ID Pasien yang Diupdate : ");
	scanf("%d", &id_update);
	fflush(stdin);
			
	hasil = binary_id_update(data_pasien, 0, data_sekarang, id_update);
		
	if  (hasil == -1){
		printf("\t\t\t\t\t ===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n\t\t\t\t\t ========== UPDATE DATA ==========\n");
		printf("\t\t\t\t\t ID Pasien 			: %d\n", data_pasien[hasil-1].id_pasien);
		printf("\t\t\t\t\t Masukan Nama Pasien 		: ");
		scanf("%s", &data_pasien[hasil-1].nama_pasien);
		fflush(stdin); 

		printf("\t\t\t\t\t Masukan Jenis Penyakit Pasien 	: ");
		scanf("%s", &data_pasien[hasil-1].jenis_penyakit); 
		fflush(stdin);

		printf("\t\t\t\t\t Masukan Jenis Kamar 		: ");
		scanf("%s", &data_pasien[hasil-1].kamar.jenis_kamar);
		fflush(stdin);

		printf("\t\t\t\t\t Masukan Nomor Kamar 		: ");
		scanf("%d", &data_pasien[hasil-1].kamar.nomor_kamar);
		fflush(stdin);

		printf("\t\t\t\t\t Masukan Tanggal 		: ");
		scanf("%d", &data_pasien[hasil-1].tanggal_masuk.tanggal);
		fflush(stdin);

		printf("\t\t\t\t\t Masukan Nama Bulan 		: ");
		scanf("%s", &data_pasien[hasil-1].tanggal_masuk.bulan);
		fflush(stdin);

		printf("\t\t\t\t\t Masukan Tahun 			: ");
		scanf("%d", &data_pasien[hasil-1].tanggal_masuk.tahun);
		fflush(stdin);
		
		printf("\t\t\t\t\t ---------------------------------------");
		printf("\n\n\t\t\t\t\t ========= DATA SUDAH DIUPDATE =========\n\n");
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

//--------------------------------------- MERGE SORT NAMA PASIEN ---------------------------------------//

void merging_nama(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(strcmp(data_pasien[i].nama_pasien, data_pasien[j].nama_pasien) <= 0)
        {
            temp[k++] = data_pasien[i++];
        }
        else if(strcmp(data_pasien[i].nama_pasien, data_pasien[j].nama_pasien) >= 0)
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

void sort_nama(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_nama(low, mid);
        sort_nama(mid+1, high);

        merging_nama(low, mid, high);
    } else { 
        return;
    }
};

//--------------------------------------- MERGE SORT JENIS PENYAKIT PASIEN ---------------------------------------//

void merging_jenis_penyakit(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(strcmp(data_pasien[i].jenis_penyakit, data_pasien[j].jenis_penyakit) <= 0)
        {
            temp[k++] = data_pasien[i++];
        }
        else if(strcmp(data_pasien[i].jenis_penyakit, data_pasien[j].jenis_penyakit) >= 0)
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

void sort_jenis_penyakit(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_jenis_penyakit(low, mid);
        sort_jenis_penyakit(mid+1, high);

        merging_jenis_penyakit(low, mid, high);
    } else { 
        return;
    }
};

//--------------------------------------- MERGE SORT JENIS KAMAR PASIEN ---------------------------------------//

void merging_jenis_kamar(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(strcmp(data_pasien[i].kamar.jenis_kamar, data_pasien[j].kamar.jenis_kamar) <= 0)
        {
            temp[k++] = data_pasien[i++];
        }
        else if(strcmp(data_pasien[i].kamar.jenis_kamar, data_pasien[j].kamar.jenis_kamar) >= 0)
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

void sort_jenis_kamar(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_jenis_kamar(low, mid);
        sort_jenis_kamar(mid+1, high);

        merging_jenis_kamar(low, mid, high);
    } else { 
        return;
    }
};

//--------------------------------------- MERGE SORT NOMOR KAMAR PASIEN ---------------------------------------//

void merging_no_kamar(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(data_pasien[i].kamar.nomor_kamar < data_pasien[j].kamar.nomor_kamar)
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

void sort_no_kamar(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_no_kamar(low, mid);
        sort_no_kamar(mid+1, high);

        merging_no_kamar(low, mid, high);
    } else { 
        return;
    }
};

//--------------------------------------- MERGE SORT TANGGAL MASUK PASIEN ---------------------------------------//

void merging_tanggal_masuk(int low, int mid, int high)
{
    int i = low;
    int j = mid + 1;
    int k = low;

	struct pasien temp[high+1];
	
    while(i<=mid && j<= high)
    {
        if(data_pasien[i].tanggal_masuk.tanggal < data_pasien[j].tanggal_masuk.tanggal)
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

void sort_tanggal_masuk(int low, int high)
{
	int mid;
    
    if(low < high) {
        mid = (low + high) / 2;
        sort_tanggal_masuk(low, mid);
        sort_tanggal_masuk(mid+1, high);

        merging_tanggal_masuk(low, mid, high);
    } else { 
        return;
    }
};


//--------------------------------------- SUB MENU SORT DATA ---------------------------------------//

void sub_sort(){
	int pilihan;
	
	system("color 0A");
	printf("\t\t\t\t\t ========== [ URUTKAN DATA PASIEN BERDASARKAN ] =========\n\n");
	printf("\t\t\t\t\t |                                                      |\n");
	printf("\t\t\t\t\t |                1. ID Pasien                          |\n");
	printf("\t\t\t\t\t |                2. Nama Pasien                        |\n");
	printf("\t\t\t\t\t |                3. Jenis Penyakit Pasien              |\n");
	printf("\t\t\t\t\t |                4. Jenis Kamar Pasien                 |\n");
	printf("\t\t\t\t\t |                5. Nomor Kamar Pasien                 |\n");
	printf("\t\t\t\t\t |                6. Tanggal Masuk Pasien               |\n");
	printf("\t\t\t\t\t |                                                      |\n");
	printf("\t\t\t\t\t ========================================================\n\n");
	printf("\t\t\t\t\t Masukan Pilihan Anda : ");
	scanf("%d", &pilihan);
	fflush(stdin);

	if(pilihan == 1)
	{
		sort_id(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else if(pilihan == 2)
	{
		sort_nama(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else if(pilihan == 3)
	{
		sort_jenis_penyakit(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else if(pilihan == 4)
	{
		sort_jenis_kamar(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else if(pilihan == 5)
	{
		sort_no_kamar(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else if(pilihan == 6)
	{
		sort_tanggal_masuk(0, data_sekarang-1);
		printf("\n\t\t\t\t\t ========= DATA SUDAH DIURUTKAN =========\n\n");
	}
	else
	{
		printf("\n");
		printf("\t\t\t\t\t Pilihan anda tidak valid! \n");
		printf("\t\t\t\t\t Silahkan Ulangi\n\n");
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

//--------------------------------------- BINARY NAMA ---------------------------------------//

char binary_nama2(struct pasien data_pasien[], int awal, int akhir, char cari_nama[]){
	int tengah = (awal + akhir) / 2;
	
	if(awal>akhir){
		return -1;
	} else if(strcmp(data_pasien[tengah].nama_pasien,cari_nama) == 0){
		return tengah+1;
	} else if(strcmp(data_pasien[tengah].nama_pasien,cari_nama) < 0){
		return binary_nama2(data_pasien, tengah+1, akhir, cari_nama);
	} else {
		return binary_nama2(data_pasien, awal, tengah-1, cari_nama);
	}
}

//--------------------------------------- BINARY SEARCH NAMA ---------------------------------------//

int binary_nama(struct pasien data_pasien[], char cari[], int n) {
    int t, hasil;
    int k = n - 1;
    int l = 0;
  
    while ( l <= k ) {
        t = (l + k) / 2;
        hasil = strcmp(data_pasien[t].nama_pasien, cari);

        if (hasil == -1)
            l = t + 1;
        else if (hasil == 1)
            k = t - 1;
        else
            return t;
    }       
    return -1;  
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH ID ---------------------------------------//

void id(){
	int cari_pasien, hasil;
	
	system("color 0B");
	printf("\t\t\t\t\t ========== [ MENU CARI DATA PASIEN ] ==========\n\n");
	printf("\t\t\t\t\t Masukan ID Pasien yang Dicari : ");
	scanf("%d", &cari_pasien);
	fflush(stdin);
	
	sort_id(0, data_sekarang-1);	
	hasil = binary_id(data_pasien, 0, data_sekarang, cari_pasien);
		
	if  (hasil == -1){
		printf("\n\t\t\t\t\t ===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n\t\t\t\t\t ===== DATA DITEMUKAN =====\n");
		printf("\t\t\t\t\t ID Pasien 	: %d\n", data_pasien[hasil-1].id_pasien);
		printf("\t\t\t\t\t Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("\t\t\t\t\t Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("\t\t\t\t\t Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("\t\t\t\t\t Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("\t\t\t\t\t Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NOMOR KAMAR ---------------------------------------//

void kamar(){
	int cari_kamar, hasil;
	
	system("color 0B");
	printf("\t\t\t\t\t ========== [ MENU CARI DATA PASIEN ] ==========\n\n");
	printf("\t\t\t\t\t Masukan Nomor Kamar yang Dicari : ");
	scanf("%d", &cari_kamar);
	fflush(stdin);
	
	sort_no_kamar(0, data_sekarang-1);			
	hasil = binary_kamar(data_pasien, 0, data_sekarang, cari_kamar);
		
	if  (hasil == -1){
		printf("\n\t\t\t\t\t ===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n\t\t\t\t\t ===== DATA DITEMUKAN =====\n");
		printf("\t\t\t\t\t ID Pasien 	: %d\n", data_pasien[hasil-1].id_pasien);
		printf("\t\t\t\t\t Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("\t\t\t\t\t Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("\t\t\t\t\t Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("\t\t\t\t\t Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("\t\t\t\t\t Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NAMA PASIEN ---------------------------------------//

void nama(){
	char cari_nama[20];
	int hasil;
	
	system("color 0B");
	printf("\t\t\t\t\t ========== [ MENU CARI DATA PASIEN ] ==========\n\n");
	printf("\t\t\t\t\t Masukan Nama yang Dicari : ");
	scanf("%s", &cari_nama);
	fflush(stdin);
	
	sort_nama(0, data_sekarang-1);
	//hasil = binary_nama(data_pasien, cari_nama, data_sekarang);
	hasil = binary_nama2(data_pasien, 0, data_sekarang, cari_nama);
	
    if  (hasil == -1){
		printf("\n\t\t\t\t\t ===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n\t\t\t\t\t ===== DATA DITEMUKAN =====\n");
		printf("\t\t\t\t\t ID Pasien 	: %d\n", data_pasien[hasil-1].id_pasien);
		printf("\t\t\t\t\t Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("\t\t\t\t\t Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("\t\t\t\t\t Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("\t\t\t\t\t Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
    	printf("\t\t\t\t\t Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
	}
}

//--------------------------------------- SUB MENU CARI DATA ---------------------------------------//

void sub_cari(){
	int cari;
	
	system("color 0A");
	printf("\t\t\t\t\t ========== [ CARI DATA PASIEN BERDASASARKAN ] ==========\n");
	printf("\t\t\t\t\t |                                                      |\n");
	printf("\t\t\t\t\t |                   1. ID Pasien                       |\n");
	printf("\t\t\t\t\t |                   2. Nama Pasien                     |\n");
	printf("\t\t\t\t\t |                   3. Nomor Kamar                     |\n");
	printf("\t\t\t\t\t |                                                      |\n");
	printf("\t\t\t\t\t ========================================================\n\n");
	printf("\t\t\t\t\t Masukan Pilihan Anda : ");
	scanf("%d", &cari);
	fflush(stdin);
	
	if(cari == 1){
		system("cls");
		id(data_sekarang);
	} else if(cari == 2){
		system("cls");
		nama(data_sekarang);	
	} else if(cari == 3){
		system("cls");
		kamar(data_sekarang);
	} else {
		printf("\n\t\t\t\t\t Pilihan anda tidak valid \n");
		printf("\t\t\t\t\t Silahkan Ulangi \n\n");
	}
}

//--------------------------------------- MAIN ---------------------------------------//

void main() {
	//Inisialisasi variabel
	int pilih;
	int loop;

	for(loop = 1; loop > 0;)
	{
		system("cls");
		fflush(stdin);
		
		system("color 0A");
		printf("\t\t\t\t\t ------ SISTEM INFORMASI RUMAH SAKIT ------\n");
		printf("\t\t\t\t\t |                                        |\n");
		printf("\t\t\t\t\t |         1. Daftarkan Pasien            |\n");
		printf("\t\t\t\t\t |         2. Lihat Data Pasien           |\n");
		printf("\t\t\t\t\t |         3. Update Data Pasien          |\n");
		printf("\t\t\t\t\t |         4. Urutkan Data                |\n");
		printf("\t\t\t\t\t |         5. Cari Data                   |\n");
		printf("\t\t\t\t\t |         6. [Keluar Program]            |\n");
		printf("\t\t\t\t\t |                                        |\n");
		printf("\t\t\t\t\t ------------------------------------------\n\n");
		printf("\t\t\t\t\t Masukan Pilihan Anda : ");
		scanf("%d", &pilih);
		fflush(stdin);

		if(pilih == 1)
		{
			system("cls");
			tentukan_id(data_sekarang);
			data_sekarang = data_sekarang + 1;
			system("pause");
		}
		else if(pilih == 2)
		{
			system("cls");
			view();
			system("pause");
		}
		else if(pilih == 3)
		{
			system("cls");
			update();
			system("pause");
		}
		else if(pilih == 4)
		{
			system("cls");
			sub_sort();
			system("pause");
		}
		else if(pilih == 5)
		{
			system("cls");
			sub_cari();
			system("pause");
		}
		else if(pilih == 6)
		{
			printf("\n\t\t\t\t\t TERIMA KASIH TELAH MENGGUNAKAN PROGRAM KAMI\n\n");
			break;
		}
	}
}
