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

// Tek sayıları listenin başına, çift sayıları listenin sonuna ekleyen fonksiyon
void ekleTekCiftListeye(struct Node** head, int value) {
    struct Node* newNode = NULL;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (value % 2 == 1) { // Tek sayı ise
        newNode->next = *head;
        *head = newNode;
    } else { // Çift sayı ise
        if (*head == NULL) { // Eğer liste boşsa
            *head = newNode;
        } else {
            struct Node* temp = *head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
}

// Liste içeriğini yazdıran fonksiyon
void yazdirListe(struct Node* head) {
    printf("List: ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    struct Node* liste = NULL;
    int sayi;

    printf("enter numbers: \n");
    while (1) {
        scanf("%d", &sayi);
        if (sayi == -1) {
            break;
        }
        ekleTekCiftListeye(&liste, sayi);
    }

    yazdirListe(liste);

    // Belleği temizle
    while (liste != NULL) {
        struct Node* temp = liste;
        liste = liste->next;
        free(temp);
    }

    return 0;
}

