#pragma once

#ifdef ACTUALSERVICE_EXPORTS
#define ACTUALSERVICE_API __declspec(dllexport)
#else 
#define ACTUALSERVICE_API __declspec(dllimport)
#endif

#include "IService.h"

namespace turtle
{
    class ACTUALSERVICE_API ActualService : public IService
    {
    public:
        static ActualService* GetInstance();

        bool Walk(const std::string& path) const;

    private:
        ActualService() = default;

        static ActualService* _actualService;
    };
} // end namespace turtle
