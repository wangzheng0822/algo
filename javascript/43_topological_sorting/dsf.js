
function Graph() {
    var graph = {
        adj: new Map(),
        addEdge: function (from, to){
            if(!this.adj.get(from)) {
                this.adj.set(from, [ to ]);
            } else {
                this.adj.get(from).push(to);
            }
        },
        sortingByDsf: function(){
            var inverseAdj = new Map();
            var keys = this.adj.keys();
            for(let key of keys) {
                let blk = this.adj.get(key);
                if(blk) {
                    for(let v of blk) {
                        if(!inverseAdj.get(v)) {
                            inverseAdj.set(v, [key]);
                        } else {
                            inverseAdj.get(v).push(key);
                        }
                    }
                }
            }

            let inKeys = inverseAdj.keys();
            let vertexes = new Set([...keys, ...inKeys]);
            let visited = [];
            for(let vertex of vertexes) {
                if(!visited.includes(vertex)) {
                    visited.push(vertex);
                    this.dsf(vertex, inverseAdj, visited);
                }
            }
        },
        dsf: function(vertex, inverseAdj, visited) {
            if(!inverseAdj.get(vertex)) {
                inverseAdj.set(vertex, []);
            }

            for(let v of inverseAdj.get(vertex)) {
                if(visited.includes(v)) {
                    continue;
                }

                visited.push(v);

                this.dsf(v, inverseAdj, visited);
            }

            console.log("->" + vertex);
        }
    }

    return graph;
}

var dag = new Graph();
dag.addEdge(2, 1);
dag.addEdge(3, 2);
dag.addEdge(2, 4);
dag.addEdge(4, 1);
dag.sortingByDsf();


var dag2 = new Graph();
dag2.addEdge("main", "parse_options");
dag2.addEdge("main", "tail_file");
dag2.addEdge("main", "tail_forever");
dag2.addEdge("tail_file", "pretty_name");
dag2.addEdge("tail_file", "write_header");
dag2.addEdge("tail_file", "tail");
dag2.addEdge("tail_forever", "recheck");
dag2.addEdge("tail_forever", "pretty_name");
dag2.addEdge("tail_forever", "write_header");
dag2.addEdge("tail_forever", "dump_remainder");
dag2.addEdge("tail", "tail_lines");
dag2.addEdge("tail", "tail_bytes");
dag2.addEdge("tail_lines", "start_lines");
dag2.addEdge("tail_lines", "dump_remainder");
dag2.addEdge("tail_lines", "file_lines");
dag2.addEdge("tail_lines", "pipe_lines");
dag2.addEdge("tail_bytes", "xlseek");
dag2.addEdge("tail_bytes", "start_bytes");
dag2.addEdge("tail_bytes", "dump_remainder");
dag2.addEdge("tail_bytes", "pipe_bytes");
dag2.addEdge("file_lines", "dump_remainder");
dag2.addEdge("recheck", "pretty_name");
dag2.sortingByDsf();
