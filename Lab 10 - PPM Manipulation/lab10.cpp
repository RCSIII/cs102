// Robert Schenck
// April 9th, 2019
// Professor Dunn
// Lab 10
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>

using namespace std;

// Pixel Structure that stores RGB values for each pixel
struct Pixel{
	int red;
	int green;
	int blue;
};

// Picture class which stores the size of the image, the pixels of the image, and the maximum intensity of the pixel, along with mutators that alter the image
class Picture{
	private:
		vector<Pixel> pixels;
		int width;
		int height;
		int maximumIntensity;
	public:
		Pixel get_pixel(int row, int column) const;
		Pixel get_pixel(int row, int column);	
		void set_pixel(int row, int column, const Pixel &p);
		void invert();
		void flip_x();
		void flip_y();
		bool read_input(istream &in);
		void write_output(ostream &out) const;

};


// Main function
int main(int argc, char* argv[]){
	// Variable declaration
	ifstream ifs;
	ofstream ofs;
	string inputFile = argv[1];
	string outputFile = argv[2];
	string distort;
	Picture p;

	// If the user enters dash the program will ask for a input file, otherwise the input file will be provided in the arguments
	if(inputFile == "-"){
		cout << "Enter a PPM file: ";
		cin >> inputFile;
		cout << '\n';
	}
	// Attempts to open the file, if unsuccessful prints an error message and exits
	// If successful then reads the file
	ifs.open(inputFile);
	if(!ifs.is_open()){
		cerr << "The file '" << inputFile << "' cannot be read.\n";
		return 1;
	}else{
		p.read_input(ifs);
		ifs.close();
	}

	// If the program is run with a third argument then based on the argument the program decides which mutator to run
	if(argc > 3){
		distort = argv[3];
		switch(distort[0]){
			case 'X':
			case 'x':
				p.flip_x();
				break;
			case 'Y':
			case 'y':
				p.flip_y();
				break;
			case 'I':
			case 'i':
				p.invert();
				break;
			default:
				break;
		}
	}

	// Attempts to open the output file, if unsuccessful, prints an error message and exits
	// If successful then writes to the file
	ofs.open(outputFile);
	if(!ofs.is_open()){
		cerr << "The file '" << outputFile << "' cannot be read.\n";
		return 1;
	}else{
		p.write_output(ofs);
		ofs.close();
	}
	return 0;

}

// Returns the given pixel (Accessor)
Pixel Picture::get_pixel(int row, int column) const{
	return pixels.at((width * row) + column);
}

// Returns the given pixel (Mutator)
Pixel Picture::get_pixel(int row, int column){
	return pixels.at((width * row) + column);
}

// Flips the image along the y-axis
void Picture::flip_y(){
	Pixel temp;
	Pixel temp2;	
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width / 2; j++){
			temp = get_pixel(i, j);
			temp2 = get_pixel(i, width - 1 - j);
			set_pixel(i, j, temp2);
			set_pixel(i, width - 1 - j, temp);
		}
	}
}

// Flips the image along the x-axis
void Picture::flip_x(){
	Pixel temp;
	Pixel temp2;
	for(int i = 0; i < height / 2; i++){
		for(int j = 0; j < width; j++){
			temp = get_pixel(i, j);
			temp2 = get_pixel(height - 1 - i, j);
			set_pixel(i, j, temp2);
			set_pixel(height - 1 - i, j, temp);
		}
	}
}

// Inverts each pixel of the image
void Picture::invert(){
	Pixel temp;
	for(int i = 0; i < height; i++){
		for(int j = 0; j < width; j++){
			temp = get_pixel(i, j);
			temp.red = maximumIntensity - temp.red;
			temp.green = maximumIntensity - temp.green;
			temp.blue = maximumIntensity - temp.blue;
			set_pixel(i, j, temp);
		}
	}

}

// Sets the given pixel
void Picture::set_pixel(int row, int column, const Pixel &p){
	get_pixel(row, column) = p;
}

// Reads the input from the file
bool Picture::read_input(istream &in){
	string temp;
	stringstream ss;
	int num = 0;
	Pixel pixelTemp;
	string filename;
	bool red = false;
	bool blue = false;
	bool green = false;
	if(!in){
		return false;
	}
	// Gets the 'P3' at the top of every PPM file
	while(getline(in, temp)){
		if(temp[0] == '#'){
			continue;
		}
		ss << temp;
		ss >> filename;
		ss.clear();
		break;
	}
	// Gets the width and height of the image and sets the pixels vector to the width times the height
	while(getline(in, temp)){
		if(temp[0] == '#'){
			continue;
		}
		ss << temp;
		ss >> width >> height;
		pixels.reserve(width * height);
		ss.clear();
		break;
	}
	// Gets the maximum intensity of the image
	while(getline(in, temp)){
		if(temp[0] == '#'){
			continue;
		}
		ss << temp;
		ss >> maximumIntensity;
		ss.clear();
		break;
	}
	// Gets the pixels from the input file and stores them in the pixels vector
	while(getline(in, temp)){
		if(temp[0] == '#'){
			continue;
		}
		ss << temp;
		while(ss >> num){
			if(!red){
				pixelTemp.red = num;
				if(pixelTemp.red > maximumIntensity){
					pixelTemp.red = maximumIntensity;
				}
				red = true;
			}else if(!green){
				pixelTemp.green = num;
				if(pixelTemp.green > maximumIntensity){
					pixelTemp.green = maximumIntensity;
				}
				green = true;
			}else if(!blue){
				pixelTemp.blue = num;
				if(pixelTemp.blue > maximumIntensity){
					pixelTemp.blue = maximumIntensity;
				}
				blue = true;
			}
			if(blue == true  && green == true && red == true){
				pixels.push_back(pixelTemp);
				blue = false;
				red = false;
				green = false;
			}
		}
		ss.clear();
	}
	return true;
}

// Writes to the output file 
void Picture::write_output(ostream &out) const{
	out << "P3\n" << width << ' ' << height << '\n' << maximumIntensity << '\n';
	for(unsigned int i = 0; i < pixels.size(); i++){
		out << pixels[i].red << ' ' << pixels[i].green << ' ' << pixels[i].blue << '\n';
	}

}
