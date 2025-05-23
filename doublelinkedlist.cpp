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
            // Step 4: newnode->next = START
            newnode->next = START;

            // Step 5: START->prev = newnode (jika START tidak NULL)
            if (START != NULL)
                START->prev = newnode;

            // Step 6: newnode->prev = NULL
            newnode->prev = NULL;

            // Step 7: START = newnode
            START = newnode;
            return;
        }

        // Step 8: Cari posisi yang tepat untuk insert
        node *current = START;
        while (current->next != NULL && current->next->nodeMhs < nim)
        {
            current = current->next;
        }

        // Step 9: Insert newnode antara current dan current->next
        newnode->next = current->next; // Step 9a
        newnode->prev = current;       // Step 9b

        if (current->next != NULL) // Step 10: Hubungkan node setelah current ke newnode
            current->next->prev = newnode;

        current->next = newnode; // Step 11: Hubungkan current ke newnode
    }
    void hapus()
    {
        if (START == NULL) // Cek apakah list kosong
        {
            cout << "\nList is empty" << endl;
            return;
        }

        cout << "\nEnter the roll number of the student whose record is to be deleted: ";
        int rollNo;
        cin >> rollNo;

        node *current = START;

        // STEP 1: Telusuri list untuk menemukan node dengan noMhs = rollNo
        while (current != NULL && current->nodeMhs != rollNo)
            current = current->next;

        if (current == NULL) // Jika tidak ditemukan
        {
            cout << "Record not found" << endl;
            return;
        }

        // STEP 2: Jika node yang akan dihapus adalah node pertama
        if (current == START)
        {
            START = current->next; // Pindahkan START ke node berikutnya
            if (START != NULL)
                START->prev = NULL; // Hilangkan hubungan ke node yang dihapus
        }
        else
        {
            // STEP 3: Hubungkan node sebelumnya ke node sesudah current
            current->prev->next = current->next;

            // STEP 4: Jika current bukan node terakhir
            if (current->next != NULL)
                current->next->prev = current->prev;
        }

        delete current; // Hapus node dari memori
        cout << "Record deleted successfully." << endl;
    }
    void traverse()
    {
        if (START == NULL)
        { // Cek apakah list kosong
            cout << "\nList is empty" << endl;
            return;
        }

        // Step 1: Tandai node pertama sebagai currentnode
        node *currentnode = START;

        // Step 2: Ulangi hingga currentnode menjadi NULL
        cout << "\nRecords in ascending order of roll number are:\n";
        int i = 0;

        while (currentnode != NULL)
        {
            cout << i + 1 << ". " << currentnode->nodeMhs << endl; // Tampilkan data
            currentnode = currentnode->next;                       // Step 3: Pindah ke node berikutnya
            i++;
        }
    }

    void revtraverse()
    {
        if (START == NULL)
        {
            cout << "nList is empty" << endl;
            return;
        }
        // step 1: move to last mode
        node *current = START;
        int i = 0;
        while (currenjtnode->next != NULL)
        {
            currentnode = currentnode->next;
            i++;
        }
        // step 2: traverse backward
        cout << "\nRecord is descending order of roll number are:\n";
        while (currentnode != NULL)
        {
            cout << i + 1 << "." << currentnode->next << "" << endl;
            // step 3 move to previous node
            current = currentnoide->previous;
            i--;
        }
    }
    void searchData(
        {
            if (START == NULL)
            {
                cout << "\nList is  empty" << endl;
                return;
            }
            inty rollNo;
            cout << "\NEnter roll number to search:";
            cin >> rollno;
            node *current = START;
            // STEP 1: TRAVERSE TO FIND MATCHING ROLL NUMBER
            while (current != NULL && current->noMhs != rollNo)
                current = current->next;

            // Step 2: Output result
            if (current != NULL)
            {
                cout << "Record not found\n";
            }
            else
            {
                cout << "Record found\n";
                cout << "Roll Number: " << current->noMhs << endl;
            }
        })
};

int main()
{
    DoubleLinkedList list;
    char choice;

    do
    {
        cout << "nMenu:\n";
        cout << "1. Add Record\n";
        cout << "2. Delete Record\n";
        cout << "3. View Ascending";
        cout << "4. View Descending";
        cout << "5. Search Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice)
        {
        case '1':
            list.addNode();
            break;
        case '2':
            list.hapus();
            break;
        case '3':
            list.traverse();
        case '4':
            list.revtraverse();
            break;
        case '5':
            list.searchData();
        case '6':
            return 0;
        default:
            cout << "Invalid option\n";
        }
        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
        cout << endl;
        system("clear");
    } while (choice != '6');
}