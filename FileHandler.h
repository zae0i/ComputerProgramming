#ifndef FILE_HANDLER_H
#define FILE_HANDLER_H

#include "SmartCity.h"
#include <string>

// 파일 입출력을 담당하는 함수 선언
void saveCityToFile(const SmartCity& city, const std::string& filename);
SmartCity loadCityFromFile(const std::string& filename);

#endif
