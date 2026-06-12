#include <iostream>
#include <string>
using namespace std;

// Struct Node digunakan sebagai satu data antrian
struct Node {
    int nomor;
    string nama;
    string keperluan;
    Node* next;
};

// Class Queue digunakan untuk menyimpan antrian aktif
class QueueAntrian {
private:
    Node* front;
    Node* rear;

public:
    QueueAntrian() {
        front = NULL;
        rear = NULL;
    }

    // Mengecek apakah queue kosong
    bool isEmpty() {
        return front == NULL;
    }

    // Menambahkan data ke antrian
    void enqueue(int nomor, string nama, string keperluan) {
        Node* newNode = new Node();
        newNode->nomor = nomor;
        newNode->nama = nama;
        newNode->keperluan = keperluan;
        newNode->next = NULL;

        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }

        cout << "Data antrian berhasil ditambahkan.\n";
    }

    // Menghapus data dari antrian paling depan
    Node* dequeue() {
        if (isEmpty()) {
            return NULL;
        }

        Node* temp = front;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        temp->next = NULL;
        return temp;
    }

    // Menampilkan seluruh antrian aktif
    void displayQueue() {
        if (isEmpty()) {
            cout << "Antrian masih kosong.\n";
            return;
        }

        Node* current = front;

        cout << "\n=== DAFTAR ANTRIAN AKTIF ===\n";
        while (current != NULL) {
            cout << "Nomor     : " << current->nomor << endl;
            cout << "Nama      : " << current->nama << endl;
            cout << "Keperluan : " << current->keperluan << endl;
            cout << "-----------------------------\n";
            current = current->next;
        }
    }

    // Mencari antrian berdasarkan nomor
    void searchByNomor(int nomorCari) {
        if (isEmpty()) {
            cout << "Antrian masih kosong.\n";
            return;
        }

        Node* current = front;
        bool found = false;

        while (current != NULL) {
            if (current->nomor == nomorCari) {
                cout << "\nData antrian ditemukan:\n";
                cout << "Nomor     : " << current->nomor << endl;
                cout << "Nama      : " << current->nama << endl;
                cout << "Keperluan : " << current->keperluan << endl;
                found = true;
                break;
            }
            current = current->next;
        }

        if (!found) {
            cout << "Data antrian dengan nomor tersebut tidak ditemukan.\n";
        }
    }
};

// Class Stack digunakan untuk menyimpan riwayat antrian yang sudah dipanggil
class StackRiwayat {
private:
    Node* top;

public:
    StackRiwayat() {
        top = NULL;
    }

    // Mengecek apakah stack kosong
    bool isEmpty() {
        return top == NULL;
    }

    // Menambahkan data ke stack riwayat
    void push(Node* data) {
        data->next = top;
        top = data;
    }

    // Menampilkan riwayat antrian yang sudah dipanggil
    void displayStack() {
        if (isEmpty()) {
            cout << "Riwayat panggilan masih kosong.\n";
            return;
        }

        Node* current = top;

        cout << "\n=== RIWAYAT ANTRIAN DIPANGGIL ===\n";
        while (current != NULL) {
            cout << "Nomor     : " << current->nomor << endl;
            cout << "Nama      : " << current->nama << endl;
            cout << "Keperluan : " << current->keperluan << endl;
            cout << "-----------------------------\n";
            current = current->next;
        }
    }
};

int main() {
    QueueAntrian queue;
    StackRiwayat stack;

    int pilihan;
    int nomorOtomatis = 1;

    do {
        cout << "\n===== SISTEM ANTRIAN LAYANAN =====\n";
        cout << "1. Tambah Antrian\n";
        cout << "2. Panggil Antrian\n";
        cout << "3. Cari Antrian\n";
        cout << "4. Tampilkan Antrian Aktif\n";
        cout << "5. Tampilkan Riwayat Panggilan\n";
        cout << "6. Keluar\n";
        cout << "Pilih menu: ";
        cin >> pilihan;
        cin.ignore();

        if (pilihan == 1) {
            string nama, keperluan;

            cout << "Masukkan nama: ";
            getline(cin, nama);

            cout << "Masukkan keperluan: ";
            getline(cin, keperluan);

            queue.enqueue(nomorOtomatis, nama, keperluan);

            cout << "Nomor antrian Anda: " << nomorOtomatis << endl;
            nomorOtomatis++;

        } else if (pilihan == 2) {
            Node* dipanggil = queue.dequeue();

            if (dipanggil == NULL) {
                cout << "Tidak ada antrian yang bisa dipanggil.\n";
            } else {
                cout << "\nAntrian dipanggil:\n";
                cout << "Nomor     : " << dipanggil->nomor << endl;
                cout << "Nama      : " << dipanggil->nama << endl;
                cout << "Keperluan : " << dipanggil->keperluan << endl;

                stack.push(dipanggil);
            }

        } else if (pilihan == 3) {
            int nomorCari;

            cout << "Masukkan nomor antrian yang dicari: ";
            cin >> nomorCari;

            queue.searchByNomor(nomorCari);

        } else if (pilihan == 4) {
            queue.displayQueue();

        } else if (pilihan == 5) {
            stack.displayStack();

        } else if (pilihan == 6) {
            cout << "Program selesai.\n";

        } else {
            cout << "Pilihan tidak valid.\n";
        }

    } while (pilihan != 6);

    return 0;
}