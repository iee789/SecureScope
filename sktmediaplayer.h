#ifndef SKTMEDIAPLAYER_H
#define SKTMEDIAPLAYER_H

#include <windows.h>

#include "vlc/vlc.h"
#include "vlc/libvlc_media.h"

//封装vlc库

#pragma comment(lib,"livlc.lib")
#pragma comment(lib,"libvlccore.lib")

#define SKT_PLAY_URL_LEN 256

class SktMediaPlayer
{
public:
    SktMediaPlayer();
    ~SktMediaPlayer();

    void SktInitMediaPlayer();
    int SktPlayVideo(const char *pstIp,HWND handle);
    void SktStopVideo(HWND handle);
    void SktSetCurVolume(int iLen);

private:
    libvlc_instance_t *m_pInstance=NULL;
    libvlc_media_player_t *m_pPlayer=NULL;
};

#endif // SKTMEDIAPLAYER_H
