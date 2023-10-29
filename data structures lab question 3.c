#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Öğrenci bilgisi saklayacak düğüm yapısı
struct Ogrenci {
    int numara;
    char isim[50];
    int yas;
    struct Ogrenci* sonraki;
};

// Yeni bir öğrenci düğümü oluşturan işlev
struct Ogrenci* yeniOgrenci(int numara, const char* isim, int yas) {
    struct Ogrenci* ogrenci = (struct Ogrenci*)malloc(sizeof(struct Ogrenci));
    ogrenci->numara = numara;
    strcpy(ogrenci->isim, isim);
    ogrenci->yas = yas;
    ogrenci->sonraki = NULL;
    return ogrenci;
}

// Öğrenci listesini ekrana yazdıran ve sayan işlev
void ogrenciListesiniYazdir(struct Ogrenci* baslangic) {
    struct Ogrenci* current = baslangic;
    int sayac = 1;

    while (current != NULL) {
        printf("%d-%s %d %d\n", current->numara, current->isim, current->yas, sayac);
        current = current->sonraki;
        sayac++;
    }
}

int main() {
    struct Ogrenci* baslangic = NULL;
    struct Ogrenci* son = NULL;
    int numara, yas;
    char isim[50];
    int sayac = 1;

    while (1) {
        printf("student number, name, age:\n ");
        scanf("%d", &numara);

        if (numara == -1) {
            break;
        }

        scanf("%s %d", isim, &yas);

        struct Ogrenci* ogrenci = yeniOgrenci(numara, isim, yas);

        if (baslangic == NULL) {
            baslangic = ogrenci;
            son = ogrenci;
        } else {
            son->sonraki = ogrenci;
            son = ogrenci;
        }
    }

    // Öğrenci listesini ekrana yazdır ve say
    ogrenciListesiniYazdir(baslangic);

    // Belleği temizle
    struct Ogrenci* current = baslangic;
    while (current != NULL) {
        struct Ogrenci* temp = current;
        current = current->sonraki;
        free(temp);
    }

    return 0;
}