// ObserverPatternConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Publisher.h"
#include "Subscribers.h"

int main()
{
	Publisher::Video video_001("Intro.mp4");
	Publisher::Video video_002("Promo_Video_046.mpeg");

	Publisher::VideoEncoder videoEncoder;

	Subscribers::MailService mailService;
	Subscribers::VoiceMessageService voiceMessageService;
	Subscribers::TextMessageService textMessageService;

	videoEncoder.VideoEncoded += &textMessageService.textMesssageServiceEventHandler;
	videoEncoder.VideoEncoded += &voiceMessageService.voiceMessageServiceEventHandler;
	videoEncoder.VideoEncoded += &mailService.mailServiceEventHandler;

	videoEncoder.Encode(video_001);
	videoEncoder.Encode(video_002);
}
