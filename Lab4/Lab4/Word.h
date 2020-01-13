#pragma once
#include "TreeItem.h"
class Word : public TreeItem
{
	void Set(int id, String english, String russian);
	String russian;
public:
	//конструкторы
	Word();
	Word(int id, String english, String russian);
	Word(const Word&);

	~Word();
	void setRussian(String str);
	virtual Word* Clone();
	virtual String ToString();









};