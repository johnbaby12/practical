#include <stdio.h>

void main() {
    int n, i, j, temp;
    int salary[100];

    printf("Enter the number of employees: ");
    scanf("%d", &n);

    printf("Enter the salaries:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &salary[i]);
    }

    // Bubble Sort Algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (salary[j] > salary[j + 1]) {
                temp = salary[j];
                salary[j] = salary[j + 1];
                salary[j + 1] = temp;
            }
        }
    }

    printf("Salaries in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("%d\n", salary[i]);
    }getch();
}
