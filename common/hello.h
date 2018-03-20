

/* this ALWAYS GENERATED file contains the definitions for the interfaces */


 /* File created by MIDL compiler version 7.00.0500 */
/* at Tue Mar 20 13:47:20 2018
 */
/* Compiler settings for hello.idl:
    Oicf, W1, Zp8, env=Win32 (32b run)
    protocol : dce , ms_ext, c_ext, robust
    error checks: allocation ref bounds_check enum stub_data 
    VC __declspec() decoration level: 
         __declspec(uuid()), __declspec(selectany), __declspec(novtable)
         DECLSPEC_UUID(), MIDL_INTERFACE()
*/
//@@MIDL_FILE_HEADING(  )

#pragma warning( disable: 4049 )  /* more than 64k source lines */


/* verify that the <rpcndr.h> version is high enough to compile this file*/
#ifndef __REQUIRED_RPCNDR_H_VERSION__
#define __REQUIRED_RPCNDR_H_VERSION__ 475
#endif

#include "rpc.h"
#include "rpcndr.h"

#ifndef __RPCNDR_H_VERSION__
#error this stub requires an updated version of <rpcndr.h>
#endif // __RPCNDR_H_VERSION__


#ifndef __hello_h__
#define __hello_h__

#if defined(_MSC_VER) && (_MSC_VER >= 1020)
#pragma once
#endif

// 使用基于管道的协议
#define PROTOCOL_SEQUENCE "ncacn_np"
// 通信基于管道
#define END_POINT "\\pipe\\hello"

/* Forward Declarations */ 

#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __hello_INTERFACE_DEFINED__
#define __hello_INTERFACE_DEFINED__

/* interface hello */
/* [implicit_handle][version][uuid] */ 

void HelloProc( 
    /* [string][in] */ unsigned char *pszString);

void Shutdown( void);


extern handle_t hello_IfHandle;


extern RPC_IF_HANDLE hello_v1_0_c_ifspec;
extern RPC_IF_HANDLE hello_v1_0_s_ifspec;
#endif /* __hello_INTERFACE_DEFINED__ */

/* Additional Prototypes for ALL interfaces */

/* end of Additional Prototypes */

#ifdef __cplusplus
}
#endif

#endif


