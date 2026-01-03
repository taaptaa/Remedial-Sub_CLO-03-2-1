#include "dll.h"

void createList(List &L) {
    L.first = NULL;
    L.last = NULL;
}

address createNewElm(infotype x) {
    address P = new elmList;
    P->url = x;
    P->next = NULL;
    P->prev = NULL;
    return P;
}

void insertLast(List &L, infotype x) {
    address P = createNewElm(x);
    if (L.first == NULL) {
        L.first = P;
        L.last = P;
    } else {
        P->prev = L.last;
        L.last->next = P;
        L.last = P;
    }
}

address cariRiwayat(List L, infotype cari) {
    address P = L.first;
    while (P != NULL) {
        if (P->url == cari) {
            return P;
        }
        P = P->next;
    }
    return NULL;
}

void hapusRiwayat(List &L, infotype x, address &P) {

    P = cariRiwayat(L, x);


    if (P == NULL) {
        cout << "Riwayat tidak terdaftar" << endl;
    }

    else if (P != L.first && P != L.last) {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = NULL;
        P->prev = NULL;
    }

    else if (P == L.first) {
        L.first = P->next;

        if (L.first != NULL) {
            L.first->prev = NULL;
        } else {
            L.last = NULL;
        }
        P->next = NULL;
    }

    else if (P == L.last) {
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}

void backward(List L, infotype x) {
    address P, SaatIni;

    P = cariRiwayat(L, x);

    if (P == NULL) {
        cout << "backward gagal (Target tidak ditemukan)" << endl;
    } else {
        cout << ">> Memulai Backward ke: " << x << endl;
        SaatIni = L.last;

        while (SaatIni != P) {
            cout << "   Mengunjungi: " << SaatIni->url << endl;
            SaatIni = SaatIni->prev;
        }
        cout << "   Sampai di: " << SaatIni->url << endl;
    }
}


void printList(List L) {
    address P = L.first;
    cout << "[History Browser]: ";
    while (P != NULL) {
        cout << P->url;
        if (P->next != NULL) cout << " <--> ";
        P = P->next;
    }
    cout << endl;
}
