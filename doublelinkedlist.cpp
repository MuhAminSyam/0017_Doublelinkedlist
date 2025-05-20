#include <iostream>  // Library untuk input-output standar
#include <string>    // Library untuk tipe data string
using namespace std; // Menggunakan standar namespace

class node
{
public:
    int nodeMhs;
    node *next;
    node *prev;
};

// Definisi class DoubleLinkedList
class DoubleLinkedList
{
private:
    node *START; // Pointer awal dari linked list

public:
    // Constructor untuk inisialisasi linked list kosong
    DoubleLinkedList()
    {
        START = NULL;
    }

    // Fungsi untuk menambahkan node
    void AddNode()
    {
        int nim; // Variabel untuk input NIM
        cout << "\nEnter the roll number of the student: ";
        cin >> nim;

        // Step 1: Alokasi memori untuk node baru
        node *newnode = new node();

        // Step 2: Isi data node dengan nim
        newnode->nodeMhs = nim;

        // Step 3: Insert di awal jika list kosong atau nim lebih kecil
        if (START == NULL || nim <= START->nodeMhs)
        {
            if (START != NULL && nim == START->nodeMhs)
            {
                cout << "\nDuplicate number not allowed" << endl;
                return;
            }
