#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Ogrenci {
    char ad[50];
    char soyad[50];
    int numara;
    struct Ogrenci *sonraki;
};

// Yeni öğrenci düğümü oluşturan fonksiyon
struct Ogrenci *ogrenciOlustur(const char *ad, const char *soyad, int numara) {
    struct Ogrenci *ogrenci = (struct Ogrenci *)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->ad, ad);
    strcpy(ogrenci->soyad, soyad);
    ogrenci->numara = numara;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

void listeGoster(const struct Ogrenci *baslangic) {
    const struct Ogrenci *gecici = baslangic;
    while (gecici != NULL) {
        printf("Ad: %s, Soyad: %s, Numara: %d\n", gecici->ad, gecici->soyad, gecici->numara);
        gecici = gecici->sonraki;
    }
}
// Öğrenci düğümlerini ekleme fonksiyonu
struct Ogrenci *ogrenciEkle(struct Ogrenci *baslangic, const char *ad, const char *soyad, int numara) {
    struct Ogrenci *yeniOgrenci = ogrenciOlustur(ad, soyad, numara);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// Verilen adı taşıyan öğrencinin bir sonraki düğümünü silen fonksiyon
struct Ogrenci *ogrenciSil(struct Ogrenci *baslangic, const char *aranan_ad) {
    struct Ogrenci *gecici = baslangic;
    struct Ogrenci *onceki = NULL;

    while (gecici != NULL) {
        if (strcmp(aranan_ad, gecici->ad) == 0) {
            if (onceki == NULL) {
                // Başlangıç düğümünü değiştir
                baslangic = gecici->sonraki;
            } else {
                // Önceki düğümün sonraki işaretçisini güncelle
                onceki->sonraki = gecici->sonraki;
            }
            free(gecici); // Belleği serbest bırak
            printf("%s adlı öğrencinin sonraki düğümü silindi.\n", aranan_ad);
            return baslangic;
        }

        onceki = gecici;
        gecici = gecici->sonraki;
    }

    printf("%s adlı öğrenci bulunamadı.\n", aranan_ad);
    return baslangic;
}

int main() {
    struct Ogrenci *baslangic = NULL;
    int ogrenciSayisi;
    char ad[50], soyad[50];
    int numara;
    int secim;

    while (1) {
        printf("1. Öğrenci Ekle\n2. Öğrenci Sil\n3. Liste Göster\n4. Çıkış\nSeçim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                printf("Ad: ");
                scanf("%s", ad);
                printf("Soyad: ");
                scanf("%s", soyad);
                printf("Numara: ");
                scanf("%d", &numara);
                baslangic = ogrenciEkle(baslangic, ad, soyad, numara);
                break;

            case 2:
                printf("Silmek istediğiniz öğrencinin adını girin: ");
                scanf("%s", ad);
                baslangic = ogrenciSil(baslangic, ad);
                break;

            case 3:
                printf("Öğrenci Listesi:\n");
                listeGoster(baslangic);
                break;

            case 4:
                exit(0);

            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    }

    return 0;
}