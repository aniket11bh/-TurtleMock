#pragma once

#ifdef MOCKSERVICE_EXPORTS
#define MOCKSERVICE_API __declspec(dllexport)
#else 
#define MOCKSERVICE_API __declspec(dllimport)
#endif

#include "IService.h"
#include "gmock/gmock.h"

namespace turtle
{
    class MOCKSERVICE_API MockService : public IService
    {
    public:

        MOCK_CONST_METHOD1(Walk, bool(const std::string& path));

        MockService();
        ~MockService();
    };
} // end namespace turtle
