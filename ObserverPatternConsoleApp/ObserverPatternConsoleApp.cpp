// ObserverPatternConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Publisher.h"
#include "Subscribers.h"

int main()
{
	Publisher::Video video_001("Intro.mp4");
	Publisher::Video video_002("Promo_Video_046.mpeg");
	
	Publisher::Search search_001("What's my name again?");
	Publisher::Search search_002("functors in c++");

	Publisher::VideoEncoder videoEncoder;
	Publisher::SearchManager searchManager;

	Subscribers::MailService mailService;
	Subscribers::VoiceMessageService voiceMessageService;
	Subscribers::TextMessageService textMessageService;

	searchManager.SearchCompleted += &textMessageService.textMesssageServiceEventHandler;
	searchManager.SearchCompleted += &voiceMessageService.voiceMessageServiceEventHandler;
	searchManager.SearchCompleted += &mailService.mailServiceEventHandler;

	videoEncoder.VideoEncoded += &textMessageService.textMesssageServiceEventHandler;
	videoEncoder.VideoEncoded += &voiceMessageService.voiceMessageServiceEventHandler;
	videoEncoder.VideoEncoded += &mailService.mailServiceEventHandler;

	videoEncoder.Encode(video_001);
	videoEncoder.Encode(video_002);

	searchManager.Search(search_001);
	searchManager.Search(search_002);

}
