#include "HelpersCpp.h"
#include <string>
#include <ctime>

std::string date_string()
{
    time_t rawtime;
    std::time(&rawtime);
    struct tm *tinfo = std::localtime(&rawtime);
    char buffer[12];
    strftime(buffer, 12, "%F", tinfo);
    return std::string(buffer);
}
