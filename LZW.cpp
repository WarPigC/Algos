/*
 *	LZW or Lempel-Ziv-Welch is a dictionary based compression algorithm that builds a dictionary of substrings and replaces repeating substrings 
 *	with their values in the dictionary.
 *
*/


#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


std::vector<int>* encode(std::string* data){
	std::vector<int>* result = new std::vector<int>();
	std::string* w = new std::string("");
	int code = 256;

	// dictionary initilization
	std::unordered_map<std::string, int> dict;

	for(int i = 0; i < 256; ++i){
		std::string s = "";
		dict[s + static_cast<char>(i)] = i;
	}

	// encoding
	for (char c : *data){
		std::string wc = *w + c;

		if (dict[wc] > 0){
			*w = wc;
		}
		else{
			result->push_back(dict[*w]);
			dict[wc] = code;
			++code;
			*w = c;
		}
	}	
	if (w->size() > 0){
		result->push_back(dict[*w]);
	}
	return result;
}


std::string* decode(std::vector<int>* data){
	std::string* result = new std::string("");
	std::string w(1, static_cast<char>(data->operator[](0)));
	int code = 256;

	data->erase(data->begin());
	result->append(w);


	// dictionary initilization
	std::unordered_map<int, std::string> dict;

	for(int i = 0; i < 256; ++i){
		std::string s = "";
		dict[i] = s + static_cast<char>(i);
	}
	std::string entry;


	for (auto k : *data){
		
		if (dict.count(k) > 0){
			entry = dict[k];
		}
		else if (k == code){
			entry = w + w[0];
		}
		else{
			std::cout << "invalid compressed code\n";
			return new std::string();
		}


		result->append(entry);
		dict[code] = w + entry[0];
		++code;
		w = entry;
	}
	return result;
}




int main(){
	
	std::string* t = new std::string();
	std::cin >> *t;

	auto v = encode(t);
	t = decode(v);

	std::cout << *t;

	delete t;

	return 0;
}
