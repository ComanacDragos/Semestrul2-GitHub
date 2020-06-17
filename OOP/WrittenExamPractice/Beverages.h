#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>

class Beverage
{
private:
	std::string description;


public:
	Beverage(const std::string& desc):description{desc}{}

	virtual double price() = 0;
	virtual void print() {
		std::cout << this->description;
	}
	std::string getDescription()
	{
		return this->description;
	}

	virtual ~Beverage(){}
};

class Coffee :public Beverage
{
private:
	double pr;

public:
	Coffee():pr{2.5}, Beverage{"Coffee"}{}

	virtual double price() override
	{
		return this->pr;
	}

	virtual void print() override
	{
		Beverage::print();
		std::cout << ' ' << this->pr;
	}
	virtual ~Coffee(){}
};

class Tea :public Beverage
{
private:
	double pr;

public:
	Tea() :pr{ 1.5 }, Beverage{ "Tea" }{}

	virtual double price() override
	{
		return this->pr;
	}

	virtual void print() override
	{
		Beverage::print();
		std::cout << ' ' << this->pr;
	}
	virtual ~Tea(){}
};

class BeverageWithMilk : public Beverage
{
private:
	int milkCount;
	std::unique_ptr<Beverage> beverage;
public:
	BeverageWithMilk(std::unique_ptr<Beverage> beverage, int milkCount) :milkCount{ milkCount }, beverage{std::move(beverage)}, Beverage{ beverage->getDescription() }{}
	
	virtual double price() override
	{
		return this->beverage->price() + 0.5 * this->milkCount;
	}
	virtual void print() override
	{
		this->beverage->print();
		std::cout << " + 0.5*" << this->milkCount << " = " << this->price();
	}

	virtual ~BeverageWithMilk(){}
};

class BeverageMachine
{
public:
	void prepare(const std::string& type, int milkCount )
	{
		if (type == "Tea")
		{
			std::unique_ptr<Beverage> tea = std::make_unique<Tea>();
			if (milkCount == 0)
				tea->print();
			else
			{
				std::unique_ptr<Beverage>withMilk = std::make_unique<BeverageWithMilk>(std::move(tea), milkCount);
				withMilk->print();
			}
		}
		else if (type == "Coffee")
		{
			std::unique_ptr<Beverage> coffee = std::make_unique<Coffee>();
			if (milkCount == 0)
				coffee->print();
			else
			{
				std::unique_ptr<Beverage>withMilk = std::make_unique<BeverageWithMilk>(std::move(coffee), milkCount);
				withMilk->print();
			}
		}
		std::cout << "\n\n";
	}
};
