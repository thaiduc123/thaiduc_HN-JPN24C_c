#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

#define MAX 100000

bool isNonDecreasing(char *str) {
    int len = strlen(str);
    for (int i = 1; i < len; i++) {
        if (str[i] < str[i - 1]) {
            return false;
        }
    }
    return true;
}

int main() {
    char input[MAX];
    fgets(input, MAX, stdin);

    char *token = strtok(input, " \n");
    int counts[MAX] = {0};
    char numbers[MAX][10];
    int numCount = 0;

    while (token != NULL) {
        if (isNonDecreasing(token)) {
            int found = -1;
            for (int i = 0; i < numCount; i++) {
                if (strcmp(numbers[i], token) == 0) {
                    found = i;
                    break;
                }
            }
            if (found != -1) {
                counts[found]++;
            } else {
                strcpy(numbers[numCount], token);
                counts[numCount] = 1;
                numCount++;
            }
        }
        token = strtok(NULL, " \n");
    }

    for (int i = 0; i < numCount - 1; i++) {
        for (int j = i + 1; j < numCount; j++) {
            if (counts[i] < counts[j] || (counts[i] == counts[j] && strcmp(numbers[i], numbers[j]) > 0)) {
                int tempCount = counts[i];
                counts[i] = counts[j];
                counts[j] = tempCount;

                char tempStr[10];
                strcpy(tempStr, numbers[i]);
                strcpy(numbers[i], numbers[j]);
                strcpy(numbers[j], tempStr);
            }
        }
    }

    for (int i = 0; i < numCount; i++) {
        printf("%s %d\n", numbers[i], counts[i]);
    }

    return 0;
}

