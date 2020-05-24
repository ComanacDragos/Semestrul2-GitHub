#pragma once
#include <sstream>
#include <exception>
#include <assert.h>
#include <string>
#include <vector>
#include <iomanip>

class Domain
{
};

class Exceptions : public std::exception
{
private:
	std::string message;

public:
	Exceptions(const std::string& s) : message{ s } {}

	const char* what() const throw() override {
		return this->message.c_str();
	}
};

std::vector < std::string> tokenize(const std::string& string, char delimiter);
std::string double_to_string(double n);