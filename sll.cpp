#include "sll.h"

void createList(List &L) {
    L.first = NULL;
}

address createNewElm(infotype x) {
    address P = new elmList;
    P->info = x;
    P->next = NULL;
    return P;
}

void tambahData(List &L, infotype x) {
    address P = createNewElm(x);
    if (L.first == NULL) {
        L.first = P;
    } else {
        P->next = L.first;
        L.first = P;
    }
}

address panenTerbanyak(List L) {
    if (L.first == NULL) {
        return NULL;
    } else {
        address q = L.first;
        address P = q;
        int Max = 0;

        while (q != NULL) {
            if (q->info.jumlah > Max) {
                Max = q->info.jumlah;
                P = q;
            }
            q = q->next;
        }
        return P;
    }
}

void panenBulanan(List L, string Bulan) {
    cout << ">> Laporan Panen Bulan " << Bulan << ": ";
    address q = L.first;
    bool found = false;

    while (q != NULL) {
        if (q->info.bulan == Bulan) {
            cout << q->info.namaT << " ";
            found = true;
        }
        q = q->next;
    }

    if (!found) {
        cout << "(Tidak ada panen)";
    }
    cout << endl;
}

void printAll(List L) {
    address P = L.first;
    cout << "\n=== DATA LIST PANEN ===" << endl;
    while (P != NULL) {
        cout << "- " << P->info.namaT
             << " | " << P->info.bulan
             << " | " << P->info.jumlah << " kg" << endl;
        P = P->next;
    }
    cout << "=======================" << endl;
}
