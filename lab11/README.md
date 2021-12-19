# Lab 11 - doublevector

Assignment
You will be creating the "vector" class manually by using pointers and dynamic memory (new/delete). It will be called doublevector, and it will support most of the member functions used in the regular vector class. Notice that the <> are NOT used for this class. These are used for "templates", which have not been used in COSC102. Templates are covered in your ZyBook under chapter 14.2, but they are beyond the scope of this course.

NOTICE: You will NOT be writing any set-up code or int main(). Those have already been written for you in the lab template. You are just required to write the appropriate member functions for the doublevector class.

Template
The following must be used for your doublevector class. You can download the template file under: lab11.cpp  Download lab11.cpp.

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
Members
double *mValues
All of the data will be stored in mValues. Remember, you can treat a pointer as an array! This variable must be treated gingerly since dereferencing a nullptr will cause segmentation faults--your program crashes. NEVER dereference a pointer with 0 values.

int mNumValues
This stores how many values will be inside of mValues. This will be 0 if mValues is set to nullptr.

doublevector() { }
This will construct a new doublevector whose size is 0. DO NOT allocate any dynamic memory for mValues! Make sure you set mValues = nullptr; for a subsequent check.

~doublevector() { }
This will destruct your double vector. It is responsible for freeing any resources in mValues. MAKE SURE you check the validity of mValues PRIOR to deleting it!

void resize(int new_size, double initial_value) { }
This will resize the doublevector to the given new_size. Do nothing if new_size is < 0. If new_size is 0, free all memory related to mValues. Remember to ALWAYS check the validity of your pointer before using it or freeing it!. Otherwise, if new_size > size, then you will need to create new memory, copy the old to the new, delete the old, and then set the initial values of the NEW values to initial_value. Lastly, if new_size < size, then all you need to do is create a smaller double pointer, copy new_size elements over, and then delete the larger mValues pointer. REMEMBER: to reset mValues = your new pointer and reset mNumValues to the new_size!!

void push_back(double value) { }
This member function will increase the size of the vector by 1, adding value to the bottom of the vector.

double &at(int index) { }
This member function will return a reference to the value at the given index. Make sure you write the following to check the validity of index. You don't have to know what is happening here, but your ZyBook does contain information about "exception handling" in chapter 13.1, should you be interested. The actual out_of_range class is documented here: http://www.cplusplus.com/reference/stdexcept/out_of_range/ (Links to an external site.)

if (index >= mNumValues) {
       ostringstream sout;
       sout << "Invalid index #" << index;
       throw out_of_range(sout.str());
}
const double &at(int index) const { }
This member function will return a read-only reference to the value at the given index. This member function will perform the exact same operation as the non-read-only version. The reason this is necessary is because C++ will choose one over the other depending on whether your class is constant or not.

unsigned long size() const { }
This member function will typecast your mNumValues into an unsigned long and return it.

Example Interaction
~$ ./lab13
Enter a command ('quit' to quit): get 0
Value at 0 = Invalid index #0     You might only get "Invalid index #0" on Tesla
Enter a command ('quit' to quit): set 0 10
Invalid index #0
Enter a command ('quit' to quit): print
Vector is empty.
Enter a command ('quit' to quit): push_back 10
Pushed back 10.0000
Enter a command ('quit' to quit): push_back 33.4
Pushed back 33.4000
Enter a command ('quit' to quit): get 0
Value at 0 = 10.0000
Enter a command ('quit' to quit): get 1
Value at 1 = 33.4000
Enter a command ('quit' to quit): print
[000] = 10.0000
[001] = 33.4000
Enter a command ('quit' to quit): resize 10
Enter a command ('quit' to quit): get 0
Value at 0 = 10.0000
Enter a command ('quit' to quit): print
[000] = 10.0000
[001] = 33.4000
[002] = -5.5500
[003] = -5.5500
[004] = -5.5500
[005] = -5.5500
[006] = -5.5500
[007] = -5.5500
[008] = -5.5500
[009] = -5.5500
Enter a command ('quit' to quit): set 2 22.14
SET: 2 = 22.1400
Enter a command ('quit' to quit): print
[000] = 10.0000
[001] = 33.4000
[002] = 22.1400
[003] = -5.5500
[004] = -5.5500
[005] = -5.5500
[006] = -5.5500
[007] = -5.5500
[008] = -5.5500
[009] = -5.5500
Enter a command ('quit' to quit): resize 0
Enter a command ('quit' to quit): print
Vector is empty.
Enter a command ('quit' to quit): quit

Restrictions
1. You may NOT use malloc(), calloc(), free() or any other C-style memory allocation.

2. You MUST use the proper versions of new and delete.

3. The doublevector member functions MUST be written below int main().

4. You must NOT have any memory leaks. Make sure you delete all memory when you're done using it.

5. You do NOT need to check if new returned a valid memory value. If you use the proper value, it will throw an exception. You do NOT need to handle this exception, either.

6. You may NOT include any additional headers than what are specified in lab13.cpp.

7. You may NOT modify the template's class prototype, print_all function, and int main function.
