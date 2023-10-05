// Дан двумерный массив ненулевых целых чисел. Определить, сколько
// раз элементы массива меняют знак (принимая, что массив
// просматривается построчно сверху вниз, а в каждой строке - слева
// направо). Смену знака при переходе на новую строку также учитывать.
// Дурко
// 05.04.2023

#include <stdio.h>

#define ROWS 3
#define COLS 4

int main() {
    int arr[ROWS][COLS] = {{1, -2, 3, -4}, {5, 6, -7, 8}, {-9, -10, 11, 12}};
    int sign_changes = 0;

    printf("Array to check:\n");

    // Выводим проверяемый массив
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", arr[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Проверяем смену знака с предыдущим элементом в строке
            if (j > 0 && ((arr[i][j] > 0 && arr[i][j-1] < 0) || (arr[i][j] < 0 && arr[i][j-1] > 0))) {
                sign_changes++;
            }
            // Проверяем смену знака с первым элементом в новой строке
            if (j == 0 && i > 0 && ((arr[i][j] > 0 && arr[i-1][COLS-1] < 0) || (arr[i][j] < 0 && arr[i-1][COLS-1] > 0))) {
                sign_changes++;
            }
        }
    }

    printf("Sign changes count: %d\n", sign_changes);

    return 0;
}
