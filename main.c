// Лабораторная работа номер 2 Нарюков Дмитрий 3824Б1ПР3

#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <stdlib.h>

int zadanie1() {
    int resjum, count = 1;
    srand(time(NULL));
    printf("Приветствуем вас в игре «Угадай число»\nВыберите режим(1-2):\n1) Программа загадывает число\n2) Вы загадываете число\n");
    scanf("%d", &resjum);

    if (resjum == 1) {
        int random = 1 + rand()%1000;
        int res = 0;
        printf("Программа выбрала случайное число, попытайтесь его удагать:\n");
        while (1) {
            scanf("%d", &res);
            if (res == random) {
                printf("\nВы угадали число! Поздравляем!\nВы угадали с %d попытки!", count);
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
    } else if (resjum == 2) {
        int random, randomBot, niz = 1, verh = 1000; count = 1;
        char vubor[1];
        printf("Введите число от 1 до 1000, которое программа будет угадывать:");
        scanf("%d", &random);
        randomBot = 1 + rand()%1000;
        printf("Программа выбрала число = %d. Выберите > < =?\n", randomBot);
        scanf("%s", vubor);
        while (1) {
            if (vubor[0] == '>') {
                verh = randomBot;
                count++;
                randomBot = niz + rand()%(verh - niz + 1);
                printf("Программа выбрала число = %d. Выберите > < =?\n", randomBot);
                scanf("%s", vubor);
            } else if (vubor[0] == '<') {
                niz = randomBot;
                count++;
                randomBot = niz + rand()%(verh - niz + 1);
                printf("Программа выбрала число = %d. Выберите > < =?\n", randomBot);
                scanf("%s", vubor);
            } else if (vubor[0] == '=') {
                printf("\nПрограмма угадала число! Потрачено попыток = %d", count);
                break;
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