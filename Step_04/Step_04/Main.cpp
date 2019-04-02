#include <stdio.h>
#include <stdlib.h>


/*******************************
	** [제어문]

	1. 분기문
	
	2. 반복문

******************************/



int main(void)
{  
		int iAge = 0;
		printf_s("나이를 입력하세요: ");
		scanf_s("%d", &iAge);


		printf_s("당신의 나이는 [%d] 입니다. \n", iAge);

		/*************************************************

			** 예제)
			* 키와 몸무게를 입력하여 비만 지수를 확인하는 
			     프로그램을 작성하시오.

			* Tip.
				
				
				* 키(cm) /= 100; [미터로 변환]
				* 비만지수(BMI) = 몸무게 (kg) / ( 키(cm) * 키(cm))

				* float 형과 double 형을 확인하여 작성.

				* 18.5보다 작으면 저체중.
				* 18.5 보다 크고 22.99 보다 작으면 정상.
				* 23.00 보다 크고 24.99 보다 작으면 과체중.
				* 25.00 보다 크고 29.99 보다 작으면 비만.
				* 30.00 보다 크면 고도 비만.

		
			
		*************************************************/
		

		float fHeight = 0;
		printf_s("당신의 키를 입력하세요: ");
		scanf_s("%f", &fHeight);

		printf_s("당신의 키는 [%f] 입니다.\n", fHeight);

		float fWidth = 0;
		printf_s("당신의 몸무게를 입력하세요: ");
		scanf_s("%f", &fWidth);


		printf_s("당신의 몸무게는 [%f] 입니다. \n", fWidth);
		
		
		fHeight /= 100;
		float fBMI = 0;
		fBMI = fWidth / (fHeight*fHeight);

		

		if (fBMI < 18.5f)
		{ 
			printf_s("당신은 저체중 입니다.");
		}
			

		else if (fBMI > 18.5f && fBMI < 22.99f)
		{
			printf_s("당신은 정상 체중 입니다.");
		}
		else if (fBMI > 23.00f && fBMI < 24.99f)
		{
			printf_s("당신은 과체중 입니다.");
		}
		else if (fBMI > 25.00f && fBMI < 29.99f)
		{
			printf_s("당신은 비만 입니다.");
		}

		else if (fBMI > 30.00f)
		{
			printf_s("당신은 고도비만 입니다.");
		}


		
	system("pause");
	return 0;

}