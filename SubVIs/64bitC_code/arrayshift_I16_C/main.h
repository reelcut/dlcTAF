#ifndef __MAIN_H__
#define __MAIN_H__

#include <windows.h>

/*  To use this exported function of dll, include this header
 *  in your project.
 */

#ifdef BUILD_DLL
    #define DLL_EXPORT __declspec(dllexport)
#else
    #define DLL_EXPORT __declspec(dllimport)
#endif


#ifdef __cplusplus
extern "C"
{
#endif

void arrayshift(short SaveArray[], short NewArray[],
		long NChan, long NData,long NNew, long *Index)

#ifdef __cplusplus
}
#endif

#endif // __MAIN_H__
