#include "City.h"
#include <iostream>

int main() {
    try {
        // SmartCity 객체 생성
        SmartCity city1("Futureville", 500000);
        city1.addFeature("Automated Traffic Control");
        city1.addFeature("Smart Energy Management");

        SmartCity city2("TechTown", 300000);
        city2.addFeature("AI-assisted Healthcare");
        city2.addFeature("Green Energy Systems");

        // 도시 비교
        if (city1 > city2) {
            std::cout << city1.name << " is larger than " << city2.name << ".\n";
        }
        else {
            std::cout << city2.name << " is larger than " << city1.name << ".\n";
        }

        // 도시 병합
        SmartCity combinedCity = city1 + city2;
        std::cout << "\nCombined City Information:\n";
        combinedCity.displayInfo();

        // 파일 입출력 테스트
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
