#include <stdio.h>
#include <string.h>
#include "menuleri_yazdir.h"
#ifndef ALGORITMA_PROJESI_TARIF_ARA_H
#define ALGORITMA_PROJESI_TARIF_ARA_H
#define DOSYA_ADI "tarifler.txt" // Dosya kullanırken her seferinde .txt uzantılı bir yapıyı DOSYA_ADI adı altında sabitleyerek daha temiz bir kod oluşturur.
#define MAX_TARIF_SAYISI 100 // Kullanıcının girebileceği maksimum tarif sayısını "100" ile sınırlar.
#define MAX_ADIM_SAYISI 10  // Her tarif için maksimum adım sayısını belirler.


void tarif_ara(struct Tarif* tarifler, int tarif_sayisi) {
    tarif_menuleri_yazdir(tarifler, tarif_sayisi);

    int aranacak_tarif_no;
    char kelime[1000];
    printf("--------------------------\n");
    printf("Aranacak Tarif Numarasini Girin:");
    scanf(" %[^\n]s", kelime);

    if (sscanf(kelime, "%d", &aranacak_tarif_no) == 1 && aranacak_tarif_no >= 1 && aranacak_tarif_no <= tarif_sayisi) {//sscanf,"kelime" içindeki veriyi belirtilen biçimde okuyarak değişkenlere atar.
        printf("--------------------------\n");
        printf("Tarif Adi: %s\n", tarifler[aranacak_tarif_no - 1].adi);
        printf("Malzemeler: %s\n", tarifler[aranacak_tarif_no - 1].malzemeler);
        printf("Tarif Adimlari:\n");
        for (int i = 0; i < tarifler[aranacak_tarif_no - 1].adim_sayisi; ++i) {
            printf("--------------------------\n");
            printf("%d. adim: %s\n", i + 1, tarifler[aranacak_tarif_no - 1].adimlar[i].adim_metni);
        }
    } else {
        int bulunan_sayisi = 0;
        for (int i = 0; i < tarif_sayisi; ++i) {
            if (strstr(tarifler[i].adi, kelime) || strstr(tarifler[i].malzemeler, kelime)) {// strstr fonksiyonu 2.indisin 1.nin içerisinde yer alıp almadığını kontrol edip programı ona göre sonlandırır.
                printf("%d. %s\n", i + 1, tarifler[i].adi);
                bulunan_sayisi++;
            }
        }

        if (bulunan_sayisi == 0) {
            printf("--------------------------\n");
            printf("Sonuc bulunamadi.\n");
        }
    }
}
#endif //ALGORITMA_PROJESI_TARIF_ARA_H


