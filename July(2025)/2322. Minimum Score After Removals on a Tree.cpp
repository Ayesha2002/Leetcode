

class Solution(object):
    def minimumScore(self, nums, edges):
        
        n = len(nums)
        graph = defaultdict(list)
        for u, v in edges:
            graph[u].append(v)
            graph[v].append(u)

        xor = [0] * n
        in_time = [0] * n
        out_time = [0] * n
        time = [0]  

        def dfs(u, parent):
            in_time[u] = time[0]
            time[0] += 1
            xor[u] = nums[u]
            for v in graph[u]:
                if v != parent:
                    dfs(v, u)
                    xor[u] ^= xor[v]
            out_time[u] = time[0]
            time[0] += 1

        dfs(0, -1)
        total_xor = xor[0]
        min_score = float('inf')

        for i in range(1, n):
            for j in range(i + 1, n):
                def is_ancestor(u, v):
                    return in_time[u] <= in_time[v] and out_time[v] <= out_time[u]

                if is_ancestor(i, j):
                    a = xor[j]
                    b = xor[i] ^ xor[j]
                    c = total_xor ^ xor[i]
                elif is_ancestor(j, i):
                    a = xor[i]
                    b = xor[j] ^ xor[i]
                    c = total_xor ^ xor[j]
                else:
                    a = xor[i]
                    b = xor[j]
                    c = total_xor ^ xor[i] ^ xor[j]

                max_val = max(a, b, c)
                min_val = min(a, b, c)
                min_score = min(min_score, max_val - min_val)

        return min_score
