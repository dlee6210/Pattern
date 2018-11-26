#pragma once
class IObserver {
public:
	virtual void Nodify(int inum) = 0;
};