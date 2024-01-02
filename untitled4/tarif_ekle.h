#include <stdio.h>
#include <string.h>
#define DOSYA_ADI "tarifler.txt" // Dosya kullanırken her seferinde .txt uzantılı bir yapıyı DOSYA_ADI adı altında sabitleyerek daha temiz bir kod oluşturur.
#define MAX_TARIF_SAYISI 100 // Kullanıcının girebileceği maksimum tarif sayısını "100" ile sınırlar.
#define MAX_ADIM_SAYISI 10  // Her tarif için maksimum adım sayısını "10" olarak belirler.
#ifndef ALGORITMA_PROJESI_TARIF_EKLE_H
#define ALGORITMA_PROJESI_TARIF_EKLE_H


void tarif_ekle(struct Tarif* tarifler, int* tarif_sayisi) {
    if (*tarif_sayisi >= MAX_TARIF_SAYISI) {//Eklenebilecek maksimum tarif sayısı olan 100 e ulaşılıp ulaşılmadığını kontrol eder.
        printf("Maksimum tarif sayisina ulasildi. Daha fazla ekleyemezsiniz.\n");
        return;
    }
    printf("--------------------------\n");
    printf("Tarif Adi: ");
    scanf(" %[^\n]s", tarifler[*tarif_sayisi].adi);// Kullanıcı Enter tuşuna basana kadar tarif ismini alır.
    printf("--------------------------\n");
    printf("Malzemeler: ");
    printf("--------------------------\n");
    scanf(" %[^\n]s", tarifler[*tarif_sayisi].malzemeler);// Kullanıcıdan eklenecek tarifin malzemeleri kullanıcı enter tuşşuna basana kadar alınır.

    printf("Tarif Adimlari (Adim yazma isine son vermek icin 'q' tusuna basiniz.)\n");
    for (int i = 0; i < MAX_ADIM_SAYISI; ++i) {
        printf("--------------------------\n");
        printf("%d. adimi giriniz: ", i + 1);
        scanf(" %[^\n]s", tarifler[*tarif_sayisi].adimlar[i].adim_metni);// " %[^\n]s" ifadesinde tırnağın başında boşluk olmasının sebebi kullanıcının space tuşuna basarak birden fazla kelime yazmasına imkan sağlamaktır.
        if (strcmp(tarifler[*tarif_sayisi].adimlar[i].adim_metni, "q") == 0) {// iki string ifade karşılaştırılır eğer kullanıcıdan alınan ifade "q" harfine eşitse strcmp "0" değerini döndürür ve döngü sona erer.
            break;
        }
        tarifler[*tarif_sayisi].adim_sayisi++;//adım sayısı 1 artırılır.
    }
    (*tarif_sayisi)++;// tarif sayısı 1 artırılır.
}

#endif //ALGORITMA_PROJESI_TARIF_EKLE_H


