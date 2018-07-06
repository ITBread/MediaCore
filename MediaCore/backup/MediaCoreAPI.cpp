

#include "MediaCoreAPI.h"
#include "MediaBase.h"
#include <windows.h>
#include "HookHelp.h"


static int count = 0;
MediaCoreAPI::MediaCoreAPI()
{
	m_mediaCore = new MediaBase();
	count++;
}

void MediaCoreAPI::Init(void * wnd)
{
	MediaBase *mediaCore = (MediaBase*)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->Init((HWND)wnd);
	}
	HookHelp::InitHook((HWND)wnd);
}

void MediaCoreAPI::Play(char * url,int rec)
{
	MediaBase *mediaCore = (MediaBase*)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->StartPlay(url);
	}
}

void MediaCoreAPI::Stop()
{
	MediaBase *mediaCore = (MediaBase*)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->StopPlay();
	}
}

void MediaCoreAPI::SetTextInfo(char * text,int fontSize)
{
	MediaBase *mediaCore = (MediaBase*)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->set_video_subtitle(text);
	}
}

int MediaCoreAPI::SetRecPath(char* path)
{
	_snprintf(rec_Path,MAX_PATH-1,"%s",path);
	return 0;
}

void MediaCoreAPI::TryVideoRefresh(void* mediaCore)
{
	if (mediaCore==NULL)
	{
		return;
	}
	MediaBase::TryVideoRefresh(mediaCore);
}

MediaCoreAPI::~MediaCoreAPI()
{
	if (count > 0)
	{
		count--;
		if (count == 0)
			HookHelp::UnInitHook();
	}
	MediaBase *mediaCore = (MediaBase*)m_mediaCore;
	if (mediaCore)
	{
		mediaCore->~MediaBase();
	}
}
