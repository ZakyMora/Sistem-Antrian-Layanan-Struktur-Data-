# Class Node digunakan sebagai satu data antrian
class Node:
    def __init__(self, nomor, nama, keperluan):
        self.nomor = nomor
        self.nama = nama
        self.keperluan = keperluan
        self.next = None


# Class Queue digunakan untuk menyimpan antrian aktif
class QueueAntrian:
    def __init__(self):
        self.front = None
        self.rear = None

    # Mengecek apakah queue kosong
    def is_empty(self):
        return self.front is None

    # Menambahkan data ke antrian
    def enqueue(self, nomor, nama, keperluan):
        new_node = Node(nomor, nama, keperluan)

        if self.is_empty():
            self.front = new_node
            self.rear = new_node
        else:
            self.rear.next = new_node
            self.rear = new_node

        print("Data antrian berhasil ditambahkan.")

    # Menghapus data dari antrian paling depan
    def dequeue(self):
        if self.is_empty():
            return None

        temp = self.front
        self.front = self.front.next

        if self.front is None:
            self.rear = None

        temp.next = None
        return temp

    # Menampilkan seluruh antrian aktif
    def display_queue(self):
        if self.is_empty():
            print("Antrian masih kosong.")
            return

        current = self.front

        print("\n=== DAFTAR ANTRIAN AKTIF ===")
        while current is not None:
            print("Nomor     :", current.nomor)
            print("Nama      :", current.nama)
            print("Keperluan :", current.keperluan)
            print("-----------------------------")
            current = current.next

    # Mencari antrian berdasarkan nomor
    def search_by_nomor(self, nomor_cari):
        if self.is_empty():
            print("Antrian masih kosong.")
            return

        current = self.front
        found = False

        while current is not None:
            if current.nomor == nomor_cari:
                print("\nData antrian ditemukan:")
                print("Nomor     :", current.nomor)
                print("Nama      :", current.nama)
                print("Keperluan :", current.keperluan)
                found = True
                break

            current = current.next

        if not found:
            print("Data antrian dengan nomor tersebut tidak ditemukan.")


# Class Stack digunakan untuk menyimpan riwayat antrian yang sudah dipanggil
class StackRiwayat:
    def __init__(self):
        self.top = None

    # Mengecek apakah stack kosong
    def is_empty(self):
        return self.top is None

    # Menambahkan data ke stack riwayat
    def push(self, data):
        data.next = self.top
        self.top = data

    # Menampilkan riwayat antrian yang sudah dipanggil
    def display_stack(self):
        if self.is_empty():
            print("Riwayat panggilan masih kosong.")
            return

        current = self.top

        print("\n=== RIWAYAT ANTRIAN DIPANGGIL ===")
        while current is not None:
            print("Nomor     :", current.nomor)
            print("Nama      :", current.nama)
            print("Keperluan :", current.keperluan)
            print("-----------------------------")
            current = current.next


def main():
    queue = QueueAntrian()
    stack = StackRiwayat()

    nomor_otomatis = 1

    while True:
        print("\n===== SISTEM ANTRIAN LAYANAN =====")
        print("1. Tambah Antrian")
        print("2. Panggil Antrian")
        print("3. Cari Antrian")
        print("4. Tampilkan Antrian Aktif")
        print("5. Tampilkan Riwayat Panggilan")
        print("6. Keluar")

        pilihan = input("Pilih menu: ")

        if pilihan == "1":
            nama = input("Masukkan nama: ")
            keperluan = input("Masukkan keperluan: ")

            queue.enqueue(nomor_otomatis, nama, keperluan)

            print("Nomor antrian Anda:", nomor_otomatis)
            nomor_otomatis += 1

        elif pilihan == "2":
            dipanggil = queue.dequeue()

            if dipanggil is None:
                print("Tidak ada antrian yang bisa dipanggil.")
            else:
                print("\nAntrian dipanggil:")
                print("Nomor     :", dipanggil.nomor)
                print("Nama      :", dipanggil.nama)
                print("Keperluan :", dipanggil.keperluan)

                stack.push(dipanggil)

        elif pilihan == "3":
            nomor_cari = int(input("Masukkan nomor antrian yang dicari: "))
            queue.search_by_nomor(nomor_cari)

        elif pilihan == "4":
            queue.display_queue()

        elif pilihan == "5":
            stack.display_stack()

        elif pilihan == "6":
            print("Program selesai.")
            break

        else:
            print("Pilihan tidak valid.")


main()