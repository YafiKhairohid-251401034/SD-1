#include <iostream>
#include <string>

using namespace std;

#define MAX 100

char stack[MAX];
int top = -1;

//menambahkan karakter ke stack
void push(char value) {
    if (top == MAX-1) {
        cout <<"Stack penuh !\n";
    } else {
        top++;
        stack[top] = value;
        cout << value <<" ditambahkan dalam stack\n";
    }
}

//mengambil karakter paling atas
void pop() {
    if (top == -1) { 
        cout <<"Stack kosong !\n";
    } else {
        cout<<"\n"<< stack[top]<<" dihapus dari stack\n";
        top--;
    }
}

// TODO : Nampilin Stack
void display() {
    if (top == -1) { 
        cout <<"Stack kosong !\n";
    } else {
        cout <<"\nIsi dari stack :\n";
        for(int i=top; i>=0; i--){
            cout << stack[i] << " ";
        }
    }
}

int main() {

    string kata;

    cout << "Masukkan sebuah kata: ";
    cin >> kata;

    //memasukkan setiap karakter ke stack
    for(int i=0; i<kata.length(); i++){
        push(kata[i]);
    }
    display();
    
    //mengeluarkan karakter dari stack
    cout << endl;

    return 0;
}