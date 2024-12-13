#ifndef FEATURE_LIST_H
#define FEATURE_LIST_H

#include <vector>
#include <iostream>

// 제네릭 클래스를 사용하여 스마트 도시의 기능을 관리
template <typename T>
class FeatureList {
private:
    std::vector<T> features; // 스마트 기능을 저장하는 동적 배열

public:
    // 스마트 기능을 추가하는 함수
    void addFeature(const T& feature) {
        features.push_back(feature);
    }

    // 모든 스마트 기능을 출력하는 함수
    void displayFeatures() const {
        for (const auto& feature : features) {
            std::cout << " - " << feature << std::endl;
        }
    }

    // 스마트 기능 리스트를 반환하는 함수
    const std::vector<T>& getFeatures() const {
        return features;
    }
};

#endif
