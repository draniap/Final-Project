# Final-Project
/* 
FINAL PROJECT MATA KULIAH C++
APLIKASI ENKRIPSI DAN DEKRIPSI SEBUAH PESAN MENGGUNAKAN MATRIKS TRANSPOSISI
NAMA KELOMPOK : DWI RANI APRIYANI
NIM : 17.83.0064
TOOLS YANG SAYA GUNAKAN ADALAH DEV C++ VERSION 5.11
*/

#include<iostream>
#include<conio.h>
#include<string.h>

// Deklarasi variabel yang digunakan untuk menyimpan informasi
char plainInput[10000]; // Karakter masukan
char cipherText[20000]; // Karakter olahan(sejenisnya)
char matriksTransposisi[500][500];
char kataKunci[500]; // Tempat untuk menyimpan karakter kunci proses enkripsi dan dekripsi
char kunciLainnya[500]; // Penyimpanan sementara kunci dekripsi
char ma[6][6]; // Tempat untuk menyimpan tabel referensi
char barisKolom[6] = {'A', 'D', 'F', 'G', 'V', 'X'};

// Deklarasi variabel yang digunakan untuk menyimpan panjang informasi
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
void enkripsi();
void dekripsi();

int main(){
    mainMenu:
        system("cls");
        std::cout << "My Final Project" << std::endl;
        std::cout << "DEKRAN Encrypt-Decrypt Project" << std::endl;
        std::cout << "=========================================================" << std::endl;
        std::cout << std::endl;
        std::cout << "Pilihan Menu" << std::endl;
        std::cout << " 1. Enkripsi" << std::endl;
        std::cout << " 2. Dekripsi" << std::endl;
        std::cout << " 3. Keluar"   << std::endl;
        std::cout << "\nPilihan: "  ;
        std::cin >> pilihan;
        switch(pilihan){
            case '1':
                enkripsi();
                goto mainMenu;
                break;
            case '2':
                dekripsi();
                goto mainMenu;
                break;
            case '3':
                goto keluar;
                break;
            default:
                // Jika terjadi kesalahan pada proses pemilihan menu
                std::cout << "ERROR!" << std::endl;
                std::cout << "Menu yang dipilih tidak tersedia. Silakan coba lagi. . ." << std::endl;
                getch();
                goto mainMenu;
        }

    keluar:
    return(0); 
}
// Funsi yang akan digunakan untuk melakukan proses enkripsi
void enkripsi(){
    system("cls");
    
    // DEKRAN Cipher array 6x6 yang akan digunakan pada proses enkripsi
    ma[0][0] = 'q'; ma[0][1] = 'w'; ma[0][2] = 'e'; ma[0][3] = 'r'; ma[0][4] = 't'; ma[0][5] = 32 ;
    ma[1][0] = 'y'; ma[1][1] = 'u'; ma[1][2] = 'i'; ma[1][3] = 'o'; ma[1][4] = 'p'; ma[1][5] = '9';
    ma[2][0] = 'a'; ma[2][1] = 's'; ma[2][2] = 'd'; ma[2][3] = 'f'; ma[2][4] = 'g'; ma[2][5] = '8';
    ma[3][0] = 'h'; ma[3][1] = 'j'; ma[3][2] = 'k'; ma[3][3] = 'l'; ma[3][4] = 'z'; ma[3][5] = '7';
    ma[4][0] = 'x'; ma[4][1] = 'c'; ma[4][2] = 'v'; ma[4][3] = 'b'; ma[4][4] = 'n'; ma[4][5] = '6';
    ma[5][0] = 'm'; ma[5][1] = '1'; ma[5][2] = '2'; ma[5][3] = '3'; ma[5][4] = '4'; ma[5][5] = '5';
    
    
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kalimat yang akan dienkripsi:" << std::endl;
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
                // Jika karakter ditemukan, periksa dimanakah baris dan kolom apakah karakter berada...
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
    
    system("cls");
    std::cout << "My final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    
    std::cout << cipherText << std::endl;

    
    std::cout << "Kalimat telah melalui tahap pertama." << std::endl;
    std::cout << "Masukkan kata kunci untuk mengamankan kalimat\n" << std::endl;
    std::cout << "[Pesan]--------------------------------------------------" << std::endl;
    std::cout << "Kunci yang dimasukkan disarankan untuk tidak memiliki karakter yang sama seperti \"kalimat\"\nkarena dapat terjadi kesalahan pada saat melakukan proses dekripsi." << std::endl;
    std::cout << "\nKunci = ";
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
    
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kataKunci << std::endl;
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "\nKalimat telah melalui tahap kedua." << std::endl;
    std::cout << "Enkripsi akan memasuki tahap ketiga. . ." << std::endl;
    getch();
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    
    // Tahap ketiga
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
    
    std::cout << "\nKalimat telah melalui tahap ketiga." << std::endl;
    std::cout << "Enkripsi akan memasuki tahap keempat. . ." << std::endl;
    getch();
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Kalimat telah melalui tahap ketiga." << std::endl;
    std::cout << "Enkripsi akan memasuki tahap terakhir. . ." << std::endl;
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Encrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
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
    std::cout << "\nKunci jangan sampai hilang!" << std::endl;
    std::cout << "Program akan kembali ke menu utama. . .";
    getch();
}


