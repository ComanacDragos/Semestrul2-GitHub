#pragma once
#include <string>
#include <exception>
#include <stdlib.h>
#include <time.h>
#include <iostream>

class Channel
{
public:
	Channel()
	{

	}
	virtual void send(const std::string& message) = 0;
};

class Telefon: public Channel
{
private:
	int nrTel;
public:
	Telefon(int nrTel) :nrTel{ nrTel }{
		
	}
	virtual void send(const std::string& message)override {
		int r = rand() % 2;
		if (r == 0)
			throw std::exception{ "Eroare" };
	std::cout << "dial " << nrTel << ' ';
	}
};

class Fax : public Telefon
{
public:
	Fax(int nrTel):Telefon{nrTel}{}

	void send(const std::string& message) override {
		Telefon::send(message);
		std::cout << "sending fax\n";
	}
};

class SMS : public Telefon
{
public:
	SMS(int nrTel):Telefon{nrTel}{}

	void send(const std::string& message) override {
		Telefon::send(message);
		std::cout << "sending SMS\n";
	}
};

class Failover : public Channel
{
private:
	Channel* c1;
	Channel* c2;

public:
	Failover(Channel* c1, Channel* c2) :Channel{}, c1{ c1 }, c2{ c2 }{
	}

	void send(const std::string& message)override {
		bool isSent = false;
		try
		{
			c1->send(message);
			isSent = true;
		}
		catch (std::exception & exc)
		{
			std::cout << "c1 is occupied\n";
		}
		if (isSent == false)
		{
			try
			{
				c2->send(message);
				isSent = true;
			}
			catch (std::exception & exc)
			{
				std::cout << "c2 is occupied\n";
			}
		}
	}
	~Failover()
	{
		delete c1;
		delete c2;
	}
};

class Contact
{
private:
	Channel* c1;
	Channel* c2;
	Channel* c3;
public:
	Contact(Channel* c1, Channel* c2, Channel* c3):c1{c1}, c2{c2}, c3{c3}{}

	void sendAlarm(const std::string& msg) {
		while (true)
		{
			try {
				c1->send(msg);
				break;
			}
			catch (std::exception & exc)
			{
				std::cout << "c1 is occupied\n";
			}

			try {
				c2->send(msg);
				break;
			}
			catch (std::exception & exc)
			{
				std::cout << "c2 is occupied\n";
			}

			try {
				c3->send(msg);
				break;
			}
			catch (std::exception & exc)
			{
				std::cout << "c3 is occupied\n";
			}
			
		}
	}
	~Contact()
	{
		delete c1;
		delete c2;
		delete c3;
	}
};

Contact* f()
{
	Telefon* t = new Telefon{ 1 };
	Fax* f = new Fax{ 2 };
	SMS* s = new SMS{ 3 };

	Contact* c = new Contact{ t,f,s };
	return c;
}