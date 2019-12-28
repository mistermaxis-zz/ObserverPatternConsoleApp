#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include "Object.h"

namespace Publisher {

	class Video : public Object::Object
	{
	public:
		Video(std::string n) { name = n; }
	};

	class EventArgs {
	public:
		Object::Message message;
		EventArgs(std::string msg) { message.name = msg; }
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
	private:
		Event VideoEncoderEvent;

	public:
		void Encode(Object source, EventArgs args)
		{
			std::cout << "Encoding Video: " << source.name << "\n";
			system("timeout 3");
			VideoEncoderEvent.Invoke(*this, args);
		}
	};
}