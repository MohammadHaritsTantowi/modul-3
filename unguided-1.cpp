#include <iostream>
 #include <string>
using namespace std;
struct Node
{
    string nama;
    int usia;
    Node *next;
};
Node *head = nullptr;
void init()
{
    head = nullptr;
}

void insertDepan(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = head;
    head = newNode;
}

void insertTengah(string nama, int usia, int posisi)
{
    if (posisi <= 1 || head == nullptr)
    {
        insertDepan(nama, usia);

        return;
    }

    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;

    Node *current = head;
    for (int i = 1; i < posisi - 1 && current->next != nullptr; i++)
    {
        current = current->next;
    }

    newNode->next = current->next;
    current->next = newNode;
}

void insertBelakang(string nama, int usia)
{
    Node *newNode = new Node;
    newNode->nama = nama;
    newNode->usia = usia;
    newNode->next = nullptr;

    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    Node *current = head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

void hapusData(string nama)
{
    if (head == nullptr)
    {
        cout << "Linked list kosong" << endl;
        return;
    }

    if (head->nama == nama)
    {
        Node *temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node *current = head;
    while (current->next != nullptr && current->next->nama != nama)
    {
        current = current->next;
    }

    if (current->next == nullptr)
    {
        cout << "Data tidak ditemukan" << endl;
        return;
    }

    Node *temp = current->next;
    current->next = current->next->next;
    delete temp;
}

void ubahData(string nama, string newNama, int newUsia)
{
    Node *current = head;
    while (current != nullptr)
    {
        if (current->nama == nama)
        {
            current->nama = newNama;
            current->usia = newUsia;
            return;
        }
        current = current->next;
    }
    cout << "Data tidak ditemukan" << endl;
}

void tampilkanData()
{
    Node *current = head;
    if (current == nullptr)
    {
        cout << "Linked list kosong" << endl;
        return;
    }
    cout << current->nama << "\t" << current->usia << endl;
    while (current->next != nullptr)
    {
        current = current->next;
        cout << current->nama << "\t" << current->usia << endl;
    }
}
int main()
{
    init();

    string namaAnda;
    int usiaAnda;
    cout << "Masukkan nama Anda: ";
    getline(cin, namaAnda);
    cout << "Masukkan usia Anda: ";
    cin >> usiaAnda;
    cin.ignore();

    insertDepan(namaAnda, usiaAnda);
    insertBelakang("John", 19);
    insertBelakang("Jane", 20);
    insertTengah("Futaba", 18, 2); // di antara John dan Jane i
    insertBelakang("Michael", 18);
    insertBelakang("Yusuke", 19);
    insertBelakang("Akechi", 20);
    insertBelakang("Hoshino", 18);
    insertBelakang("Karin", 18);
    hapusData("Akechi");
    insertDepan("Igor", 20);
    ubahData("Michael", "Reyn", 18);
    tampilkanData();

    return 0;
}
