# PPM Manipulation

# **Assignment**
You will be writing a program designed to read in a text-based picture file, manipulating it, and then writing the manipulated picture file into an output file.

# **PPM File Format**
A PPM file is called a "Portable Pixmap", which is essentially a plain-text file of numbers from 0-255 which describe the color channels of a picture.

The very first line is always "P3", which identifies this as a PPM file. If this file does not contain P3, do not read it, and let the user know that there was an error.

The second line contains two values in order: width and height. These describe the width and height in pixels.

The third line contains one value: max intensity. This describes the maximum intensity of a color value starting at 0. This value is typically 255, but you cannot assume it is.

The rest of the lines contain three values: red, green, and blue. These are integers that describe the amount of color each pixel gets. These values must be in the range of [0..max intensity]. If you find a value that is > max intensity, WARN the user, and set the pixel's value to max intensity.

ANY line beginning with a # is a comment, and it must be ignored by your program. You do not need to check if # is anywhere else in the file, such as after a value on the same line.

The red, green, and blue values may be on a line by themselves, or they may be on a single line, or may be split between a line, whitespace, comment, and another line. Your program must be able to handle all situations.

PPM file example:

```
P3
#width height
5 4
#maximum intensity
255
#row 0
2 9 4 100 200 100 7 9 1 91 99 94 18 44 19 
#row 1
72 91 44 88 44 12 91 99 94 14 55 22 19 88 77
#row 2
44 12 22 91 99 94 78 44 19 191 215 222 177 199 121
#row 3
41 98 111 91 99 94 22 11 22 177 144 121 91 99 94
```

The PPM file example above contains the 'P3' identifying this as a PPM file. It then has a width of 5 pixels and a height of 4 pixels. This means that there should be exactly 20 pixels (5 x 4) laid out after the maximum intensity, which for this file, is 255. The pixels are both in a row and on lines by themselves. You cannot assume how the PPM file will store the pixels. So, your program must handle multiple pixels per line as well as multiple pixels on their own lines.

Notice that there are three values per pixel. In order, these are the values for the red, green, and blue color channels.

# **Structures**
# Pixel
Create a Pixel structure that contains three members which will contain values between [0..max intensity]. Only positive numbers will be stored. One member will store the value of the red channel, one for the green, and lastly, one for the blue channel.
# Picture
Create a Picture class that contains:

1. a private vector of Pixel structures.

2. a private integer representing the width of the picture.

3. a private integer representing the height of the picture.

4. a private integer representing the maximum intensity of each pixel color.

5. a public constructor that takes no arguments. This constructor will set the width, height, and maximum intensity to 0.

6. a public accessor called get_pixel. This function will take a row and a column as integer values, and it will return the given Pixel at the row and column by-constant-reference. You may assume that the row and column will exist. Remember, the private vector stores all pixel values in one dimension. This means that you'll need a little bit of math to figure out where the pixel begins. For this, remember that each row contains a number of pixels, which is equal to the number of columns. For example, a file that has a width of 10 and a height of 5 has 10 columns and 5 rows. This means that row[0] starts at vector.at(0) and row[1] starts at vector.at(total_number_of_columns) and row[2] starts at vector.at(total_number_of_columns * 2);

7. a public mutator also called get_pixel. This function is exactly like the accessor get_pixel, except it is a mutator, and allows for you to write set_pixel by returning a mutable reference to a pixel.

8. a public mutator called set_pixel. This function will take a row and column as integers and a Pixel structure by read-only reference. The point of this function is simply to set the given pixel to the Pixel value. You must use the mutator version of get_pixel(row, col) = pixel to complete this function.

9. a public mutator called invert. This function takes no arguments, and will invert all pixels using get_pixel and set_pixel. Inversion means that you take the maximum intensity for all pixels and subtract the current pixel value. Remember, there are THREE color channels per pixel, so you must subtract from the maximum intensity the red, green, and blue color channels for every pixel. This mutator will store the updated values back into the private vector.

10. a public mutator called flip_x. This function takes no arguments and returns nothing. This function will flip all pixels around the X axis (top becomes bottom and bottom becomes top). Essentially, you'll swap the first row with the last row, followed by the second row with the penultimate row, and so forth. Use your get_pixel and set_pixel functions to get and set the appropriate pixel values. Do not manually manipulate the vector!

11. a public mutator called flip_y. This function takes no arguments and returns nothing. This function will flip all pixels around the Y axis (left becomes right and right becomes left). Essentially, you'll swap the first column with the last column, followed by the second column with the penultimate column, and so forth. Use your get_pixel and set_pixel functions to get and set the appropriate pixel values.

12. a public mutator called read_input. This function will take an istream by reference and return a bool. This mutator will read a PPM file into the private vector, and it will set the width, height, and maximum intensity members accordingly. You must be efficient with this function. Since the width and height tell you exactly how many values will be in your vector, you must reserve the proper amount of pixels in your vector before reading. Notice that the term is "reserve"! This will preclude your program from reallocating memory over and over again as it reads the PPM file. This function will return true if the PPM file was able to be read properly. This means that there were exactly width x height pixels. Again, if a pixel value exceeds the maximum intensity, set the pixel's value to the maximum intensity.

13. a public accessor called write_output. This function will take an ostream by reference and return nothing. The point of this function is to write the PPM file to the ostream. This function will have to write an entire PPM file, including the "P3", width, height, maximum intensity, and each pixel. For purposes of this function, write each pixel on a line of its own. So, you will have three integer values per line.

# **Row/Column versus X,Y**
Remember that rows are essentially your Y value (top to bottom) and that columns are essentially your X value (left to right).

# **Command Line Arguments**
The first command line argument will specify the input PPM file to read or a dash '-' to read the PPM file from cin. This means that you will need to open the input file, check it, OR set it to cin inside of int main().

The second command line argument will specify the output PPM file to write or a dash '-' to write the PPM file to cout. This means that you will need to open the output file, check it, OR set it to cout inside of int main().

The third command line argument will be one of the following (case insensitive): I, Y, X, or it may not even be specified. If the value I is specified, this instructs your program to invert all pixels prior to writing the PPM output file. If the value Y is specified, this instructs your program to flip the PPM picture around the Y axis (left becomes right, right becomes left). If the value X is specified, this instructs your program to flip the PPM picture around the X axis (top becomes bottom, bottom becomes top). Finally, if no argument is specified, your program will read the input and simply write to the output file without inverting or flipping the picture.

# **Submission**
Compile your lab using the following command:

```
g++ -Wall -O0 -g -std=c++11 -o lab lab.cpp
```
