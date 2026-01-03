#include <iostream>
#include "dll.h"

using namespace std;

int main() {
    List L;
    createList(L);
    address P_deleted;


    insertLast(L, "https://www.google.com/");
    insertLast(L, "https://chatgpt.com/");
    insertLast(L, "https://outlook.office.com/");
    insertLast(L, "https://igracias.telkomuniversity.ac.id/");

    cout << "=== APLIKASI RIWAYAT BROWSER (DLL) ===" << endl;
    printList(L);
    cout << endl;


    cout << "--- Test 1: Simulasi Backward ---" << endl;
    backward(L, "https://www.google.com/");


    cout << "\n--- Test 2: Simulasi Backward (Gagal) ---" << endl;
    backward(L, "https://facebook.com");

    cout << "\n--- Test 3: Hapus Riwayat ---" << endl;

    cout << "1. Menghapus 'Outlook'..." << endl;
    hapusRiwayat(L, "https://outlook.office.com/", P_deleted);
    printList(L);

    cout << "2. Menghapus 'Google' (First)..." << endl;
    hapusRiwayat(L, "https://www.google.com/", P_deleted);
    printList(L);

    cout << "3. Menghapus 'Telkom' (Last)..." << endl;
    hapusRiwayat(L, "https://igracias.telkomuniversity.ac.id/", P_deleted);
    printList(L);

    cout << "\nSisa History: ";
    printList(L);

    return 0;
}
