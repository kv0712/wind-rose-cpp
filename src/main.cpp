#include <iostream>
#include <fstream>
#include <vector>
#include "wind_rose.h"
#include "constants.h"

using namespace std;

void readData(const string& filename, vector<WindRecord>& records) {
    ifstream file(filename);
    if (!file.is_open()) {
        cout << "Error opening file!" << endl;
        return;
    }

    WindRecord record;
    while (file >> record.day >> record.month >> record.direction >> record.speed) {
        records.push_back(record);
    }
    file.close();
}

void printRecords(const vector<WindRecord>& records) {
    for (size_t i = 0; i < records.size(); i++) {
        const WindRecord& r = records[i];
        cout << r.day << "." << r.month << " - " << r.direction 
             << " (" << r.speed << " m/s)" << endl;
    }
}

void filterByDirection(const vector<WindRecord>& records) {
    for (size_t i = 0; i < records.size(); i++) {
        const WindRecord& r = records[i];
        if (r.direction == "West" || r.direction == "NorthWest" || r.direction == "North") {
            cout << r.day << "." << r.month << " - " << r.direction << endl;
        }
    }
}

void filterBySpeed(const vector<WindRecord>& records) {
    for (size_t i = 0; i < records.size(); i++) {
        const WindRecord& r = records[i];
        if (r.speed > 5.0) {
            cout << r.day << "." << r.month << " - " << r.speed << " m/s" << endl;
        }
    }
}


int main() {
    vector<WindRecord> records;
    readData("data/wind_data.txt", records);
    
    cout << "=== Все записи ===" << endl;
    printRecords(records);
    
    cout << "\n=== Записи (Запад/Северо-Запад/Север) ===" << endl;
    filterByDirection(records);
    
    cout << "\n=== Записи (скорость > 5 м/с) ===" << endl;
    filterBySpeed(records);
    
    cout << "\n=== Сортировка по скорости (сортировка пузырьком) ===" << endl;
    shakerSort(records); 
    printRecords(records);
    
    cout << "\nВыберите тип сортировки:\n"
         << "1 - По скорости (сильный -> слабый)\n"
         << "2 - По дате (старые -> новые)\n"
         << "Ваш выбор: ";
    
    int choice;
    cin >> choice;
    
    if (choice == 1) {
        shakerSort(records);
    } else if (choice == 2) {
        // Доработайте mergeSort для работы с compareByDate
        cout << "Сортировка по дате (реализуйте отдельно)\n";
    } else {
        cout << "Неверное значение\n";
        return 0;
    }
    cout << "\n=== Результат сортировки ===" << endl;
    printRecords(records);
    
    return 0;
}
