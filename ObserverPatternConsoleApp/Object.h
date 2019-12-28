#pragma once
#include <iostream>
#include <string>

namespace Object {

	class Object
	{
	public:
		std::string name;
		Object() { name = typeid(this).name(); }
	};

	class Message : public Object
	{
		std::string message;

	public:
		Message() { name = typeid(this).name(); };
		Message(std::string msg) { message = msg; }

		std::string GetMessage() { return message; }
	};
}