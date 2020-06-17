#pragma once
#include <string>
#include <vector>
#include <iostream>
#include <memory>
#include <exception>


class Beverage
{
private:
	std::string description;


public:
	Beverage(){}
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
	BeverageWithMilk(std::unique_ptr<Beverage> beverage, int milkCount) :milkCount{ milkCount }, beverage{std::move(beverage)}{}
	
	virtual double price() override
	{
		return this->beverage->price() + 0.5 * this->milkCount;
	}
	virtual void print() override
	{
		//Beverage::print();
		beverage->print();
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
/*
#pragma once
#include <string>
#include <iostream>
#include <exception>
#include <memory>
//11:47


class Beverage {
protected:
	std::string description;
public:
	//default constructor
	Beverage() {}

	//constructor with parameters
	Beverage(std::string description) {
		this->description = description;
	};

	//copy constructor
	Beverage(Beverage* beverage) {
		this->description = beverage->description;
	}
	virtual double price() const = 0;
	void print() {
		std::cout << description << " " << price() << " ";
	};
};

class Coffee : public Beverage {
public:
	Coffee() : Beverage("Coffee") {}
	Coffee(Coffee* coffee) : Beverage("Coffee") {}
	double price() const override {
		return 2.5;
	}
};

class Tea : public Beverage {
public:
	Tea() : Beverage("Tea") {}
	Tea(Tea* tea) : Beverage("Tea") {}
	double price() const override {
		return 1.5;
	}
};

class BeverageWithExtraIngredient : public Beverage {
protected:
	Beverage* beverage;
public:
	BeverageWithExtraIngredient(Beverage* _beverage) {
		this->beverage = _beverage;
	};
	double price() const override {
		return this->beverage->price();
	}
	void print() {
		this->beverage->print();
	}
};

class BeverageWithMilk : public BeverageWithExtraIngredient {
private:
	int milkCount;
	//Beverage* beverage;
public:
	BeverageWithMilk(BeverageWithExtraIngredient* beverage, int milkCount) : BeverageWithExtraIngredient(beverage), milkCount{ milkCount } {
	};
	double price() const override {
		return BeverageWithExtraIngredient::price() + 0.5 * this->milkCount;
	}
	void print() {
		Beverage::print();
		std::cout << "price" << this->price() << " ";
		std::cout << std::to_string(milkCount) << " extra milk" << " ";
	}
};

class BeverageWithSugar : public BeverageWithExtraIngredient {
private:
	int sugarCount;
	//Beverage* beverage;
public:
	BeverageWithSugar(BeverageWithExtraIngredient* beverage, int sugarCount) : BeverageWithExtraIngredient(beverage), sugarCount{ sugarCount } {
	};
	double price() const override {
		return BeverageWithExtraIngredient::price() + 0.3 * this->sugarCount;
	}
	void print() {
		Beverage::print();
		std::cout << "price" << this->price() << " ";
		std::cout << std::to_string(sugarCount) << " extra sugar" << " ";
	}
};

class BeverageMachine {
public:
	BeverageMachine() {};
	void prepare(std::string beverageType, int milkCount, int sugarCount=0) {
		if (beverageType == "Tea") {
			Tea* tea = new Tea();
			BeverageWithExtraIngredient* teaExtra = new BeverageWithExtraIngredient(tea);
			BeverageWithMilk* milkTea = new BeverageWithMilk(teaExtra, milkCount);
			BeverageWithSugar* milkSugarTea = new BeverageWithSugar(milkTea, sugarCount);
			milkSugarTea->print();
			std::cout << "\n";
		}
		else if (beverageType == "Coffee") {
			Coffee* coffee = new Coffee();
			BeverageWithExtraIngredient* coffeeExtra = new BeverageWithExtraIngredient(coffee);
			BeverageWithMilk* milkCoffee = new BeverageWithMilk(coffeeExtra, milkCount);
			BeverageWithSugar* milkSugarCoffee = new BeverageWithSugar(milkCoffee, sugarCount);
			milkSugarCoffee->print();
			std::cout << "\n";
		}
	}
};

*/