// adjacency list implementation in cpp

#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue> 

typedef std::pair<char, char> charPair;
typedef std::vector<charPair> vChar;
typedef std::unordered_map<char, std::vector<char>> map;

map makeList(vChar v){
	map m;

	for (auto& i: v){
		if (m[i.second].size() == 0){
			m[i.second]  = {};
		}
		m[i.first].push_back(i.second);
	}
	
	return m;
}

int dfs(char source, char target, map m, int count){
	if (source == target) return 1;

	for (auto& i: m[source]){
		count += dfs(i, target, m, 0);
	}
	return count;
}

int bfs(char source, char target, map m){
	int count = 0;
	std::queue<char> q;
	q.push(source);

	while (q.size()){
		char temp = q.front();
		q.pop();

		if (temp == target){
			++count;
			continue;
		}

		for (auto& i: m[source]){
			q.push(i);
		}
	}

	return count;
}


int main(){

	vChar v{
			{'A', 'B'},
			{'B', 'C'},
			{'B', 'E'},
			{'C', 'E'},
			{'E', 'D'}
	};

	auto d = makeList(v);

	// count all paths from A to D
	// result is 2

	std::cout << dfs('A', 'D', d, 0) << std::endl;
	std::cout << bfs('A', 'D', d) << std::endl;

	return 0;
}
