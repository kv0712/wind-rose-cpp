#ifndef PROCESSING_H
#define PROCESSING_H

#include <vector>
#include "wind_rose.h"

double calculateAverageSpeed(const std::vector<WindRecord>& records, int month);

#endif