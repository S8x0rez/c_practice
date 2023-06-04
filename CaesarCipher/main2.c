#include<stdio.h>

int main(void)
{
	char alph[] = "abcdefghijklmnopqrstuvwxyzABEDEFGHIJKLMNOPQRSTUVWXYZ";
	char sent_bef[81], sent_aft[81];
	char *p_in, *p_out, *p_alph;
	int slide, i, j, m;

	printf("-----------------英字の暗号化-------------\n");
	printf("英文を入力してください\n");
	gets_s(sent_bef);
	printf("スライドする文字数を入力してください--->");
	scanf_s("%d", &slide);
	printf("---------------暗号化後の文字列-----------\n");
	printf("\n");

	p_in = sent_bef;
	p_out = sent_aft;
	p_alph = alph;

	for (i = 0; *(p_in+i) != '\0'; i++)
	{
		*(p_out + i) = *(p_in + i);
		for (j = 0; j < 52; j++)
		{
			if (*(p_in + i) == *(p_alph + j))
			{
				m = j + slide;
				if (m >= 52)
					m -= 52;
				*(p_out + i) = *(p_alph + m); break;
			}
		}
	}
	*(p_out + i) = '\0';

	printf("%s\n", sent_aft);

	return 0;
}
