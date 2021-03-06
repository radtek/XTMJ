#include "Work.h"
#include "BaseCommonFunc.h"

#if _LINUX
#include "../LBase/Func.h"
#include <unistd.h>
#else
#include "MiniDump.h"
#endif

int main(int argc, char *argv[])
{
#if _LINUX
	char strCurPath[512] = {0};
	getcwd(strCurPath, 512);
	chdir(strCurPath);
	SetCoreFileUnlimit();
	SetSockFileSize(0);
	if(argc == 1) daemonize(strCurPath);
	char* exeName = strrchr(argv[0], '/');
	exeName = exeName ? exeName+1 : argv[0];
	int nRet = WriteProcessPID(strCurPath, exeName);
	if(nRet < 0) exit(0);
#else
	MiniDumper minDump(true);
	disableConsoleCloseButton();
#endif

	gWork.Init();
	gWork.Start();
	gWork.Join();
	return 0;
}