#ifndef SMART_CITY_H
#define SMART_CITY_H

#include "City.h"
#include "FeatureList.h"

// 스마트 도시를 나타내는 클래스 (City 클래스 상속)
class SmartCity : public City {
private:
    FeatureList<std::string> features; // 제네릭 클래스를 사용한 스마트 기능 리스트

public:
    // 생성자: 스마트 도시 이름과 인구를 초기화
    SmartCity(const std::string& name, int population);

    // 스마트 기능을 추가하는 함수
    void addFeature(const std::string& feature);

    // 도시 정보를 출력하는 함수 (가상 함수 구현)
    void displayInfo() const override;

    // 도시 데이터를 파일에 저장하는 함수
    void saveToFile(const std::string& filename) const;

    // 파일에서 도시 데이터를 불러오는 함수
    void loadFromFile(const std::string& filename);

    // 연산자 오버로딩: 두 도시를 병합
    SmartCity operator+(const SmartCity& other) const;
};

#endif
