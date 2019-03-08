function lsDist(str1, str2) {
    var n = str1.length;
    var m = str2.length;

    var memo = new Array(n);
    for(let i = 0; i < n; i++) {
        memo[i] = new Array(m);
        if (str1[i] === str2[0]) {
            memo[i][0] = i - 0;
        } else if(i === 0) {
            memo[i][0] = 1;
        } else {
            memo[i][0] = memo[i - 1][0] + 1;
        }
    }

    for(let j = 0; j < m; j++) {
        if(str1[0] === str2[j]) {
            memo[0][j] = j - 0;
        } else if(j === 0) {
            memo[0][j] = 1;
        } else {
            memo[0][j] = memo[0][j - 1] + 1;
        }
    }

    for(let i = 1; i < n; i++) {
        for(let j = 1; j < m; j++) {
            if(str1[i] === str2[j]) {
                memo[i][j] = Math.min(memo[i - 1][j] + 1, memo[i][j - 1] + 1, memo[i - 1][j - 1 ]);
            } else {
                memo[i][j] = Math.min(memo[i - 1][j] + 1, memo[i][j - 1] + 1, memo[i - 1][j - 1 ] + 1);
            }
        }
    }
    console.log(memo);

    return memo[n - 1][m - 1];
}


var s = "mitcmu";
var t = "mtacnu";

console.log( lsDist(s, t) );

var s = "kitten";
var t = "sitting";

console.log( lsDist(s, t) );

var s = "flaw";
var t = "lawn";
console.log( lsDist(s, t) );
