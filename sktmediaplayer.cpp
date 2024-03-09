#include "sktmediaplayer.h"


//#pragma comment(lib,"libvlc.lib")
//#pragma comment(lib,"libvlccore.lib")

SktMediaPlayer::SktMediaPlayer()
{

}

SktMediaPlayer::~SktMediaPlayer()
{

}

void SktMediaPlayer::SktInitMediaPlayer()
{
    m_pInstance=libvlc_new(0,NULL);
}

int SktMediaPlayer::SktPlayVideo(const char *pstIp, HWND handle)
{
    char szSktPlayUrl[SKT_PLAY_URL_LEN]={0};
    sprintf(szSktPlayUrl,"rtsp://admin:admin1234@%s",pstIp);

    EnableWindow(handle,FALSE);
    //播放协议
    //libvlc_media_t *pMedia=libvlc_media_new_location(m_pInstance,szSktPlayUrl);
    //播放音视频
    libvlc_media_t *pMedia=libvlc_media_new_path(m_pInstance,"f:\\bandicam 2023-10-10 17-19-27-872.mp4");
    if(NULL == pMedia)
    {
        return 1;
    }

    libvlc_media_player_t *pPlayer=libvlc_media_player_new_from_media(pMedia);
    if(NULL==pPlayer)
    {
        return 2;
    }

    libvlc_media_player_set_hwnd(pPlayer,handle);
    int iRet = libvlc_media_player_play(pPlayer);
    if (0!=iRet)
    {
        libvlc_media_player_release(pPlayer);
        libvlc_media_player_stop(pPlayer);
        return 3;
    }

    return 0;
}

void SktMediaPlayer::SktStopVideo(HWND handle)
{
    libvlc_media_player_release(m_pPlayer);
    libvlc_media_player_stop(m_pPlayer);
}

void SktMediaPlayer::SktSetCurVolume(int iLen)
{
    if(!m_pPlayer)
        return ;

    if(0==libvlc_media_player_is_playing(m_pPlayer))
        return ;

    libvlc_audio_set_volume(m_pPlayer,iLen);
}
