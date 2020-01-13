#pragma once
#include "stdafx.h"
#include "Word.h"

void Word::Set(int id, String english, String russian)
{
	this->id = id;
	if (english.GetLength() > maxName)
		this->name = english.substr(0, maxName);
	else
		this->name = english;
	if (russian.GetLength() > maxName)
		this->russian = russian.substr(0, maxName);
	else
		this->russian = russian;
}

Word::Word() { Set(-1, "none", "none"); }
Word::Word(int id, String english, String russian) { Set(id, english, russian); }
Word::Word(const Word& tmp) { Set(tmp.id, tmp.name, tmp.russian); }

Word::~Word(){}

void Word::setRussian(String str){ Set(this->id, this->name, str); }
Word* Word::Clone() { return new Word(id, name, russian); }
String Word::ToString(){



	return 	 name + "\t" + russian;
}