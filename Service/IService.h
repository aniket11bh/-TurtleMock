#pragma once

#ifdef SERVICE_EXPORTS
#define SERVICE_API __declspec(dllexport)
#else 
#define SERVICE_API __declspec(dllimport)
#endif

#include <iostream>
#include <string>

namespace turtle
{
    class IService
    {
    public:

        virtual SERVICE_API bool Walk(const std::string& path) const = 0;

        virtual ~IService() = default;

    };
} // end namespace turtle
