#ifndef VENUE_H
#define VENUE_H

#include <string>
#include <vector>

class Venue {
public:
    std::string name;
    std::vector<std::string> availableDates;

    Venue(std::string name);

    void addDate(const std::string& date);
    bool bookDate(const std::string& date);
};

#endif // VENUE_H
