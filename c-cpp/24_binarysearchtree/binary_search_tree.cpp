#include <iostream>

using namespace std;

typedef int DataType;

struct tree_node
{
	DataType data;
	tree_node* left=NULL;
	tree_node* right=NULL;
};

class binary_search_tree{
private:
	tree_node* root;
	int num;
public:
	binary_search_tree() :num(0)
	{
		root = new tree_node;
		root->left = NULL;
		root->right = NULL;
	}

	bool find(DataType it,tree_node* root)
	{
		if (NULL == root)return false;
		if (it == root->data) {
			return true;
		}
		else if (it > root->data)
		{
			return find(it, root->right);
		}
		else
		{
			return find(it, root->left);
		}
	}

	bool find_data(DataType it)
	{
		return find(it, root);
		/*
		tree_node* p = root;
		while (p != NULL)
		{
			if (it < p->data)p = p->left;
			else if (it>p->data)p = p->right;
			else return true;
		}
		return false;
		*/
	}


	void insert_data(DataType it)
	{

		if (0==num)
		{
			root->data = it;
			num++;
			return;
		}
		tree_node* p = root;
		while (p != NULL)
		{
			if (it < p->data)
			{
				if (NULL == p->left)
				{
					p->left = new tree_node;
					p->left->data = it;
					num++;
					return;
				}
				p = p->left;
			}
			else
			{
				if (NULL == p->right)
				{
					p->right = new tree_node;
					p->right->data = it;
					num++;
					return;
				}
				p = p->right;
			}
		}
		
	}

	void delet(DataType it)
	{
		if (NULL == root)return;
		tree_node* p = root;
		tree_node* pp = NULL;//pp记录的是p的父节点
		while (p != NULL&&p->data != it)
		{
			pp = p;
			if (it > p->data)p = p->right;
			else
				p = p->left;
		}
		if (p == NULL)return;//没有找到
		//删除的节点有两个子节点
		if (p->left != NULL&&p->right != NULL)
		{
			tree_node* minP = p->right;
			tree_node* minPP = p;//记录P的父节点
			while (minP->left != NULL)//寻找右子树最小节点
			{
				minPP = minP;
				minP = minP->left;
			}
			p->data = minP->data;//将minP替换到p中
			//将p换到叶节点上，使用叶节点方法进行删除
			p = minP;
			pp = minPP;
		}

		//删除节点是叶节点或者是仅有一个节点
		tree_node* child;
		if (p->left != NULL) child = p->left;
		else if (p->right != NULL) child = p->right;
		else child = NULL;

		if (NULL == pp) root = child;//删除的是根节点
		else if (p == pp->left)pp->left = child;
		else pp->right = child;
	}

	DataType get_max()
	{
		if (NULL == root)return NULL;
		tree_node* tmp=root;
		while (tmp->right != NULL)
		{
			tmp = tmp->right;
		}
		return tmp->data;
	}
	DataType get_min()
	{
		if (NULL == root)return NULL;
		tree_node* tmp=root;
		while (tmp->left != NULL)
		{
			tmp = tmp->left;
		}
		return tmp->data;
	}

	DataType get_prenode(DataType it)
	{
		if (NULL == root)return NULL;
		if (it == root->data) return NULL;
		tree_node* p=root;
		tree_node* pp=NULL;
		while ((p->data != it)&&(p!=NULL))
		{
			pp = p;
			if (p->data < it)
			{
				p=p->right;
			}
			else
			{
				p = p->left;
			}
		}
		return ((NULL==p)?NULL:pp->data);
	}

	DataType get_postnode(DataType it)
	{
		if (NULL == root)return -1;
		tree_node* p = root;
		while ((p->data != it) && (p != NULL))
		{
			if (p->data < it)
			{
				p = p->left;
			}
			else
			{
				p = p->right;
			}
		}
		if (NULL == p)
		{
			return -1;
		}
		else if (p->left!=NULL)
		{
			return p->left->data;
		}
		else if (p->right!=-NULL)
		{
			return p->right->data;
		}
		else
		{
			return NULL;
		}
	}

	void mid_order(tree_node* rt)
	{
		if (NULL == rt)return;
		mid_order(rt->left);
		cout << rt->data;
		mid_order(rt->right);
	}
	void order()
	{
		if (NULL == root)return;
		return mid_order(root);
	}

	int get_high(tree_node* rt)
	{
		int lhigh = 0;
		int rhigh = 0;
		if (NULL == rt)return 0;
		lhigh = get_high(rt->left);
		rhigh = get_high(rt->right);
		return ((lhigh > rhigh) ? (lhigh + 1) : (rhigh + 1));
	}

	int high()
	{
		if (NULL == root) return 1;
		return get_high(root);
	}
};

int main()
{
	binary_search_tree my_tree;

	my_tree.insert_data(5);
	my_tree.insert_data(4);
	my_tree.insert_data(6);
	my_tree.insert_data(10);
	my_tree.insert_data(3);
	my_tree.insert_data(8);
	my_tree.insert_data(1);
	if (my_tree.find_data(3))
	{
		cout << "找到了数字3" << endl;
	}
	else
	{
		cout << "没有找到数字3" << endl;
	}
	my_tree.delet(4);
	cout << "Max" << my_tree.get_max() << endl;
	cout << "Min" << my_tree.get_min() << endl;
	cout << "pre node of 5 is " <<my_tree.get_prenode(5) <<endl;
	cout << "post node of 5 is " << my_tree.get_postnode(5) << endl;
	my_tree.order();
	cout << "high of tree is " << my_tree.high() << endl;
	return 0;
} 