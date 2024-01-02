#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "menuleri_yazdir.h"
#define DOSYA_ADI "tarifler.txt" // Dosya kullanırken her seferinde .txt uzantılı bir yapıyı DOSYA_ADI adı altında sabitleyerek daha temiz bir kod oluşturur.
#define MAX_TARIF_SAYISI 100 // Kullanıcının girebileceği maksimum tarif sayısını "100" ile sınırlar.
#define MAX_ADIM_SAYISI 10  // Her tarif için maksimum adım sayısını belirler.
#ifndef ALGORITMA_PROJESI_TARIF_DUZENLE_H
#define ALGORITMA_PROJESI_TARIF_DUZENLE_H

#define MAX_ADIM_METNI_UZUNLUK 100
#define MAX_TARIF_ADI_UZUNLUK 50
#define MAX_MALZEME_UZUNLUK 50
#define MAX_MALZEME_SAYISI 20


void tarif_duzenle(struct Tarif* tarifler, int tarif_sayisi) {
    tarif_menuleri_yazdir(tarifler, tarif_sayisi);

    int duzenlenecek_tarif_no;
    printf("--------------------------\n");
    printf("Duzenlemek istediginiz tarifin numarasini girin: ");
    scanf("%d", &duzenlenecek_tarif_no);
    duzenlenecek_tarif_no--;// Tarif numarasının 1'den başlaması gerektiği ve buna karşın ARRAY yapısının ilk indisinin 0 olması sebebiyle girilen tarif numarasının ARRAY ile uygun çalışacak biçime gelmesi için tarif numarası 1 azaltılır.

    if (duzenlenecek_tarif_no < 0 || duzenlenecek_tarif_no >= tarif_sayisi) {
        printf("Gecersiz tarif numarasi.\n");// Tarif numarasının olması gereken degerler arasında olup olmadığı kontrol edilir.
        return;
    }
    printf("--------------------------\n");
    printf("Duzenlenen Tarif: %s\n", tarifler[duzenlenecek_tarif_no].adi);
    printf("--------------------------\n");
    printf("Duzenlenen Tarifin Malzemeleri: %s\n", tarifler[duzenlenecek_tarif_no].malzemeler);

    // Tarif adını düzenleme seçeneği
    char adi_duzenle;
    printf("--------------------------\n");
    printf("Tarifin adini da duzenlemek ister misiniz? (E/H): ");//Tarif düzenlenirken kullanıcının tarifin adını da düzenlemeyi isteyip istemediği sorgulanır.
    scanf(" %c", &adi_duzenle);

    if (adi_duzenle == 'E' || adi_duzenle == 'e') {
        printf("--------------------------\n");
        printf("Yeni Tarif Adi: ");
        scanf(" %[^\n]s", tarifler[duzenlenecek_tarif_no].adi);// ^\n işareti ile \n yani boşluk ifadesi hariç diğer karakterleri okuyarak kullanıcının aralarında boşluk olan kelimeler ile cümle kurmasına imkan tanınır.
    }

    // Malzemeleri düzenleme seçeneği
    char malzemeleri_duzenle;
    printf("--------------------------\n");
    printf("Tarifin malzemelerini de duzenlemek ister misiniz? (E/H): ");//Tarif düzenlenirken kullanıcının malzemelerini de düzenlemeyi isteyip istemediği sorgulanır.
    scanf(" %c", &malzemeleri_duzenle);

    if (malzemeleri_duzenle == 'E' || malzemeleri_duzenle == 'e') {
        printf("--------------------------\n");
        printf("Yeni Malzemeleri Girin: ");
        scanf(" %[^\n]s", tarifler[duzenlenecek_tarif_no].malzemeler);
    }
    printf("--------------------------\n");
    printf("Duzenlenen Tarifin Adimlari:\n");
    for (int i = 0; i < tarifler[duzenlenecek_tarif_no].adim_sayisi; ++i) {
        printf("%d. adim: %s\n", i + 1, tarifler[duzenlenecek_tarif_no].adimlar[i].adim_metni);
    }

    int duzenlenecek_adim_no;
    printf("--------------------------\n");
    printf("Düzenlemek istediginiz adimin numarasini girin (bitirmek icin -1): ");
    scanf("%d", &duzenlenecek_adim_no);
    duzenlenecek_adim_no--;// Tarif adımlarının 1'den başlaması gerektiği ve buna karşın ARRAY yapısının ilk indisinin 0 olması sebebiyle girilen tarif numarasının ARRAY ile uygun çalışacak biçime gelmesi için tarif numarası 1 azaltılır.

    while (duzenlenecek_adim_no != -1) {
        if (duzenlenecek_adim_no < 0  || duzenlenecek_adim_no >= tarifler[duzenlenecek_tarif_no].adim_sayisi ) {
            printf("Gecersiz adim numarasi.\n");
            return;
        }
        printf("--------------------------\n");
        printf("Yeni %d. adimi girin: ", duzenlenecek_adim_no + 1);// Adımı düzenle
        scanf(" %[^\n]s", tarifler[duzenlenecek_tarif_no].adimlar[duzenlenecek_adim_no].adim_metni);

        printf("--------------------------\n");
        printf("Duzenlenen Tarifin Adimlari:\n");
        for (int i = 0; i < tarifler[duzenlenecek_tarif_no].adim_sayisi; ++i) {
            printf("--------------------------\n");
            printf("%d. adim: %s\n", i + 1, tarifler[duzenlenecek_tarif_no].adimlar[i].adim_metni);
        }

        printf("--------------------------\n");
        printf("Duzenlemek istediginiz bir sonraki adimin numarasini girin (bitirmek icin -1): ");
        scanf("%d", &duzenlenecek_adim_no);
        duzenlenecek_adim_no--;// Tarif adımlarının 1'den başlaması gerektiği ve buna karşın ARRAY yapısının ilk indisinin 0 olması sebebiyle girilen tarif numarasının ARRAY ile uygun çalışacak biçime gelmesi için tarif numarası 1 azaltılır.
    }
    printf("--------------------------\n");
    printf("Tarif duzenlendi.\n");
}


#endif //ALGORITMA_PROJESI_TARIF_DUZENLE_H
