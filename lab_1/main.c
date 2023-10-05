//Заполнить массив вещественными числами с клавиатуры. Заменить все
// элементы на их квадраты. Вывести массив до и после преобразования.
// Дурко
// 05.04.2023

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10 // Максимальный размер массива

int main() {
    char repeat; // Переменная для запроса повторения задачи

    do {
        float arr[MAX_SIZE]; // Объявление массива с плавающей точкой
        int n; // Переменная для количества элементов

        // Буфер для хранения пользовательского ввода, если его не использовать, 
        // то при неверном вводе произойдет зацикливание
        char buffer[100];

        // Запрос количества элементов у пользователя
        do {
            printf("Введите количество элементов (не более %d): ", MAX_SIZE);
            fgets(buffer, sizeof(buffer), stdin); // Считываем строку из входного потока

            // Проверяем, что введено число в диапазоне 2..MAX_SIZE
            if (sscanf(buffer, "%d", &n) != 1 || n <= 0 || n > MAX_SIZE) { 
                printf("Неверный ввод. Пожалуйста, введите число от 1 до %d.\n", MAX_SIZE);
            }
        } while (n <= 0 || n > MAX_SIZE);

        // Заполнение массива элементами
        for (int i = 0; i < n; i++) {
            do {
                printf("Введите элемент %d: ", i+1);
                fgets(buffer, sizeof(buffer), stdin); // Считываем строку из входного потока
                if (sscanf(buffer, "%f", &arr[i]) != 1) {
                    printf("Неверный ввод. Пожалуйста, введите вещественное число.\n");
                }
            } while (arr[i] <= 0);
        }

        // Вывод массива до преобразования
        printf("\nМассив до преобразования:\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", arr[i]);
        }

        // Преобразование элементов массива в квадраты
        for (int i = 0; i < n; i++) {
            arr[i] = arr[i] * arr[i];
        }

        // Вывод массива после преобразования
        printf("\n\nМассив после преобразования:\n");
        for (int i = 0; i < n; i++) {
            printf("%f ", arr[i]);
        }

        // Запрос на повторение задачи
        printf("\n\nХотите выполнить еще раз? (y/n): ");
        fgets(buffer, sizeof(buffer), stdin); // Получаем пользовательский ввод
        sscanf(buffer, " %c", &repeat);  // Преобразуем в символ, игнорируя символ новой строки

    } while (repeat == 'y' || repeat == 'Y'); // Повторять, если ответ 'y' или 'Y'

    return 0;
}
