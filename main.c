#include <stdio.h>
#include <assert.h>
#include "dataStructures/vector/vector.h"

void test_pushBack_emptyVector() {
    vector v = createVector(3);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 8);

    assert(v.size == 3 && v.capacity == 3 && v.data[0] == 2 && v.data[1] == 3
    && v.data[2] == 8);
}

void test_pushBack_fullVector() {
    vector v = createVector(3);
    pushBack(&v, 2);
    pushBack(&v, 3);
    pushBack(&v, 8);
    pushBack(&v, 123);

    assert(v.size == 4 && v.capacity == 6);
}

void test_popBack_notEmptyVector() {
    vector v = createVector(0);
    pushBack(&v, 10);

    assert(v.size == 1);
    popBack(&v);
    assert(v.size == 0);
    assert(v.capacity == 1);
}

void test() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
}

int main() {
    test();

    return 0;
}
