#include "City.h"

// ������: ���� �̸��� �α��� �ʱ�ȭ
City::City(const std::string& name, int population) : name(name), population(population) {}

// ������ �����ε�: �� ������ �α��� ��
bool City::operator>(const City& other) const {
    return this->population > other.population;
}

// ���� �Ҹ���: �޸� ������ ����
City::~City() {}
