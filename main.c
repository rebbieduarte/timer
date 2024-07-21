#include <stdio.h>
#include <stdlib.h>  // Para a função exit
#include <unistd.h>  // Para a função sleep

int main() {
    int hour, minute, second;
    int d = 1000; // delay de 1000 milissegundos que usaremos na função sleep

    printf("Set time (formato hh:mm:ss): \n");
    scanf("%d:%d:%d", &hour, &minute, &second);

    if (hour > 12 || minute >= 60 || second >= 60) {
        printf("ERROR! Hora, minuto ou segundo fora do intervalo permitido.\n");
        exit(0);
    }

    while (1) {
      // Limpar o console
        system("cls");

        second++;
        if (second > 59) {
            second = 0;
            minute++;
            if (minute > 59) {
                minute = 0;
                hour++;
                if (hour > 12) {
                    hour = 1;  // Voltar para 1 depois de 12 (formato 12 horas)
                }
            }
        }

        printf("CLOCK: \n");
        printf("%02d : %02d : %02d", hour, minute, second);

    
        sleep(1); // conta os segundos

    }

    return 0;
}
