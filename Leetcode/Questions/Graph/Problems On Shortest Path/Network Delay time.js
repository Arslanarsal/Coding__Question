/**
 * @param {number[][]} times
 * @param {number} n
 * @param {number} k
 * @return {number}
 */
// import MinPriorityQueue from 'heap'; // For the 'heap' library
// import PriorityQueue from 'priorityqueue';
// var networkDelayTime = function (times, n, k) {
//   const graph = new Map();
//   for (const edge of times) {
//     if (!graph.has(edge[0])) {
//       graph.set(edge[0], []);
//     }
//     graph.get(edge[0]).push([edge[1], edge[2]]);
//   }

//   const pq = new MinPriorityQueue({ priority: (x) => x[0] });
//   pq.enqueue([0, k]);

//   const distance = new Array(n + 1).fill(Infinity);
//   distance[k] = 0;

//   while (!pq.isEmpty()) {
//     const [d, u] = pq.dequeue().element;

//     if (d > distance[u]) continue;

//     if (graph.has(u)) {
//       for (const [v, w] of graph.get(u)) {
//         if (distance[v] > distance[u] + w) {
//           distance[v] = distance[u] + w;
//           pq.enqueue([distance[v], v]);
//         }
//       }
//     }
//   }

//   let maxTime = 0;
//   for (let i = 1; i <= n; i++) {
//     if (distance[i] === Infinity) return -1;
//     maxTime = Math.max(maxTime, distance[i]);
//   }

//   return maxTime;
// };



// Importing the MinPriorityQueue class from a library
// import MinPriorityQueue from 'heap'; // For the 'heap' library

// Define tasks with their priorities
// const tasks = [
//     ['Task 1', 5], // Task 1 has priority 5
//     ['Task 2', 3], // Task 2 has priority 3
//     ['Task 3', 8], // Task 3 has priority 8
//     ['Task 4', 1]  // Task 4 has priority 1
// ];

// // Create a new MinPriorityQueue instance
// const pq = new MinPriorityQueue({ priority: (x) => x[1] });

// // Insert tasks into the priority queue
// tasks.forEach(task => {
//     pq.enqueue(task);
// });

// // Dequeue tasks from the priority queue in order of priority
// while (!pq.isEmpty()) {
//     const task = pq.dequeue().element;
//     console.log(`Executing task: ${task[0]} (Priority: ${task[1]})`);
// }