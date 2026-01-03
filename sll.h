#ifndef SLL_H_INCLUDED
#define SLL_H_INCLUDED

#include <iostream>
#include <string>

using namespace std;
struct tPanen {
    string namaT;
    string bulan;
    int jumlah;
};

typedef tPanen infotype;
typedef struct elmList *address;

struct elmList {
    infotype info;
    address next;
};

struct List {
    address first;
};

void createList(List &L);
address createNewElm(infotype x);
void tambahData(List &L, infotype x);
address panenTerbanyak(List L);
void panenBulanan(List L, string Bulan);
void printAll(List L);

#endif // SLL_H_INCLUDED
