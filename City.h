#ifndef CITY_H
#define CITY_H

#include <string>
#include <vector>
#include <iostream>

// �߻� Ŭ������ ���ø� ��Ÿ��
class City {
protected:
    std::string name; // ���� �̸�
    int population;   // ���� �α�

public:
    // ���� �̸��� �α��� �ʱ�ȭ�ϴ� ������
    City(const std::string& name, int population);

    // ���� ������ ����ϴ� ���� ���� �Լ� (�߻� �޼���)
    virtual void displayInfo() const = 0;

    // �� ������ �α��� ���ϴ� ������ �����ε�
    bool operator>(const City& other) const;

    // ���� �Ҹ���
    virtual ~City();
};

// ����Ʈ ���ø� ��Ÿ���� �Ļ� Ŭ����
class SmartCity : public City {
private:
    std::vector<std::string> features; // ����Ʈ ��� ����Ʈ

public:
    // ����Ʈ ���� �̸��� �α��� �ʱ�ȭ�ϴ� ������
    SmartCity(const std::string& name, int population);

    // ����Ʈ ����� �߰��ϴ� �Լ�
    void addFeature(const std::string& feature);

    // ����Ʈ ���� ������ ����ϴ� �Լ� (�߻� �Լ� ����)
    void displayInfo() const override;

    // ���� �����͸� ���Ͽ� �����ϴ� �Լ�
    void saveToFile(const std::string& filename) const;

    // ���Ͽ��� ���� �����͸� �ҷ����� �Լ�
    void loadFromFile(const std::string& filename);

    // �� ����Ʈ ������ ����Ʈ ����� ��ġ�� ������ �����ε�
    SmartCity operator+(const SmartCity& other) const;
};

#endif
