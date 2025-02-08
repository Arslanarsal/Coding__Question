/**
 * @param {number[][]} edges
 * @param {number[]} nums
 * @return {number[]}
 */
var longestSpecialPath = function (edges, nums) {
    let n = nums.length;
    let adj = Array.from({ length: n }, () => []);

    for (const [u, v, w] of edges) {
        adj[v].push([u, w]);
        adj[u].push([v, w]);
    }

    
};