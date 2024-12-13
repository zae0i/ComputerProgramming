#include "FileHandler.h"

// ����Ʈ ���� �����͸� ���Ͽ� ����
void saveCityToFile(const SmartCity& city, const std::string& filename) {
    city.saveToFile(filename);
}

// ���Ͽ��� ����Ʈ ���� �����͸� �ҷ���
SmartCity loadCityFromFile(const std::string& filename) {
    SmartCity city("", 0);
    city.loadFromFile(filename);
    return city;
}
