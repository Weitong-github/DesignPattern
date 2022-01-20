#include<iostream>
#include<stdio.h>
using namespace std;

int main () {
    char* b[10] = {"after","before"};
    char* c[10] = {"after2","before2"};
    char** a[10] = {b,c};
    char*** p;
    p = a;
    cout<<**(++p);
    return 0;
}