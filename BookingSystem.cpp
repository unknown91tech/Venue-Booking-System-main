#include "BookingSystem.h"
#include <fstream>
#include <sstream>
#include <iostream>

void BookingSystem::addVenue(const std::string& name) {
    venues[name] = Venue(name);
}

void BookingSystem::addDateToVenue(const std::string& venueName, const std::string& date) {
    venues[venueName].addDate(date);
}

bool BookingSystem::bookVenue(const std::string& venueName, const std::string& date) {
    return venues[venueName].bookDate(date);
}

void BookingSystem::loadFromCSV(const std::string& filename) {
    std::ifstream file(filename);
    std::string line;
    while (getline(file, line)) {
        std::istringstream ss(line);
        std::string venueName, date;
        getline(ss, venueName, ',');
        addVenue(venueName);
        while (getline(ss, date, ',')) {
            addDateToVenue(venueName, date);
        }
    }
}

void BookingSystem::saveToCSV(const std::string& filename) {
    std::ofstream file(filename);
    for (const auto& pair : venues) {
        file << pair.first;
        for (const auto& date : pair.second.availableDates) {
            file << "," << date;
        }
        file << "\n";
    }
}

void BookingSystem::printVenues() {
    for (const auto& pair : venues) {
        std::cout << "Venue: " << pair.first << "\nAvailable Dates:\n";
        for (const auto& date : pair.second.availableDates) {
            std::cout << "  " << date << "\n";
        }
    }
}
