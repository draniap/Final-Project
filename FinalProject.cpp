/* 
FINAL PROJECT MATA KULIAH C++
APLIKASI ENKRIPSI DAN DEKRIPSI SEBUAH PESAN MENGGUNAKAN MATRIKS TRANSPOSISI 6x6
NAMA KELOMPOK : DWI RANI APRIYANI
NIM : 17.83.0064
TOOLS YANG SAYA GUNAKAN ADALAH DEV C++ VERSION 5.11
*/

#include<iostream> //memanggil library iostream sebagai standar input output operasi
#include<conio.h> //memanggil library conio untuk menampilkan hasil antarmuka
#include<string.h> //memanggil library string untuk memanipulasi string

// Deklarasi variabel yang digunakan input pesan
char plainInput[10000]; // Karakter untuk input pesan
char cipherText[20000]; // Karakter pesan
char matriksTransposisi[500][500]; //karakter matriks
char kataKunci[500]; // Untuk menyimpan karakter kunci proses enkripsi dan dekripsi
char kunciLainnya[500]; // Penyimpanan sementara kunci dekripsi
char ma[6][6]; // Untuk tabel huruf dan angka
char barisKolom[6] = {'D', 'E', 'K', 'R', 'A', 'N'}; //Karakter baris dan kolom

// Deklarasi variabel yang digunakan
int panjangKalimat;
int panjangKunci;
int tinggiMatriksTransposisi;
int panjangMatriksTransposisi;

// Deklarasi variabel tambahan
char pilihan;
int posisiKarakter = 0;
int posisiCipher = 0;
int baris;
int kolom;

// Konstruktor?
void enkripsi(); //prosedur enkripsi
void dekripsi(); //prosedur dekripsi

