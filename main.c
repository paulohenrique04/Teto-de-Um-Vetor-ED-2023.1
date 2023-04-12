/*
    Problema do Teto em um Vetor: Dado um vetor ordenado de tamanho n e um inteiro k, encontrar o teto de k dentro do vetor. O teto de
    um número k no vetor, é o menor número do vetor que é maior ou igual k. Mostre um algoritmo Recursivo que resolve esse problema com
    tempo O(log n) no pior caso.
*/ 

#include <stdio.h>

int encontrar_teto(int vet[], int k, int ini, int fim)
{
    if(k > vet[fim]) {
        return -1;
    }
    if(k == vet[fim]){
        return vet[fim];
    } 
    if(k <= vet[ini]){
        return vet[ini];
    } 
    int meio = (ini + fim)/2;

    if(vet[meio] == k) {
        return vet[meio];
    } 
    else if(k > vet[meio]) {
        if(k > vet[meio] && k <= vet[meio+1]) {
            return vet[meio+1];
        } else {
            return encontrar_teto(vet, k, meio+1, fim);
        }
    } else {
        if(k < vet[meio] && k > vet[meio-1]) {
            return vet[meio];
        } else {
            return encontrar_teto(vet, k, ini, meio-1);
        }
    }
}

int main()
{
    printf("Insira o tamanho do vetor: ");
    int tam;
    scanf("%d", &tam);
    printf("Leia os elemenos do vetor: ");
    int vetor[tam];
    for(int i = 0; i < tam; i++) {
        scanf("%d", &vetor[i]);
    }
    printf("Diga o Valor de K: ");
    int k;
    scanf("%d", &k);

    printf("%d", encontrar_teto(vetor, k, 0, tam-1));

}