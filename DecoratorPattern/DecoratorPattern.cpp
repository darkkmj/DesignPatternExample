// DecoratorPattern.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "DecoratorPattern.h"

using namespace std;

class Beverage {
public:
	Beverage() = default;
	virtual ~Beverage() = default;

	virtual std::string getDescription() {
		return (description);
	}

	virtual double cost() abstract;

protected:
	std::string description = "No description";
};

class CondimentDecorator : public Beverage {
public:	
	virtual std::string getDescription() abstract;
};

class Espresso : public Beverage {
public:
	Espresso() {
		description = "Espresso";
	}

	double cost() override {
		return 1.99;
	}
};

class HouseBlend : public Beverage {
public:
	HouseBlend() {
		description = "HouseBlend";
	}

	double cost() override {
		return 0.89;
	}
};

class DarkRoast : public Beverage {
public:
	DarkRoast() {
		description = "DarkRoast";
	}

	double cost() override {
		return 0.99;
	}
};

class Decaffeine : public Beverage {
public:
	Decaffeine() {
		description = "Decaffeine";
	}

	double cost() override {
		return 1.05;
	}
};

class Mocha : public CondimentDecorator {
public:
	Mocha(Beverage* beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() override {
		return (beverage->getDescription() + ", Mocha");
	}

	double cost() override {
		return (0.20 + beverage->cost());
	}

private:
	Beverage* beverage;
};

class SteamMilk : public CondimentDecorator {
public:
	SteamMilk(Beverage* beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() override {
		return (beverage->getDescription() + ", SteamMilk");
	}

	double cost() override {
		return (0.10 + beverage->cost());
	}

private:
	Beverage* beverage;
};

class Soy : public CondimentDecorator {
public:
	Soy(Beverage* beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() override {
		return (beverage->getDescription() + ", Soy");
	}

	double cost() override {
		return (0.15 + beverage->cost());
	}

private:
	Beverage* beverage;
};

class Whip : public CondimentDecorator {
public:
	Whip(Beverage* beverage) {
		this->beverage = beverage;
	}

	std::string getDescription() override {
		return (beverage->getDescription() + ", Whip");
	}

	double cost() override {
		return (0.10 + beverage->cost());
	}

private:
	Beverage* beverage;
};

int main()
{
	Beverage* beverage = (Beverage*)new Espresso();
	std::cout << beverage->getDescription() << " $" << beverage->cost() << std::endl;

	Beverage* beverage2 = (Beverage*)new DarkRoast();
	beverage2 = (Beverage*)new Mocha(beverage2);
	beverage2 = (Beverage*)new Mocha(beverage2);
	beverage2 = (Beverage*)new Whip(beverage2);
	std::cout << beverage2->getDescription() << " $" << beverage2->cost() << std::endl;

	Beverage* beverage3 = (Beverage*)new HouseBlend();
	beverage3 = (Beverage*)new Soy(beverage3);
	beverage3 = (Beverage*)new Mocha(beverage3);
	beverage3 = (Beverage*)new Whip(beverage3);
	std::cout << beverage3->getDescription() << " $" << beverage3->cost() << std::endl;

	return 0;
}
