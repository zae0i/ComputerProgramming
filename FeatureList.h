#ifndef FEATURE_LIST_H
#define FEATURE_LIST_H

#include <vector>
#include <iostream>

// ���׸� Ŭ������ ����Ͽ� ����Ʈ ������ ����� ����
template <typename T>
class FeatureList {
private:
    std::vector<T> features; // ����Ʈ ����� �����ϴ� ���� �迭

public:
    // ����Ʈ ����� �߰��ϴ� �Լ�
    void addFeature(const T& feature) {
        features.push_back(feature);
    }

    // ��� ����Ʈ ����� ����ϴ� �Լ�
    void displayFeatures() const {
        for (const auto& feature : features) {
            std::cout << " - " << feature << std::endl;
        }
    }

    // ����Ʈ ��� ����Ʈ�� ��ȯ�ϴ� �Լ�
    const std::vector<T>& getFeatures() const {
        return features;
    }
};

#endif
