#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define MAX_VAL 30000

void findMostFrequent(int arr[], int n) {
    int count[MAX_VAL + 1] = {0};
    int maxCount = 0;

    for (int i = 0; i < n; i++) {
        count[arr[i]]++;
        if (count[arr[i]] > maxCount) {
            maxCount = count[arr[i]];
        }
    }

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] == maxCount) {
            printf("%d ", arr[i]);
            count[arr[i]] = 0; 
        }
    }
    printf("\n");
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int arr[MAX];

        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        findMostFrequent(arr, n);
    }

    return 0;
}

