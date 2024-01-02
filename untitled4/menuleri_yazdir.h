#include <stdio.h>
#include <string.h>
#ifndef ALGORITMA_PROJESI_MENULERI_YAZDIR_H
#define ALGORITMA_PROJESI_MENULERI_YAZDIR_H
#define DOSYA_ADI "tarifler.txt"
#define MAX_TARIF_SAYISI 100 // Kullanıcının girebileceği maksimum tarif sayısını "100" ile sınırlar.
#define MAX_ADIM_SAYISI 10  // Her tarif için maksimum adım sayısını belirler.


struct Adim {
    char adim_metni[1000];
};

struct Tarif {
    char adi[1000];
    char malzemeler[1000];
    struct Adim adimlar[MAX_ADIM_SAYISI];
    int adim_sayisi;
};

void tarif_menuleri_yazdir(struct Tarif* tarifler, int tarif_sayisi) {
    printf("--------------------------\n");
    printf("\nTarifler\n");
    for (int i = 0; i < tarif_sayisi; ++i) {
        printf("%d. %s\n", i + 1, tarifler[i].adi);
    }
}

#endif //ALGORITMA_PROJESI_MENULERI_YAZDIR_H
