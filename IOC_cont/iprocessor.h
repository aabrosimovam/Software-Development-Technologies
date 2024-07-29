#ifndef IPROCESSOR_H
#define IPROCESSOR_H

#include <iostream>
using namespace std;

enum ProcessorType
{
   x86=86,
   x64=64
};

class IProcessor
{
  public:
    IProcessor(){}
    virtual string GetterProcessor()=0;
    virtual void SetterProcessor(string version, ProcessorType type, double speed)=0;
    virtual ~IProcessor(){}
};

class IntelProcessor:public IProcessor
{
     string Version;
     ProcessorType Type;
     double Speed;
   public:
     IntelProcessor(){}
     string GetterProcessor()
     {
         string speed = to_string(Speed);
         string type = to_string(Type);
         return  "Processor for " + Version + ". It`s speed = " + speed + "; Type = " + type;
     }

     void SetterProcessor(string version, ProcessorType type, double speed)
     {
         Version = version;
         Type = type;
         Speed = speed;
     }
     ~IntelProcessor(){}

 };

class AMDProcessor:public IProcessor
{
    string Version;
    ProcessorType Type;
    double Speed;
  public:
    AMDProcessor(){}
    string GetterProcessor()
    {
        string speed = to_string(Speed);
        string type = to_string(Type);
        return  "Processor for " + Version + ". It`s speed = " + speed + "; Type = " + type;
    }

    void SetterProcessor(string version, ProcessorType type, double speed)
    {
        Version = version;
        Type = type;
        Speed = speed;
    }
    ~AMDProcessor(){}
};


#endif // IPROCESSOR_H
