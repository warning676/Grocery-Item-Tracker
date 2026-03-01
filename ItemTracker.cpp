#include "ItemTracker.h"

ItemTracker::ItemTracker(std::string filename) {
    loadInitialData(filename);
}

/**
 * Converts string to lowercase
 */
std::string ItemTracker::toLowerCase(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(),
        [](unsigned char c) { return std::tolower(c); });
    return str;
}

/**
 * Capitalizes the first letter of a string for the UI
 */
std::string ItemTracker::capitalize(std::string str) {
    if (!str.empty()) {
        str[0] = std::toupper(str[0]);
    }
    return str;
}

void ItemTracker::loadInitialData(std::string filename) {
    std::ifstream inputFile(filename);
    std::string itemName;

    if (inputFile.is_open()) {
        while (inputFile >> itemName) {
            // Store everything in lowercase to consolidate counts
            itemFrequencies[toLowerCase(itemName)]++;
        }
        inputFile.close();
    }
    else {
        std::cerr << "Error: Could not open input file " << filename << std::endl;
    }

    saveBackup("frequency.dat");
}

void ItemTracker::saveBackup(std::string filename) {
    std::ofstream outputFile(filename);
    if (outputFile.is_open()) {
        for (auto const& [item, count] : itemFrequencies) {
            outputFile << capitalize(item) << " " << count << std::endl;
        }
        outputFile.close();
    }
}

int ItemTracker::getItemFrequency(std::string item) {
    std::string searchKey = toLowerCase(item);
    if (itemFrequencies.count(searchKey)) {
        return itemFrequencies.at(searchKey);
    }
    return 0;
}

void ItemTracker::printAllFrequencies() {
    for (auto const& [item, count] : itemFrequencies) {
        // Capitalize only for the console output
        std::cout << capitalize(item) << " " << count << std::endl;
    }
}

void ItemTracker::printHistogram() {
    for (auto const& [item, count] : itemFrequencies) {
        // Capitalize for the histogram label
        std::cout << std::left << std::setw(12) << capitalize(item) << " ";
        for (int i = 0; i < count; ++i) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}