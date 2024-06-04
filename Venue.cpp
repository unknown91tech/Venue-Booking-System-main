#include "Venue.h"
#include <algorithm>

Venue::Venue(std::string name) : name(name) {}

void Venue::addDate(const std::string& date) {
    availableDates.push_back(date);
}

bool Venue::bookDate(const std::string& date) {
    auto it = std::find(availableDates.begin(), availableDates.end(), date);
    if (it != availableDates.end()) {
        availableDates.erase(it);
        return true;
    }
    return false;
}
