/**
 * author dreamapplehappy
 * 关于代码的一些解释可以看一下这里：https://github.com/dreamapplehappy/blog/tree/master/2018/12/02
 */

const MAX_LEVEL = 16;

class Node{
    data = -1;
    maxLevel = 0;
    refer = new Array(MAX_LEVEL);
}

class SkipList{
    levelCount = 1;
    head = new Node();

    static randomLevel() {
        let level = 1;
        for(let i = 1; i < MAX_LEVEL; i++) {
            if(Math.random() < 0.5) {
                level++;
            }
        }
        return level;
    }

    insert(value) {
        const level = SkipList.randomLevel();
        const newNode = new Node();
        newNode.data = value;
        newNode.maxLevel = level;
        const update = new Array(level).fill(new Node());
        let p = this.head;
        for(let i = level - 1; i >= 0; i--) {
            while(p.refer[i] !== undefined && p.refer[i].data < value) {
                p = p.refer[i];
            }
            update[i] = p;
        }
        for(let i = 0; i < level; i++) {
            newNode.refer[i] = update[i].refer[i];
            update[i].refer[i] = newNode;
        }
        if(this.levelCount < level) {
            this.levelCount = level;
        }
    }

    find(value) {
        if(!value){return null}
        let p = this.head;
        for(let i = this.levelCount - 1; i >= 0; i--) {
            while(p.refer[i] !== undefined && p.refer[i].data < value) {
                p = p.refer[i];
            }
        }

        if(p.refer[0] !== undefined && p.refer[0].data === value) {
            return p.refer[0];
        }
        return null;
    }

    remove(value) {
        let _node;
        let p = this.head;
        const update = new Array(new Node());
        for(let i = this.levelCount - 1; i >= 0; i--) {
            while(p.refer[i] !== undefined && p.refer[i].data < value){
                p = p.refer[i];
            }
            update[i] = p;
        }

        if(p.refer[0] !== undefined && p.refer[0].data === value) {
            _node = p.refer[0];
            for(let i = 0; i <= this.levelCount - 1; i++) {
                if(update[i].refer[i] !== undefined && update[i].refer[i].data === value) {
                    update[i].refer[i] = update[i].refer[i].refer[i];
                }
            }
            return _node;
        }
        return null;
    }

    printAll() {
        let p = this.head;
        while(p.refer[0] !== undefined) {
            // console.log(p.refer[0].data)
            p = p.refer[0];
        }
    }
}
