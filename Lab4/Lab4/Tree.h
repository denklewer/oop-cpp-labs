#pragma once
#include "TreeNode.h"
#include "stdafx.h"

class Tree
{

private:
	TreeNode* root;
	TreeItem* search;

	TreeNode* Insert(TreeNode* node, TreeItem* data)
	{
		if (node == 0)
			return new TreeNode(data);
		else
		{
			if (data->CompareTo(node->data) < 0)
				node->left = Insert(node->left, data);
			else
				node->right = Insert(node->right, data);
			return node;
		}
	}
	void Print(TreeNode* node){
		
	
		if (node != 0){

			if (node->left != 0){

				Print(node->left);
			}
			cout << node->data->id << "\t" << (node->data->ToString().GetString()) << "\n";
			if (node->right != 0){
				Print(node->right);

			}
		}
	}
	TreeItem* LookUp(TreeNode* node, int id){   // поиск по ID
		if (node == 0){ return 0; }
		if (node->data->id == id){
			return node->data;
		}
		if (node->data->id > id){
			return LookUp(node->left, id);
		}
		if (node->data->id < id){
			return LookUp(node->right, id);
		}
	}
	TreeItem* LookUp(TreeNode* node, String eng){     // поиск по имени
		if (node == 0){ return 0; }
		if (node->data->name == eng){
			return node->data;
		}
		if (node->data->name > eng){
			return LookUp(node->left, eng);
		}
		if (node->data->name < eng){
			return LookUp(node->right, eng);
		}
	}
	TreeNode* DeleteByName(TreeNode* node, TreeItem* data)   // удаление по имени
	{
		if (node == 0)
			return node;
		else
		{
			if (data->name<node->data->name){
				node->left = DeleteByName(node->left, data);
				return node;
			}
			else if (data->name>node->data->name) {
				node->right = DeleteByName(node->right, data);
				return node;
			}
			else if (data->name == node->data->name){
				if (node->left == 0 && node->right == 0){
					node->data = NULL;
					node = NULL;
					return node;
				}


				else if (node->left == 0){ node->data = node->right->data; node->left = node->right->left; node->right = node->right->right; return node; }
				else if (node->right == 0){ node->data = node->left->data; node->left = node->left->left; node->right = node->left->right; return node; }
				else  if (node->right->left == 0){ node->data = node->right->data;  node->right = node->right->right; return node; }
				else { 
					TreeNode* pT = node->right;
					while (pT->left->left != NULL)
					{
						pT = pT->left;
					}


					node->data = pT->left->data; pT->left = DeleteByName(pT->left, pT->left->data); return node;
				}
			}
		}
	}

	TreeNode* Delete(TreeNode* node, TreeItem* data)
	{
		if (node == 0)
			return node;
		else
		{
			if (data->id<node->data->id){
				node->left = Delete(node->left, data);
				return node;
			}
			else if (data->id>node->data->id) {
				node->right = Delete(node->right, data);
				return node;
			}
			else if (data->id == node->data->id){
				if (node->left == 0 && node->right == 0){
					node->data = NULL;
					node = NULL;
					return node;
				}


				else if (node->left == 0){ node->data = node->right->data; node->left = node->right->left; node->right = node->right->right; return node; }
				else if (node->right == 0){ node->data = node->left->data; node->left = node->left->left; node->right = node->left->right; return node; }
				else  if (node->right->left == 0){ node->data = node->right->data;  node->right = node->right->right; return node; }
				else {
					TreeNode* pT = node->right;
					while (pT->left->left != NULL)
					{
						pT = pT->left;
					}


					node->data = pT->left->data; pT->left = Delete(pT->left, pT->left->data); return node;
				}
			}
		}
	}




public:
	void Insert(TreeItem* data) { root = Insert(root, data); }
	void Print(){
		Print(root);
	};
	TreeItem* LookUp(int id) { return LookUp(root, id); }
	TreeItem* LookUp(String eng) { return LookUp(root, eng); }
	void Delete(TreeItem* data){ root = Delete(root, data); }
	void DeleteByName(TreeItem* data){ root = DeleteByName(root, data); }
};
