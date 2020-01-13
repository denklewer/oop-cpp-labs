#pragma once
#include <assert.h>
#include "Algo.h"
#include "stackExcp.h"
template <class T>
class Stack {
private :
	
	unsigned FCount;  // максимальное число элементов в стеке
	unsigned top;
	T* FData;
	
public:
	Stack(unsigned count = 0) :FCount(0)  // создание стека из count элементов
	{

		Resize(count, false);
		top = -1;
	};
	Stack(unsigned count, const T *data) :FCount(0) {       // создание полного стека из count элементов
		
		Assign(count, data);
	};

	Stack(const Stack& arr) :FCount(0){// конструктор копирования
		Assign(arr.FCount, arr.FData);
	}
	
	~Stack(){
		Clear();
	};
	unsigned Count() const { return FCount; }
	void Count(unsigned count){ Resize(count); }
	void Assign(unsigned count, const T *data){ // устанавливает размер стека count и копирует в него элементы из data
		Resize(count, false);
		Copy(FData, data, FCount);
		top = count;
	}
	void Insert(const Stack& arr,unsigned place, unsigned a1, unsigned a2) {
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
	Stack& operator=(const Stack& arr) {
		if (this != &arr)
			Assign(arr.FCount, arr.FData);
		return *this;
	}
	const T& operator [] (unsigned index) const {// операция индексации для константного массива
		if (index > top) { throw StackOutOfRange(index); };
		return Fdata[index];
	}
	T& operator [] (unsigned index) {
		if (index > top) { throw StackOutOfRange(index); };
		return FData[index];

	}
	// операция вывода в поток
	friend ostream& operator <<(ostream &stream, const Stack& array)
	{
		
		Write(array.FData, array.FCount, stream);
			return stream;
	};

	// Операция ввода из потока.
	friend istream& operator >>(istream &stream, Stack& array)
	{
			Read(array.FData, array.FCount, stream);
		return stream;
	};


	friend bool operator ==(const Stack& x, const Stack& y)
	{

		if (&x != &y)
		
		if (x.FCount == y.FCount)
			
			return Compare(x.FData, y.FData, FCount);
		
		else
			return false;
	
		return true;
	};


	



	friend bool operator !=(const Stack& x, const Stack& y) {
		return !(x == y);
	};


	bool full(){ if (top == FCount-1) { return true; } else { return false; } };
	bool empty() {
		if (top == -1) { return true; }
		else { return false; };
	}
	T& Pop()
	{
		if (empty())
			throw StackUnderflow();

		top = top - 1;
		return FData[top + 1];

		
	}
	void Push(T value)
	{
	

		if (full())
		{
			throw StackOverflow();
		}
	
			top = top + 1;
	
		FData[top] = value;

	}

	unsigned GetSize(){
		
		return (top+1 );
	}
	unsigned Capacity(){
		if (top == -1){
			return FCount;
		}
		else {
			return FCount - top-1;
		}
	}




};

