#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Öğrenci yapısı
struct Ogrenci {
    char isim[50];
    struct Ogrenci* sonraki;
};

// Yeni öğrenci düğümü oluşturan fonksiyon
struct Ogrenci* ogrenciOlustur(const char* isim) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    strcpy(ogrenci->isim, isim);
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Yeni öğrenci düğümünü listenin başına ekleyen fonksiyon
struct Ogrenci* ogrenciEkle(struct Ogrenci* baslangic, const char* isim) {
    struct Ogrenci* yeniOgrenci = ogrenciOlustur(isim);
    yeniOgrenci->sonraki = baslangic;
    return yeniOgrenci;
}

// En uzun ismi ve uzunluğunu bulan fonksiyon
void enUzunIsimliOgrenciyiBul(const struct Ogrenci* baslangic) {
    const struct Ogrenci* gecici = baslangic;
    const char* enUzunIsim = NULL;
    size_t enUzunUzunluk = 0;

    while (gecici != NULL) {
        size_t uzunluk = strlen(gecici->isim);
        if (uzunluk > enUzunUzunluk) {
            enUzunUzunluk = uzunluk;
            enUzunIsim = gecici->isim;
        }
        gecici = gecici->sonraki;
    }

    if (enUzunIsim != NULL) {
        printf("En uzun isim: %s\n", enUzunIsim);
        printf("Uzunluk: %zu \n", enUzunUzunluk);
    } else {
        printf("Liste boş.\n");
    }
}

int main() {
    struct Ogrenci* baslangic = NULL;
    int secim;

    while (1) {
        printf("1. İsim Ekle\n2. En Uzun İsimli Öğrenciyi Bul\n3. Çıkış\nSeçim: ");
        scanf("%d", &secim);

        switch (secim) {
            case 1:
                char isim[50];
                printf("İsim: ");
                scanf("%s", isim);
                baslangic = ogrenciEkle(baslangic, isim);
                break;

            case 2:
                enUzunIsimliOgrenciyiBul(baslangic);
                break;

            case 3:
                exit(0);

            default:
                printf("Geçersiz seçim!\n");
                break;
        }
    }

    return 0;
}