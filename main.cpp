#include "BookingSystem.h"
#include <iostream>
#include <limits>

int main() {
    BookingSystem system;
    system.loadFromCSV("venues.csv");

    int choice;
    std::string venueName, date;

    while (true) {
        std::cout << "1. Add Venue\n2. Add Date to Venue\n3. Book Venue\n4. Show Venues\n5. Exit\n";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignore leftover input

        switch (choice) {
            case 1:
                std::cout << "Enter venue name: ";
                std::getline(std::cin, venueName);
                system.addVenue(venueName);
                break;
            case 2:
                std::cout << "Enter venue name: ";
                std::getline(std::cin, venueName);
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                system.addDateToVenue(venueName, date);
                break;
            case 3:
                std::cout << "Enter venue name: ";
                std::getline(std::cin, venueName);
                std::cout << "Enter date (YYYY-MM-DD): ";
                std::getline(std::cin, date);
                if (system.bookVenue(venueName, date)) {
                    std::cout << "Booking successful!\n";
                } else {
                    std::cout << "Booking failed. Date not available.\n";
                }
                break;
            case 4:
                system.printVenues();
                break;
            case 5:
                system.saveToCSV("venues.csv");
                return 0;
            default:
                std::cout << "Invalid choice. Try again.\n";
        }
    }

    return 0;
}
