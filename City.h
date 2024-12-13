#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>

// 추상 클래스를 사용하여 도시의 기본 구조를 정의
class City {
protected:
    std::string name; // 도시 이름
    int population;   // 도시 인구

public:
    // 생성자: 도시 이름과 인구를 초기화
    City(const std::string& name, int population);

    // 도시 이름을 반환하는 함수
    virtual std::string getName() const { return name; }

    // 순수 가상 함수: 도시 정보를 출력하는 기능
    virtual void displayInfo() const = 0;

    // 연산자 오버로딩: 두 도시의 인구를 비교
    bool operator>(const City& other) const;

    // 가상 소멸자: 메모리 누수를 방지
    virtual ~City();
};

#endif
