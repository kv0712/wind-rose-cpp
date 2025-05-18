#ifndef WIND_ROSE_H
#define WIND_ROSE_H

#include <vector>
#include <string>

struct WindRecord {
    int day;
    int month;
    std::string direction;
    double speed;
};

void readData(const std::string& filename, std::vector<WindRecord>& records);
void printRecords(const std::vector<WindRecord>& records);

void shakerSort(std::vector<WindRecord>& records);
void mergeSort(std::vector<WindRecord>& records);

bool compareBySpeed(const WindRecord& a, const WindRecord& b);  
bool compareByDate(const WindRecord& a, const WindRecord& b);   

#endif