#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

bool subset[MAX_SIZE];
int set[MAX_SIZE];
int n;
int targetSum;

void printSubset() {
    printf("{ ");
    for (int i = 0; i < n; i++) {
        if (subset[i]) {
            printf("%d ", set[i]);
        }
    }
    printf("}\n");
}

void subsetSum(int index, int currentSum) {
    if (currentSum == targetSum) {
        printSubset();
        return;
    }

    if (index == n || currentSum > targetSum) {
        return;
    }
    subset[index] = true;
    subsetSum(index + 1, currentSum + set[index]);
    subset[index] = false;
    subsetSum(index + 1, currentSum);
}

int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);

    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }

    printf("Enter the target sum: ");
    scanf("%d", &targetSum);

    printf("Subsets with sum equal to %d are:\n", targetSum);
    subsetSum(0, 0);

    return 0;
}
