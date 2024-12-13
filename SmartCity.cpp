#include "SmartCity.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

// 생성자: 스마트 도시 이름과 인구를 초기화
SmartCity::SmartCity(const std::string& name, int population) : City(name, population) {}

// 스마트 기능을 추가하는 함수
void SmartCity::addFeature(const std::string& feature) {
    features.addFeature(feature);
}

// 스마트 도시 정보를 출력하는 함수 (가상 함수 구현)
void SmartCity::displayInfo() const {
    std::cout << "City: " << name << ", Population: " << population << std::endl;
    std::cout << "Smart Features: " << std::endl;
    features.displayFeatures();
}

// 연산자 오버로딩: 두 스마트 도시를 병합
SmartCity SmartCity::operator+(const SmartCity& other) const {
    SmartCity combinedCity(this->name + " & " + other.name, this->population + other.population);

    // 병합된 도시의 스마트 기능 리스트를 구성
    for (const auto& feature : this->features.getFeatures()) {
        combinedCity.addFeature(feature);
    }
    for (const auto& feature : other.features.getFeatures()) {
        if (std::find(combinedCity.features.getFeatures().begin(),
            combinedCity.features.getFeatures().end(),
            feature) == combinedCity.features.getFeatures().end()) {
            combinedCity.addFeature(feature);
        }
    }
    return combinedCity;
}

// 스마트 도시 데이터를 파일에 저장하는 함수
void SmartCity::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) throw std::runtime_error("Failed to open file for writing.");
    outFile << name << "\n" << population << "\n";
    for (const auto& feature : features.getFeatures()) {
        outFile << feature << "\n";
    }
}

// 파일에서 스마트 도시 데이터를 불러오는 함수
void SmartCity::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) throw std::runtime_error("Failed to open file for reading.");
    std::getline(inFile, name);
    inFile >> population;
    inFile.ignore();
    features = FeatureList<std::string>(); // 기존 리스트 초기화
    std::string feature;
    while (std::getline(inFile, feature)) {
        features.addFeature(feature);
    }
}
