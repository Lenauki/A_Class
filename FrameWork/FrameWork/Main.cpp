#include"MainUpdate.h"




int main(void)
{

	MainUpdate Main;
	Main.Initalize();

	while (true)
	{
		system("pause");
		Main.Progress();
		Main.Render();

	}


	return 0;
}