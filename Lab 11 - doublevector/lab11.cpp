// Robert Schenck
// Lab 11
// Professor Dunn
// 4/15/2019
#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <stdexcept>
using namespace std;

class doublevector {
     static constexpr double DOUBLE_DEFAULT_VALUE = -5.55;
     double *mValues;
     int mNumValues;
public:
     doublevector();
     ~doublevector();
     void resize(int new_size, double initial_value=DOUBLE_DEFAULT_VALUE);
     void push_back(double value);
     double &at(int index);
     const double &at(int index) const;
     unsigned long size() const;
};
void print_all(const doublevector &v)
{
     if (v.size() == 0) {
           cout << "Vector is empty.\n";
     }
     else {
          unsigned long i;
          for (i = 0;i < v.size();i++) {
                cout << "[" << setfill('0') << right << setw(3) << i
                     << "] = " << fixed << setprecision(4) << v.at(i)
                     << '\n';
          }
     }
}
int main()
{
      doublevector v;
      do {
           string command;
           cout << "Enter a command ('quit' to quit): ";
           if (!(cin >> command) || command == "quit") {
                break;
           }
           else if (command == "push_back") {
                double value;
                cin >> value;
                v.push_back(value);
		cout << "Pushed back "
		     << fixed << setprecision(4)
		     << value << '\n';
           }
           else if (command == "resize") {
                string line;
                int new_size;
                double initial;
                cin >> new_size;
                getline(cin, line);
                istringstream sin(line);

                if (sin >> initial)
                     v.resize(new_size, initial);
                else
                     v.resize(new_size);
           }
           else if (command == "size") {
                cout << v.size() << '\n';
           }
           else if (command == "print") {
                print_all(v);
           }
           else if (command == "get") {
                int index;
                cin >> index;
                try {
                     cout << "Value at " << index << " = "
		          << setprecision(4) << fixed
                          << v.at(index) << '\n';;
                }
                catch(out_of_range &err) {
                     cout << err.what() << '\n';
                }
           }
           else if (command == "set") {
		   double d;
		   int index;
                   cin >> index >> d;
                   try {
			v.at(index) = d;
                        cout << "SET: " << index << " = "
			     << setprecision(4) << fixed
                             << v.at(index) << '\n';;
                   }
                   catch(out_of_range &err) {
                        cout << err.what() << '\n';
                   }
           }
           else if (command == "clear") {
                v.resize(0);
           }
           else {
                cout << "Invalid command '" << command << "'\n";
           }
      } while(true);
      cout << endl;
      return 0;
}

//Write your class members below here.

// Resizes the vector with the given parameters 
void doublevector::resize(int new_size, double initial_value){
	// Temp variable that is used to grow/shrink the vector depending on the current size and the new size
	double *temp = new double[new_size];
	// If the new_size is greater than the current size than the vector grows
	if(new_size > size()){
		// Checks to see if mValues is null
		if(mValues != nullptr){
			// Iterates through the new vector and copies the values old
			for(int i = 0; i < new_size; i++){
				if(i < size()){
					temp[i] = mValues[i];
				}else{
					// Once all the old values have been copied a given initial value is copied into the new vector
					temp[i] = initial_value;
				}
			}
			// Deletes old values
			delete[] mValues;
		}else{
			// If mValues is null sets the vector to have a given initial value
			for(int i = 0; i < new_size; i++){
				temp[i] = initial_value;
			}
		}
		// Sets the temp to the new mValues
		mValues = temp;
		// Sets the new length of the vector
		mNumValues = new_size;
	// If the new size is less thatn the current size than the vector shrinks
	}else if(new_size < size()){
		// Iterates through the new vector and copies the values from the old
		for(int i = 0; i < new_size; i++){
			temp[i] = mValues[i];
		}
		delete[] mValues;
		mValues = temp;
		mNumValues = new_size;
	// If the new size is equal to current size do nothing
	}else if(new_size == size()){
	}
}

// Pushes the given value to the back of the vector adding the vector length
void doublevector::push_back(double value){
	resize(mNumValues + 1, value);
}

// Returns the vector's value at the given index
double& doublevector::at(int index){
	if(index >= mNumValues){
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];
}

// Returns the vector's value at the given index
const double& doublevector::at(int index) const{
	if(index >= mNumValues){
		ostringstream sout;
		sout << "Invalid index #" << index;
		throw out_of_range(sout.str());
	}
	return mValues[index];	
}

// Returns the size of the vector so that it can be compared in the resize function
unsigned long doublevector::size() const{
	unsigned long size = (unsigned long)mNumValues;
	return size;
}

// Constructor sets default values
doublevector::doublevector(){
	mValues = nullptr;
	mNumValues = 0;

}

// Destructor free all the allocated memory
doublevector::~doublevector(){
	if(mValues != nullptr){
		delete[] mValues;
	}
}
