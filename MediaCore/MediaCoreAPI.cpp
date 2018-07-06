#include "MediaCoreAPI.h"
#include "MediaCore.h"
#include <crtdbg.h>
#include "va_copy.h"

static void printDebuglog(void *ptr, int level, const char *fmt, va_list vl)
{
	va_list vl2;
	char line[1024];
	static int print_prefix = 1;

	va_copy(vl2, vl);
	av_log_default_callback(ptr, level, fmt, vl);
	av_log_format_line(ptr, level, fmt, vl2, line, sizeof(line), &print_prefix);
	va_end(vl2);
	OutputDebugStringA(line);
}

MediaCoreAPI::MediaCoreAPI(void)
{
	MediaCore *mediaCore=new MediaCore();
	m_mediaCore=mediaCore;
#ifdef _DEBUG
	mediaCore->set_log_callback(printDebuglog);
#endif
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
