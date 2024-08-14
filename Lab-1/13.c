#include <stdio.h>
#include <stdlib.h>
void readArrayFromFile(const char *filename, int arr[], int n) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error opening file.\n");
        exit(1);
    }
    for (int i = 0; i < n; i++) {
        fscanf(file, "%d", &arr[i]);
    }

    fclose(file);
}
int countDuplicates(int arr[], int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    return count;
}
int findMostRepeatingElement(int arr[], int n) {
    int maxCount = 0, mostRepeating = arr[0];
    for (int i = 0; i < n; i++) {
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mostRepeating = arr[i];
        }
    }
    return mostRepeating;
}
int main() {
    int n;
    const char *filename = "input13.txt";
    printf("Enter how many numbers you want to read from file: ");
    scanf("%d", &n);
    int arr[n];
    readArrayFromFile(filename, arr, n);
    printf("The content of the array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    int totalDuplicates = countDuplicates(arr, n);
    printf("Total number of duplicate values = %d\n", totalDuplicates);
    int mostRepeating = findMostRepeatingElement(arr, n);
    printf("The most repeating element in the array = %d\n", mostRepeating);
    return 0;
}