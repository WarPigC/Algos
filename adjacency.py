# adjacency list implementation in python

from collections import defaultdict

def makeList(edges: list):
    d = defaultdict(list)

    for i, j in edges:
        if not len(d[j]):
            d[j] = []
        d[i].append(j)

    return d

def dfs(edges: list):  
    def backtrack(source, target, Dict, count):
        if source == target:
            return 1
        
        for i in Dict[source]:
            count += backtrack(i, target, Dict, 0)
        return count

    d = makeList(edges)

    return backtrack('A', 'D', d, 0)


def bfs(edges: list):  

    source = 'A'
    target = 'D'
    d = makeList(edges)
    count = 0

    q = [source]

    while len(q):
        temp = q.pop()
        
        if temp == target:
            count += 1
            continue
        
        for i in d[temp]:
            q.append(i)
    return count


def main():
    edges = [["A", "B"],  ["B", "C"], ["B", "E"], ["C", "E"], ["E", "D"]]
   
    # num of paths to target node
    print(dfs(edges))
    print(bfs(edges))

    # answer should be 2 with the following list:
    # edges = [["A", "B"],  ["B", "C"], ["B", "E"], ["C", "E"], ["E", "D"]]

if __name__ == '__main__': main()
