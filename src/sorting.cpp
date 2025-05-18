#include "wind_rose.h"
#include <algorithm>

void shakerSort(std::vector<WindRecord>& records) {
    bool swapped = true;
    int start = 0;
    int end = records.size() - 1;

    while (swapped) {
        swapped = false;
        
        // Проход слева направо
        for (int i = start; i < end; ++i) {
            if (compareBySpeed(records[i], records[i+1])) {
                std::swap(records[i], records[i+1]);
                swapped = true;
            }
        }
        
        if (!swapped) break;
        
        swapped = false;
        end--;
        
        // Проход справа налево
        for (int i = end - 1; i >= start; --i) {
            if (compareBySpeed(records[i], records[i+1])) {
                std::swap(records[i], records[i+1]);
                swapped = true;
            }
        }
        
        start++;
    }
}

// Функции сравнения
bool compareBySpeed(const WindRecord& a, const WindRecord& b) {
    return a.speed < b.speed;  
}

bool compareByDate(const WindRecord& a, const WindRecord& b) {
    if (a.month != b.month) return a.month > b.month;
    return a.day > b.day;
}