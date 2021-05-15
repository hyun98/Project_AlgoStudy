#include<stdio.h>
int main() {
	char str[1000000];
	int cnt=0;
	int len;
	
	scanf("%s", &str); //문자열 입력
	len = strlen(str); //문자열의 길이

	for (int i = 0; i < len; i++) 
	{
		if (str[i] == 'P') 
		{
			//P일 때 cnt값 증가
			cnt++; 
		}

		if (str[i] == 'A') 
		{
			if (cnt>=2 && str[i + 1] == 'P') 
			{
				//P의 개수가 2개 이상이고 i+1번째가 P일 때
				//PPAP가 되므로 P로 치환 가능 == cnt값을 하나 감소
				cnt--;

				//i+1번째 값이 P이므로 i+1
				i++;
			}
			else
			{
				//PPAP가 아닐 경우
				printf("NP\n");
			}
		}
	}


	if (cnt == 1) 
	{
		//PPAP가 될 경우 
		printf("PPAP\n"); 
	}
	else 
	{
		//PPAP가 아닐 경우
		printf("NP\n");
	} 

	return 0;
}