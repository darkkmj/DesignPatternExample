// FactoryPattern.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "FactoryPattern.h"

using namespace std;

class Pizza {
public:
	Pizza() = default;
	~Pizza() = default;

	virtual void prepare() {
		std::cout << "Preparing " << name << std::endl;
		std::cout << "Tossing dough... " << std::endl;
		std::cout << "Adding sauce..." << std::endl;
		std::cout << "Adding toppings: " << std::endl;
		for (auto it : toppings) {
			std::cout << "   " << it << std::endl;
		}
	}

	virtual void bake() {
		std::cout << "Bake for 25 minutes at 350" << std::endl;
	}

	virtual void cut() {
		std::cout << "Cutting the pizza into diagonal slices" << std::endl;
	}

	virtual void box() {
		std::cout << "Place pizza in official PizzaStore box" << std::endl;
	}

	std::string getName() {
		return name;
	}

protected:
	std::string name;
	std::string dough;
	std::string sauce;
	std::list<std::string> toppings;
};

class NYStyleCheesePizza : public Pizza {
public:
	NYStyleCheesePizza() {
		name = "NY Style Sauce and Cheese Pizza";
		dough = "Thin Crust Dough";
		sauce = "Marinara Sauce";

		toppings.push_back("Grated Reggiano Cheese");
	}
};

class ChicagoStyleCheesePizza : public Pizza {
public:
	ChicagoStyleCheesePizza() {
		name = "Chicago Style Deep Dish Cheese Pizza";
		dough = "Extra Thick Crust Dough";
		sauce = "Plum Tomato Sauce";

		toppings.push_back("Shredded Mozzarella Cheese");
	}

	void cut() override {
		std::cout << "Cutting the pizza into square slices" << std::endl;
	}
};

class PizzaStore abstract {
public:
	Pizza* orderPizza(std::string type) {
		Pizza* pizza;
		pizza = createPizza(type);
		pizza->prepare();
		pizza->bake();
		pizza->cut();
		pizza->box();

		return pizza;
	}

protected:
	virtual Pizza* createPizza(std::string type) abstract;
};

class NYPizzaStore : public PizzaStore {
	Pizza* createPizza(std::string type) override {
		Pizza* pizza;

		if (type == "cheese") {
			pizza = new NYStyleCheesePizza();
		}
		else {
			std::cerr << "Unknown pizza !!!";
		}

		return pizza;
	}
};

class ChicagoPizzaStore : public PizzaStore {
	Pizza* createPizza(std::string type) override {
		Pizza* pizza;

		if (type == "cheese") {
			pizza = new ChicagoStyleCheesePizza();
		}
		else {
			std::cerr << "Unknown pizza !!!";
		}

		return pizza;
	}
};

int main()
{
	PizzaStore* nyStore = new NYPizzaStore();
	PizzaStore* chicagoStore = new ChicagoPizzaStore();

	Pizza* pizza = nyStore->orderPizza("cheese");
	std::cout << "Ethan ordered a " << pizza->getName() << std::endl;

	pizza = chicagoStore->orderPizza("cheese");
	std::cout << "Joel ordered a " << pizza->getName() << std::endl;

	return 0;
}
