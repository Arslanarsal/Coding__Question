/**
 * @param {number[][]} graph
 * @return {number[]}
 */
var eventualSafeNodes = function (graph) {
  const n = graph.length;
  let adj = Array.from({ length: n }, () => []);

  let ingoing = Array(n).fill(0);

  for (let i = 0; i < graph.length; i++) {
    for (let j = 0; j < graph[i].length; j++) {
      adj[graph[i][j]].push(i);
      ingoing[i]++;
    }
  }

  let p = new Set();

  for (let i = 0; i < ingoing.length; i++) {
    if (!ingoing[i]) {
      p.add(i);
    }
  }
  let ans = [];
  while (!p.size) {
    let node = p.pop();
    ans.push(node);

    for (const nei of adj[node]) {
      ingoing[nei]--;
      if (!ingoing[i]) {
        p.add(nei);
      }
    }
  }
  ans.sort((a, b) => a - b);
  return ans;
};

// eventualSafeNodes();
let p = new Set([1, 2, 31, 4]);
let iterator = p.values(); // Get an iterator for the values of the Set

console.log(iterator.next()); // Output: { value: 1, done: false }
console.log(iterator.next()); // Output: { value: 2, done: false }
console.log(iterator.next()); // Output: { value: 3, done: false }
console.log(iterator.next()); // Output: { value: 3, done: false }
console.log(p.values()); 
console.log(iterator.next()); // Output: { value: undefined, done: true }
