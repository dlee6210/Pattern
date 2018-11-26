#pragma once
#include"IObserver.h"

class ISubject {
public:
	virtual void AddObject(IObserver *p) = 0;
};