#pragma once

#ifdef SERVICEPROXY_EXPORTS
#define SERVICEPROXY_API __declspec(dllexport)
#else 
#define SERVICEPROXY_API __declspec(dllimport)
#endif

#include "IService.h"

namespace turtle
{
    class SERVICEPROXY_API ServiceProxy : public IService
    {
    public:
        static ServiceProxy* GetInstance();

        static void SetMockObject(IService* mockObject);
        
        virtual bool Walk(const std::string& path) const;

    private:
        ServiceProxy() = default;

        static ServiceProxy* _serviceProxy;

        IService* _mockService;
    };
} // end namespace turtle
