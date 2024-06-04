#ifndef BOOKINGSYSTEM_H
#define BOOKINGSYSTEM_H

#include "Venue.h"
#include <unordered_map>
#include <string>

class BookingSystem {
private:
    std::unordered_map<std::string, Venue> venues;

public:
    void addVenue(const std::string& name);
    void addDateToVenue(const std::string& venueName, const std::string& date);
    bool bookVenue(const std::string& venueName, const std::string& date);
    void loadFromCSV(const std::string& filename);
    void saveToCSV(const std::string& filename);
    void printVenues();
};

#endif // BOOKINGSYSTEM_H
