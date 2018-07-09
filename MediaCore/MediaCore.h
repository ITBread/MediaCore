#pragma once

#include "BaseHeader.h"

typedef void(*log_callback)(void*, int, const char*, va_list);
#define SUBTITLE_LENGTH 512

class MediaCore
{

public:
	MediaCore(void);
	~MediaCore(void);
private:
	void PreInit();
public:
	void Init(HWND wnd);
	void init_opts();
	void init_dynload();
	void uninit_opts(void);
	void set_log_callback(log_callback cb);
	void StartPlay(char* url,int rec=0); 
	void StopPlay();
	virtual void OnStatusChanged(int statuCode){};
#ifdef CONFIG_AVFILTER
	void set_video_subtitle(const char* text);
	void set_subtitle_font(const char* font_file_path);
	/*font color value is 000000~FFFFFF*/
	void set_subtitle_font_color(const char* font_color = "FFFFFF");
	/*alpha value is 0.0~1.0*/
	void set_subtitle_font_color_alpha(double alpha = 1);
	void set_subtitle_font_size(unsigned int size = 30);
#endif
	/*Underlying protocol send/receive buffer size*/
	void set_rtsp_buffer_size(const char* size = "102400");
	/*set RTSP transport protocols: udp, tcp ,http, udp_multicast*/
	void set_rtsp_transport(const char* transport = "tcp");
	/*set timeout (in microseconds) of socket TCP I/O operations*/
	void set_rtsp_connect_timeout(const char* timeout = "15000000");
	void set_rtsp_max_delay(const char* delay = "500000");
public:
	VideoState *is;
	AVDictionary *sws_dict ;
	AVDictionary *swr_opts ;
	AVDictionary *format_opts ;
	AVDictionary *codec_opts ;
	AVDictionary *resample_opts;
public:
	int m_rec;
	/* options specified by the user */
	AVInputFormat *file_iformat;
	const char *input_filename;
	const char *window_title;
	int default_width /*= 640*/;
	int default_height/* = 480*/;
	int screen_width/* = 0*/;
	int screen_height /*= 0*/;
	int audio_disable;
	int video_disable;
	int subtitle_disable;
	const char* wanted_stream_spec[AVMEDIA_TYPE_NB] /*= { 0 }*/;
	int seek_by_bytes /*= -1*/;
	int display_disable;
	int borderless;
	int startup_volume/* = 100*/;
	int show_status/* = 1*/;
	int av_sync_type/* = AV_SYNC_AUDIO_MASTER*/;
	int64_t start_time /*= AV_NOPTS_VALUE*/;
	int64_t duration /*= AV_NOPTS_VALUE*/;
	int fast /*= 0*/;
	int genpts /*= 0*/;
	int lowres/* = 0*/;
	int decoder_reorder_pts/* = -1*/;
	int autoexit;
	int exit_on_keydown;
	int exit_on_mousedown;
	int loop /*= 1*/;
	int framedrop/* = -1*/;
	int infinite_buffer /*= -1*/;
	ShowMode show_mode/* = SHOW_MODE_NONE*/;
	const char *audio_codec_name;
	const char *subtitle_codec_name;
	const char *video_codec_name;
	double rdftspeed/* = 0.02*/;
	int64_t cursor_last_shown;
	int cursor_hidden/* = 0*/;
#if CONFIG_AVFILTER
	const char **vfilters_list /*= NULL*/;
	int nb_vfilters/* = 0*/;
	char *afilters /*= NULL*/;
#endif
	int autorotate /*= 1*/;
	int find_stream_info /*= 1*/;

	/* current context */
	int is_full_screen;
	int64_t audio_callback_time;

	AVPacket flush_pkt /*= { 0 }*/;

	SDL_Window *window/*=NULL*/;
	SDL_Renderer *renderer /*= NULL*/;
	SDL_RendererInfo renderer_info /*= { 0 }*/;
	HWND m_hwnd /*= NULL*/;
	/*SDL_AudioDeviceID audio_dev;*/

#ifdef CONFIG_AVFILTER
	char font[256];
	char fontcolor[16];
	char boxcolor[16];
	char subtitle[SUBTITLE_LENGTH];
	double fontcolor_alpha;
	double boxcolor_alpha;
	unsigned int fontsize;
	int shadowy;
	int box;
	int x;
	int y;
	int is_subtitle_change;
#endif

};

