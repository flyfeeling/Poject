// Server.cpp: 定义应用程序的入口点。
//
#include <iostream>
#include "CrashReport.h"
#include "GameService.h"

int main(int argc, char* argv[])
{
	SetCrashReport("AIServer");
	if (!CGameService::GetInstancePtr()->Init())
	{
		return 0;
	}

	CGameService::GetInstancePtr()->Run();

	CGameService::GetInstancePtr()->Uninit();
	UnSetCrashReport();
	return 0;
}
