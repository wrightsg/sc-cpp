#ifndef SC_CPP_DATE_PROVIDER_H
#define SC_CPP_DATE_PROVIDER_H

#include <string>

class DateProvider
{
public:
    virtual ~DateProvider () = default;
    virtual std::string get_date () const = 0;
};

#endif //SC_CPP_DATE_PROVIDER_H
