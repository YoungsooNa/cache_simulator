#pragma once
#include <string>

using namespace std;

class Word {
public:
	Word();
	void init(int set_n, int block_n);
private:
	int index;
	int **tag;
	bool **valid;


};

class Memory {
public:
	Memory(int set_n, int block_n, int word_n);
	int acess(string address);
private:
	bool parsing(string adress);
	Word *words = NULL;

	int set_n;
	int block_n;
	int word_n;

	int log2_set_n;
	int log2_block_n;
	int log2_word_n;

	int index_word;
	int index;
	int tag;

	int hit;
	int miss;
};

