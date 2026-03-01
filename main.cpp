/**
 * Ben Reynolds
 * February 2026
 */

#include <iostream>
#include <string>
#include <limits>
#include "ItemTracker.h"

 /**
  * Prints a formatted menu to the console
  */
void displayMenu() {
    std::cout << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "  CORNER GROCER ITEM TRACKER   " << std::endl;
    std::cout << "===============================" << std::endl;
    std::cout << "1 - Search for an item" << std::endl;
    std::cout << "2 - Display all frequencies" << std::endl;
    std::cout << "3 - Display histogram" << std::endl;
    std::cout << "4 - Exit program" << std::endl;
    std::cout << "-------------------------------" << std::endl;
    std::cout << "Enter your choice: ";
}

int main() {
    // Instantiate the tracker with the required input file
    ItemTracker tracker("CS210_Project_Three_Input_File.txt");
    int choice = 0;
    std::string searchItem;

    // Main application loop
    while (choice != 4) {
        displayMenu();

        // Input validation for menu selection
        if (!(std::cin >> choice)) {
            std::cout << std::endl << "Error: Invalid input. Please enter a number (1-4)." << std::endl;
            std::cin.clear(); // Clear error flags
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer
            continue;
        }

        std::cout << std::endl;

        // Process user choice
        switch (choice) {
        case 1:
            // Prompt for specific item search
            std::cout << "Enter the item name you wish to look for: ";
            std::cin >> searchItem;
            std::cout << "\nResult: " << searchItem << " appeared "
                << tracker.getItemFrequency(searchItem) << " times." << std::endl;
            break;

        case 2:
            // Display full frequency list
            std::cout << "--- Item Frequency List ---" << std::endl;
            tracker.printAllFrequencies();
            break;

        case 3:
            // Display visual histogram
            std::cout << "--- Item Frequency Histogram ---" << std::endl;
            tracker.printHistogram();
            break;

        case 4:
            // Terminate program
            break;

        default:
            std::cout << "Invalid choice. Please select an option between 1 and 4." << std::endl;
        }

        std::cout << std::endl;
    }

    return 0;
}