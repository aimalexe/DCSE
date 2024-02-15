#include <stdio.h>
#include <stdlib.h>

int* fib(int terms) {
    int *sequence = (int*)malloc(terms * sizeof(int));

    if (sequence == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(1);
    }

    int first = 0, second = 1, next;

    for (int i = 0; i < terms; i++) {
        sequence[i] = first;
        next = first + second;
        first = second;
        second = next;
    }
    return sequence;
}

int main() {
    int terms = 10;
    int *s = fib(terms);

    for (int i = 0; i < terms; i++)
        printf("%d, ", s[i]);

    // Free the dynamically allocated memory
    free(s);

    return 0;
}
