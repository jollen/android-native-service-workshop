#include <utils/RefBase.h>
#include <binder/IInterface.h>
#include <binder/Parcel.h>

namespace android {

class BnLedService: public BnInterface<ILedService>
{

};

}
