## 如何設計與實作 Android Native Service

## Step 1: Use BnInterface template

* Native service 的 server 使用 BnInterface template

```
class BnLedService: public BnInterface<ILedService>
{
};
```

## Step 2: Declare ILedService and extend framework

** 將 ILedService 擴充 (extend) 至 Android Framework

```
class ILedService: public IInterface
{

};
```

## Step 3: Declare LedService class 

* 物件的實例化將會使用 singleton pattern
* 使用 virtual function (polymorphism)

```
class LedService: public BnLedService
{
private:
    LedService();
    virtual ~LedService();
};
```

## Step 4: Define APIs

* 使用 *instantiate()* 取得 instance (singleton pattern)

```
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
```





