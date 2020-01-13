#pragma once
#include "stdafx.h"
#include "TreeItem.h"


bool TreeItem::byID = false;


void TreeItem::Set(int id, String name)
	{
		this->id = id;
		this->name = name;
		if (name.GetLength() > maxName)
			this->name = this->name.substr(0, maxName);
	}

TreeItem::TreeItem() { Set(-1, "None"); }
TreeItem::TreeItem(int id, String name) { Set(id, name); }
TreeItem::TreeItem(const TreeItem& r) { Set(r.id, r.name); }

void TreeItem::SetRule(bool byID) { TreeItem::byID = byID; }

int TreeItem::CompareTo(TreeItem* data)
	{
		return byID ? id - data->id : name.compare(data->name);
	}
TreeItem* TreeItem::Clone() { return new TreeItem(id, name); }

String  TreeItem::ToString()
	{
		char buf[128];
		sprintf_s(buf, "%d.\t%s", id, name.GetString());
		return String(buf);
	}
bool  TreeItem::Equals(TreeItem* other)
	{
		return id == other->id && name == other->name;
	}



