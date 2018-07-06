#include "MediaCoreAPI.h"
#include "MediaCore.h"


MediaCoreAPI::MediaCoreAPI(void)
{
	m_mediaCore=new MediaCore();
}


void MediaCoreAPI::Init(void* hwnd)
{
	MediaCore *mediaCore=(MediaCore *)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->Init(hwnd);
	}
}

int MediaCoreAPI::StartPlay(const char* url)
{
	MediaCore *mediaCore=(MediaCore *)m_mediaCore;
	if (mediaCore)
	{
		return	mediaCore->StartPlay(url);
	}
	return 1;
}

void MediaCoreAPI::StopPlay()
{
	MediaCore *mediaCore=(MediaCore *)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->StopPlay();
	}
}

MediaCoreAPI::~MediaCoreAPI(void)
{

}
