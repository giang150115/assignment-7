#ifndef HASHTABLE_H
#define HASHTABLE_H

#define TABLE_SIZE 10

typedef struct Node {
    char name[50];
    char phone[15];
    struct Node* next;
} Node;

// Khai báo mảng buckets (external)
extern Node* buckets[TABLE_SIZE];

// Nguyên mẫu các hàm
void init_table();
unsigned int hash(char *str);
void insert(char *name, char *phone);
void search(char *name);
void delete(char *name);
void free_table();
void displayAll();

#endif
