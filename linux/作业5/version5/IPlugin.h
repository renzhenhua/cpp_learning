#ifndef _IPLUGIN_H_
#define _IPLUGIN_H_

class IPlugin
{
public:
	virtual void Print() = 0;
	virtual void Help() = 0;
	virtual int GetID() = 0;
	virtual char* GetName() = 0;
	virtual void Func(char*) = 0;
public:
	IPlugin(){
	}
	virtual ~IPlugin(){
	}
};

#endif
