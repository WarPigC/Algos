/*
 *	Burrows Wheeler Transform algorithm is a compression algorithm used with other algorithms like RLE to efficiently work
 *	It uses a Burrows Wheeler matrix to store a string and shift it n times where n is the size of the string 
 *	the matrix's first column is sorted and last column is returned to be processed
 */


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

#define SIZE data.size()

std::string bwt(std::string data){
	std::vector<std::string> bw_matrix;

	for (int i = 0; i < data.size(); ++i){
		data = data[SIZE - 1] + data;
		data.pop_back();
		bw_matrix.push_back(data);
	}


	std::sort(bw_matrix.begin(), bw_matrix.end(),
			[](const std::string& a, const std::string& b){ return a[0] < b[0]; });

	data = "";
	for(auto i : bw_matrix){ 
		data += i[i.size() - 1];
		// std::cout << i << '\n';
	}
	std::cout << std::endl;

	return data;
}

std::string RLE(std::string data){
	
	std::string result {};

	int count = 1;
	char current = data[0];

	for(int i = 0; i < data.size(); ++i){
		if (data[i] == current){
			++count;
			continue;
		}
		result += std::to_string(count) + current;
		current = data[i];
		count = 1;
	}
	return result;
}



int main(){

	std::ifstream file_i;
	file_i.open("image.png", std::ios_base::binary);

	std::string input, temp;

	while(std::getline(file_i, temp)){
		input += temp;
	}
	file_i.close();

	input = bwt(input);

	std::cout << "Original file size: " << input.size() << std::endl;

	input = RLE(input);

	std::cout << "Compressed file size: " << input.size() << std::endl;

	return 0;
}
