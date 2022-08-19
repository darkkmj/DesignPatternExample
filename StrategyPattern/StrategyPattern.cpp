// StrategyPattern.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "StrategyPattern.h"

using namespace std;

struct FlyBehavior {
	virtual void fly() = 0;
	virtual ~FlyBehavior() {}
};

struct QuackBehavior {
	virtual void quack() = 0;
	virtual ~QuackBehavior() {}
};

class FlyWithWings : public FlyBehavior {
public:
	void fly() override {
		cout << " -> FlyWithWings!!!" << endl;
	}
};

class FlyNoWay : public FlyBehavior {
public:
	void fly() override {
		cout << " -> FlyNoWay!!!" << endl;
	}
};

class Quack : public QuackBehavior {
public:
	void quack() override {
		cout << " -> Quack!!!" << endl;
	}
};

class Squeak : public QuackBehavior {
public:
	void quack() override {
		cout << " -> Squeak!!!" << endl;
	}
};

class MuteQuack : public QuackBehavior {
public:
	void quack() override {
		cout << " -> MuteQuack!!!" << endl;
	}
};

class Duck {
	FlyBehavior*   flyBehavior = nullptr;
	QuackBehavior* quackBehavior = nullptr;

public:
	void setFlyBehavior(FlyBehavior* pFly) { flyBehavior = pFly; }
	void setQuackBehavior(QuackBehavior* pQuack) { quackBehavior = pQuack; }
	void performQuack() { quackBehavior->quack(); }
	void performFly() { flyBehavior->fly(); }
	virtual void display() { cout << "Duck" << endl; }
};

class MallardDuck : public Duck {
public:
	void display() override {
		cout << "[MallardDuck]" << endl;
	}
};

class RedheadDuck : public Duck {
public:
	void display() override {
		cout << "[RedheadDuck]" << endl;
	}
};

class RubberDuck : public Duck {
public:
	void display() override {
		cout << "[RubberDuck]" << endl;
	}
};

int main()
{
	// Duck classes
	MallardDuck malDuck;
	RedheadDuck redDuck;
	RubberDuck  rubDuck;

	// Behavior classes
	FlyWithWings flywithwinds;
	FlyNoWay flynoway;
	Quack quack;
	Squeak squeak;
	MuteQuack mutequack;

	malDuck.setFlyBehavior(&flywithwinds);
	malDuck.setQuackBehavior(&quack);
	redDuck.setFlyBehavior(&flywithwinds);
	redDuck.setQuackBehavior(&squeak);
	rubDuck.setFlyBehavior(&flynoway);
	rubDuck.setQuackBehavior(&mutequack);

	malDuck.display();
	malDuck.performFly();
	malDuck.performQuack();

	redDuck.display();
	redDuck.performFly();
	redDuck.performQuack();

	rubDuck.display();
	rubDuck.performFly();
	rubDuck.performQuack();

	return 0;
}
