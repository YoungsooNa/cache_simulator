#include "architecture.h"

#include <iostream>
#include<math.h>

using namespace std;

const char* hex_char_to_bin(char c)
{
	// TODO handle default / error
	switch (toupper(c))
	{
	case '0': return "0000";
	case '1': return "0001";
	case '2': return "0010";
	case '3': return "0011";
	case '4': return "0100";
	case '5': return "0101";
	case '6': return "0110";
	case '7': return "0111";
	case '8': return "1000";
	case '9': return "1001";
	case 'A': return "1010";
	case 'B': return "1011";
	case 'C': return "1100";
	case 'D': return "1101";
	case 'E': return "1110";
	case 'F': return "1111";
	default : return "FALSE";
	}
}

Word::Word() {
}
void Word::init(int set_n, int block_n) {
	index = (int)(block_n / set_n);
	valid = new bool*[index];
	tag = new int* [index];
	for (int i = 0; i < index; i++) {
		valid[i] = new bool[set_n];
		tag[i] = new int[set_n];
		for (int k = 0; k < set_n; k++) {
			valid[i][k] = false;
		}
	}
}


Memory::Memory(int set_n, int block_n, int word_n) {
	this->set_n = set_n;
	this->block_n = block_n;
	this->word_n = word_n;

	log2_set_n = (int)(log2(set_n));
	log2_block_n = (int)(log2(block_n));
	log2_word_n = (int)(log2(word_n));

	words = new Word[word_n];

	for (int i = 0; i < word_n; i++) {
		words[i].init(set_n, block_n);
	}
}

// acess the memory with address : str
int Memory::acess(string address) {
	if (parsing(address)) {
		cout << "parsing success" << endl;
	}
	else {
		return -1;
	}
}

// It parsing address and change word, index, tag value in class 
bool Memory::parsing(string address) {
	//check length of address
	if (address.length() != 10) {
		return false;
	}

	string address_bin = "";

	for (int i = 2; i < address.length(); i++) {
		if (hex_char_to_bin(address[i]) == "FALSE") {
			return false;
		}
		address_bin += hex_char_to_bin(address[i]);
	}
	cout << address_bin << endl;

	reverse(address_bin.begin(), address_bin.end());

	cout << address_bin << endl;

	int byte_offset = 2;

	if (this->log2_word_n == 0) {
		this->index_word = 0;
	}
	else {
		string word_index_string = address_bin.substr(byte_offset , log2_word_n);
		reverse(word_index_string.begin(), word_index_string.end());
		this->index_word = stoi(word_index_string, 0, 2);
	}
	cout << index_word << endl;
	return true;

}