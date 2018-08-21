#include "ServiceProxy.h"
#include "ActualService.h"

using namespace turtle;

ServiceProxy* ServiceProxy::_serviceProxy = nullptr;

ServiceProxy* ServiceProxy::GetInstance()
{
    if (_serviceProxy) return _serviceProxy;

    _serviceProxy = new ServiceProxy();

    return _serviceProxy;
}

void ServiceProxy::SetMockObject(IService * mockObject)
{
    ServiceProxy* sp = ServiceProxy::GetInstance();
    sp->_mockService = mockObject;
}

bool ServiceProxy::Walk(const std::string & path) const
{
    if (_mockService) return _mockService->Walk(path);
    else return ActualService::GetInstance()->Walk(path);
}