// Fungsi yang akan digunakan untuk melakukan proses dekripsi
void dekripsi(){
    system("cls");
    
    // DEKRAN Cipher array 6x6 yang akan digunakan pada proses dekripsi
    ma[0][0] = 'q'; ma[0][1] = 'w'; ma[0][2] = 'e'; ma[0][3] = 'r'; ma[0][4] = 't'; ma[0][5] = 32 ;
    ma[1][0] = 'y'; ma[1][1] = 'u'; ma[1][2] = 'i'; ma[1][3] = 'o'; ma[1][4] = 'p'; ma[1][5] = '9';
    ma[2][0] = 'a'; ma[2][1] = 's'; ma[2][2] = 'd'; ma[2][3] = 'f'; ma[2][4] = 'g'; ma[2][5] = '8';
    ma[3][0] = 'h'; ma[3][1] = 'j'; ma[3][2] = 'k'; ma[3][3] = 'l'; ma[3][4] = 'z'; ma[3][5] = '7';
    ma[4][0] = 'x'; ma[4][1] = 'c'; ma[4][2] = 'v'; ma[4][3] = 'b'; ma[4][4] = 'n'; ma[4][5] = '6';
    ma[5][0] = 'm'; ma[5][1] = '1'; ma[5][2] = '2'; ma[5][3] = '3'; ma[5][4] = '4'; ma[5][5] = '5';
    
    // Tanya masukan
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kalimat yang akan didekripsi:" << std::endl;
    fflush(stdin); // Bersihkan sisa masukan
    gets(cipherText);
    
    // Cari panjang kode cipher
    panjangKalimat = strlen(cipherText);
    
    // Tanya kata kunci
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    std::cout << "Masukkan kunci = ";
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
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kunciLainnya << std::endl;
    // Tampilkan hasil transposisi
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "Kalimat telah melalui tahap pertama." << std::endl;
    std::cout << "Dekripsi akan memasuki tahap kedua . . .";
    getch();
    
    
    
    
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
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;
    
    std::cout << kunciLainnya << std::endl;
    // Tampilkan hasil transposisi
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            std::cout << matriksTransposisi[i][j];
        }
        std::cout << std::endl;
    }
    
    std::cout << "Kalimat telah melalui tahap kedua." << std::endl;
    std::cout << "Dekripsi akan memasuki tahap ketiga . . .";
    getch();
    
    // Atur ulang penhitung
    posisiCipher = 0;
    
    // Ubah matriks transposisi menjadi matriks berdimensi satu
    for(int i = 0; i < tinggiMatriksTransposisi; i++){
        for(int j = 0; j < panjangMatriksTransposisi; j++){
            cipherText[posisiCipher] = matriksTransposisi[i][j];
            posisiCipher++;
        }
    }
    
    system("cls");
    std::cout << "My Final Project" << std::endl;
    std::cout << "DEKRAN Decrypt Project" << std::endl;
    std::cout << "=========================================================" << std::endl;
    std::cout << std::endl;    
    std::cout << "Dekripsi telah mencapai tahap akhir . . ." << std::endl;
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
    getch();
}
