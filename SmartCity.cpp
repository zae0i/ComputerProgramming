#include "SmartCity.h"
#include <algorithm>
#include <fstream>
#include <stdexcept>

// ������: ����Ʈ ���� �̸��� �α��� �ʱ�ȭ
SmartCity::SmartCity(const std::string& name, int population) : City(name, population) {}

// ����Ʈ ����� �߰��ϴ� �Լ�
void SmartCity::addFeature(const std::string& feature) {
    features.addFeature(feature);
}

// ����Ʈ ���� ������ ����ϴ� �Լ� (���� �Լ� ����)
void SmartCity::displayInfo() const {
    std::cout << "City: " << name << ", Population: " << population << std::endl;
    std::cout << "Smart Features: " << std::endl;
    features.displayFeatures();
}

// ������ �����ε�: �� ����Ʈ ���ø� ����
SmartCity SmartCity::operator+(const SmartCity& other) const {
    SmartCity combinedCity(this->name + " & " + other.name, this->population + other.population);

    // ���յ� ������ ����Ʈ ��� ����Ʈ�� ����
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

// ����Ʈ ���� �����͸� ���Ͽ� �����ϴ� �Լ�
void SmartCity::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    if (!outFile) throw std::runtime_error("Failed to open file for writing.");
    outFile << name << "\n" << population << "\n";
    for (const auto& feature : features.getFeatures()) {
        outFile << feature << "\n";
    }
}

// ���Ͽ��� ����Ʈ ���� �����͸� �ҷ����� �Լ�
void SmartCity::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile) throw std::runtime_error("Failed to open file for reading.");
    std::getline(inFile, name);
    inFile >> population;
    inFile.ignore();
    features = FeatureList<std::string>(); // ���� ����Ʈ �ʱ�ȭ
    std::string feature;
    while (std::getline(inFile, feature)) {
        features.addFeature(feature);
    }
}
