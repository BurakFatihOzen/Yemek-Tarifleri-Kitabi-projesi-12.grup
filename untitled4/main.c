#include <stdio.h>
#include <string.h>
#include"tarif_ara.h"// tarif_ara fonksiyonun çalışması için gereken kendi oluşturduğumuz kütüphaneyi çağırır.
#include "tarif_ekle.h"// tarif_ekle fonksiyonun çalışması için gereken kendi oluşturduğumuz kütüphaneyi çağırır.
#include "menuleri_yazdir.h"// tarif_menuleri_yazdir fonksiyonun çalışması için gereken kendi oluşturduğumuz kütüphaneyi çağırır.
#include "tarif_duzenle.h"// tarif_duzenle fonksiyonun çalışması için gereken kendi oluşturduğumuz kütüphaneyi çağırır.
#include "tarif_sil.h" // tarif siler.
#define DOSYA_ADI "tarifler.txt" // Dosya kullanırken her seferinde .txt uzantılı bir yapıyı DOSYA_ADI adı altında sabitleyerek daha temiz bir kod oluşturur.
#define MAX_TARIF_SAYISI 100 // Kullanıcının girebileceği maksimum tarif sayısını "100" ile sınırlar.
#define MAX_ADIM_SAYISI 10  // Her tarif için maksimum adım sayısını belirler.

int main() {
    struct Tarif tarifler[MAX_TARIF_SAYISI];
    int tarif_sayisi = 0; // Tarif sayısı gereken adımlarda değişeceği için programın rastgele bir sayı üretmemesi için başlangıç değeri sıfıra eşitlenir.
    FILE* dosya = fopen(DOSYA_ADI, "r"); // tarifler.txt dosyasını okuma işlemi gerçekleştirilir.

    if (dosya != NULL) {
        while (fscanf(dosya, "%[^\n]\n%[^\n]\n", tarifler[tarif_sayisi].adi,tarifler[tarif_sayisi].malzemeler) == 2) {// dosyadan tarif adı ve malzemeleri okur.Eğer iki adet string okursa döngüye girer.
            for (int i = 0; i < MAX_ADIM_SAYISI; ++i) {                                                                           //  %[^\n] olmasının sebebi kullanıcının enter tuşuna basmasına kadar programın tüm gördüklerini okumasını sağlamaktır.
                if (fscanf(dosya, "%[^\n]\n", tarifler[tarif_sayisi].adimlar[i].adim_metni) != 1) {//Her adımın metni için bir satırı okur ve okuma başarılıyken döngüye devam eder.
                    break;
                }
                tarifler[tarif_sayisi].adim_sayisi++;// Tarifteki adım sayısını "1" arttırır.
            }
            tarif_sayisi++;
            if (tarif_sayisi >= MAX_TARIF_SAYISI) {
                printf("--------------------------\n");
                printf("Maksimum tarif sayisina ulasildi. Daha fazla ekleyemezsiniz.\n");
                break;
            }
        }
        fclose(dosya);// Dosya kapatılır.
    }
    else{
        printf("Dosya islemleri basarisiz oldu :(\n");
    }
    while (1) {
        printf("--------------------------\n");
        printf("---Tarif Kitabi---\n");//Kullanıcıya menü ekranını sunar.
        printf("1. Tarif Ekle\n");
        printf("2. Tarif Duzenle\n");
        printf("3. Tarif Ara\n");
        printf("4. Tarif Sil\n");
        printf("5. Cikis.\n");

        int secim;
        printf("--------------------------\n");
        printf("Seciminizi yapin (1-5): ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                tarif_ekle(tarifler, &tarif_sayisi);
                break;
            case 2:
                tarif_duzenle(tarifler, tarif_sayisi);
                break;
            case 3: {
                tarif_ara(tarifler, tarif_sayisi);
                break;
            }
            case 4:
                tarif_sil(tarifler, &tarif_sayisi);
                break;

            case 5:
                dosya = fopen(DOSYA_ADI, "w");//yazma modunda dosyayı açar.
                for (int i = 0; i < tarif_sayisi; ++i) {
                    fprintf(dosya, "%s\n%s\n", tarifler[i].adi, tarifler[i].malzemeler);//hafızaya alınan tariflerin en son halini for döngüsü ile dosyanın içine yazdırır.
                    for (int j = 0; j < tarifler[i].adim_sayisi; ++j) {
                        fprintf(dosya, "%s\n", tarifler[i].adimlar[j].adim_metni);//hafızaya alınan tariflerin adımlarını ve adım içeriklerinim en son halini for döngüsü ile dosyanın içine yazdırır.
                    }
                }
                fclose(dosya);// Dosyayı kapatır.
                return 0;
            default:
                printf("--------------------------\n");
                printf("Gecersiz secim. Lutfen tekrar deneyin.\n");
        }
    }
}
