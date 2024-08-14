#include <stdio.h>
void EXCHANGE(int arr[], int p, int q) {
    int temp = arr[p];
    arr[p] = arr[q];
    arr[q] = temp;
}
void ROTATE_RIGHT(int arr[], int p2) {
    if (p2 > 0) {
        int last_element = arr[p2 - 1];
        for (int i = p2 - 1; i > 0; i--) {
            EXCHANGE(arr, i, i - 1);
        }
        arr[0] = last_element;
    }
}
int main() {
    int N;
    printf("Enter the size of the array (N): ");
    scanf("%d", &N);
    int arr[N];
    printf("Enter the elements of the array: ");
    for (int i = 0; i < N; i++) {
        scanf("%d", &arr[i]);
    }
    int p2;
    printf("Enter the number of elements to rotate (p2): ");
    scanf("%d", &p2);
    printf("Before ROTATE:\t");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    ROTATE_RIGHT(arr, p2);
    printf("After ROTATE:\t");
    for (int i = 0; i < N; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}