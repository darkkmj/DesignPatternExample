// ObserverPattern.cpp : 애플리케이션의 진입점을 정의합니다.
//

#include "ObserverPattern.h"


// Interface classes
struct Observer {
	virtual void update(float temp, float humidity, float pressure) = 0;
	virtual ~Observer() {}
};

struct DisplayElement {
	virtual void display(void) = 0;
	virtual ~DisplayElement() {}
};

struct Subject {
	virtual void registerObserver(Observer *p) = 0;
	virtual void removeObserver(Observer* p) = 0;
	virtual void notifyObserver() = 0;
	virtual ~Subject() {}
};

// Main class
class WeatherData : public Subject {
	std::list< Observer*> m_observer_list;
	float m_temp;
	float m_humidity;
	float m_pressure;

public:
	WeatherData() : m_temp(0.0), m_humidity(0.0), m_pressure(0.0) {}

	float getTemperature() { return m_temp; }
	float getHumidity() { return m_humidity; }
	float getPressure() { return m_pressure; }

	void measurementsChanged() {
		// Event callback function
		notifyObserver();
	}

	void registerObserver(Observer* p) override {
		m_observer_list.push_back(p);
	}

	void removeObserver(Observer* p) override {
		for (auto it : m_observer_list) {
			if (it == p) {
				m_observer_list.remove(it);
				break;
			}
		}
	}

	void notifyObserver() override {
		for (auto it : m_observer_list) {
			it->update(m_temp, m_humidity, m_pressure);
		}
	}

	// For test
	void setMeasurements(float temp, float humidity, float pressure) {
		m_temp = temp;
		m_humidity = humidity;
		m_pressure = pressure;

		measurementsChanged();
	}
};

// Display classes
class CurrentConditions : public Observer, public DisplayElement {
	float m_temp = 0.0;
	float m_humidity = 0.0;
	float m_pressure = 0.0;
	Subject* weatherData;

public:
	CurrentConditions(Subject* p) {
		weatherData = p;
		weatherData->registerObserver(this);
	}

	~CurrentConditions() {
		weatherData->removeObserver(this);
	}

	void update(float temp, float humidity, float pressure) override {
		m_temp = temp;
		m_humidity = humidity;
		m_pressure = pressure;

		display();
	}

	void display() override {
		std::cout << "[Current Conditions]" << std::endl;
		std::cout << "  Temperature: " << m_temp << ", ";
		std::cout << "  Humidity: " << m_humidity << ", ";
		std::cout << "  Pressure: " << m_pressure << std::endl;
	}
};

class StatisticsDiplay : public Observer, public DisplayElement {
	float m_temp = 0.0;
	float m_humidity = 0.0;
	float m_pressure = 0.0;
	Subject* weatherData;

public:
	StatisticsDiplay(Subject* p) {
		weatherData = p;
		weatherData->registerObserver(this);
	}

	~StatisticsDiplay() {
		weatherData->removeObserver(this);
	}

	void update(float temp, float humidity, float pressure) override {
		m_temp = temp;
		m_humidity = humidity;
		m_pressure = pressure;

		display();
	}

	void display() override {
		std::cout << "[Statistics]" << std::endl;
		std::cout << "  Min/Max/Average values are displayed" << std::endl;
	}
};

int main()
{
	WeatherData* weatherData = new WeatherData();
	CurrentConditions* currentDisplay = new CurrentConditions(weatherData);
	StatisticsDiplay* statisticDisplay = new StatisticsDiplay(weatherData);

	weatherData->setMeasurements(80, 65, 30.4f);
	weatherData->setMeasurements(82, 70, 29.2f);

	delete statisticDisplay;

	weatherData->setMeasurements(78, 90, 32.7f);

	return 0;
}
