#include "SmartCity.h"
#include "FileHandler.h"
#include <iostream>
#include <exception>

int main() {
    try {
        // === ���� 1: �߻� Ŭ������ ���� �Լ� �׽�Ʈ ===
        std::cout << "=== Test 1: Abstract Class and Virtual Function ===" << std::endl;
        SmartCity city1("Futureville", 500000);
        city1.addFeature("Automated Traffic Control");
        city1.addFeature("Smart Energy Management");
        city1.displayInfo();
        std::cout << std::endl;

        // === ���� 2: ������ �ߺ� �׽�Ʈ ===
        std::cout << "=== Test 2: Operator Overloading ===" << std::endl;
        SmartCity city2("TechTown", 300000);
        city2.addFeature("AI-assisted Healthcare");
        city2.addFeature("Green Energy Systems");

        if (city1 > city2) {
            std::cout << city1.getName() << " is larger than " << city2.getName() << ".\n";
        }
        else {
            std::cout << city2.getName() << " is larger than " << city1.getName() << ".\n";
        }

        SmartCity combinedCity = city1 + city2;
        std::cout << "\nCombined City Information:" << std::endl;
        combinedCity.displayInfo();
        std::cout << std::endl;

        // === ���� 3: ���� ����� �׽�Ʈ ===
        std::cout << "=== Test 3: File Input and Output ===" << std::endl;
        const std::string filename = "city_data.txt";
        saveCityToFile(combinedCity, filename);

        SmartCity loadedCity = loadCityFromFile(filename);
        std::cout << "Loaded City Information:" << std::endl;
        loadedCity.displayInfo();
        std::cout << std::endl;

        // === ���� 4: ��ü �迭 Ȱ�� �׽�Ʈ ===
        std::cout << "=== Test 4: Using Object Array ===" << std::endl;
        city1.addFeature("Smart Parking Systems");
        city1.displayInfo();
        std::cout << std::endl;

        // === ���� 5: ���� ó�� �׽�Ʈ ===
        std::cout << "=== Test 5: Exception Handling ===" << std::endl;
        try {
            SmartCity invalidCity("", 0);
            invalidCity.loadFromFile("non_existent_file.txt");
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
        std::cout << std::endl;

    }
    catch (const std::exception& e) {
        std::cerr << "Unexpected Error: " << e.what() << std::endl;
    }

    return 0;
}
