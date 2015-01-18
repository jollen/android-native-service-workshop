#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class ILedService: public IInterface
{

};

class BnLedService: public BnInterface<ILedService>
{

};

class LedService: public BnLedService
{
private:
    LedService();
    virtual ~LedService();
}; 

}
