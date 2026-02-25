#pragma once
#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <map>
#include <string>

class ItemTracker
{private:
	//a map used to store the items and frequency
	std::map<std::string, int> itemFrequencyMap;
    //helper method to load data
    void loadData(std::string fileName);

public:
    //constructor
    ItemTracker(std::string fileName);
    //menu Option 1
    int GetItemFrequency(std::string itemName);
    //menu Option 2
    void PrintAllFrequencies();
    //menu Option 3
    void PrintHistogram();
    //create the backup frequency.dat file
    void SaveBackupFile(std::string outputFileName);

#endif
};

