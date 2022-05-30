#include <stdio.h>

#define SIZE 10
#define TRUE 1

int main(void)
{
    int initialAveragedOver, finalAveragedOver, numberOfValues = 0;
    int OLD = 0, NEW = 0;
    int values[SIZE] = {};
    int sum = 0;
    int firstnum = 0;
    float average = 0.0;

    printf("Enter the number of values to be averaged over (N): ");
    scanf("%d", &initialAveragedOver);

    while (TRUE) {
        printf("Enter a value: ");
        scanf("%d", &values[NEW]);
        numberOfValues++;

        if (numberOfValues > initialAveragedOver) {firstnum = values[OLD]; OLD++;}
        OLD = OLD % SIZE;

        sum = sum - firstnum + values[NEW];
        NEW++;
        NEW = NEW % SIZE;

        printf("Buffer contents: ");
        for (int i = 0; i < SIZE; i++) printf("%d  ", values[i]);

        if (numberOfValues < initialAveragedOver) finalAveragedOver = numberOfValues;
        else finalAveragedOver = initialAveragedOver;

        average = (float) sum / finalAveragedOver;
        printf("\nNumber of values entered: %d    Average over: %d    Average: %.2f\n\n", numberOfValues, finalAveragedOver, average);
    }
    return 0;
}