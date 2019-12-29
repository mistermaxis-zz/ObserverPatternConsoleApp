#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Object.h"

namespace Publisher {

	const char * wait_three = "timeout /t 3 >nul";

	class Video : public Object::Object
	{
	public:
		Video(std::string n) { name = n; }
	};

	class EventArgs {
	public:
		std::vector<Object::Message> message;
		EventArgs(std::vector<std::string> msg) { for (auto i = msg.cbegin(); i != msg.cend(); i++) { message.push_back(*i); } }
	};

	class EventHandler {
	public:
		EventHandler() {}
		virtual void operator()(Object::Object source, EventArgs e) = 0;
	};

	class Event {
	public:
		std::vector<EventHandler*> handlers;
	public:
		void operator +=(EventHandler* h) { handlers.push_back(h); }

		void Invoke(Object::Object source, EventArgs e) { if (handlers.empty() == false) for (auto i = handlers.cbegin(); i != handlers.cend(); i++) (**i)(source, e); }
	}; 

	class VideoEncoder : private Object::Object {
	public:
		Event VideoEncoded;

		void Encode(Object source)
		{
			std::cout << "\nEncoding Video: " << source.name << "\n";
			EventArgs args({ source.name, "Video Encoded" });
			system(wait_three);
			VideoEncoded.Invoke(*this, args);
		}
	};
}