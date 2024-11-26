def jagga_tax(test_cases):
    results = []
    for case in test_cases:
        N, M, edges = case
        
        # Step 1: Initialize graph
        graph = {i: [] for i in range(1, N + 1)}
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        # Step 2: Calculate shortest paths using Floyd-Warshall
        from collections import defaultdict, deque
        shortest_path_counts = defaultdict(int)
        
        for start in range(1, N + 1):
            # Perform BFS from start
            dist = [-1] * (N + 1)
            dist[start] = 0
            queue = deque([start])
            paths = defaultdict(list)  

            while queue:
                node = queue.popleft()
                for neighbor in graph[node]:
                    if dist[neighbor] == -1: 
                        dist[neighbor] = dist[node] + 1
                        queue.append(neighbor)
                    if dist[neighbor] == dist[node] + 1:  
                        paths[neighbor].append(node)

            for end in range(1, N + 1):
                if end != start:
                    for via in paths[end]:
                        shortest_path_counts[via] += 1

        
        sorted_crossings = sorted(range(1, N + 1), 
                                  key=lambda x: (-shortest_path_counts[x], x))

      
        results.append(sorted_crossings[:5])

    return results


t = int(input())
test_cases = []
for _ in range(t):
    N, M = map(int, input().split())
    edges = [tuple(map(int, input().split())) for _ in range(M)]
    test_cases.append((N, M, edges))


answers = jagga_tax(test_cases)
for answer in answers:
    print("\n".join(map(str, answer)))