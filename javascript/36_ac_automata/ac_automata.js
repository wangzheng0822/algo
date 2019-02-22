
MAX_LEN = 128;

class ACNode {
    constructor(data){
        this.data = data;
        this.children = new Array(MAX_LEN);
        this.isEndingChar = false;
        this.length = 0;
        this.fail = null;
    }
}

class ACTree {

    constructor(data){
        this.root = new ACNode('/')
    }

    insert (text) {
        let node = this.root;
        for (let char of text) {
            let index = char.charCodeAt() + 1;
            if(!node.children[index]) {
                node.children[index] = new ACNode(char);
            }
            node = node.children[index];
        }

        node.isEndingChar = true;
        node.length = text.length;
    }

    buildFailurePointer() {
        let root = this.root;
        let queue = [];
        queue.push(root);

        while (queue.length > 0) {
            let p = queue.shift();

            for (let i = 0; i < MAX_LEN; i++) {
                let pc = p.children[i];
                if (!pc) {
                    continue;
                } 

                if(p == root) {
                    pc.fail = root;
                } else {
                    let q = p.fail;
                    while (q) {
                        let qc = q.children[pc.data.charCodeAt() + 1];
                        if(qc) {
                            pc.fail = qc;
                            break;
                        }
                        q = q.fail;
                    }
                    if(!q) {
                        pc.fail = root;
                    }
                }
                queue.push(pc);
            }
        }
    }

    match (text) {
        let root = this.root;
        let n = text.length;
        let p = root;

        for(let i = 0; i < n; i++) {
            let idx = text[i].charCodeAt() + 1;
            while(!p.children[idx] && p != root){
                p = p.fail;
            }

            p = p.children[idx];
            if(!p) {
                p = root;
            }

            let tmp = p;
            while ( tmp != root) {
                if (tmp.isEndingChar == true) {
                    console.log(`Start from ${i - p.length + 1}, length: ${p.length}`);
                }
                tmp = tmp.fail;
            }
        }
    }
}

let automata = new ACTree();
let patterns = ["at", "art", "oars", "soar"];
for (let pattern of patterns) {
    automata.insert(pattern);
}

automata.buildFailurePointer()
automata.match("soarsoars");