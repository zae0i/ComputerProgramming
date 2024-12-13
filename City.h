#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>
#include <iostream>

// 추상 클래스로 도시를 나타냄
class City {
protected:
    std::string name; // 도시 이름
    int population;   // 도시 인구

public:
    // 도시 이름과 인구를 초기화하는 생성자
    City(const std::string& name, int population);

    // 도시 정보를 출력하는 순수 가상 함수 (추상 메서드)
    virtual void displayInfo() const = 0;

    // 두 도시의 인구를 비교하는 연산자 오버로딩
    bool operator>(const City& other) const;

    // 가상 소멸자
    virtual ~City();
};

// 스마트 도시를 나타내는 파생 클래스
class SmartCity : public City {
private:
    std::vector<std::string> features; // 스마트 기능 리스트

public:
    // 스마트 도시 이름과 인구를 초기화하는 생성자
    SmartCity(const std::string& name, int population);

    // 스마트 기능을 추가하는 함수
    void addFeature(const std::string& feature);

    // 스마트 도시 정보를 출력하는 함수 (추상 함수 구현)
    void displayInfo() const override;

    // 도시 데이터를 파일에 저장하는 함수
    void saveToFile(const std::string& filename) const;

    // 파일에서 도시 데이터를 불러오는 함수
    void loadFromFile(const std::string& filename);

    // 두 스마트 도시의 스마트 기능을 합치는 연산자 오버로딩
    SmartCity operator+(const SmartCity& other) const;
};

#endif
