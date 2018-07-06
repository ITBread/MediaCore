#pragma once
#ifdef MEDIACOREAPI_EXPORTS
#define MEDIACORE_API __declspec(dllexport)
#else
#define MEDIACORE_API __declspec(dllimport)
#endif

#ifdef __cplusplus
extern "C" {
#endif

void MEDIACORE_API Init(void* hwnd);
int MEDIACORE_API StartFile(char * url);
int StartStream(char * url);


#ifdef __cplusplus
}
#endif


