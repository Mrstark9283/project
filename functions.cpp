#include "functions.h"
#include <iostream>
using namespace std;

int toBinary(int a){
    string s = "";
    while(a!=0){
        int rem = a%2;
        a = a/2;
        s = to_string(rem) + s;
    }
    return stoi(s);
}
int power(int base, int exp) {
    int bin = toBinary(exp);
    int current = 1;
    while (bin!=0)
    {
        if(bin%10==1){
            current *= base;
        }
        bin = bin/10;
        base*=base;
    }

    return current;
}