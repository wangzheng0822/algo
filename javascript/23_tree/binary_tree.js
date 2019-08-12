class Node {
    constructor(value) {
        this.value = value;
        this.left = null;
        this.right = null;
    }
}
/**
 * 搜索二叉树
 *  允许重复值添加
 *  实现有点弯弯绕
 */
class SearchTree {
    constructor() {
        this.root = null;
    }
    insert(num) {
        let node = new Node(num);
        if (this.root === null) {
            this.root = node;
            return
        }
        let prent = this.getPrev(num);
        if (num < prent.value) {
            prent.left = node;
        } else {
            prent.right = node;
        }

    }
    remove(num) {
        let point = this.root;
        let prent = null;
        let tree = this;

        let res = null;
        while (true) {
            if (point.left) {
                if (num < point.left.value || num < point.value) {
                    prent = point;
                    point = point.left;
                    continue
                }
            }
            if (point.right) {
                if (num >= point.right.value || num >= point.value) {
                    if (num === point.value) {
                        delMethod(point, prent);
                        if (prent === null) {
                            point = this.root;
                        } else {
                            prent = prent;
                            point = prent.right;
                        }
                        res = true;
                        continue
                    }
                    prent = point;
                    point = point.right;
                    continue
                }
            }
            if (point.value === num) {
                res = true;
                delMethod(point, prent);
            }
            break;
        }
        return res;
        function delMethod(delNode, parent) {
            let p = delNode; // p指向要删除的节点
            let pp = parent; // pp记录的是p的父节点 

            // 要删除的节点有两个子节点
            if (p.left != null && p.right != null) { // 查找右子树中最小节点
                let minP = p.right;
                let minPP = p; // minPP表示minP的父节点
                while (minP.left != null) {
                    minPP = minP;
                    minP = minP.left;
                }
                p.value = minP.value; // 将minP的数据替换到p中
                p = minP; // 下面就变成了删除minP了
                pp = minPP;
            }

            // 删除节点是叶子节点或者仅有一个子节点
            let child; // p的子节点
            if (p.left != null) child = p.left;
            else if (p.right != null) child = p.right;
            else child = null;

            if (pp == null) {
                tree.root = child
            }
            else if (pp.left == p) {
                pp.left = child;
            }
            else {
                pp.right = child;
            }
        }

    }
    //中序遍历
    print() {
        let point = this.root;
        if (point) {
            printAll(point.left)
            console.log(point.value);
            printAll(point.right)
        }
        function printAll(point) {
            if (point == null) {
                return
            }
            printAll(point.left);
            console.log(point.value);
            printAll(point.right)
        }
    }
    find(num) {
        if (this.root === null) {
            this.root = node;
            return
        }
        return this.getPrev(num, true);
    }
    //添加和查找的公用部分
    getPrev(num, find = false) {
        let point = this.root;
        let res = [];
        while (true) {
            if (point.left) {
                if (num < point.left.value || num < point.value) {
                    point = point.left
                    continue
                }
            }

            if (point.right) {
                if (num >= point.right.value || num >= point.value) {
                    //搜索时如果有多个值则缓存
                    if (find && num === point.value) {
                        res.push(point.value);
                    }
                    point = point.right;
                    continue
                }
            }
            //如果是搜索
            if (find) {
                if (point.value === num) {
                    res.push(point.value);
                }

                if (res.length === 0) {
                    return null
                }

                if (res.length === 1) {
                    return res[0];
                }

                return res;
            }
            //如果是添加 返回的是应该添加的那各节点的父节点
            return point;
        }
    }
}



function baseTest() {
    let searchTree = new SearchTree();
    console.log('step 1:')
    searchTree.insert(4);
    searchTree.insert(1);
    searchTree.insert(2);
    searchTree.insert(5);

    searchTree.print(); //1 2 4 5
    console.log('step 2:')
    console.log('5', searchTree.find(5)) //5
    console.log('null:', searchTree.find(6)) //null
    searchTree.insert(5);
    searchTree.insert(5);
    console.log('5,5,5:', searchTree.find(5))


}
//删除测试
function delTest() {
    let searchTree = new SearchTree();
    console.log('add: 4 1 2 5 ')
    searchTree.insert(4);
    searchTree.insert(1);
    searchTree.insert(2);
    searchTree.insert(5);
    searchTree.print(); //1 2 4 5
    //console.log('del 3 null:', searchTree.remove(3));
    console.log('del 1 true:', searchTree.remove(1));
    // console.log('print 2 4 5:')
    // searchTree.print();
    // console.log('del 4 root true:', searchTree.remove(4));
    // console.log('print 2 5:')
    // searchTree.print();
    // console.log('add: 3 7 1 5 5 5 ')
    // searchTree.insert(3);
    // searchTree.insert(7);
    // searchTree.insert(1);
    // searchTree.insert(5);
    // searchTree.insert(5);
    // searchTree.insert(5);
    // console.log('print: 1 2 3 5 5 5 5 7 ')
    // searchTree.print();
    // console.log('del 5 true:', searchTree.remove(5));
    // console.log('print: 1 2 3 7 ')
    // searchTree.print();
}

delTest();





