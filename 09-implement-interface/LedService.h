#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class ILedService: public IInterface
{
public:
    DECLARE_META_INTERFACE(LedService);

    int setOn(int led);
    int setOff(int led);
};

class BnLedService: public BnInterface<ILedService>
{

};

class LedService: public BnLedService
{
public:
    static void instantiate();
    virtual int setOn(int led);
    virtual int setOff(int led);

private:
    LedService();
    virtual ~LedService();
}; 

}
