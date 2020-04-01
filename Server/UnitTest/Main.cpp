#include <iostream>
#include "Tests/Include.h"



int main(int argc, char* argv[])
{
	Solution* sln = new Test_redis();
	sln->Excute();
	printf("\n³ÌĞò¼´½«ÖÕÖ¹!\n");
	Sleep(5000);
	return 0;
}
