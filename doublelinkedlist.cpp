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
    DoubleLinkedList()
    {
        START = NULL;
    }
