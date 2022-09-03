#include<stdio.h>
#include<stdlib.h>
#include<time.h>

typedef struct vector
{
    int* data;
    int size, length;
}vector;

vector* init(int n) {
    vector* vec = (vector*)malloc(sizeof(vector));
    vec->data = (int*)malloc(sizeof(int) * n);
    vec->size = n;
    vec->length = 0;
    return vec;
}

int expand(vector* vec) {
    int new_size = vec->size * 2;
    int *p = (int *)realloc(vec->data, sizeof(int) * new_size);
    if (p == NULL) return 0;
    vec->size = new_size;
    vec->data = p;
    return 1;
}

int insert(vector* vec, int ind, int val) {
    if (vec == NULL) return 0;
    if (vec->length == vec->size) {
        if (!expand(vec)) return 0;
        printf("expand vector size to %d success\n", vec->size);
    }
    if (ind < 0 || ind > vec->length) return 0;
    for (int i = vec->length;i > ind;i--) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->data[ind] = val;
    vec->length += 1;
    return 1;
}

int erase(vector* vec, int ind) {
    if (vec == NULL) return 0;
    if (vec->length == 0) return 0;
    if (ind < 0 || ind >= vec->length) return 0;
    for (int i = ind + 1;i < vec->length;i++) {
        vec->data[i] = vec->data[i - 1];
    }
    vec->length -= 1;
    return 1;
}

void clear(vector* vec) {
    if (vec == NULL) return;
    free(vec->data);
    free(vec);
    return;
}

void output(vector* vec) {
    printf("Vector(%d)=[", vec->length);
    for (int i = 0;i < vec->length;i++) {
        if (i != 0) printf(", ");
        printf("%d", vec->data[i]);
    }
    printf("]\n");
    return;
}

int main() {
#define MAX_OP 20
    vector* vec = init(1);
    int op, ind, val;
    for (int i = 0; i < MAX_OP; i++) {
        op = rand() % 2;
        ind = rand() % (vec->length + 1);
        val = rand() % 100;
        switch (op) {
        case 0: {
            printf("insert %d at %d to vector\n", val, ind);
            insert(vec, ind, val);
        } break;
        case 1: {
            printf("erase item at %d from vector\n", ind);
            erase(vec, ind);
        }break;
        }
        output(vec);
    }
    return 0;
}