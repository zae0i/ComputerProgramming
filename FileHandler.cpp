#include "FileHandler.h"

// 스마트 도시 데이터를 파일에 저장
void saveCityToFile(const SmartCity& city, const std::string& filename) {
    city.saveToFile(filename);
}

// 파일에서 스마트 도시 데이터를 불러옴
SmartCity loadCityFromFile(const std::string& filename) {
    SmartCity city("", 0);
    city.loadFromFile(filename);
    return city;
}
