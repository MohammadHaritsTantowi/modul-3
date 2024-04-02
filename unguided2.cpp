#include <iostream>
#include <string>
using namespace std;
struct Node
{
    string namaProduk;
    int harga;
    Node *prev;
    Node *next;
};

Node *head = nullptr;
Node *tail = nullptr;
void init()
{
    head = nullptr;
    tail = nullptr;
}

void tambahData(string namaProduk, int harga)
{
    Node *newNode = new Node;
    newNode->namaProduk = namaProduk;
    newNode->harga = harga;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void hapusData(string namaProduk)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    Node *current = head;
    while (current != nullptr)
    {
        if (current->namaProduk == namaProduk)
        {
            if (current == head)
            {
                head = head->next;
                if (head != nullptr)
                {
                    head->prev = nullptr;
                }
            }
            else if (current == tail)
            {
                tail = tail->prev;
                tail->next = nullptr;
            }
            else
            {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            cout << "Data " << namaProduk << " berhasil dihapus" << endl;
            return;

            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }
}

    void updateData(string namaProduk, string newNamaProduk, int newHarga)
    {
        Node *current = head;
        while (current != nullptr)
        {
            if (current->namaProduk == namaProduk)
            {
                current->namaProduk = newNamaProduk;
                current->harga = newHarga;
                cout << "Data berhasil diupdate" << endl;
                return;
            }
            current = current->next;
        }
        cout << "Data tidak ditemukan" << endl;
    }

    void tambahDataUrutanTertentu(string namaProduk, int harga, int posisi)
    {
        if (posisi <= 1 || head == nullptr)
        {
            tambahData(namaProduk, harga);
            return;
        }

        Node *newNode = new Node;
        newNode->namaProduk = namaProduk;
        newNode->harga = harga;

        Node *current = head;
        for (int i = 1; i < posisi - 1 && current->next != nullptr; i++)
        {
            current = current->next;
        }

        newNode->next = current->next;
        newNode->prev = current;
        if (current->next != nullptr)
        {
            current->next->prev = newNode;
        }
        current->next = newNode;
    }

    void hapusDataUrutanTertentu(int posisi)
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }

        if (posisi == 1)
        {
            Node *temp = head;
            head = head->next;
            if (head != nullptr)
            {
                head->prev = nullptr;
            }
            delete temp;
            cout << "Data pada posisi 1 berhasil dihapus" << endl;
            return;
        }

        Node *current = head;
        for (int i = 1; i < posisi && current != nullptr; i++)
        {
            current = current->next;
        }

        if (current == nullptr)
        {
            cout << "Posisi tidak valid" << endl;
            return;
        }

        if (current == tail)
        {
            tail = tail->prev;
            tail->next = nullptr;
        }
        else
        {
            current->prev->next = current->next;
            current->next->prev = current->prev;
        }
        delete current;
        cout << "Data pada posisi " << posisi << " berhasil dihapus"
             << endl;
    }

    void hapusSeluruhData()
    {
        while (head != nullptr)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        cout << "Seluruh data berhasil dihapus" << endl;
    }

    void tampilkanData()
    {
        if (head == nullptr)
        {
            cout << "Linked list kosong" << endl;
            return;
        }

        Node *current = head;
        cout << "Nama Produk\tHarga" << endl;
        while (current != nullptr)
        {
            cout << current->namaProduk << "\t" << current->harga <<

                endl;
                current = current->next;
        }
    }

    

    int main()
    {
        cout << "MOHAMMAD HARITS TANTOWI" << endl;
        cout << "2311102016" << endl;

        init();

        tambahData("Originote", 60000);
        tambahData("Somethinc", 150000);
        tambahData("Skintific", 100000);
        tambahData("Wardah", 50000);
        tambahData("Hanasui", 30000);

        int pilihan;
        do
        {
            cout << "\nToko Skincare Purwokerto" << endl;
            cout << "1. Tambah Data" << endl;
            cout << "2. Hapus Data" << endl;
            cout << "3. Update Data" << endl;
            cout << "4. Tambah Data Urutan Tertentu" << endl;
            cout << "5. Hapus Data Urutan Tertentu" << endl;
            cout << "6. Hapus Seluruh Data" << endl;
            cout << "7. Tampilkan Data" << endl;
            cout << "8. Exit" << endl;
            cout << "Pilihan Anda: ";
            cin >> pilihan;
            cin.ignore();

            switch (pilihan)
            {
            case 1:
            {
                string namaProduk;
                int harga;
                cout << "Masukkan nama produk: ";
                getline(cin, namaProduk);
                cout << "Masukkan harga produk: ";
                cin >> harga;
                tambahData(namaProduk, harga);
                break;
            }
            case 2:
            {
                string namaProduk;
                cout << "Masukkan nama produk yang ingin dihapus:";
                    getline(cin, namaProduk);
                hapusData(namaProduk);
                break;
            }
            case 3:
            {
                string namaProduk, newNamaProduk;
                int newHarga;
                cout << "Masukkan nama produk yang ingin diupdate : ";
                               getline(cin, namaProduk);
                cout << "Masukkan nama baru produk: ";
                getline(cin, newNamaProduk);
                cout << "Masukkan harga baru produk: ";
                cin >> newHarga;
                updateData(namaProduk, newNamaProduk, newHarga);
                break;
            }
            case 4:
            {
                string namaProduk;
                int harga, posisi;
                cout << "Masukkannama produk yang ingin ditambahkan : ";
                                  getline(cin, namaProduk);
                cout << "Masukkan harga produk: ";
                cin >> harga;
                cout << "Masukkan posisi penambahan data: ";
                cin >> posisi;
                tambahDataUrutanTertentu(namaProduk, harga,
                                         posisi);
                break;
            }
            case 5:
            {
                int posisi;
                cout << "Masukkan posisi data yang ingin dihapus: ";
                        cin >>
                    posisi;
                hapusDataUrutanTertentu(posisi);
                break;
            }
            case 6:
            {
                hapusSeluruhData();
                break;
            }
            case 7:
            {
                tampilkanData();
                break;
            }
            case 8:
            {
                cout << "Terima kasih telah menggunakan layanan kami " << endl;
                    break;
            }
            default:
                cout << "Pilihan tidak valid" << endl;
                break;
            }
        } while (pilihan != 8);

        return 0;
    }

