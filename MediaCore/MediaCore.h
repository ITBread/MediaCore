#pragma once

#include "BaseHeader.h"
#include <Windows.h>

typedef void(*log_callback)(void*, int, const char*, va_list);

class MediaCore
{
public:
	MediaCore(void);
	~MediaCore(void);

public:
	void PreInit();
	void set_log_callback(log_callback cb);
	void Init(void* hwnd);
	void Init_sdl();
	int StartPlay(const char* url);
	void StopPlay();
	int  packet_queue_put_private(PacketQueue *q, AVPacket *pkt);
	int  packet_queue_put(PacketQueue *q, AVPacket *pkt);
	int  packet_queue_put_nullpacket(PacketQueue *q, int stream_index);
	int  packet_queue_init(PacketQueue *q);
	void packet_queue_flush(PacketQueue *q);
	void packet_queue_destroy(PacketQueue *q);
	void packet_queue_abort(PacketQueue *q);
	void packet_queue_start(PacketQueue *q);
	int  packet_queue_get(PacketQueue *q, AVPacket *pkt, int block, int *serial);

	void decoder_init(Decoder *d, AVCodecContext *avctx, PacketQueue *queue, SDL_cond *empty_queue_cond);
	int  decoder_decode_frame(Decoder *d, AVFrame *frame, AVSubtitle *sub);
	void decoder_destroy(Decoder *d);
	void decoder_abort(Decoder *d, FrameQueue *fq);
	inline void fill_rectangle(int x, int y, int w, int h);
	int realloc_texture(SDL_Texture **texture, Uint32 new_format, int new_width,
		int new_height, SDL_BlendMode blendmode, int init_texture);
	int upload_texture(SDL_Texture **tex, AVFrame *frame, struct SwsContext **img_convert_ctx);
	void video_image_display(VideoState *is);
	void video_audio_display(VideoState *s);

	void stream_component_close(VideoState *is, int stream_index);
	void stream_close(VideoState *is);
	void do_exit(VideoState *is);
	void set_default_window_size(int width, int height, AVRational sar);
	 int video_open(VideoState *is);
	 void video_display(VideoState *is);
	 void video_refresh(void *opaque, double *remaining_time);
	 int queue_picture(VideoState *is, AVFrame *src_frame, double pts, double duration, int64_t pos, int serial);
	 int get_video_frame(VideoState *is, AVFrame *frame);

#if CONFIG_AVFILTER
	 int configure_filtergraph(AVFilterGraph *graph, const char *filtergraph,
		 AVFilterContext *source_ctx, AVFilterContext *sink_ctx);

	 int configure_video_filters(AVFilterGraph *graph, VideoState *is, const char *vfilters, AVFrame *frame);
	 int configure_audio_filters(VideoState *is, const char *afilters, int force_output_format);

#endif  /* CONFIG_AVFILTER */
	 int decoder_start(Decoder *d, int (*fn)(void *), void *arg);
	 VideoState *stream_open(const char *filename, AVInputFormat *iformat);
	 void stream_cycle_channel(MediaCore *mediaCore, int codec_type);
	 void toggle_full_screen(VideoState *is);
	

public:
	int opt_width(void *optctx, const char *opt, const char *arg);
	int opt_height(void *optctx, const char *opt, const char *arg);
	int opt_format(void *optctx, const char *opt, const char *arg);
	int opt_frame_pix_fmt(void *optctx, const char *opt, const char *arg);
	int opt_sync(void *optctx, const char *opt, const char *arg);
	int opt_seek(void *optctx, const char *opt, const char *arg);
	int opt_duration(void *optctx, const char *opt, const char *arg);
	int opt_show_mode(void *optctx, const char *opt, const char *arg);
	void opt_input_file(void *optctx, const char *filename);
	int opt_codec(void *optctx, const char *opt, const char *arg);

public:
	VideoState *is;
	 AVCodecContext *avcodec_opts[AVMEDIA_TYPE_NB];
	 AVFormatContext *avformat_opts;
	 AVDictionary *sws_dict;
	 AVDictionary *swr_opts;
	 AVDictionary *format_opts, *codec_opts, *resample_opts;
	 int hide_banner;
public:
	AVInputFormat *file_iformat;
	const char *input_filename;
	const char *window_title;
	int default_width /* = 640*/;
	int default_height /*= 480*/;
	int screen_width /* = 0*/;
	int screen_height /*= 0*/;
	int audio_disable;
	int video_disable;
	int subtitle_disable;
	const char* wanted_stream_spec[AVMEDIA_TYPE_NB] /*= {0}*/;
	int seek_by_bytes /*= -1*/;
	int display_disable;
	int borderless;
	int startup_volume/* = 100*/;
	int show_status /*= 1*/;
	int av_sync_type /*= AV_SYNC_AUDIO_MASTER*/;
	int64_t start_time /*= AV_NOPTS_VALUE*/;
	int64_t duration/* = AV_NOPTS_VALUE*/;
	int fast/* = 0*/;
	int genpts /*= 0*/;
	int lowres/* = 0*/;
	int decoder_reorder_pts/* = -1*/;
	int autoexit;
	int exit_on_keydown;
	int exit_on_mousedown;
	int loop /*= 1*/;
	int framedrop /*= -1*/;
	int infinite_buffer /*= -1*/;
	 ShowMode show_mode /*= ShowMode::SHOW_MODE_NONE*/;
	const char *audio_codec_name;
	const char *subtitle_codec_name;
	const char *video_codec_name;
	double rdftspeed /*= 0.02*/;
	int64_t cursor_last_shown;
	int cursor_hidden /*= 0*/;
#if CONFIG_AVFILTER
	 const char **vfilters_list /*= NULL*/;
	 int nb_vfilters /*= 0*/;
	 char *afilters /*= NULL*/;
#endif
	 int autorotate /*= 1*/;
	 int find_stream_info/* = 1*/;

	/* current context */
	 int is_full_screen;
	 int64_t audio_callback_time;

	 AVPacket flush_pkt;

#define FF_QUIT_EVENT    (SDL_USEREVENT + 2)

	HWND m_hwnd/*=NULL*/;
	SDL_Window *window;
	SDL_Renderer *renderer;
	SDL_RendererInfo renderer_info /*= {0}*/;
	SDL_AudioDeviceID audio_dev;

};

