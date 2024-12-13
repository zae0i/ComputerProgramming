#include "City.h"
#include <iostream>

int main() {
    try {
        // City 1 ����
        SmartCity city1("Futureville", 500000);
        city1.addFeature("Automated Traffic Control");
        city1.addFeature("Smart Energy Management");
        city1.addFeature("AI-assisted Healthcare");

        // City 1 ���� ���
        std::cout << "Initial City Information:\n";
        city1.displayInfo();

        // City 2 ����
        SmartCity city2("TechTown", 300000);
        city2.addFeature("AI-assisted Healthcare");
        city2.addFeature("Green Energy Systems");

        // City 2 ���� ���
        std::cout << "\nCity 2 Information:\n";
        city2.displayInfo();

        // ���յ� ���� ���� ���
        SmartCity combinedCity = city1 + city2;
        std::cout << "\nCombined City Information:\n";
        combinedCity.displayInfo();

        // ���Ͽ� ���� �� �ҷ����� �׽�Ʈ
        const std::string filename = "city_data.txt";
        combinedCity.saveToFile(filename);

        SmartCity loadedCity("", 0);
        loadedCity.loadFromFile(filename);

        std::cout << "\nLoaded City Information:\n";
        loadedCity.displayInfo();

    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
