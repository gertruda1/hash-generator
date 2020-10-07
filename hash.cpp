#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>

void AsciiToBinary(int num, std::string &bin)
{ 
    if (num > 1) 
        AsciiToBinary(num/2, bin); 
  
    bin = bin + std::to_string(num%2); 
}

std::string xOR(std::string A, std::string B)
{
	std::string C;
	char a[A.size() + 1];
	char b[B.size() + 1];
	strcpy(a, A.c_str());
	strcpy(b, B.c_str());
	for(int i = 0; i < 32; i++)
	{
		if (a[i] == b[i]) C += "0";
		else C += "1";
	}

	return C;
}

 void leftrotate(std::string &s, int d)
{
    reverse(s.begin(), s.begin()+d);
    reverse(s.begin()+d, s.end());
    reverse(s.begin(), s.end());
}


struct help_me_pls
{
	std::vector<std::string> blokas;
};

int main()
{
	
	std::string input = "A Test";
	

	char input_array[input.size() + 1];
	strcpy(input_array, input.c_str());
	std::vector<std::string> binary_8bit;
	for (int i = 0; i < input.size(); i++)
	{
		int ascii = (int)input_array[i];
		std::string binary;
		AsciiToBinary(ascii, binary);

		char zero = '0';

		while (binary.size() != 8)
			binary = zero + binary;

		binary_8bit.push_back(binary);
	}

	std::string binary_8bit_join;

	for (int i = 0; i < binary_8bit.size(); i++)
	{
		binary_8bit_join += binary_8bit.at(i);
	}
	binary_8bit_join += '1';
	
	while(binary_8bit_join.length() % 512 != 448)
		binary_8bit_join += '0';

	std::string binary;
	AsciiToBinary(input.size(), binary);
	
	while (binary.size() != 64)
			binary = '0' + binary;
	binary_8bit_join += binary;


	char tmp[binary_8bit_join.size() + 1];
	strcpy(tmp, binary_8bit_join.c_str());
	
	std::vector<help_me_pls> chunks_32;
	int s = binary_8bit_join.size() / 512;

	for(int i = 0; i < s; i++)
	{
		help_me_pls tmp;
		for(int j = 0; j < 512; j += 32)
		{
			tmp.blokas.push_back(binary_8bit_join.substr(j, j + 32));
		}
		chunks_32.push_back(tmp);
	}

	
	

	// 11 punktas
	
	for(int j = 0; j < s; j++)
	{
		help_me_pls tmp;
		for (size_t i = 16; i < 80; i++)
		{
			//take four words from chunks_32 using i in current loop
			std::string wordA = chunks_32[j].blokas[i - 3];
			std::string wordB = chunks_32[j].blokas[i - 8];
			std::string wordC = chunks_32[j].blokas[i - 14];
			std::string wordD = chunks_32[j].blokas[i - 16];

			//perform xor bitwise operations going through each word
			std::string xorA = xOR(wordA, wordB);
			std::string xorB = xOR(xorA, wordC);
			std::string xorC = xOR(xorB, wordD);

			//left rotate by one
			leftrotate(xorC, 1);
			chunks_32[j].blokas.push_back(xorC);
		}
	}
		

	std::cout << chunks_32[0].blokas[79];

	// declare variables


	std::string h0 = "01100111010001010010001100000001";
	std::string h1 = "11101111110011011010101110001001";
	std::string h2 = "10011000101110101101110011111110";
	std::string h3 = "00010000001100100101010001110110";
	std::string h4 = "11000011110100101110000111110000";
	std::string a = h0;
	std::string b = h1;
	std::string c = h2;
	std::string d = h3;
	std::string e = h4;


	return 0;
}