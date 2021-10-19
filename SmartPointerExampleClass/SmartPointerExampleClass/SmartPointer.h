#pragma once
#include "Reference.h"

template <typename T>
class SmartPointer
{
private:
	T* pointer_data;
	Reference* reference;

public:
	// CONSTRUCTORS
	SmartPointer();
	SmartPointer(T* pointer_value);
	SmartPointer(const SmartPointer<T>& smart_pointer);

	// DESTRUCTOR
	~SmartPointer();

	// OPERATORS
	T& operator * ();
	T* operator -> ();
	SmartPointer<T>& operator = (const SmartPointer<T>& smart_pointer);
};

// CONSTRUCTORS - definitions
template<typename T>
inline SmartPointer<T>::SmartPointer() : 
	pointer_data(nullptr),
	reference(nullptr)
{
	this->reference = new Reference();
	this->reference->addReference();
}

template<typename T>
inline SmartPointer<T>::SmartPointer(T* pointer_value) : 
	pointer_data(pointer_value),
	reference(nullptr)
{
	this->reference = new Reference();
	this->reference->addReference();
}

template<typename T>
inline SmartPointer<T>::SmartPointer(const SmartPointer<T>& smart_pointer) :
	pointer_data(smart_pointer.pointer_data),
	reference(smart_pointer.reference)
{
	this->reference->addReference();
}

// DESTRUCTOR - definitions
template<typename T>
inline SmartPointer<T>::~SmartPointer()
{
	if (this->reference->release() == 0)
	{
		delete this->pointer_data;
		delete this->reference;
	}
}

// OPERATORS - definitions
template<typename T>
inline T& SmartPointer<T>::operator*()
{
	return *pointer_data;
}

template<typename T>
inline T* SmartPointer<T>::operator->()
{
	return pointer_data;
}

template<typename T>
inline SmartPointer<T>& SmartPointer<T>::operator=(const SmartPointer<T>& smart_pointer)
{
	if (this != &smart_pointer)
	{
		if (this->reference->release() == 0)
		{
			delete this->pointer_data;
			delete this->reference;
		}

		this->pointer_data = smart_pointer.pointer_data;
		this->reference = smart_pointer.reference;

		this->reference->addReference();
	}
	return *this;
}
