#include <stdio.h>
#include <stdlib.h>

// Düğüm yapısı
struct Node {
    int data;
    struct Node* next;
};

// Yeni bir düğüm oluşturur
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Liste içeriğini yazdıran fonksiyon
void yazdirListe(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d", current->data);
        if (current->next != NULL) {
            printf(" -> ");
        }
        current = current->next;
    }
    printf("\n");
}

// Düğümü sıralı bir şekilde liste içine ekleyen fonksiyon
void siraliEkle(struct Node** head, int value) {
    struct Node* new_node = newNode(value);
    
    if (*head == NULL || value > (*head)->data) {
        new_node->next = *head;
        *head = new_node;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->data > value) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
    }
}

int main() {
    struct Node* liste = NULL;
    int sayi;
    int i;

    // Rastgele 100 sayıyı liste içine ekleyin
    for (i = 0; i < 100; i++) {
        sayi = rand() % 100; // 0 ile 999 arasında rastgele bir sayı üretir
        siraliEkle(&liste, sayi);
    }

    // Sıralanmış liste içeriğini ekrana yazdırın
    printf(":");
    yazdirListe(liste);

    // Belleği temizle
    while (liste != NULL) {
        struct Node* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}





