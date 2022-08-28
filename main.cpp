#include <fstream>
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>
#include <string>
#include "sorts.h"

using namespace std;
 
int main ( int argc, char *argv[] )
{   
	std::string output_file;
	std::string input_file;
	std::vector<int> lines;
	std::vector<int> final;

     if ( argc == 1 ) 
   	 return 0;
    else if (argc>1) {
	if(std::string(argv[1])=="--name"){ //checks if --name is given by the user
		cout<<"Sai Abhishek Aravind"; } //prints name.

	else {
		if(std::string(argv[2])=="-o"){ //check if the syntax is correct as per the question.
		input_file = std::string(argv[1]); //stores read file name into input_file
		std::string line; //init to read lines
		ifstream readfile(input_file); //open the file in read mode
		while(getline(readfile,line)){ //to go till EOF
			lines.push_back(stoi(line));} //pushes the data into the vector and converts them to integer

		output_file = std::string(argv[3]); //stores the output file name
		//output_file.erase(0,3);
		//output_file +=".my";
		//sort(lines.begin(), lines.end());
		std::string Alg_Logic = std::string(argv[4]); //checks what type of alg is given by the user
		Alg_Logic.erase(0,6); //removes --alg= from the string
		if (Alg_Logic=="merge") { //checks if alg is merge
			merge_sort(lines, 0, lines.size() - 1); //calls merge sort function
		//final = magicsort(lines);
		ofstream write_file; //simple snippet for writing the vector back into the output file
		write_file.open(output_file);
		for(int i=0;i<lines.size();i++){
			write_file<<lines.at(i)<<"\n";}
		 }

		 else if (Alg_Logic=="quick") { //checks if logic = quick
			quick_sort(lines, 0, lines.size() - 1); //calls the quick sort
		ofstream write_file;
		write_file.open(output_file);
		for(int i=0;i<lines.size();i++){
			write_file<<lines.at(i)<<"\n";}
		 }

		}

	}
		
	}
return 0;

}
