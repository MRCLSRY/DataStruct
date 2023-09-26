#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node
{
    char word;
    struct Node *next, *prev;
}*head = NULL, *tail = NULL;

int count = 0;

struct Node *createNewNode(char word)
{
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->word = word;

    newNode->next = newNode->prev = NULL;

    return newNode;
}

void push(char word)
{
    struct Node *newNode = createNewNode(word);
    if (head == NULL)
    {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
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
    struct Node *curr = tail;
    while (curr)
    {
        printf("%c", curr->word);
        curr = curr->prev;
    }
    puts("");
}

int main()
{
    int choose = -1;
    do
    {
        system("cls");
        puts("1. Masukkan Kata");
        puts("2. Balikan Kata");
        scanf("%d", &choose); getchar();
        switch (choose)
        {
        case 1:;
        system("cls");
            char type = 'f';
            do
            {
                scanf("%c", &type);
                push(type);
            } while (type != '\n');
            break;
        case 2:
        system("cls");
            puts("Palindrome:");
            display();
            getchar();
            break;
        default:
            break;
        }
    } while (choose != 0);

    return 0;    
}