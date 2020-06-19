#pragma once
#include <string>
#include <memory>
#include <vector>

class Channel
{
public:
	virtual void send(const std::string& msg) = 0;
	virtual ~Channel() {}
};

class Telephone
{
private:
	std::string nr;
public:
	Telephone(const std::string& nr)
};