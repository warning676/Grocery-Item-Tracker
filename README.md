# Corner Grocer Item Tracker

> Coursework for CS-210 at Southern New Hampshire University (SNHU)

## Project Summary

This project is a data analysis tool designed for "The Corner Grocer" to track the frequency of items purchased throughout a day. It reads a text-based input file, processes the data to consolidate item counts regardless of capitalization, and provides a menu for searching specific items, viewing a full frequency list, or displaying a visual histogram.

---

## Successes

I am particularly proud of the data encapsulation within the `ItemTracker` class. By using a `std::map<std::string, int>`, I was able to create an efficient lookup system that handles data storage and retrieval in a clean, organized manner.

---

## Potential Enhancements

To make the code more secure and efficient, I could implement more robust file-path handling to ensure the program doesn't crash if the input file is missing. Additionally, transitioning to a database or a more structured JSON format for the backup file (`frequency.dat`) would improve data portability and scalability.

---

## Challenges and Solutions

The most challenging part was ensuring case-insensitive matching (e.g., treating "Apples" and "apples" as the same item). I overcame this by creating a `toLowerCase` helper function using the `std::transform` algorithm. To support my growth, I am adding the C++ Standard Library documentation (cppreference.com) and Stack Overflow to my support network for troubleshooting complex STL containers.

---

## Transferable Skills

The logic used for file I/O and data persistence is highly transferable to any software development role. Specifically, the ability to read unstructured data from a file and transform it into a structured format (a Map) is a fundamental skill in data science and back-end development.

---

## Maintainability and Readability

To ensure the program is maintainable, I used clear, descriptive variable names and included comments for every function. I also followed the Single Responsibility Principle by separating the User Interface (in `main.cpp`) from the data logic (in `ItemTracker.cpp`), making the code easier to adapt or update in the future.
