#include "processing.h"
#include <numeric>

double calculateAverageSpeed(const std::vector<WindRecord>& records, int month) {
    double sum = 0.0;
    int count = 0;
    
    for (const auto& record : records) {
        if (record.month == month) {
            sum += record.speed;
            count++;
        }
    }
    
    return count > 0 ? sum / count : 0.0;
}