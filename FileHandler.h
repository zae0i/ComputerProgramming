#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "SmartCity.h"
#include <string>

// ���� ������� ����ϴ� �Լ� ����
void saveCityToFile(const SmartCity& city, const std::string& filename);
SmartCity loadCityFromFile(const std::string& filename);

#endif
