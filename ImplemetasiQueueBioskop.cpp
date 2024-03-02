#include <iostream>
#include <string>
#include <conio.h>

using namespace std;

struct PenontonFilm
{
    string nama;
    int usia;
    PenontonFilm *next;
};

PenontonFilm *head = NULL;
PenontonFilm *tail = NULL;
const int KapasitasMaksimum = 50;
int jumlahData = 0; // Variabel global untuk menyimpan jumlah data yang akan dimasukkan

// Fungsi isFull
bool isFull()
{
    int count = 0;
    PenontonFilm *penonton = head;
    while (penonton != NULL)
    {
        count++;
        penonton = penonton->next;
    }
    return count >= KapasitasMaksimum;
}

// Fungsi enqueue
void enqueue()
{
    for (int i = 0; i < jumlahData; ++i)
    {
        if (head != NULL && isFull())
        {
            cout << "\nAntrian sudah penuh. Proses antrian dihentikan." << endl;
            return;
        }

        PenontonFilm *penontonBaru = new PenontonFilm();
        cout << "\nData ke-" << i + 1 << ":" << endl;
        cout << "Masukkan nama: ";
        cin.ignore();
        getline(cin, penontonBaru->nama);
        cout << "Masukkan usia: ";
        cin >> penontonBaru->usia;

        penontonBaru->next = NULL;

        if (head == NULL)
        {
            head = penontonBaru;
            tail = penontonBaru;
        }
        else
        {
            tail->next = penontonBaru;
            tail = penontonBaru;
        }
    }

    cout << "\nProses penambahan data selesai." << endl;
}

// Fungsi dequeue
void dequeue()
{
    if (head == NULL)
    {
        cout << "\nAntrian kosong" << endl;
    }
    else
    {
        PenontonFilm *penonton = head;
        cout << endl;
        cout << penonton->nama << " (" << penonton->usia << " tahun) masuk ke dalam bioskop." << endl;

        head = head->next;
        delete penonton;
    }
}

// Fungsi display
void display()
{
    if (head == NULL)
    {
        cout << "Antrian kosong\n"
             << endl;
    }
    else
    {
        PenontonFilm *penonton = head;
        cout << "\nAntrian penonton: " << endl;
        while (penonton != NULL)
        {
            cout << penonton->nama << "(" << penonton->usia << " tahun)\n";
            penonton = penonton->next;
        }
        cout << endl;
    }
}

// Fungsi count
void count()
{
    int count = 0;
    PenontonFilm *penonton = head;
    while (penonton != NULL)
    {
        count++;
        penonton = penonton->next;
    }
    cout << "\nJumlah penonton dalam antrian: " << count << endl;
}

// Fungsi destroy
void destroy()
{
    while (head != NULL)
    {
        PenontonFilm *penonton = head;
        head = head->next;
        delete penonton;
    }
    cout << "\nAntrian penonton telah dihapus" << endl;
}

int main()
{
    char inputChar;
    int pilihan;

    do
    {
        cout << endl;
        cout << "\t============================================" << endl;
        cout << "\t|      SELAMAT DATANG DI MINI BIOSKOP      |" << endl;
        cout << "\t|        Jl. Raya Gunung Anyar No.2        |" << endl;
        cout << "\t|    Gunung Anyar, Surabaya, Jawa Timur    |" << endl;
        cout << "\t|  Kode Pos 60294 - Call Center 1 500 046  |" << endl;
        cout << "\t============================================" << endl
             << endl;
        cout << "1. Antri untuk nonton film" << endl;
        cout << "2. Masuk ke dalam bioskop" << endl;
        cout << "3. Tampilkan antrian" << endl;
        cout << "4. Cek apakah antrian penuh" << endl;
        cout << "5. Cek apakah antrian kosong" << endl;
        cout << "6. Hitung jumlah penonton" << endl;
        cout << "7. Tutup bioskop" << endl;
        cout << "8. Keluar" << endl;
        cout << "\nTekan Sesuai Pilihan\n";
        inputChar = getch();
        pilihan = inputChar - '0';

        system("cls");

        switch (pilihan)
        {
        case 1:
            cout << "Masukkan jumlah data yang akan dimasukkan: ";
            cin >> jumlahData;
            enqueue();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 2:
            dequeue();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 3:
            display();
            cout << "Tekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 4:
            cout << endl;
            cout << (isFull() ? "Antrian penuh" : "Antrian tidak penuh") << endl;
            count();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 5:
            cout << endl;
            cout << (head == NULL ? "Antrian kosong" : "Antrian tidak kosong") << endl;
            count();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 6:
            count();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 7:
            destroy();
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        case 8:
            cout << endl;
            cout << "Program selesai. Selamat menonton film!" << endl;
            break;
        default:
            cout << endl;
            cout << "Pilihan tidak valid" << endl;
            cout << "\nTekan Apapun Untuk Kembali";
            getch();
            system("cls");
            break;
        }
    } while (pilihan != 8);

    return 0;
}