int main(){ //fungsi default
    mainMenu:
        system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
        std::cout << "My Final Project" << std::endl; //Tambilan pesan project
        std::cout << "DEKRAN Encrypt-Decrypt Project" << std::endl; //Tampilan judul project
        std::cout << "====================***====================" << std::endl;
        std::cout << std::endl;
        std::cout << "Pilihan Menu" << std::endl; //Tampilan menu
        std::cout << " 1. Enkripsi" << std::endl; //pihian menu untuk enkripsi
        std::cout << " 2. Dekripsi" << std::endl; //pilihan menu untuk dekripsi
        std::cout << " 3. Keluar"   << std::endl; //pilihan menu untuk dari program
        std::cout << "\nPilihan: "  ;
        std::cin >> pilihan;
        switch(pilihan){ //membuat percabangan pilihan
            case '1': //mengevalusi kondisi (pilihan)
                enkripsi(); //memanggil fungsi enkripsi
                goto mainMenu;
                break; //untuk keluar dari struktur case 1
            case '2': //mengevalusi kondisi (pilihan)
                dekripsi(); 
                goto mainMenu; //memanggil fungsi dekripsi
                break; //untuk keluar dari struktur case 2
            case '3': //mengevalusi kondisi (pilihan)
                goto keluar;
                break; //untuk keluar dari struktur case 1
            default:
                // Jika terjadi kesalahan pada proses pemilihan menu
                std::cout << "ERROR!" << std::endl; //menampilkan pesan ERROR
                std::cout << "Menu yang dipilih tidak tersedia. Silakan coba lagi. . ." << std::endl; //menampilkan pesan menu tidak tersedia
                getch(); //untuk menghentikan proses yang berjalan
                goto mainMenu;
        }

    keluar:
    return(0); //mengembalikan nilai 0
}
// Funsi yang akan digunakan untuk melakukan proses enkripsi
void enkripsi(){ //isi dari enkripsi yang akan dijalankan
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    
    // Table array 6x6 yang akan digunakan pada proses enkripsi
    //dalam penyusunan matriks ini menggunakan transposisi secara acak
    ma[0][0] = 'a'; ma[0][1] = 'b'; ma[0][2] = 'c'; ma[0][3] = 'd'; ma[0][4] = 'e'; ma[0][5] = 'f'; 
	ma[1][0] = 's'; ma[1][1] = 't'; ma[1][2] = 'u'; ma[1][3] = 'v'; ma[1][4] = 'w'; ma[1][5] = 'x';
	ma[2][0] = 'g'; ma[2][1] = 'h'; ma[2][2] = 'i'; ma[2][3] = 'j'; ma[2][4] = 'k'; ma[2][5] = 'l';
	ma[3][0] = 'y'; ma[3][1] = 'z'; ma[3][2] = '1'; ma[3][3] = '2'; ma[3][4] = '3'; ma[3][5] = '4';
	ma[4][0] = 'm'; ma[4][1] = 'n'; ma[4][2] = 'o'; ma[4][3] = 'p'; ma[4][4] = 'q'; ma[4][5] = 'r';
	ma[5][0] = '5'; ma[5][1] = '6'; ma[5][2] = '7'; ma[5][3] = '8'; ma[5][4] = '9'; ma[5][5] = ' ';		
    
    
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan pesan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kalimat yang akan dienkripsi:" << std::endl; //Tampilan pesan
    fflush(stdin); // Bersihkan sisa masukan
    gets(plainInput);
    
    // Cari panjang kalimat
    panjangKalimat = strlen(plainInput);
    
    // Atur ulang penghitung
    posisiKarakter = 0;
    // Cari posisi baris dan kolom setiap karakter pada tabel tersedia
    for(int k = 0; k < panjangKalimat; k++){
        for (int i = 0; i < 6; i++){
            for (int j = 0; j < 6; j++){
                // Memeriksa dimanakah baris dan kolom karakter berada...
                if (plainInput[posisiKarakter] == ma[i][j]){
                    cipherText[posisiCipher] = barisKolom[i];
                    posisiCipher++;
                    cipherText[posisiCipher] = barisKolom[j];
                    posisiCipher++;
                    posisiKarakter++;
                }
            }
        }
    }
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    
    std::cout << cipherText << std::endl;

    std::cout << "Masukkan kata kunci untuk mengamankan kalimat\n" << std::endl;
    std::cout << "Kunci yang dimasukkan disarankan untuk tidak memiliki karakter yang sama seperti \"kalimat\"\nkarena dapat terjadi kesalahan pada saat melakukan proses dekripsi." << std::endl;
    std::cout << "\nKunci = "; //Tampilan pesan untuk input kunci
    std::cin >> kataKunci;
    
    // Cari panjang kata kunci
    panjangKunci = strlen(kataKunci);
    tinggiMatriksTransposisi = (panjangKalimat * 2) / panjangKunci;
    panjangMatriksTransposisi = panjangKunci;
    
    // Transposisi kalimat secara horizontal dengan panjang mengikuti panjang kata kunci
    posisiKarakter = 0; // Atur ulang penghitung karakter
    posisiCipher = 0; // Atur ulang penghitung cipher
    for(int i = 0; i <= ((panjangKalimat * 2) / panjangKunci); i++){
        for(int j = 0; j < panjangKunci; j++){
            matriksTransposisi[i][j] = cipherText[posisiKarakter];
            posisiKarakter++;
        }
    }
    
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kataKunci << std::endl;
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "Pesan akan memasuki tahap enkripsi . ." << std::endl;
    getch(); //untuk menghentikan proses yang berjalan
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    
    // Urutkan kata kunci dan ikuti perubahan posisi kolom matriks transposisi
    for(int i = 0; i < panjangKunci; i++){
        for(int j = 0; j < panjangKunci; j++){
            if(kataKunci[j] > kataKunci[i]){
                char temp = kataKunci[j];
                kataKunci[j] = kataKunci[i];
                kataKunci[i] = temp;
                
                // Pindahkan kolom matriks transposisi mengikuti perpindahan karakter kunci
                for(int k = 0; k < tinggiMatriksTransposisi; k++){
                    temp = matriksTransposisi[k][j];
                    matriksTransposisi[k][j] = matriksTransposisi[k][i];
                    matriksTransposisi[k][i] = temp;
                }
            }
        }
    }
    std::cout << kataKunci << std::endl;
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    std::cout << "Enkripsi telah memasuki tahap terakhir. . ." << std::endl;
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl; //Tampilan judul project
    std::cout << "DEKRAN Encrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    std::cout << "Proses enkripsi telah selesai. . ." << std::endl;
    std::cout << std::endl;
    
    // Tahap keempat
    // Tampilkan karakter hasil enkripsi secara menurun
    for(int i = 0; i < panjangMatriksTransposisi; i++){
        for(int j = 0; j < tinggiMatriksTransposisi; j++){
            std::cout << matriksTransposisi[j][i];
        }
    }
    
    std::cout << std::endl;
    std::cout << "\nKunci jangan sampai hilang sayang!" << std::endl;
    std::cout << "Enter untuk kembali ke menu utama. . .";
    getch(); //untuk menghentikan proses yang berjalan
}


