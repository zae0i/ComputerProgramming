#include <algorithm>
#include "City.h"
#include <fstream>
#include <stdexcept>

// City Ŭ���� ������
City::City(const std::string& name, int population) : name(name), population(population) {}

// �� ������ �α��� ���ϴ� ������ �����ε� ����
bool City::operator>(const City& other) const {
    return this->population > other.population;
}

// City Ŭ���� �Ҹ���
City::~City() {}

// SmartCity Ŭ���� ������
SmartCity::SmartCity(const std::string& name, int population) : City(name, population) {}

// ����Ʈ ����� �߰��ϴ� �Լ�
void SmartCity::addFeature(const std::string& feature) {
    features.push_back(feature);
}

// ����Ʈ ���� ������ ����ϴ� �Լ� (�߻� �Լ� ����)
void SmartCity::displayInfo() const {
    std::cout << "City: " << name << ", Population: " << population << std::endl;
    std::cout << "Smart Features: " << std::endl;
    for (const auto& feature : features) {
        std::cout << " - " << feature << std::endl;
    }
}

// ���� �����͸� ���Ͽ� �����ϴ� �Լ�
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

// ���Ͽ��� ����Ʈ ���� �����͸� �ҷ����� �Լ�
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

// �� ����Ʈ ������ ����Ʈ ����� ��ġ�� ������ �����ε� ����
SmartCity SmartCity::operator+(const SmartCity& other) const {
    SmartCity combinedCity(this->name + " & " + other.name, this->population + other.population);
    combinedCity.features = this->features;

    // �ٸ� ������ ����Ʈ ��� ���� (�ߺ� ����)
    for (const auto& feature : other.features) {
        if (std::find(combinedCity.features.begin(), combinedCity.features.end(), feature) == combinedCity.features.end()) {
            combinedCity.features.push_back(feature);
        }
    }
    return combinedCity;
}
