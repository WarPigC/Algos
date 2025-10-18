#include <iostream>
#include <string>
#include <vector>

void solve (){

	int n; std::cin >> n;
	std::vector<std::string> data;
	int maxBit = 0;

	for(int i = 0; i < n; ++i){
		int temp; std::cin >> temp;
		std::string sData = "";
		int tempBit = 0;

		while (temp){
			sData = (((temp & 1) == 1) ? '1' : '0') + sData;
			temp >>= 1;
			++tempBit;
		}
		maxBit = std::max(maxBit, tempBit);

		data.push_back(sData);
	}
	for(auto& i: data){
		auto s = i.size();
		for(int j = 0; j < maxBit - s; ++j){
			i = '0' + i;
		}
	}


	std::string final("", maxBit);

	for(int i = 0; i < maxBit; ++i){
		int ones = 0;
		for(int j = 0; j < n; ++j){
			if (data[j][i] == '1') ++ones;
		}
		if (ones & 1) final[i] = '1';
		else final[i] = '0';
	}

	data.push_back(final);

	for(auto& i: data) std::cout << i << '\n';
}

int main(){
	
}
