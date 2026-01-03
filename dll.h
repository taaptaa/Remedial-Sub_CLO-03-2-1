void hapusRiwayat(List &L, infotype x, address &P) {
    // 1. Cari elemen target
    P = cariRiwayat(L, x);

    // 2. Logika Hapus
    if (P == NULL) {
        cout << "Riwayat tidak terdaftar" << endl;
    } 
    // Kasus: Elemen di tengah (bukan first, bukan last)
    else if (P != L.first && P != L.last) {
        P->prev->next = P->next;
        P->next->prev = P->prev;
        P->next = NULL;
        P->prev = NULL;
    }
    // Kasus: Elemen adalah First
    else if (P == L.first) {
        L.first = P->next;
        // Cek jika list tidak menjadi kosong set prev jadi null
        if (L.first != NULL) {
            L.first->prev = NULL;
        } else {
            L.last = NULL; // Jika list jadi kosong
        }
        P->next = NULL;
    }
    // Kasus: Elemen adalah Last
    else if (P == L.last) {
        L.last = P->prev;
        L.last->next = NULL;
        P->prev = NULL;
    }
}
