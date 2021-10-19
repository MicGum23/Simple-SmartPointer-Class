#include "Reference.h"

void Reference::addReference()
{
	this->count++;
}

long Reference::release()
{
	return --this->count;
}
