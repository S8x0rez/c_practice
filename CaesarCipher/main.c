#include<stdio.h>

int main(void)
{
	char alph[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!";
	char sent_bef[81], sent_aft[81];
	int shift, i, j, m;

	printf("-----------------英字の暗号化-------------\n");
	printf("英文を入力してください\n");
	gets_s(sent_bef);
	printf("---------------暗号化後の文字列-----------\n");
	printf("\n");

	for (shift = 1; shift < 27; shift++){
		for (i = 0; sent_bef[i] != '\0'; i++)
		{
			sent_aft[i] = sent_bef[i];
			for (j = 0; j < 27; j++)
			{
				if (sent_bef[i] == alph[j])
				{
					m = j - shift;
					if (m < 0)
						m += 27;
					sent_aft[i] = alph[m]; break;
				}
			}
		}
		sent_aft[i] = '\0';

		printf("%s\n", sent_aft);
	}

return 0;
}
