#include <stdio.h>

int main(){
    int value = 5;      // Create an actual integer variable
    int *x = &value;
    printf("%p", (void*)&x);
}