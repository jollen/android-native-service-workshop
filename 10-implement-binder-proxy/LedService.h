#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class ILedService: public IInterface
{
public:
   enum {
        CONNECT = IBinder::FIRST_CALL_TRANSACTION,
        LED_ON,
        LED_OFF
   };

    DECLARE_META_INTERFACE(LedService);

    int setOn(int led);
    int setOff(int led);
};

class BnLedService: public BnInterface<ILedService>
{
public:
    virtual status_t    onTransact( uint32_t code,
                                    const Parcel& data,
                                    Parcel* reply,
                                    uint32_t flags = 0);
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
