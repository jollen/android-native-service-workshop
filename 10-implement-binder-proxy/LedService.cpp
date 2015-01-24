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
	Parcel data, reply;
	data.writeInterfaceToken(ILedService::getInterfaceDescriptor());
	data.writeInt32(led);
	remote()->transact(BnLedService::LED_ON, data, &reply);
        return 0;
    }

    virtual int setOff(int led)
    {
	Parcel data, reply;
	data.writeInterfaceToken(ILedService::getInterfaceDescriptor());
	data.writeInt32(led);
	remote()->transact(BnLedService::LED_OFF, data, &reply);
        return 0;
    }

};

IMPLEMENT_META_INTERFACE(LedService, "mokoid.hardware.ILedService");

status_t BnLedService::onTransact(
    uint32_t code, const Parcel& data, Parcel* reply, uint32_t flags)
{
    int result;

    switch(code) {
        case CONNECT:
            CHECK_INTERFACE(ILedService, data, reply);
            return NO_ERROR;
	case LED_ON:
	    CHECK_INTERFACE(ILedService, data, reply);
	    result = setOn(data.readInt32());
	    reply->writeInt32(result);
	    return NO_ERROR;
	case LED_OFF:
	    CHECK_INTERFACE(ILedService, data, reply);
	    result = setOff(data.readInt32());
	    reply->writeInt32(result);
	    return NO_ERROR;
        default:
            return BBinder::onTransact(code, data, reply, flags);
    }
}

LedService::LedService()
{
}

LedService::~LedService()
{
}

// Singleton
void LedService::instantiate() {
     defaultServiceManager()->addService(
             String16("led"), new LedService());
}

int LedService::setOn(int led)
{
    ALOGI("Set: %d ON", led);
    return 0;
}

int LedService::setOff(int led)
{
    ALOGI("Set: %d ON", led);
    return 0;
}

};
