#include <stdio.h>

int main() {
    int L, K;
    scanf("%d %d", &L, &K);

    if (K == 0) {
        // If there are no ones, the longest block of zeros is the entire string
        printf("%d\n", L);
    } else if (K >= L) {
        // If the number of ones is equal to or greater than the length of the string
        printf("0\n");
    } else {
        // Calculate the maximum length of consecutive zeros
        int max_zeros = (L - K) / (K + 1);
        if ((L - K) % (K + 1) != 0) {
            max_zeros++;
        }
        printf("%d\n", max_zeros);
    }

    return 0;
}
