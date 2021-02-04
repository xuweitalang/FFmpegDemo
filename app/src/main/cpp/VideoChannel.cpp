//
// Created by Administrator on 2019/8/9.
//

#include "VideoChannel.h"

VideoChannel::VideoChannel(int id) : BaseChannel(id) {}

VideoChannel::~VideoChannel() {

}

/**
 * 准备线程pid_video_decode真正执行的函数
 * @param args
 * @return
 */
void *task_video_decode(void *args) {
    VideoChannel *videoChannel = static_cast<VideoChannel *>(args);
    videoChannel->video_decode();
    return 0;//一定一定一定要返回0！！！
}

/**
 * 准备线程pid_video_play真正执行的函数
 * @param args
 * @return
 */
void *task_video_play(void *args) {
    VideoChannel *videoChannel = static_cast<VideoChannel *>(args);
    videoChannel->video_play();
    return 0;//一定一定一定要返回0！！！
}


void VideoChannel::start() {
    isPlaying = 1;
    //设置队列状态为工作状态
    packets.setWork(1);
    //进行解码播放
    pthread_create(&pid_video_decode, 0, task_video_decode, this);
    pthread_create(&pid_video_play, 0, task_video_play, this);
}

void VideoChannel::stop() {

}

/**
 * 真正视频解码
 */
void VideoChannel::video_decode() {
    AVPacket *packet = 0;
    while (isPlaying) {
        int ret = packets.pop(packet); //出栈成功返回1，否则返回0
        if (!isPlaying) {
            //如果停止播放了，跳出循环
            break;
        }
        if (!ret) { //失败
            continue;
        }
        //拿到视频数据包（编码压缩了的），需要把数据包给解码
//        avcodec_send_packet(,packet);
    }
    releaseAVPacket(&packet);
}

void VideoChannel::video_play() {

}
