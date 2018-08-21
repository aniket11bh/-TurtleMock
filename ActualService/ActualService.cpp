#include "ActualService.h"

using namespace turtle;

ActualService* ActualService::_actualService = nullptr;


ActualService * turtle::ActualService::GetInstance()
{
    if (_actualService) return _actualService;
    
    _actualService = new ActualService();

    return _actualService;
}


bool ActualService::Walk(const std::string & path) const
{
    std::cout << "Actual service called " << std::endl;
    return true;
}