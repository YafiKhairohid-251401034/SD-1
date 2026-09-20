#include <iostream>
using namespace std;

// deklarasikan nodenya
struct Node {
    int value;
    Node *next;
};

Node *head = NULL;
Node *tail = NULL;

// untuk insert di depan
void insertFirst(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        newNode->next = head;
        head = newNode;
    }
}

// ini jg insert tapi di akhir
void insertLast(int n) {
    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
        tail = head;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

// ini insert di akhir
void insertAfter(int n, int check) {
    if (head == NULL) {
        cout << "List kosong, silakan insert di depan\n";
        return;
    }

    Node *newNode = new Node;
    newNode->value = n;
    newNode->next = NULL;

    Node *p = head;

    while (p != NULL && p->value != check) {
        p = p->next;
    }

    if (p == NULL) {
        cout << "Node dengan nilai " << check << " tidak ketemu\n";
        delete newNode;
    }
    else {
        newNode->next = p->next;
        p->next = newNode;

        if (p == tail) {
            tail = newNode;
        }
    }
}

// hapus node pertama
void deleteFirst() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    Node *temp = head;
    head = head->next;

    if (head == NULL) {
        tail = NULL;
    }
    delete temp;
}


// hapus node terakhir
void deleteLast() {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    // kalo cuma ada satu node
    if (head == tail) {
        delete head;
        head = tail = NULL;
        return;
    }

    Node *p = head;

    while (p->next != tail) {
        p = p->next;
    }
    delete tail;

    tail = p;
    tail->next = NULL;
}


// hapus node berdasarkan nilai tertentu
void deleteMiddle(int value) {
    if (head == NULL) {
        cout << "List kosong!\n";
        return;
    }

    // kalo nilai yang dihapus adalah node pertama
    if (head->value == value) {
        deleteFirst();
        return;
    }

    Node *p = head;

    while (p->next != NULL && p->next->value != value) {
        p = p->next;
    }

    // kalo nilai tidak ditemukan
    if (p->next == NULL) {
        cout << "Node dengan nilai " << value << " tidak ketemu\n";
    }
    else {
        Node *temp = p->next;
        p->next = temp->next;

        if (temp == tail) {
            tail = p;
        }
        delete temp;
    }
}


// cetak linked list
void printList() {
    Node *temp = head;

    cout << "Isi Linked List: ";

    while (temp != NULL) {
        cout << temp->value << " -> ";
        temp = temp->next;
    }

    cout << "NULL\n";
}

// program utama
int main() {
    int pilihan, nilai, nilaiCari;

    while (true) {
        cout << "\n===== MENU SINGLE LINKED LIST =====\n";
        cout << "1. Tambah di awal\n";
        cout << "2. Tambah di akhir\n";
        cout << "3. Tambah setelah nilai tertentu\n";
        cout << "4. Hapus berdasarkan nilai\n";
        cout << "5. Tampilkan Linked List\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertFirst(nilai);
                printList();
                break;

            case 2:
                cout << "Masukkan nilai: ";
                cin >> nilai;
                insertLast(nilai);
                printList();
                break;

            case 3:
                cout << "Masukkan nilai baru: ";
                cin >> nilai;
                cout << "Masukkan nilai yang ingin dicari: ";
                cin >> nilaiCari;
                insertAfter(nilai, nilaiCari);
                printList();
                break;

            case 4:
                cout << "Masukkan nilai yang ingin dihapus: ";
                cin >> nilai;
                deleteMiddle(nilai);
                printList();
                break;

            case 5:
                printList();
                break;

            case 0:
                cout << "Program selesai.\n";
                return 0;

            default:
                cout << "Pilihan tidak tersedia!\n";
        }
    }
    return 0;
}