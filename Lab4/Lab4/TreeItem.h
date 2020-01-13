#pragma once

#include "String.h"
using namespace std;

class TreeItem
{
friend class TreeNode;
friend class Tree;
protected:
int id;
String name;
static const int maxName = 30;
static bool byID;
private:
void Set(int, String);
public:
TreeItem();
TreeItem(int, String);
TreeItem(const TreeItem&);

static void SetRule(bool byID);

int CompareTo(TreeItem* data);

virtual TreeItem* Clone();

virtual String ToString();
virtual bool Equals(TreeItem* other);
};