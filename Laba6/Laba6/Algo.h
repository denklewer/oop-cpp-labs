#pragma once
template <class T>
inline const T& Min(const T &x, const T &y)     // поиск минимума
{
	return x < y ? x : y;
}


template <class T>
void Copy(T *x, const T *y, unsigned count)   //   копирование элементов одного массива в другой , при равной длине.
{
	while (count--)
		*x++ = *y++;
}

template <class T>
bool Compare(const T *x, const T *y, unsigned count)        // сравнение элементов двух массивов
{
	while (count--)
	if (*x++ != *y++) return false;
	return true; 
}
        // функции для работы с потоком в массивах
template <class T>
void Read(T *x, unsigned count, istream &stream = cin)            
{
	while (count--)
		stream >> *x++;
}

static const char *WriteDefDelim = " ";
template <class T>
void Write(const T *x, unsigned count, ostream &stream = cout, const char *delim = WriteDefDelim)
{
while (count--)
  stream << *x++ << delim;
}