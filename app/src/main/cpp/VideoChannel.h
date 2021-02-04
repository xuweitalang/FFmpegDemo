//
// Created by Administrator on 2019/8/9.
//

#ifndef NE_PLAYER_1_VIDEOCHANNEL_H
#define NE_PLAYER_1_VIDEOCHANNEL_H


#include "BaseChannel.h"

class VideoChannel : public BaseChannel {
public:
    VideoChannel(int id);

    ~VideoChannel();

    void start();

    void stop();

    void video_decode();

    void video_play();

private:
    pthread_t pid_video_decode;
    pthread_t pid_video_play;
};


#endif //NE_PLAYER_1_VIDEOCHANNEL_H
