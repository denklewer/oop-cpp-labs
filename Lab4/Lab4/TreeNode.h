#pragma once
#include "TreeItem.h"
class TreeNode
{
	friend class Tree;
	TreeItem *data;
	TreeNode *left, *right;
public:
	TreeNode() { left = right = 0;  data = 0; }
	TreeNode(TreeItem *data)
	{
		left = right = 0;
		this->data = data->Clone();
	}
	TreeNode(int id, String name)
	{
		left = right = 0;
		data = new TreeItem(id, name);
	}
	TreeNode(TreeNode *node)
	{
		left = right = 0;
		data = node->data->Clone();
	}
};
