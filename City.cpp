#include "City.h"

// 생성자: 도시 이름과 인구를 초기화
City::City(const std::string& name, int population) : name(name), population(population) {}

// 연산자 오버로딩: 두 도시의 인구를 비교
bool City::operator>(const City& other) const {
    return this->population > other.population;
}

// 가상 소멸자: 메모리 누수를 방지
City::~City() {}
