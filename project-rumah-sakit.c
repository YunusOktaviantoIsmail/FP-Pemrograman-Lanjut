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
	
	printf("Masukan Nama Pasien 			: ");
	gets(input_nama);
	strcpy(data_pasien[data_sekarang].nama_pasien, input_nama);
	fflush(stdin); 
	
	printf("Masukan Jenis Penyakit Pasien 	: ");
	gets(input_jenis_penyakit);
	strcpy(data_pasien[data_sekarang].jenis_penyakit, input_jenis_penyakit);
	fflush(stdin);

	printf("Masukan Jenis Kamar 			: ");
	gets(input_jenis_kamar);
	strcpy(data_pasien[data_sekarang].kamar.jenis_kamar, input_jenis_kamar);
	fflush(stdin);

	printf("Masukan Nomor Kamar 			: ");
	scanf("%d", &data_pasien[data_sekarang].kamar.nomor_kamar);
	fflush(stdin);

	printf("Masukan Tanggal 				: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tanggal);
	fflush(stdin);

	printf("Masukan Nama Bulan 				: ");
	gets(input_bulan);
	strcpy(data_pasien[data_sekarang].tanggal_masuk.bulan, input_bulan);
	fflush(stdin);

	printf("Masukan Tahun 					: ");
	scanf("%d", &data_pasien[data_sekarang].tanggal_masuk.tahun);
	fflush(stdin);
}

//--------------------------------------- PENENTUAN ID ---------------------------------------//

int tentukan_id(){
	printf("Masukan ID Pasien 		: "); fflush(stdin);
	scanf("%d", &data_pasien[data_sekarang].id_pasien);
	fflush(stdin);
	
	if(data_pasien[data_sekarang].id_pasien == data_pasien[data_sekarang-1].id_pasien){
		printf("\n===== ID SUDAH DIGUNAKAN =====\n");
		system("pause");
		system("cls");
	} else {
		printf("\n");
		printf("ID Pasien 			: %d\n", data_pasien[data_sekarang].id_pasien);
		input(data_sekarang);
	}
}

//--------------------------------------- VIEW DATA ---------------------------------------//

void view(){
	fflush(stdin);
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

	printf("Masukan ID Pasien yang Diupdate : ");
	scanf("%d", &id_update);
	fflush(stdin);
			
	hasil = binary_id_update(data_pasien, 0, data_sekarang, id_update);
		
	if  (hasil == -1){
		printf("===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n========== DATA DITEMUKAN ==========\n");
		printf("ID Pasien 			: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Masukan Nama Pasien 		: ");
		scanf("%s", &data_pasien[hasil-1].nama_pasien);
		fflush(stdin); 

		printf("Masukan Jenis Penyakit Pasien 	: ");
		scanf("%s", &data_pasien[hasil-1].jenis_penyakit); 
		fflush(stdin);

		printf("Masukan Jenis Kamar 		: ");
		scanf("%s", &data_pasien[hasil-1].kamar.jenis_kamar);
		fflush(stdin);

		printf("Masukan Nomor Kamar 		: ");
		scanf("%d", &data_pasien[hasil-1].kamar.nomor_kamar);
		fflush(stdin);

		printf("Masukan Tanggal 		: ");
		scanf("%d", &data_pasien[hasil-1].tanggal_masuk.tanggal);
		fflush(stdin);

		printf("Masukan Nama Bulan 		: ");
		scanf("%s", &data_pasien[hasil-1].tanggal_masuk.bulan);
		fflush(stdin);

		printf("Masukan Tahun 			: ");
		scanf("%d", &data_pasien[hasil-1].tanggal_masuk.tahun);
		fflush(stdin);
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

	printf("Urutkan Data Berdasarkan : \n");
	printf("1. ID Pasien\n");
	printf("2. Nama Pasien\n");
	printf("3. Jenis Penyakit Pasien\n");
	printf("4. Jenis Kamar Pasien\n");
	printf("5. Nomor Kamar Pasien\n");
	printf("6. Tanggal Masuk Pasien \n");
	printf("Masukan Pilihan Anda : ");
	scanf("%d", &pilihan);
	fflush(stdin);

	if(pilihan == 1)
	{
		sort_id(0, data_sekarang-1);
	}
	else if(pilihan == 2)
	{
		sort_nama(0, data_sekarang-1);
	}
	else if(pilihan == 3)
	{
		sort_jenis_penyakit(0, data_sekarang-1);
	}
	else if(pilihan == 4)
	{
		sort_jenis_kamar(0, data_sekarang-1);
	}
	else if(pilihan == 5)
	{
		sort_no_kamar(0, data_sekarang-1);	
	}
	else if(pilihan == 6)
	{
		sort_tanggal_masuk(0, data_sekarang-1);
	}
	else
	{
		printf("\n");
		printf("Pilihan anda tidak valid! \n");
		printf("Silahkan pilih kembali \n");
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
	
	printf("Masukan ID Pasien yang Dicari : ");
	scanf("%d", &cari_pasien);
	fflush(stdin);
	
	sort_id(0, data_sekarang-1);	
	hasil = binary_id(data_pasien, 0, data_sekarang, cari_pasien);
		
	if  (hasil == -1){
		printf("\n===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 		: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NOMOR KAMAR ---------------------------------------//

void kamar(){
	int cari_kamar, hasil;
	
	printf("Masukan Nomor Kamar yang Dicari : ");
	scanf("%d", &cari_kamar);
	fflush(stdin);
	
	sort_no_kamar(0, data_sekarang-1);			
	hasil = binary_kamar(data_pasien, 0, data_sekarang, cari_kamar);
		
	if  (hasil == -1){
		printf("\n===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 		: %d\n", data_pasien[hasil-1].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil-1].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil-1].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil-1].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil-1].kamar.nomor_kamar);
		printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil-1].tanggal_masuk.tanggal, data_pasien[hasil-1].tanggal_masuk.bulan, data_pasien[hasil-1].tanggal_masuk.tahun);
    }
}

