#include<stdio.h>
int main() {
	char str[1000000];
	int cnt=0;
	int len;
	
	scanf("%s", &str); //���ڿ� �Է�
	len = strlen(str); //���ڿ��� ����

	for (int i = 0; i < len; i++) 
	{
		if (str[i] == 'P') 
		{
			//P�� �� cnt�� ����
			cnt++; 
		}

		if (str[i] == 'A') 
		{
			if (cnt>=2 && str[i + 1] == 'P') 
			{
				//P�� ������ 2�� �̻��̰� i+1��°�� P�� ��
				//PPAP�� �ǹǷ� P�� ġȯ ���� == cnt���� �ϳ� ����
				cnt--;

				//i+1��° ���� P�̹Ƿ� i+1
				i++;
			}
			else
			{
				//PPAP�� �ƴ� ���
				printf("NP\n");
			}
		}
	}


	if (cnt == 1) 
	{
		//PPAP�� �� ��� 
		printf("PPAP\n"); 
	}
	else 
	{
		//PPAP�� �ƴ� ���
		printf("NP\n");
	} 

	return 0;
}