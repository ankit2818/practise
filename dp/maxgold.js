mine = 
[
    [1, 3, 1, 5],
    [2, 2, 4, 1],
    [5, 0, 2, 3],
    [0, 6, 1, 2]
]
row = mine.length
col = mine[0].length

function max(a,b) {
    return a > b ? a : b
}

function solveUtility(r, c, memo = {}) {
    let key = r+","+c
    if(r >= row || r < 0 || c >= col) return 0;
    if(memo[key]) return memo[key];
    memo[key] =  mine[r][c] + max(solveUtility(r-1, c+1, memo), max(solveUtility(r, c+1, memo), solveUtility(r+1,c+1, memo)))
    return memo[key];
}

function solve() {
    let maxgold = 0
    for(let i = 0; i < row; i++) {
        let value = solveUtility(i, 0)
        if(maxgold < value) maxgold = value
    }
    return maxgold
}

console.log(solve())

// [
//     [1, 3, 1, 5],
//     [2, 2, 4, 1],
//     [5, 0, 2, 3],
//     [0, 6, 1, 2]
// ]