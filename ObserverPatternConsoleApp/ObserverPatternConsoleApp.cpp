// ObserverPatternConsoleApp.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Publisher.h"
#include "Subscribers.h"

int main()
{
	Publisher::Video video_001("Intro.mp4");
	Publisher::VideoEncoder videoEncoder;
	videoEncoder.Encode(video_001, Publisher::EventArgs("Video Encoded"));
}
