# FP-Pemrograman-Lanjut

# Pendahuluan
## Kata Pengantar
Puji syukur kami panjatkan atas kehadirat Tuhan Yang Maha Esa, yang telah memberikan segala kenikmatan jasmani dan rohani, sehingga kami dapat menyelesaikan program *final project* beserta laporan resmi ini dengan lancar dan sukses dalam pengerjaannya. Tidak lupa juga, kami haturkan banyak terima kasih kepada seluruh pihak-pihak yang telah membantu kami selama proses pengerjaan program ini yaitu program “Aplikasi Pendataan Rumah Sakit”. 

Dengan minimnya pengetahuan yang kami miliki dalam proses pembuatan laporan ini, kami ucapkan mohon maaf apabila terdapat kesalahan penulisan atau ejaan, maka dari itu kami mohon arahan dan saran kepada para pembaca agar kedepannya laporan telah kami buat dapat lebih baik lagi dan semoga laporan ini dapat bermanfaat bagi para pembacanya. Akhir kata kami ucapkan terima kasih.

## Latar Belakang
Permasalahan yang dapat diselesaikan dalam program ini diantaranya yaitu:

- Bagaimana membuat program yang mudah pengoperasiannya?.
- Bagaimana membuat program dengan kode sumber yang efisien?.

## Tujuan
Tujuan dari pembuatan program ini adalah: 

- Dapat membuat program yang mudah dalam pengoperasiannya.
- Dapat menerapkan kode sumber yang efisien.

## Manfaat
Manfaat dari pembuatan program ini adalah:

- Program dapat digunakan sesuai kebutuhan pengguna berdasarkan fitur yang telah tersedia.
- Dalam pembuatan program ini, mahasiswa dapat mengasah dan memperdalam teori-teori yang telah disampaikan sebelumnya serta dapat mengimplementasikannya dalam bentuk program.

## Deskripsi Program
Program Proyek Akhir yang dibuat adalah suatu aplikasi dengan judul **“Aplikasi Pendataan Rumah Sakit”** dimana aplikasi tersebut dapat mengolah data-data atau informasi-informasi dengan kriteria sebagai berikut:
1. ID Pasien
2. Nama Pasien
3. Jenis Penyakit
4. Jenis Kamar
5. Nomor Kamar
6. Tanggal Masuk

Dari kriteria tersebut maka diharapkan program yang telah kami buat dapat melakukan operasi-operasi sebagai berikut:
1. Tambah Data
2. Menampilkan Data
3. Ubah Data
4. Pencarian Data (Nama pasien, ID pasien, Nomor kamar)
5. Pengurutan Data (Semua kriteria)

# Pembahasan
## Bahasa Pemrograman C
Bahasa Pemrograman C adalah salah satu bahasa pemrograman komputer yang dibuat pada tahun 1972 oleh Dennis Ritchie untuk Sistem Operasi Unix di Bell Telephone Laboratories. Meskipun Bahasa C dibuat untuk memprogram sistem dan jaringan komputer namun Bahasa ini juga sering digunakan dalam pengembangan software aplikasi. Bahasa C juga banyak dipakai oleh berbagai jenis platform sistem operasi dan arsitektur komputer,bahkan terdapat beberapa compiler yang sangat popular telah tersedia.

## Binary Search
Binary Search adalah teknik pencarian data dengan cara membagi data menjadi dua bagian setiap kali terjadi proses pencarian. Sebelum menggunakan konsep binary search, data yang telah disediakan diharuskan untuk diurutkan terlebih dahulu sebelum dilakukan pencarian suatu data tertentu. Prinsip binary search yaitu sebagai berikut:
1. Data diambil dari posisi 1 hingga posisi N.
2. Kemudian cari posisi data tengah dengan rumus posisi_data_tengah = (posisi_data_awal + posisi_data_akhir) / 2.
3. Kemudian data yang dicari dibandingan dengan data yang tengah, apakah lebih kecil atau lebih besar?.
4. Jika lebih besar, maka proses pencarian dicari dengan posisi awal adalah posisi tengah + 1.
5. Jika lebih kecil, maka proses pencarian dicari dengan posisi akhir adalah posisi tengah – 1.
6. Jika data sama, maka data sudah ketemu. 

## Merge Sort
Merge Sort adalah metode sorting dengan konsep rekursif dan teknik desain divide-and-conquer. Teknik divide-and-conquer adalah teknik untuk memecah kemudian menyelesaikan setiap bagian lalu menggabungkannya kembali. 
1. Pertama data dipecah menjadi 2 bagian dimana bagian pertama merupakan setengah (jika data genap) atau setengah minus satu (jika data ganjil) dari seluruh data.
2. Kemudian dilakukan pemecahan kembali untuk masing-masing blok sampai hanya terdiri dari satu data tiap blok. 
3. Setelah itu, data digabungkan kembali dengan membandingkan pada blok yang sama apakah data pertama lebih besar daripada data ke-tengah+1?.
4. Jika ya maka data ke-tengah+1 dipindah sebagai data pertama, kemudian data ke-pertama sampai data ke-tengah digeser menjadi data ke-dua sampai ke-tengah+1.
Demikian seterusnya sampai menjadi satu blok utuh seperti awalnya.

# Penutup
Dari penjelasan diatas, maka dapat kami simpulkan bahwa final project yang kami kerjakan yaitu menggunakan bahasa pemrograman C yang dapat membuat sebuah data, menambahkan data, menampilkan data, mengubah data, mengurutkan data, dan mencari sebuah data. Konsep pengurutan atau sorting yang kami gunakan dalam pembuatan program ini yaitu merge sort, sedangkan untuk konsep pencarian atau searching, kami penggunakan binary search. Disamping itu, program yang kami buat adalah program yang mengutamakan kemudahan pengoperasian oleh user dan menerapkan konsep error handling. Hal tersebut bertujuan untuk memudahkan pengguna dalam menjalankan program yang telah kami buat ini. Sekian laporan yang telah kami sampaikan terkait final project mata kuliah Pemrograman Lanjut dengan judul “Aplikasi Pendataan Rumah Sakit”, apabila ada kesalahan kata atau ejaan mohon arahan dan saran dari para pembaca. Terima kasih.

# Daftar Pustaka
Wirdasari, (Vol.8:2010) “Pengertian Bahasa Pemrograman C”, http://eprints.polsri.ac.id/

Addison-Wesley, (1997), “Pengertian Binary Search”, https://id.wikipedia.org/

John von Neumann (1945), “Pengertian Merge Sort dan implementasinya”, http://ilmuduniainformatika.blogspot.com/