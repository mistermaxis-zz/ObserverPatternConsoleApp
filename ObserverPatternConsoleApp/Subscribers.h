#pragma once
#include <iostream>
#include "Object.h"
#include "Publisher.h"

namespace Subscribers {

	class MailServiceEventHandler : public Publisher::EventHandler
	{
	public:
		MailServiceEventHandler() {}

		virtual void operator()(Object::Object obj, Publisher::EventArgs args)
		{
			std::cout << "Sending Message: \"" << args.message[1].GetMessage() << ": " << args.message[0].GetMessage() << "\" through Email.\n";
			system(Publisher::wait_three);
		}
	};

	class TextMessageServiceEventHandler : public Publisher::EventHandler
	{
	public:
		TextMessageServiceEventHandler() {}

		virtual void operator()(Object::Object obj, Publisher::EventArgs args)
		{
			std::cout << "Sending Message: \"" << args.message[1].GetMessage() << ": " << args.message[0].GetMessage() << "\" through Text Message.\n";
			system(Publisher::wait_three);
		}
	};

	class VoiceMessageServiceEventHandler : public Publisher::EventHandler
	{
	public:
		VoiceMessageServiceEventHandler() {}

		virtual void operator()(Object::Object obj, Publisher::EventArgs args)
		{
			std::cout << "Sending Message: \"" << args.message[1].GetMessage() << ": " << args.message[0].GetMessage() << "\" through Voice Message.\n";
			system(Publisher::wait_three);
		}
	};

	class MailService {
	public:
		MailServiceEventHandler mailServiceEventHandler;
	};

	class TextMessageService {	
	public:
		TextMessageServiceEventHandler textMesssageServiceEventHandler;
	};

	class VoiceMessageService {
	public:
		VoiceMessageServiceEventHandler voiceMessageServiceEventHandler;
	};
}