#include <stdio.h>
#include <assert.h>
#include "dataStructures/vector/vector.h"
#include "dataStructures/vectorVoid/vectorVoid.h"

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

void test_atVector_notEmptyVector() {
    vector v = createVector(5);
    pushBack(&v, 10);
    pushBack(&v, 142);
    pushBack(&v, 13);
    pushBack(&v, 0);

    assert(atVector(&v, 2) == &v.data[2]);
}

void test_atVector_requestToLastElement() {
    vector v = createVector(5);
    pushBack(&v, 10);
    pushBack(&v, 142);
    pushBack(&v, 13);
    pushBack(&v, 0);
    pushBack(&v, 0);

    assert(atVector(&v, 4) == &v.data[4]);
}

void test_back_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    assert(back(&v) == &v.data[0]);
}

void test_front_oneElementInVector() {
    vector v = createVector(1);
    pushBack(&v, 10);
    assert(front(&v) == &v.data[0]);
}

void test_vector() {
    test_pushBack_emptyVector();
    test_pushBack_fullVector();
    test_popBack_notEmptyVector();
    test_atVector_notEmptyVector();
    test_back_oneElementInVector();
    test_front_oneElementInVector();
}

void test_getVectorValueV() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    int x;
    getVectorValueV(&v, 0, &x);
    assert(x == 1);
}

void test_setVectorValueV() {
    vectorVoid v = createVectorV(2, sizeof(int));
    int a = 1;
    pushBackV(&v, &a);
    int x = 2;
    setVectorValueV(&v, 0, &x);

    int res;
    getVectorValueV(&v, 0, &res);

    assert(res == 2);
}

void test_vectorVoid() {
    test_getVectorValueV();
    test_setVectorValueV();
}

int main() {
    test_vector();
    test_vectorVoid();

    return 0;
}
