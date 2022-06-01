#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char from[10];
    char to[10];
    int val;
}transaction;

typedef struct {
    transaction t[2];
    int link;
}block;

typedef struct {
    block* block_data[1010];
    int tail;
}block_chain;

// TODO: return the hash value of the given block
int hash(block* b) {
    int sum = (b->t[0].val + b->t[1].val);
    int blink = b->link;
    int ans = ((((sum * sum) ^ blink) + blink * blink) % 1000) + 1;
    return ans;
}

// TODO: create a block with the given information and return its address
block* create_block(int currentTail, transaction t[2]) {
    block *tmp = (block*) malloc(sizeof(block));
    tmp->link = currentTail;
    tmp->t[0] = t[0];
    tmp->t[1] = t[1];
    return tmp;
}

// TODO: query someone's balance
int query(block_chain *bc, char name[10], int initial_saving) {
    int ptr = bc->tail;
    while (ptr != 0) {
        for (int i = 0; i < 2; i++) {
            if (!strcmp(bc->block_data[ptr]->t[i].from, name)) {
                initial_saving -= bc->block_data[ptr]->t[i].val;
            }
            else if (!strcmp(bc->block_data[ptr]->t[i].to, name)) {
                initial_saving += bc->block_data[ptr]->t[i].val;
            }
            //printf("search = %d\n", initial_saving);
        }
        ptr = bc->block_data[ptr]->link;
    }
    return initial_saving;
}
