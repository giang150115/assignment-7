#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "hashtable.h"

Node* buckets[TABLE_SIZE];

void init_table() {
    for (int i = 0; i < TABLE_SIZE; i++) buckets[i] = NULL;
}

unsigned int hash(char *str) {
    unsigned int hash_val = 0;
    while (*str) {
        hash_val = (hash_val * 31) + *str;
        str++;
    }
    return hash_val % TABLE_SIZE;
}

void insert(char *name, char *phone) {
    unsigned int index = hash(name);
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    strcpy(newNode->phone, phone);
    newNode->next = buckets[index];
    buckets[index] = newNode;
}

void search(char *name) {
    unsigned int index = hash(name);
    Node* temp = buckets[index];
    while (temp != NULL) {
        if (strcmp(temp->name, name) == 0) {
            printf("Tim thay: %s - %s\n", temp->name, temp->phone);
            return;
        }
        temp = temp->next;
    }
    printf("Khong tim thay: %s\n", name);
}

void delete(char *name) {
    unsigned int index = hash(name);
    Node *temp = buckets[index], *prev = NULL;
    while (temp != NULL && strcmp(temp->name, name) != 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) return;
    if (prev == NULL) buckets[index] = temp->next;
    else prev->next = temp->next;
    free(temp);
}

void free_table() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = buckets[i];
        while (temp) {
            Node* to_free = temp;
            temp = temp->next;
            free(to_free);
        }
        buckets[i] = NULL;
    }
}

void displayAll() {
    for (int i = 0; i < TABLE_SIZE; i++) {
        Node* temp = buckets[i];
        if (temp) {
            printf("Bucket %d: ", i);
            while (temp) {
                printf("[%s] ", temp->name);
                temp = temp->next;
            }
            printf("\n");
        }
    }
}
