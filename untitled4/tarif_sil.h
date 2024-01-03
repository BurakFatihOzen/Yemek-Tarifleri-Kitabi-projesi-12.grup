#ifndef UNTITLED4_TARIF_SIL_H
#define UNTITLED4_TARIF_SIL_H

#ifndef UNTITLED46_TARIF_SIL_H
#define UNTITLED46_TARIF_SIL_H
#endif //UNTITLED46_TARIF_SIL_H



#include <stdio.h>
#include <string.h>
#include "tarif_ara.h"
#include "tarif_ekle.h"
#include "tarif_duzenle.h"
#include "menuleri_yazdir.h"


void tarif_sil(struct Tarif* tarifler, int* tarif_sayisi) {
    tarif_menuleri_yazdir(tarifler, *tarif_sayisi);

    int silinecek_tarif_no;
    printf("--------------------------\n");
    printf("Silinecek Tarif Numarasini Girin: ");
    scanf("%d", &silinecek_tarif_no);
    silinecek_tarif_no--;  // Array indeksleri 0'dan başladığı için kullanıcıdan alınan numarayı bir azaltıyoruz

    if (silinecek_tarif_no < 0 || silinecek_tarif_no >= *tarif_sayisi) {
        printf("Gecersiz tarif numarasi.\n");
        return;
    }

    for (int i = silinecek_tarif_no; i < *tarif_sayisi - 1; ++i) {// Silinecek tarifi diziden çıkarır.
        strcpy(tarifler[i].adi, tarifler[i + 1].adi);
        strcpy(tarifler[i].malzemeler, tarifler[i + 1].malzemeler);
        for (int j = 0; j < tarifler[i + 1].adim_sayisi; ++j) {
            strcpy(tarifler[i].adimlar[j].adim_metni, tarifler[i + 1].adimlar[j].adim_metni);
        }
        tarifler[i].adim_sayisi = tarifler[i + 1].adim_sayisi;
    }

    (*tarif_sayisi)--;

    printf("--------------------------\n");
    printf("Tarif silindi.\n");

}

#endif //UNTITLED4_TARIF_SIL_H
