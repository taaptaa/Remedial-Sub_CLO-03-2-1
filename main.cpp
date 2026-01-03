#include <iostream>
#include "sll.h"

using namespace std;

int main() {
    List L;
    createList(L);
    infotype data;

    cout << "Program SLL Data Panen Tani" << endl;

    data = {"Wortel", "Januari", 500};
    tambahData(L, data);

    data = {"Padi", "Februari", 850};
    tambahData(L, data);

    data = {"Labu", "Maret", 550};
    tambahData(L, data);

    data = {"Jagung", "Maret", 790};
    tambahData(L, data);

    data = {"Padi", "Maret", 1000};
    tambahData(L, data);
    printAll(L);

    address pMax = panenTerbanyak(L);
    cout << "\n[Test Fungsi Panen Terbanyak]" << endl;
    if (pMax != NULL) {
        cout << "Hasil: Tanaman terbanyak adalah " << pMax->info.namaT
             << " dengan total " << pMax->info.jumlah << " kg." << endl;
    } else {
        cout << "List kosong." << endl;
    }


    cout << "\n[Test Prosedur Panen Bulanan]" << endl;
    panenBulanan(L, "Maret");
    panenBulanan(L, "Februari");
    panenBulanan(L, "Desember");

    return 0;
}
