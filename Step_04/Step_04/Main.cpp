#include <stdio.h>
#include <stdlib.h>


/*******************************
	** [���]

	1. �б⹮
	
	2. �ݺ���

******************************/



int main(void)
{  
		int iAge = 0;
		printf_s("���̸� �Է��ϼ���: ");
		scanf_s("%d", &iAge);


		printf_s("����� ���̴� [%d] �Դϴ�. \n", iAge);

		/*************************************************

			** ����)
			* Ű�� �����Ը� �Է��Ͽ� �� ������ Ȯ���ϴ� 
			     ���α׷��� �ۼ��Ͻÿ�.

			* Tip.
				
				
				* Ű(cm) /= 100; [���ͷ� ��ȯ]
				* ������(BMI) = ������ (kg) / ( Ű(cm) * Ű(cm))

				* float ���� double ���� Ȯ���Ͽ� �ۼ�.

				* 18.5���� ������ ��ü��.
				* 18.5 ���� ũ�� 22.99 ���� ������ ����.
				* 23.00 ���� ũ�� 24.99 ���� ������ ��ü��.
				* 25.00 ���� ũ�� 29.99 ���� ������ ��.
				* 30.00 ���� ũ�� ���� ��.

		
			
		*************************************************/
		

		float fHeight = 0;
		printf_s("����� Ű�� �Է��ϼ���: ");
		scanf_s("%f", &fHeight);

		printf_s("����� Ű�� [%f] �Դϴ�.\n", fHeight);

		float fWidth = 0;
		printf_s("����� �����Ը� �Է��ϼ���: ");
		scanf_s("%f", &fWidth);


		printf_s("����� �����Դ� [%f] �Դϴ�. \n", fWidth);
		
		
		fHeight /= 100;
		float fBMI = 0;
		fBMI = fWidth / (fHeight*fHeight);

		

		if (fBMI < 18.5f)
		{ 
			printf_s("����� ��ü�� �Դϴ�.");
		}
			

		else if (fBMI > 18.5f && fBMI < 22.99f)
		{
			printf_s("����� ���� ü�� �Դϴ�.");
		}
		else if (fBMI > 23.00f && fBMI < 24.99f)
		{
			printf_s("����� ��ü�� �Դϴ�.");
		}
		else if (fBMI > 25.00f && fBMI < 29.99f)
		{
			printf_s("����� �� �Դϴ�.");
		}

		else if (fBMI > 30.00f)
		{
			printf_s("����� ������ �Դϴ�.");
		}


		
	system("pause");
	return 0;

}