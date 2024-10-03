// Лабораторная работа номер 2 Нарюков Дмитрий 3824Б1ПР3

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int zadanie1() {
    int rezjum, count = 1;
    srand(time(NULL));
    printf("Приветствуем вас в игре «Угадай число»\nВыберите режим(1-2):\n1) Программа загадывает число\n2) Вы загадываете число\n");
    scanf("%d", &rezjum);

    if (rezjum == 1) {
        int random = 1 + rand()%1000;
        int res = 0;
        printf("Программа выбрала случайное число, попытайтесь его удагать:\n");
        while (1) {
            scanf("%d", &res);
            if (res == random) {
                printf("Вы угадали число! Поздравляем!\nВы угадали с %d попытки!", count);
                break;
            } else {
                if (res > random) {
                    printf("Вы ввели число большее, чем рандомное\nПовторите ввод:");
                    count++;
                } else if (res < random) {
                    printf("Вы ввели число меньшее, чем рандомное\nПовторите ввод:");
                    count++;
                }
            }
        }
    }
}



int main() {
    SetConsoleOutputCP(CP_UTF8);
    int number;
    printf("Введите номер задачи(1-2):");
    scanf("%d", &number);

    switch(number) {
        case 1: zadanie1(); break;
    }
}