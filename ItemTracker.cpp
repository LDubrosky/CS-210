#include "ItemTracker.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//constructor calls loadData so it can be used
ItemTracker::ItemTracker(string fileName) {
    loadData(fileName);
}

//reads strings from the file 
void ItemTracker::loadData(string fileName) {
    ifstream inputFile(fileName);
    string item;

    //checks for file
    if (inputFile.is_open()) {
        while (inputFile >> item) {
            //adds to the count for the item
            itemFrequencyMap[item]++;
        }
        inputFile.close();
    }
    else {
        cerr << "Error: Could not open input file." << endl; //error if the file is not found
    }
}

//searching for a specific item frequency
int ItemTracker::GetItemFrequency(string itemName) {
    if (itemFrequencyMap.count(itemName)) {
        return itemFrequencyMap.at(itemName);
    }
    return 0; //return 0 if item is not found
}
//lists all item frequencies
void ItemTracker::PrintAllFrequencies() {
    for (const auto& pair : itemFrequencyMap) {
        cout << pair.first << " " << pair.second << endl;
    }
}
//creates a histogram using "*"
void ItemTracker::PrintHistogram() {
    for (const auto& pair : itemFrequencyMap) {
        //pair.first is the item name and pair.second is the frequency
        cout << left << setw(12) << pair.first << " ";
        //the loop adds one "*" for each time the name shows up
        for (int i = 0; i < pair.second; ++i) {
            cout << "*";
        }
        cout << endl;
    }
}
//creates the backup
void ItemTracker::SaveBackupFile(string outputFileName) {
    ofstream outFile(outputFileName);
    if (outFile.is_open()) {
        for (const auto& pair : itemFrequencyMap) {
            outFile << pair.first << " " << pair.second << endl;
        }
        outFile.close();
    }
}
