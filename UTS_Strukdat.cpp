#include <iostream>
#include <string>

using namespace std;

// Struktur untuk menyimpan informasi kontak
struct Contact 
{
    string nama;
    string nomorHP;
    Contact* next;
};

// Kelas untuk mengelola linked list kontak
class ContactList 
{
private:
    Contact* head;
public:
    ContactList() 
    {
        head = nullptr;
    }

    // Menambahkan kontak baru ke linked list
    void addContact(const string& nama, const string& nomorHP) 
    {
        Contact* newContact = new Contact;
        newContact->nama = nama;
        newContact->nomorHP = nomorHP;
        newContact->next = nullptr;

        if (head == nullptr)
        {
            head = newContact;
        }
        else 
        {
            Contact* temp = head;
            while (temp->next != nullptr) 
            {
                temp = temp->next;
            }
            temp->next = newContact;
        }
        cout << "Kontak '" << nama << "' berhasil ditambahkan." << endl;
    }

    // Menampilkan semua kontak dalam linked list
    void displayContacts() 
    {
        if (head == nullptr) 
        {
            cout << "Daftar kontak kosong." << endl;
            return;
        }
        Contact* temp = head;
        cout << "Daftar Kontak:" << endl;
        while (temp != nullptr) 
        {
            cout << "Nama: " << temp->nama << ", Nomor Telepon: " << temp->nomorHP << endl;
            temp = temp->next;
        }
    }

    // Menghapus kontak berdasarkan nama
    void deleteContact(const string& nama)
    {
        if (head == nullptr) 
        {
            cout << "Daftar kontak kosong." << endl;
            return;
        }
        Contact* temp = head;
        Contact* prev = nullptr;
        while (temp != nullptr) 
        {
            if (temp->nama == nama) 
            {
                if (prev == nullptr) 
                {
                    head = temp->next;
                }
                else 
                {
                    prev->next = temp->next;
                }
                delete temp;
                cout << "Kontak '" << nama << "' berhasil dihapus." << endl;
                return;
            }
            prev = temp;
            temp = temp->next;
        }
        cout << "Kontak '" << nama << "' tidak ditemukan." << endl;
    }

    // Menghapus semua kontak dalam linked list
    void deleteAllContacts() 
    {
        Contact* temp;
        while (head != nullptr) 
        {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Semua kontak berhasil dihapus." << endl;
    }

    ~ContactList() 
    {
        deleteAllContacts();
    }
};

int main() 
{
    ContactList contacts;

    while (true) 
    {
        cout << "Menu: " << endl;
        cout << "1. Tambah Kontak" << endl;
        cout << "2. Tampilkan Kontak" << endl;
        cout << "3. Hapus Kontak" << endl;
        cout << "4. Keluar" << endl;

        int choice;
        cout << "Pilih: ";
        cin >> choice;

        if (choice == 1) 
        {
            string nama, nomorHP;
            cout << "Masukkan nama kontak: ";
            cin >> nama;
            cout << "Masukkan nomor telepon kontak: ";
            cin >> nomorHP;
            contacts.addContact(nama, nomorHP);
        }
        else if (choice == 2) 
        {
            contacts.displayContacts();
        }
        else if (choice == 3) 
        {
            string nama;
            cout << "Masukkan nama kontak yang ingin dihapus: ";
            cin >> nama;
            contacts.deleteContact(nama);
        }
        else if (choice == 4) 
        {
            break;
        }
        else 
        {
            cout << "Pilihan tidak valid." << endl;
        }
    }

    return 0;
}