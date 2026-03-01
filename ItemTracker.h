#ifndef ITEM_TRACKER_H
#define ITEM_TRACKER_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <iomanip>
#include <algorithm>
#include <cctype>

/**
 * Class: ItemTracker
 * Purpose: Manages grocery item data, including file processing,
 * data persistence, and frequency reporting
 */
class ItemTracker {
private:
    // Stores item names as keys and their purchase counts as values
    std::map<std::string, int> itemFrequencies;

    // Internal helper to read input and populate the map
    void loadInitialData(std::string filename);

    // Internal helper to create the required backup data file
    void saveBackup(std::string filename);

    // Helper to convert strings to lowercase for case-insensitive matching
    std::string toLowerCase(std::string str);

    // Helper to capitalize the first letter of a string
    std::string capitalize(std::string str);

public:
    // Constructor: Initializes the tracker and processes the data file
    ItemTracker(std::string filename);

    // Returns the frequency of a specific item; returns 0 if not found
    int getItemFrequency(std::string item);

    // Displays a list of all unique items and their total counts
    void printAllFrequencies();

    // Displays a visual histogram of item purchase frequencies
    void printHistogram();
};

#endif