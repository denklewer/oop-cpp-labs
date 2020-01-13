#pragma once
#include <assert.h>
#include "Algo.h"
template <class T>
class Array {
private :
	unsigned FCount;
	T* FData;
public:
	Array(unsigned count = 0) :FCount(0)  // создание массива из count элементов
	{
		Resize(count, false);
	};
	Array(unsigned count, const T *data) :FCount(0) {     
		
		Assign(count, data);
	};

	Array(const Array& arr) :FCount(0){// конструктор копирования
		Assign(arr.FCount, arr.FData);
	}
	
	~Array(){
		Clear();
	};
	unsigned Count() const { return FCount; }
	void Count(unsigned count){ Resize(count); }
	void Assign(unsigned count, const T *data){ // устанавливает размер массива count и копирует в него элементы из data 
		Resize(count, false);
		Copy(FData, data, FCount);
	}
	void Insert(const Array& arr,unsigned place, unsigned a1, unsigned a2) {
		T *p = new T[FCount-place];
		Copy(p, (FData + place), (FCount - place));
		unsigned count = FCount + (a2 - a1)+1;
		Resize(count, true);
		
		unsigned i;
		unsigned j;
		for ( i = a1, j = place; i < a2 + 1; i++, j++){
			FData[j] = arr.FData[i];
}
		for ( i = place + a2, j =0; i < count; i++,j++){
			FData[i] = p[j];
		}
	}

	void Resize(unsigned count, bool store = true) {// изменение размера и копирование элементов если нужно.
		if (FCount != count) {

			if (count) {
				T *p = new T[count];
				if (store)	Copy(p, FData, Min(FCount, count));
				if (FCount) delete[] FData;
				FData = p;
			}

			else delete[] FData;

			FCount = count;
		}
	};

	void Clear() {
		Count(0);
	}
	Array& operator=(const Array& arr) {
		if (this != &arr)
			Assign(arr.FCount, arr.FData);
		return *this;
	}
	const T& operator [] (unsigned index) const {// операция индексации для константного массива
		assert(index < FCount);
		return Fdata[index];
	}
	T& operator [] (unsigned index) {
		assert(index < FCount);
		return FData[index];

	}
	// операция вывода в поток
	friend ostream& operator <<(ostream &stream, const Array& array)
	{
		
		Write(array.FData, array.FCount, stream);
			return stream;
	};

	// Операция ввода из потока.
	friend istream& operator >>(istream &stream, Array& array)
	{
			Read(array.FData, array.FCount, stream);
		return stream;
	};


	friend bool operator ==(const Array& x, const Array& y)
	{

		if (&x != &y)
		
		if (x.FCount == y.FCount)
			
			return Compare(x.FData, y.FData, FCount);
		// Иначе, массивы не равны.
		else
			return false;
	
		return true;
	};


	



	friend bool operator !=(const Array& x, const Array& y) {
		return !(x == y);
	};


};

