#pragma once
#ifdef MEDIACOREAPI_EXPORTS
#define MEDIACORE_API __declspec(dllexport)
#else
#define MEDIACORE_API __declspec(dllimport)
#endif

class MEDIACORE_API MediaCoreAPI
{
public:
	MediaCoreAPI(void);
	void Init(void* hwnd);
	int StartPlay(const char* url);
	void StopPlay();
	~MediaCoreAPI(void);
private:
	void* m_mediaCore;
};