// Fungsi yang digunakan untuk melakukan proses dekripsi
void dekripsi(){
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    
    // Table array 6x6 yang digunakan pada proses dekripsi
    //dalam penyusunan matriks ini menggunakan transposisi secara acak sama dengan susunan matriks dalam proses enkripsi
    ma[0][0] = 'a'; ma[0][1] = 'b'; ma[0][2] = 'c'; ma[0][3] = 'd'; ma[0][4] = 'e'; ma[0][5] = 'f';
	ma[1][0] = 's'; ma[1][1] = 't'; ma[1][2] = 'u'; ma[1][3] = 'v'; ma[1][4] = 'w'; ma[1][5] = 'x';
	ma[2][0] = 'g'; ma[2][1] = 'h'; ma[2][2] = 'i'; ma[2][3] = 'j'; ma[2][4] = 'k'; ma[2][5] = 'l';
	ma[3][0] = 'y'; ma[3][1] = 'z'; ma[3][2] = '1'; ma[3][3] = '2'; ma[3][4] = '3'; ma[3][5] = '4';
	ma[4][0] = 'm'; ma[4][1] = 'n'; ma[4][2] = 'o'; ma[4][3] = 'p'; ma[4][4] = 'q'; ma[4][5] = 'r';
	ma[5][0] = '5'; ma[5][1] = '6'; ma[5][2] = '7'; ma[5][3] = '8'; ma[5][4] = '9'; ma[5][5] = ' ';
    
    // Tanya masukan
    std::cout << "My Final Project" << std::endl; //Tampilan judul project
    std::cout << "DEKRAN Decrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kalimat yang akan didekripsi:" << std::endl;
    fflush(stdin); // Bersihkan sisa masukan
    gets(cipherText);
    
    // Cari panjang kode cipher
    panjangKalimat = strlen(cipherText);
    
    // Tanya kata kunci
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl; //Tampilan judul project
    std::cout << "DEKRAN Decrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kunci = "; //Tampilan pesan untuk input kunci
    std::cin >> kataKunci;
    
    // Cari panjang kata kunci
    panjangKunci = strlen(kataKunci);
    
    // Salin kunci
    for(int i = 0; i < panjangKunci; i++){
        kunciLainnya[i] = kataKunci[i];
    }
    
    // Urutkan kunci
    for(int i = 0; i < panjangKunci; i++){
        for(int j = 0; j < panjangKunci; j++){
            if(kunciLainnya[j] > kunciLainnya[i]){
                char temp = kunciLainnya[j];
                kunciLainnya[j] = kunciLainnya[i];
                kunciLainnya[i] = temp;
            }
        }
    }
    
    // Cari tinggi dan panjang matriks transposisi
    tinggiMatriksTransposisi = panjangKalimat / panjangKunci;
    panjangMatriksTransposisi = panjangKunci;
    
    // Atur ulang penghitung
    posisiCipher = 0;
    
    // Tahap pertama
    // Susun kode cipher kedalam bentuk matriks transposisi vertikal berdasarkan kunci yang diberikan
    for(int i = 0; i < panjangMatriksTransposisi; i++){
        for(int j = 0; j < tinggiMatriksTransposisi; j++){
            matriksTransposisi[j][i] = cipherText[posisiCipher];
            posisiCipher++;
        }
    }
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Decrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kunciLainnya << std::endl;
    // Tampilkan hasil transposisi
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "Dekripsi akan memasuki tahap kedua . . .";
    getch(); //untuk menghentikan proses yang berjalan
    
    
    // Tahap kedua
    // Susun setiap kolom mengikuti kata kunci
    for(int i = 0; i < panjangKunci; i++){
        for(int j = 0; j < panjangKunci; j++){
            if(kunciLainnya[i] == kataKunci[j]){
                char temp = kunciLainnya[i];
                kunciLainnya[i] = kunciLainnya[j];
                kunciLainnya[j] = temp;
                // Pindahkan kolom matriks
                for(int k = 0; k < tinggiMatriksTransposisi; k++){
                    temp = matriksTransposisi[k][j];
                    matriksTransposisi[k][j] = matriksTransposisi[k][i];
                    matriksTransposisi[k][i] = temp;
                }
            }
        }
    }
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kunciLainnya << std::endl;
    // Tampilkan hasil transposisi
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "Dekripsi akan memasuki tahap terakhir . . .";
    getch(); //untuk menghentikan proses yang berjalan
    
    // Atur ulang penhitung
    posisiCipher = 0;
    
    // Ubah matriks transposisi menjadi matriks berdimensi satu
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            cipherText[posisiCipher] = matriksTransposisi[i][j];
            posisiCipher++;
        }
    }
    
    system("cls"); //untuk membersihkan layar pada program yang akan dijalankan 
    std::cout << "My Final Project" << std::endl; //Tampilan pesan project
    std::cout << "DEKRAN Decrypt Project" << std::endl; //Tampilan judul project
    std::cout << "====================***====================" << std::endl;
    std::cout << std::endl;    
    std::cout << "Proses Dekripsi telah selesai . . ." << std::endl;
    std::cout << std::endl;
    
    posisiCipher = 0; // Tetapkan posisi awal
    for(int i = 0; i < panjangKalimat; i += 2){
        // Cari kolom
        for(int j = 0; j < 6; j++){
            if(cipherText[i] == barisKolom[j]){
                kolom = j;
            }
        }
        // Cari posisi baris
        for(int j = 0; j < 6; j++){
            if(cipherText[i + 1] == barisKolom[j]){
                baris = j;
            }
        }
        std::cout << ma[kolom][baris];
    }    
    getch(); //untuk menghentikan proses yang berjalan
}
