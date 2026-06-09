#include <stdio.h>
#include <stdlib.h>
 
long long merge_e_conta(int arr[], int aux[], int esq, int dir);
 
// Função para o qsort checar duplicatas
int comp(const void *a, const void *b) { return (*(int*)a - *(int*)b); }
 
void resolve() {
    int n;
    scanf("%d", &n);
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    int *temp = malloc(n * sizeof(int));
 
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
 
    // 1. Check duplicatas
    qsort(b, n, sizeof(int), comp);
    for (int i = 0; i < n - 1; i++) {
        if (b[i] == b[i+1]) {
            printf("YES\n");
            free(a); free(b); free(temp);
            return;
        }
    }
 
    // 2. Conta inversões (Merge Sort)
    if (merge_e_conta(a, temp, 0, n - 1) % 2 == 0) printf("YES\n");
    else printf("NO\n");
 
    free(a); free(b); free(temp);
}
 
int main() {
    int t;
    scanf("%d", &t);
    while (t--) resolve();
    return 0;
}
 
// Lógica de contagem rápida (O(n log n))
long long merge_e_conta(int arr[], int aux[], int esq, int dir) {
    if (esq >= dir) return 0;
    int meio = (esq + dir) / 2;
    long long c = merge_e_conta(arr, aux, esq, meio) + merge_e_conta(arr, aux, meio + 1, dir);
    
    int i = esq, j = meio + 1, k = esq;
    while (i <= meio && j <= dir) {
        if (arr[i] <= arr[j]) aux[k++] = arr[i++];
        else { aux[k++] = arr[j++]; c += (meio - i + 1); } // Inversão detectada
    }
    while (i <= meio) aux[k++] = arr[i++];
    while (j <= dir) aux[k++] = arr[j++];
    for (i = esq; i <= dir; i++) arr[i] = aux[i];
    return c;
}