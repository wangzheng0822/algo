/*
 * Filename: /home/zwk/code/data_structrue/c++/tree/binary_search_tree/main.cpp
 * Path: /home/zwk/code/data_structrue/c++/tree/binary_search_tree
 * Created Date: Wednesday, May 8th 2019, 11:04:48 pm
 * Author: zwk
 *
 * refer to https://time.geekbang.org/column/article/68334
 */

#include <iostream>

using namespace std;

typedef int DataType;

struct treeNode
{
    DataType data;
    treeNode *left = nullptr;
    treeNode *right = nullptr;
};

class binarySearchTree
{
private:
    treeNode *root;
    int num; // tree node numbers
public:
    binarySearchTree() : num(0)
    {
        root = new treeNode;
        root->left = nullptr;
        root->right = nullptr;
    }

    bool find(DataType it, treeNode *root)
    {
        if (nullptr == root)
            return false;
        if (it == root->data) {
            return true;
        } else if (it > root->data) {
            return find(it, root->right);
        } else {
            return find(it, root->left);
        }
    }

    bool find_data(DataType it)
    {
        return find(it, root);
        /*
		treeNode* p = root;
		while (p != nullptr)
		{
			if (it < p->data)p = p->left;
			else if (it>p->data)p = p->right;
			else return true;
		}
		return false;
		*/
    }

    DataType get_max()
    {
        if (nullptr == root)
            return NULL;
        treeNode *tmp = root;
        while (tmp->right != nullptr) {
            tmp = tmp->right;
        }
        return tmp->data;
    }

    DataType get_min()
    {
        if (nullptr == root)
            return NULL;
        treeNode *tmp = root;
        while (tmp->left != nullptr) {
            tmp = tmp->left;
        }
        return tmp->data;
    }

    void insert_data(DataType it)
    //  利用二分查找的思想，借助树的结构使用递归
    {
        if (0 == num) {
            root->data = it;
            num++;
            return;
        }
        treeNode *p = root;
        while (p != nullptr) {
            if (it < p->data) {
                if (nullptr == p->left) {
                    p->left = new treeNode;
                    p->left->data = it;
                    num++;
                    return;
                }
                p = p->left;
            } else {
                if (nullptr == p->right) {
                    p->right = new treeNode;
                    p->right->data = it;
                    num++;
                    return;
                }
                p = p->right;
            }
        }
    }

    DataType get_prenode(DataType it)
    {
        if (nullptr == root)
            return NULL;
        if (it == root->data)
            return NULL;
        treeNode *p = root;
        treeNode *pp = nullptr;
        while (p != nullptr) {
            if (p->data < it) {
                pp = p; // label parent root
                p = p->right;

            } else if (p->data > it) {
                pp = p; // label parent root
                p = p->left;
            } else {

                break;
            }
        }
        return ((nullptr == p) ? NULL : pp->data);
    }

    DataType get_postnode(DataType it)
    {
        if (nullptr == root)
            return -1;
        treeNode *p = root;
        while (p != nullptr) {
            if (p->data < it) {
                p = p->right;
            } else if (p->data > it) {
                p = p->left;
            } else {
                break;
            }
        }
        if (nullptr == p) {
            return -1;
        } else if (p->left != nullptr) {
            return p->left->data;
        } else if (p->right != nullptr) {
            return p->right->data;
        } else {
            return NULL;
        }
    }

    void mid_order(treeNode *rt)
    {
        if (nullptr == rt)
            return;
        mid_order(rt->left);
        cout << rt->data << '\t';
        mid_order(rt->right);
    }

    void order()
    {
        if (nullptr == root)
            return;
        return mid_order(root);
    }

    int get_high(treeNode *rt)
    {
        int lhigh = 0;
        int rhigh = 0;
        if (nullptr == rt)
            return 0;
        lhigh = get_high(rt->left);
        rhigh = get_high(rt->right);
        return ((lhigh > rhigh) ? (lhigh + 1) : (rhigh + 1));
    }

    int high()
    {
        if (nullptr == root)
            return 1;
        return get_high(root);
    }

    void delet(DataType it)
    {
        if (NULL == root)
            return;
        treeNode *p = root;
        treeNode *pp = NULL; //pp记录的是p的父节点
        while (p != NULL && p->data != it) {
            pp = p;
            if (it > p->data)
                p = p->right;
            else
                p = p->left;
        }
        if (p == NULL)
            return; //没有找到
        //删除的节点有两个子节点
        if (p->left != NULL && p->right != NULL) {
            treeNode *minP = p->right;
            treeNode *minPP = p;       //记录P的父节点
            while (minP->left != NULL) //寻找右子树最小节点
            {
                minPP = minP;
                minP = minP->left;
            }
            // 注意这里，非常巧妙的办法。只是换值。“换汤不换药”
            // 用后继节点替换到要删除节点的位置。 然后就变成删除后继节点的问题了。为了逻辑统一 代码书写简洁。我们把后继节点赋给了p
            p->data = minP->data; //将minP的值替换到p中
            //将p换到叶节点上，使用叶节点方法进行删除， 而且最小节点肯定没有左节点，叶节点删除方法参见后面的代码。
            p = minP;
            pp = minPP;
        }

        //删除节点是叶节点或者是仅有一个节点
        treeNode *child;
        if (p->left != NULL)
            child = p->left;
        else if (p->right != NULL)
            child = p->right;
        else
            child = NULL;

        if (NULL == pp)
            root = child; //删除的是根节点
        else if (p == pp->left)
            pp->left = child;
        else
            pp->right = child;
    }
};

int main()
{
    binarySearchTree my_tree;

    // must input in the order of layers
    my_tree.insert_data(33);
    my_tree.insert_data(16);
    my_tree.insert_data(50);
    my_tree.insert_data(13);
    my_tree.insert_data(18);
    my_tree.insert_data(34);
    my_tree.insert_data(58);
    my_tree.insert_data(15);
    my_tree.insert_data(17);
    my_tree.insert_data(25);
    my_tree.insert_data(51);
    my_tree.insert_data(66);
    my_tree.insert_data(19);
    my_tree.insert_data(27);
    my_tree.insert_data(55);

    if (my_tree.find_data(25)) {
        cout << "找到了数字25" << endl;
    } else {
        cout << "没有找到数字25" << endl;
    }
    my_tree.delet(13);
    my_tree.delet(18);
    my_tree.delet(55);
    cout << "Max:  " << my_tree.get_max() << endl;
    cout << "Min:  " << my_tree.get_min() << endl;
    cout << "pre node of 17 is " << my_tree.get_prenode(17) << endl;
    cout << "pre node of 51 is " << my_tree.get_prenode(51) << endl;
    cout << "pre node of 33 is " << my_tree.get_prenode(33) << endl;

    cout << "post node of 19 is " << my_tree.get_postnode(19) << endl;
    cout << "post node of 25 is " << my_tree.get_postnode(25) << endl;
    cout << "post node of 58 is " << my_tree.get_postnode(58) << endl;
    cout << "post node of 58 is " << my_tree.get_postnode(51) << endl;
    my_tree.order();
    cout << "high of tree is " << my_tree.high() << endl;
    return 0;
}
