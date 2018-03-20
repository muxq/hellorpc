// hellorpc_s.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "hello.h"

void HelloProc(unsigned char * pszString)
{
	printf("%s\n", pszString);
}

void Shutdown(void)
{
	RPC_STATUS status;
	status = RpcMgmtStopServerListening(NULL);
	if (status) {
		exit(status);
	}
	status = RpcServerUnregisterIf(NULL, NULL, FALSE);
	if (status) {
		exit(status);
	}
}


int _tmain(int argc, _TCHAR* argv[])
{
	RPC_STATUS status;
	unsigned int   cMinCalls           = 1;
	unsigned int    cMaxCalls           = 20;
	status = RpcServerUseProtseqEp((unsigned char *)PROTOCOL_SEQUENCE, 20, (unsigned char *)END_POINT, NULL);  // Security descriptor
	if(status) {
		exit(GetLastError());
	}
	status = RpcServerRegisterIf(hello_v1_0_s_ifspec, NULL, NULL); 
	if(status) {
		exit(GetLastError());
	}
	status = RpcServerListen(1, 20, FALSE);
	if(status) {
		exit(GetLastError());
	}
	getchar();
	return 0;
}

/*********************************************************************/
/*                MIDL allocate and free                             */
/*********************************************************************/

void __RPC_FAR * __RPC_USER midl_user_allocate(size_t len)
{
	return(malloc(len));
}

void __RPC_USER midl_user_free(void __RPC_FAR * ptr)
{
	free(ptr);
}