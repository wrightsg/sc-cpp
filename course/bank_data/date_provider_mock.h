#ifndef SC_CPP_DATE_PROVIDER_MOCK_H
#define SC_CPP_DATE_PROVIDER_MOCK_H

#include "gmock/gmock.h"

#include "date_provider.h"

class DateProviderMock : public DateProvider
{
public:
    MOCK_CONST_METHOD0(get_date, std::string());
};

#endif //SC_CPP_DATE_PROVIDER_MOCK_H
