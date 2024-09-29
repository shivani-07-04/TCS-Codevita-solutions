#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>

// Function to find the nearest good letter
char findNearestGoodLetter(char c, const char *goodString, char prevGoodLetter) {
    int minDistance = INT_MAX;
    char nearestGoodLetter = prevGoodLetter;
    for (int i = 0; goodString[i] != '\0'; i++) {
        int distance = abs(c - goodString[i]);
        if (distance < minDistance) {
            minDistance = distance;
            nearestGoodLetter = goodString[i];
        } else if (distance == minDistance) {
            // If distances are equal, choose the one nearest to the previous good letter
            if (abs(prevGoodLetter - goodString[i]) < abs(prevGoodLetter - nearestGoodLetter)) {
                nearestGoodLetter = goodString[i];
            }
        }
    }
    return nearestGoodLetter;
}

int calculateTotalDistance(const char *goodString, const char *name) {
    int totalDistance = 0;
    char prevGoodLetter = goodString[0]; // Initially, previous good letter is the first letter of good string

    for (int i = 0; name[i] != '\0'; i++) {
        if (strchr(goodString, name[i]) == NULL) {
            char nearestGoodLetter = findNearestGoodLetter(name[i], goodString, prevGoodLetter);
            totalDistance += abs(name[i] - nearestGoodLetter);
            prevGoodLetter = nearestGoodLetter;
        }
    }
    return totalDistance;
}

int main() {
    char goodString[101];
    char name[10001];

    printf("Enter the good string: ");
    fgets(goodString, sizeof(goodString), stdin);
    goodString[strcspn(goodString, "\n")] = '\0'; // Remove newline character

    printf("Enter the name: ");
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = '\0'; // Remove newline character

    int totalDistance = calculateTotalDistance(goodString, name);
    printf("Total distance: %d\n", totalDistance);

    return 0;
}
