// FactoryPattern.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "FactoryPattern.h"

using namespace std;

class Pizza {
public:
	Pizza() = default;
	~Pizza() = default;

	void prepare() {
		std::cout << "Preparing " << name << std::endl;
		std::cout << "Tossing dough... " << std::endl;
		std::cout << "Adding sauce..." << std::endl;
		std::cout << "Adding toppings: " << std::endl;
		for (auto it : toppings) {
			std::cout << "   " << it << std::endl;
		}
	}

	void bake() {
		std::cout << "Bake for 25 minutes at 350" << std::endl;
	}

	void cut() {
		std::cout << "Cutting the pizza into diagonal slices" << std::endl;
	}

	void box() {
		std::cout << "Place pizza in official PizzaStore box" << std::endl;
	}

	std::string getName() {
		return name;
	}

private:
	std::string name;
	std::string dough;
	std::string sauce;
	std::list<std::string> toppings;
};

int main()
{


	return 0;
}
