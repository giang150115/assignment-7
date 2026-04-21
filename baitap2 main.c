#include <stdio.h>
#include "hashtable.h"

int main() {
    init_table();
    
    insert("An", "111");
    insert("Binh", "222");
    insert("Chi", "333");
    
    printf("--- Kiem tra tim kiem ---\n");
    search("An");
    search("Ngoan"); // Khong ton tai
    
    printf("--- Sau khi xoa Binh ---\n");
    delete("Binh");
    displayAll();
    
    free_table();
    return 0;
}
