#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int quickSort(int *vet, int inicio, int fim) {

    int aleatorio = inicio + (rand() % (fim+1-inicio));
    int pivo = vet[aleatorio];
    int j = inicio, aux;

    vet[aleatorio] = vet[inicio];
    vet[inicio] = pivo;

    for(int i=inicio+1; i<=fim; i++) {
        if(pivo > vet[i]) {
            j++;
            if(i != j) {
                aux = vet[j];
                vet[j] = vet[i];
                vet[i] = aux;
            }
        }
    }

    vet[inicio] = vet[j];
    vet[j] = pivo;
    return j;
}

void quick(int *vet, int inicio, int fim) {
    if(fim > inicio) {
        int pivo = quickSort(vet, inicio, fim);
        quick(vet, inicio, pivo-1);
        quick(vet, pivo+1, fim);
    }
}

void ordena(int *vet, int inicio, int meio, int fim) {

    int aux[fim-inicio];
    int i=inicio, j=meio+1, k=0;

    while (i<=meio && j<=fim) {
        if(vet[i] < vet[j]) {
            aux[k++] = vet[i++];
        } else {
            aux[k++] = vet[j++];
        }
    }
    
    while(i<=meio) {
        aux[k++] = vet[i++];
    }
    while(j<=fim) {
        aux[k++] = vet[j++];
    }

    j = 0;
    for(i=inicio; i<=fim; i++) {
        vet[i] = aux[j++];
    }

}

void merge(int *vet, int inicio, int fim) {
    if(fim > inicio) {
        int meio = (fim+inicio)/2;
        merge(vet, inicio, meio);
        merge(vet, meio+1, fim);
        ordena(vet, inicio, meio, fim);
    }
}

int main() {

    int n = 100000;
    int vet[n], vetR[n];
    clock_t inicio, fim;
    float tempo;

    srand(time(NULL));

    for(int i=0; i<n; i++) {
        vet[i] = i;
        vetR[i] = vet[i];
    }
    printf("\n");

    inicio = clock();
    quick(vet, 0, n-1);
    fim = clock();
    tempo = (float)fim-inicio;
    printf("%.10f", tempo/CLOCKS_PER_SEC);
    printf("\n");
    
    inicio = clock();
    merge(vetR, 0, n-1);
    fim = clock();
    tempo = (float)fim-inicio;
    printf("%.10f", tempo/CLOCKS_PER_SEC);
    printf("\n");

    printf("\n");

    return 0;
}