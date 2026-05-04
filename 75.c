#include <stdio.h>

#define MAX 1000

int main() {
    int arr[MAX], n = 0;

    while (scanf("%d", &arr[n]) == 1) {
        n++;
    }

    int max_len = 0;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0) {
                if (j - i + 1 > max_len) {
                    max_len = j - i + 1;
                }
            }
        }
    }

    printf("%d", max_len);

    return 0;
}
