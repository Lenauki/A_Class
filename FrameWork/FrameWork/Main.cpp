#include"MainUpdate.h"




int main(void)
{

	MainUpdate Main;
	Main.Initalize();

	while (true)
	{
		system("cls");
		Main.Progress();
		system("pause");
	}
	system("pause");

	return 0;
}