//--------------------------------------- TAMPILAN INPUTAN SEARCH NAMA PASIEN ---------------------------------------//

void nama(){
	char cari_nama[20];
	int hasil;
	
	printf("Masukan Nama yang Dicari : ");
	scanf("%s", &cari_nama);
	fflush(stdin);
	
	sort_nama(0, data_sekarang-1);
	hasil = binary_nama(data_pasien, cari_nama, data_sekarang);
	
    if  (hasil == -1){
		printf("\n===== DATA TIDAK DITEMUKAN =====\n\n");
    } else {
    	printf("\n===== DATA DITEMUKAN =====\n");
		printf("ID Pasien 	: %d\n", data_pasien[hasil].id_pasien);
		printf("Nama Pasien 	: %s\n", data_pasien[hasil].nama_pasien);
		printf("Jenis Penyakit 	: %s\n", data_pasien[hasil].jenis_penyakit);
		printf("Jenis Kamar 	: %s\n", data_pasien[hasil].kamar.jenis_kamar);
		printf("Nomor Kamar 	: %d\n", data_pasien[hasil].kamar.nomor_kamar);
    	printf("Tanggal Masuk 	: %d %s %d\n\n", data_pasien[hasil].tanggal_masuk.tanggal, data_pasien[hasil].tanggal_masuk.bulan, data_pasien[hasil].tanggal_masuk.tahun);
	}
}

//--------------------------------------- SUB MENU CARI DATA ---------------------------------------//

void sub_cari(){
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

//////////////////////////////////////////////////////////

void main() {
	//Inisialisasi variabel
	int pilih;
	int loop;

	for(loop = 1; loop > 0;)
	{
		system("cls");
		fflush(stdin);

		//printf("Data sekarang sebanyak : %d \n", data_sekarang);
		printf("===== SISTEM INFORMASI RUMAH SAKIT =====\n");
		printf("1. Daftarkan Pasien\n");
		printf("2. Lihat Data Pasien\n");
		printf("3. Update Data Pasien\n");
		printf("4. Urutkan Data\n");
		printf("5. Cari Data\n");
		printf("6. [Keluar Program] \n");
		printf("Masukan Pilihan Anda : ");
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
			break;
		}
	}
}
