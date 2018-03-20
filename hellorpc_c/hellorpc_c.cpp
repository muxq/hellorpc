// hellorpc_c.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "hello.h"

int _tmain(int argc, _TCHAR* argv[])
{
	RPC_STATUS status;
	unsigned char *pszString = (unsigned char *)"Hello World!\0";
	unsigned char *pszBindStr = NULL;
	status = RpcStringBindingCompose(NULL, (unsigned char *)PROTOCOL_SEQUENCE, NULL, (unsigned char *)END_POINT, NULL, &pszBindStr);
	if(status) {
		exit(GetLastError());
	}
	
	status = RpcBindingFromStringBinding(pszBindStr, &hello_IfHandle);
	if(status) {
		exit(GetLastError());
	}
	RpcTryExcept {
		HelloProc(pszString);  // 远程调用
		Shutdown();  // 服务端关闭
	}
	RpcExcept(1) {
		printf("远程调用发生异常，异常错误码:%ld", RpcExceptionCode());
	}
	RpcEndExcept

	//执行远程内存释放
	status = RpcStringFree(&pszBindStr);  // remote calls done; unbind
	if (status) {
		exit(status);
	}
	//执行unbind
	status = RpcBindingFree(&hello_IfHandle);  // remote calls done; unbind
	if (status) {
		exit(status);
	}
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