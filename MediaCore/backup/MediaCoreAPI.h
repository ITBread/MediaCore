#pragma once
#ifdef MEDIACOREAPI_EXPORTS
#define MEDIACORE_API __declspec(dllexport)
#else
#define MEDIACORE_API __declspec(dllimport)
#endif

#define WM_USER          0x0400
#define WM_MY_MESSAGE WM_USER +200
#define MAX_PATH          260

/**  
@brief MediaCoreAPI.
*/
class MEDIACORE_API MediaCoreAPI
{
	enum StatusCode
	{
		ET_STATUS_UNKNOW=-1,
		ET_STATUS_PLAYING=0,
		ET_STATUS_ERROR=1,
		ET_STATUS_STOP=2,
	};
public:
	MediaCoreAPI();
	void Init(void* wnd);
	/**  
	@brief 播放rtsp流 .
	@param url rtsp流地址
	@param rec 录制视频 1录制 0不录制	
	@return 返回操作结果 大于0成功，否则失败。
	*/
	void Play(char* url,int rec=0);
	/**  
	@brief 停止播放. 
	*/
	void Stop();
	/**   
	@brief 设置字幕信息.
	@param  text 文本信息
	@param  fontSize 字体大小
	@return 无返回值。
	*/
	void SetTextInfo(char* text,int fontSize=24);

	/**   
	@brief 设置录制路径.
	@param   path 路径
	*/
	int SetRecPath( char* path);
	/**  
	@brief 播放状态改变.
	@param   statuCode 状态码
	*/
	virtual void OnStatusChanged(StatusCode statuCode){}
	static void TryVideoRefresh(void* mediaCore);
	~MediaCoreAPI();

private:
	void* m_mediaCore;
	char rec_Path[MAX_PATH];
};

