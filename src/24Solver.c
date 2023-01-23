#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define TARGET 24


int get_card_value(char card[]) {
    if (strcmp(card, "j") == 0) return 11;
    else if (strcmp(card, "J") == 0) return 11;
    else if (strcmp(card, "q") == 0) return 12;
    else if (strcmp(card, "Q") == 0) return 12;
    else if (strcmp(card, "k") == 0) return 13;
    else if (strcmp(card, "K") == 0) return 13;
    else if (strcmp(card, "A") == 0) return 1;
    else if (strcmp(card, "a") == 0) return 1;
    else return atoi(card);
}

void check_equation(int a, int b, int c, int d) {
    int nums[] = {a, b, c, d};
    int i, j, k, l, cnt=0;
    char ops[] = {'+', '-', '*', '/'};
    clock_t start_time = clock();

    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == i) continue;
            for (k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                l = 6 - i - j - k;
                int num1 = nums[i];
                int num2 = nums[j];
                int num3 = nums[k];
                int num4 = nums[l];

                for (int op1 = 0; op1 < 4; op1++) {
                    for (int op2 = 0; op2 < 4; op2++) {
                        for (int op3 = 0; op3 < 4; op3++) {
                            int result = num1;
                            if (op1 == 0) result += num2;
                            else if (op1 == 1) result -= num2;
                            else if (op1 == 2) result *= num2;
                            else if (op1 == 3) {
                                if (num2 != 0) result /= num2;
                                else continue;
                            }

                            if (op2 == 0) result += num3;
                            else if (op2 == 1) result -= num3;
                            else if (op2 == 2) result *= num3;
                            else if (op2 == 3) {
                            if (num3 != 0) result /= num3;
                            else continue;
                            }
                        if (op3 == 0) result += num4;
                        else if (op3 == 1) result -= num4;
                        else if (op3 == 2) result *= num4;
                        else if (op3 == 3) {
                            if (num4 != 0) result /= num4;
                            else continue;
                        }

                        if (result == TARGET) {
                            printf("((%d %c %d) %c %d) %c %d = %d\n", num1, ops[op1], num2, ops[op2], num3, ops[op3], num4, TARGET);
                            cnt++;
                        }
                    }
                }
            }
        }
    }
}
    if (cnt == 0) printf("No solution found.\n");
    else printf("Total solutions: %d\n", cnt);
    clock_t end_time = clock();
    double time_used = (double)(end_time - start_time) / CLOCKS_PER_SEC;
    printf("Time used: %f seconds\n", time_used);
    printf("Do you want to save the solution to a text file? (y/n): ");
    char save;
    scanf(" %c", &save);
        if (save == 'y') {
            FILE *fp;
            fp = fopen("../test/24_solution.txt", "w");
            if (fp == NULL) {
                printf("Error opening file!\n");
                exit(1);
            }

            for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            if (j == i) continue;
            for (k = 0; k < 4; k++) {
                if (k == i || k == j) continue;
                l = 6 - i - j - k;
                int num1 = nums[i];
                int num2 = nums[j];
                int num3 = nums[k];
                int num4 = nums[l];

                for (int op1 = 0; op1 < 4; op1++) {
                    for (int op2 = 0; op2 < 4; op2++) {
                        for (int op3 = 0; op3 < 4; op3++) {
                            int result = num1;
                            if (op1 == 0) result += num2;
                            else if (op1 == 1) result -= num2;
                            else if (op1 == 2) result *= num2;
                            else if (op1 == 3) {
                                if (num2 != 0) result /= num2;
                                else continue;
                            }

                            if (op2 == 0) result += num3;
                            else if (op2 == 1) result -= num3;
                            else if (op2 == 2) result *= num3;
                            else if (op2 == 3) {
                            if (num3 != 0) result /= num3;
                            else continue;
                            }
                        if (op3 == 0) result += num4;
                        else if (op3 == 1) result -= num4;
                        else if (op3 == 2) result *= num4;
                        else if (op3 == 3) {
                            if (num4 != 0) result /= num4;
                            else continue;
                        }

                        if (result == TARGET) {
                            fprintf(fp,"((%d %c %d) %c %d) %c %d = %d\n", num1, ops[op1], num2, ops[op2], num3, ops[op3], num4, TARGET);
                        }
                    }
                }
            }
        }
    }
}
            fprintf(fp, "Total solutions: %d\n", cnt);
            fprintf(fp, "Time used: %f seconds\n", time_used);
            fclose(fp);
            printf("Solution saved to 24_solution.txt\n");
        } else if (save == 'n') {
            printf("Solution not saved\n");
        } else {
            printf("Invalid input\n");
        }
    }


void splash(){
printf("\n");
printf("\n");
printf("██████  ██   ██     ███████  ██████  ██      ██    ██ ███████ ██████  \n");
printf("     ██ ██   ██     ██      ██    ██ ██      ██    ██ ██      ██   ██ \n");
printf(" █████  ███████     ███████ ██    ██ ██      ██    ██ █████   ██████  \n");
printf("██           ██          ██ ██    ██ ██       ██  ██  ██      ██   ██ \n");
printf("███████      ██     ███████  ██████  ███████   ████   ███████ ██   ██ \n");
printf("\n");
printf("\n");
}


int main() {
    splash();
    int a, b, c, d, temp;
    char at, bt, ct, dt;
    srand(time(NULL));
    printf("choose your input\n");
    printf("1. input from keyboard\n");
    printf("2. random\n");
    printf("input: ");
    scanf("%d", &temp);
    printf("\n");
    if (temp == 1) {
        char card1[10], card2[10], card3[10], card4[10];
        printf("Enter four cards: ");
        scanf("%s %s %s %s", card1, card2, card3, card4);
        int a = get_card_value(card1);
        int b = get_card_value(card2);
        int c = get_card_value(card3);
        int d = get_card_value(card4);
        check_equation(a, b, c, d);
    } else if (temp == 2) {
        a = rand() % 13+1;
        b = rand() % 13+1;
        c = rand() % 13+1;
        d = rand() % 13+1;
        check_equation(a, b, c, d);
    } else {
        printf("invalid input");
        return 0;
    }
    return 0;
}
