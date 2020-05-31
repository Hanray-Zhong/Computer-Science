#include <stdio.h>
#include <stdlib.h>
void main() {
    int v_1[300];
    int v_2[300];
    int v_3[300];
    char c_1[300];
    char c_2[300];
    int results[300];
    int result;
    for (int i = 0; i < 300; i++) {
        v_1[i] = rand() % 101;
        v_2[i] = rand() % 101;
        v_3[i] = rand() % 101;
        int j = rand() % 16;
        switch (j)
        {
        case 0: result = v_1[i] + v_2[i] + v_3[i];
                c_1[i] = '+';
                c_2[i] = '+'；
                break;
        case 1: result = v_1[i] + v_2[i] - v_3[i];
                c_1[i] = '+';
                c_2[i] = '-'；
                break;
        case 2: result = v_1[i] + v_2[i] * v_3[i];
                c_1[i] = '+';
                c_2[i] = '*'；
                break;
        case 3: result = v_1[i] + v_2[i] / v_3[i];
                c_1[i] = '+';
                c_2[i] = '/'；
                break;
        case 4: result = v_1[i] - v_2[i] + v_3[i];
                c_1[i] = '-';
                c_2[i] = '+'；
                break;
        case 5: result = v_1[i] - v_2[i] - v_3[i];
                c_1[i] = '-';
                c_2[i] = '-'；
                break;
        case 6: result = v_1[i] - v_2[i] * v_3[i];
                c_1[i] = '-';
                c_2[i] = '*'；
                break;
        case 7: result = v_1[i] - v_2[i] / v_3[i];
                c_1[i] = '-';
                c_2[i] = '/'；
                break;
        case 8: result = v_1[i] * v_2[i] + v_3[i];
                c_1[i] = '*';
                c_2[i] = '+'；
                break;
        case 9: result = v_1[i] * v_2[i] - v_3[i];
                c_1[i] = '*';
                c_2[i] = '-'；
                break;
        case 10: result = v_1[i] * v_2[i] * v_3[i];
                c_1[i] = '*';
                c_2[i] = '*'；
                break;
        case 11: result = v_1[i] * v_2[i] / v_3[i];
                c_1[i] = '*';
                c_2[i] = '/'；
                break;
        case 12: result = v_1[i] / v_2[i] + v_3[i];
                c_1[i] = '/';
                c_2[i] = '+'；
                break;
        case 13: result = v_1[i] / v_2[i] - v_3[i];
                c_1[i] = '/';
                c_2[i] = '-'；
                break;
        case 14: result = v_1[i] / v_2[i] * v_3[i];
                c_1[i] = '/';
                c_2[i] = '*'；
                break;
        case 15: result = v_1[i] / v_2[i] / v_3[i];
                c_1[i] = '/';
                c_2[i] = '/'；
                break;
        default:
                break;
        }
        if (result > 100 || result <0) {
            i--;
            continue;
        }
        results[i] = result;
    }
    for (int i = 0; i < 300; i++) {
        printf ("%d : %d %c %d %c %d = %d\n", i + 1, v_1[i], c_1[i], v_2[i], c_2[i], v_3[i], results[i]);
    }
    return;
}