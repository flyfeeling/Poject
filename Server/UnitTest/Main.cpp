#include <iostream>
#include "Tests/Include.h"



int main(int argc, char* argv[])
{
	Solution* sln = new Test_redis();
	sln->Excute();
	printf("\n���򼴽���ֹ!\n");
	Sleep(5000);
	return 0;
}
