#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int maxx(int a, int b) {

    if (a > b) {

        return a;
    }

    else {

        return b;
    }
}

void input(int* words, int* maxLen) {

    FILE* in = fopen("FILE.txt", "r");
    int st = 0, a = -1;
    char ch = (char)getc(in);

    while (ch != EOF) {

        if (ch == ' ' || ch == '\n') {

            (*words)++;
            *maxLen = maxx(*maxLen, st - a - 1);
            a = st;
        }
        st++;
        ch = (char)getc(in);
    }
    (*words)++;
    *maxLen = maxx(*maxLen, st - a - 1);
    fclose(in);
}

int getLen(char* str) {

    char* p = str;

    while (*p) {

        p++;
    }

    return p - str - 1;
}

int boolEqual(char* a, char* b) {

    int len = getLen(b), i = 0;

    for (; 0 <= len; len--, i++) {

        if (a[i] != b[len]) {

            return 0;
        }
    }
    if (a[i] == '\0') {

        return 1;
    }

    else {
        return 0;
    }
}

void inputWords(char** arr) 
{
        int str = 0;
        FILE* in = fopen("FILE.txt", "r");
        char ch = (char)getc(in);
        int i = 0;

        while (ch != EOF) {

            arr[str][i] = ch;
            i++;
            ch = (char)getc(in);

            if (ch == ' ' || ch == '\n') {

                arr[str][i] = '\0';
                str++;
                i = 0;
                ch = (char)getc(in);
            }
        }
        arr[str][i] = '\0';
        fclose(in); 
}

int main() {

    int words = 0, maxLen = 0;
    input(&words, &maxLen);
    char** arr = (char**)malloc(words * sizeof(char*));

    if (arr == NULL) {

        printf("dont have enough memory");
        return 0;
    }
    int q;
    for (q = 0; q < words; ++q) {

        arr[q] = (char*)malloc(maxLen + 1);
    }
    inputWords(arr);
    int i, j;

    for (i = 0; i < words - 1; ++i) {

        for (j = i + 1; j < words; ++j) {

            if (boolEqual(arr[i], arr[j])) {

                printf("%s %s\n", arr[i], arr[j]);
            }
        }
    }

    for (q = 0; q < words; ++q) {

        free(arr[q]);
    }
    free(arr);
    return 0;
}