
# Question in DSA using Python NPTEL week 3 assignment

# Based on the question in Indian National Olympiad in Informatics, 2005

# https://www.iarcs.org.in/inoi/2005/inoi2005/inoi2005-qpaper.pdf


from collections import deque

m, n = map(int, input().split())

r = []
for i in range(m):
    r.append(list(map(int, input().split())))

d = []
for i in range(m):
    d.append(list(map(int, input().split())))

queue = deque([(0, 0, 0)])
visited = [[False] * n for _ in range(m)]
visited[0][0] = True

while queue:
    row, col, jumps = queue.popleft()
    
    if row == m - 1 and col == n - 1:
        print(jumps)
        break
    
    for step in range(1, r[row][col] + 1):
        new_col = col + step
        if new_col < n and not visited[row][new_col]:
            visited[row][new_col] = True
            queue.append((row, new_col, jumps + 1))
    
    for step in range(1, d[row][col] + 1):
        new_row = row + step
        if new_row < m and not visited[new_row][col]:
            visited[new_row][col] = True
            queue.append((new_row, col, jumps + 1))
