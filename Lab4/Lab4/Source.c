#define _CRT_SECURE_NO_WARNINGS
#define LONG_STR 100
#define MAX_WORD 50
#include <string.h>
#include <stdio.h>

void main()
{
	int strNum, i, j, res = 0, cnt = 0;
	char text[10][LONG_STR];
	char* word[MAX_WORD], * ptr, separator[] = " ,.?!;:";

	do {

		rewind(stdin);
		printf("%s", "How many strings?\nstrings : ");
		res = scanf_s("%d", &strNum);

		if (res == 1)
		{
			rewind(stdin);
			
			for (i = 0; i < strNum; i++) {

				printf("%s%d%s", "String ", (i + 1), " is:");
				gets(text[i]);
			}

			for (i = 0; i < strNum; i++) {

				ptr = strtok(text[i], separator);

				while (ptr) {

					word[cnt++] = ptr;
					ptr = strtok(NULL, separator);

				}

			}

			for (i = 0; i < cnt; i++) {

				for (j = i + 1; j < cnt; j++) {

					if (strlen(word[i]) > strlen(word[j])) {

						char* tmp = word[i];
						word[i] = word[j];
						word[j] = tmp;

					}
				}
			}
			printf("\n%s", "Sorting : ");

			for (i = 0; i < cnt; i++)
				printf("%s ", word[i]);

		}

	} 

	while (res <= 0);
}