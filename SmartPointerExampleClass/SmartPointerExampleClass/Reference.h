#pragma once
class Reference
{
private:
	long count;
	
public:
	void addReference();
	long release();
};

