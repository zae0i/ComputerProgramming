#ifndef SMART_CITY_H
#define SMART_CITY_H

#include "City.h"
#include "FeatureList.h"

// ����Ʈ ���ø� ��Ÿ���� Ŭ���� (City Ŭ���� ���)
class SmartCity : public City {
private:
    FeatureList<std::string> features; // ���׸� Ŭ������ ����� ����Ʈ ��� ����Ʈ

public:
    // ������: ����Ʈ ���� �̸��� �α��� �ʱ�ȭ
    SmartCity(const std::string& name, int population);

    // ����Ʈ ����� �߰��ϴ� �Լ�
    void addFeature(const std::string& feature);

    // ���� ������ ����ϴ� �Լ� (���� �Լ� ����)
    void displayInfo() const override;

    // ���� �����͸� ���Ͽ� �����ϴ� �Լ�
    void saveToFile(const std::string& filename) const;

    // ���Ͽ��� ���� �����͸� �ҷ����� �Լ�
    void loadFromFile(const std::string& filename);

    // ������ �����ε�: �� ���ø� ����
    SmartCity operator+(const SmartCity& other) const;
};

#endif
