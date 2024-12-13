#include <algorithm>
#include "City.h"
#include <fstream>
#include <stdexcept>

// City 클래스 생성자
City::City(const std::string& name, int population) : name(name), population(population) {}

// 두 도시의 인구를 비교하는 연산자 오버로딩 구현
bool City::operator>(const City& other) const {
    return this->population > other.population;
}

// City 클래스 소멸자
City::~City() {}

// SmartCity 클래스 생성자
SmartCity::SmartCity(const std::string& name, int population) : City(name, population) {}

// 스마트 기능을 추가하는 함수
void SmartCity::addFeature(const std::string& feature) {
    features.push_back(feature);
}

// 스마트 도시 정보를 출력하는 함수 (추상 함수 구현)
void SmartCity::displayInfo() const {
    std::cout << "City: " << name << ", Population: " << population << std::endl;
    std::cout << "Smart Features: " << std::endl;
    for (const auto& feature : features) {
        std::cout << " - " << feature << std::endl;
    }
}

// 도시 데이터를 파일에 저장하는 함수
void SmartCity::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) {
        throw std::runtime_error("Failed to open file for writing.");
    }
    outFile << name << "\n" << population << "\n";
    for (const auto& feature : features) {
        outFile << feature << "\n";
    }
    outFile.close();
}

// 파일에서 스마트 도시 데이터를 불러오는 함수
void SmartCity::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) {
        throw std::runtime_error("Failed to open file for reading.");
    }
    std::getline(inFile, name);
    inFile >> population;
    inFile.ignore();
    features.clear();
    std::string feature;
    while (std::getline(inFile, feature)) {
        features.push_back(feature);
    }
    inFile.close();
}

// 두 스마트 도시의 스마트 기능을 합치는 연산자 오버로딩 구현
SmartCity SmartCity::operator+(const SmartCity& other) const {
    SmartCity combinedCity(this->name + " & " + other.name, this->population + other.population);
    combinedCity.features = this->features;

    // 다른 도시의 스마트 기능 병합 (중복 제거)
    for (const auto& feature : other.features) {
        if (std::find(combinedCity.features.begin(), combinedCity.features.end(), feature) == combinedCity.features.end()) {
            combinedCity.features.push_back(feature);
        }
    }
    return combinedCity;
}
