#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char sendName[40], sender[40], revName[40], receiver[40];
    int weight;
    struct Node *next, *prev;
}*head = NULL, *tail = NULL;

int count = 0;

struct Node *createNewNode(char *sendName, char *sender, char *revName, char *receiver, int weight)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    strcpy(newNode->sendName, sendName);
    strcpy(newNode->sender, sender);
    strcpy(newNode->revName, revName);
    strcpy(newNode->receiver, receiver);
    newNode->weight = weight;

    newNode->next = newNode->prev = NULL;

    return newNode;
}

void push(char *sendName, char *sender, char *revName, char *receiver, int weight)
{
    struct Node *newNode = createNewNode(sendName, sender, revName, receiver, weight);
    if (head == NULL)
    {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
    count++;
    return;
}

void pop()
{
    struct Node *curr = tail;
    if (head == NULL)
    {
        return;
    } else if (head == tail)
    {
        curr->next = NULL;
        curr->prev = NULL;
        head = tail = NULL;
        free(curr);
    } else
    {
        curr->prev->next = NULL;
        curr->next = NULL;
        tail = curr->prev;
        free(curr);
    }
}

void display()
{
    if (head == NULL)
    {
        puts("Tidak ada paket!");
        return;
    }
    
    struct Node *curr = tail;
    printf("%s %s %s %s %d\n", curr->receiver, curr->revName, curr->sender, curr->sendName, curr->weight);
}

int main()
{
    int choose = -1;
    do
    {
        system("cls");
        puts("1. Masukkan Paket");
        puts("2. Lihat Kapasitas Gudang");
        puts("3. Lihat Paket Terakhir");
        puts("4. Lihat Apakah Gudang Penuh atau Tidak");
        puts("5. Hapus Paket");
        scanf("%d", &choose); getchar();
        switch (choose)
        {
        case 1:
            system("cls");
            char sendName[40], sender[40], revName[40], receiver[40];
            int weight;
            puts("Nama Pengirim : ");
            gets(sendName);
            puts("Alamat Pengirim : ");
            gets(sendName);
            puts("Nama Penerima : ");
            gets(sendName);
            puts("Alamat penerima : ");
            gets(sendName);
            puts("Masukkan berat pake :");
            scanf("%d", &weight); getchar();
            push(sendName, sender, revName, receiver, weight);
            puts("Paket berhasil di input!");    
            break;
        case 2:
            system("cls");
            printf("Kapasitas gudang saat ini : %d\n", 15-count);
            getchar();
            break;
        case 3:
            system("cls");
            puts("Paket terakhir:");
            display();
            getchar();
            break;
        case 4:
            system("cls");
            if (count<15)
            {
                puts("Kapasitas gudang tersedia");
            } else {
                puts("Kapasitas gudang penuh");
            }
            getchar();
            break;
        case 5:
            pop();
            puts("Paket berhasil di hapus!"); getchar();
            break;
        default:
            break;
        }
    } while (choose != 0);


    return 0;
}