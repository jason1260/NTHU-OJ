#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "13410.h"

void traverse_block_chain(block_chain *bc) {
    int ptr = bc->tail;
    while (ptr != 0) {
        printf("<-%d", ptr);
        ptr = bc->block_data[ptr]->link;
    }
    printf("\n");
}

int main() {
    int command;
    char name1[10], name2[10];
    int tmp, i, hash_value;
    block_chain chain;
    block* new_block;
    chain.tail = 0;
    chain.block_data[0] = NULL;
    int count;
    scanf("%d", &count);
    while (count--) {
        scanf("%d", &command);
        if (command == 1) {                     // CREATE BLOCK
            transaction t[2];
            for (i = 0; i < 2; i++) {
                scanf("%s %s %d", name1, name2, &tmp);
                strcpy(t[i].from, name1);
                strcpy(t[i].to, name2);
                t[i].val = tmp;
            }
            new_block = create_block(chain.tail, t);
            hash_value = hash(new_block);
            chain.block_data[hash_value] = new_block;
            chain.tail = hash_value;
        }else if (command == 2) {               // QUERY
            scanf("%s %d", name1, &tmp);
            printf("%d\n", query(&chain, name1, tmp));
        }else if (command == 0) {               // EXIT
            traverse_block_chain(&chain);
        }else {
            return 1;
        }
    }
    return 0;
}
