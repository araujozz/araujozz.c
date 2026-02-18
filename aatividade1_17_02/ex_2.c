#include <stdio.h>

int fibonacci(int n){
    if (n <= 0) return 0;      
    if (n == 1) return 1;      
    return fibonacci(n-1) + fibonacci(n-2);
}

int main(){
    int n;
    printf("Informe n: ");
    if (scanf("%d", &n) != 1) return 1;
    printf("fibonacci(%d) = %d\n", n, fibonacci(n));
    return 0;
}
