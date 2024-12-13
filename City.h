#ifndef CITY_H
#define CITY_H

#include <string>
#include <iostream>

// �߻� Ŭ������ ����Ͽ� ������ �⺻ ������ ����
class City {
protected:
    std::string name; // ���� �̸�
    int population;   // ���� �α�

public:
    // ������: ���� �̸��� �α��� �ʱ�ȭ
    City(const std::string& name, int population);

    // ���� �̸��� ��ȯ�ϴ� �Լ�
    virtual std::string getName() const { return name; }

    // ���� ���� �Լ�: ���� ������ ����ϴ� ���
    virtual void displayInfo() const = 0;

    // ������ �����ε�: �� ������ �α��� ��
    bool operator>(const City& other) const;

    // ���� �Ҹ���: �޸� ������ ����
    virtual ~City();
};

#endif
