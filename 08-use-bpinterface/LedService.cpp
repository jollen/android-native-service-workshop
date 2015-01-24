#include <stdint.h>
#include <math.h>
#include <sys/types.h>

#include <utils/SortedVector.h>
#include <utils/KeyedVector.h>
#include <utils/threads.h>
#include <utils/Atomic.h>
#include <utils/Errors.h>
#include <utils/RefBase.h>
#include <utils/String16.h>
#include <binder/Binder.h>
#include <binder/IServiceManager.h>

#include "LedService.h"

namespace android {

class BpLedService: public BpInterface<ILedService>
{
public:
    BpLedService(const sp<IBinder>& impl)
        : BpInterface<ILedService>(impl)
    {
    }

    virtual int setOn(int led)
    {
        return 0;
    }

    virtual int setOff(int led)
    {
        return 0;
    }

};

IMPLEMENT_META_INTERFACE(LedService, "mokoid.hardware.ILedService");

LedService::LedService()
{
}

// Singleton
void LedService::instantiate() {
     defaultServiceManager()->addService(
             String16("led"), new LedService());
}

};
