//
// Created by saidchoquehuanca on 19/9/2019.
// Aceptado por la uva

#include<iostream>
#define primos 25

using namespace std;

int primeNumbers[primos]= {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};

int* divisores(int number, const int *primosnum, int *contador_primos){
    int j = 0;
    while (number > 1) {
        int count = 0;
        while (number % primosnum[j] == 0) {
            number /= primosnum[j];
            count++;
        }
        contador_primos[j] += count;
        ++j;
    }
    return contador_primos;
}
int main(){

    int factor, numero, j;
    while (cin >> factor && factor != 0) {
        int impresion = factor;
        int contador[primos] = {0};
        while (factor != 1) {
            numero = factor;
            divisores(numero, primeNumbers, contador);
            factor--;
        }
        for (numero = 24; numero >= 0; --numero) {
            if (contador[numero] != 0)
                break;
        }
        j = numero;
        printf("%3d! =", impresion);
        int limite = 0;
        if (j >= 15){
            limite = 0;
        }else
            limite = 15;
        for (numero = 0; numero <= j; numero++) {
            printf("%3d", contador [numero]);
            limite++;
            if (limite == 15)
                printf("\n%6c",' ');
        } printf("\n");
    }
    return 0;
}



