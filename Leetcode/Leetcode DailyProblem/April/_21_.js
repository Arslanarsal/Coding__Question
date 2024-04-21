/**
 * @param {number} n
 * @param {number[][]} edges
 * @param {number} source
 * @param {number} destination
 * @return {boolean}
 */
var validPath = function (n, edges, source, destination) {
  let edge = Array.from({ length: n }, () => []);
  for (let i = 0; i < edges.length; i++) {
    const [start, end] = edges[i];
    edge[start].push(end);
    edge[end].push(start);
  }
  let visit = new Array(n).fill(0);
  visit[source] = 1;
  let arr = [];
  arr.push(source);
  while (!arr.length) {
    let node = arr[0];
    arr.shift();
    if (node === destination) {
      return true;
    }
    for (let i = 0; i < edge[node].length; i++) {
      if (!visit[edge[node][i]]) {
        arr.push(edge[node][i]);
        visit[edge[node][i]] = 1;
      }
    }
  }
  return false;
};
