# Speeding Tickets 2
# **Assignment**
You will be developing a speeding ticket fee calculator. This program will ask for a ticket file, which is produced by a central police database, and your program will output to a file or to the console depending on the command line arguments. Furthermore, your program will restrict the output to the starting and ending dates given by the user.

The ticket fee is calculated using four multipliers, depending on the type of road the ticket was issued:

```
Interstate multiplier:  5.2252
Highway multiplier:     9.4412
Residential multiplier: 17.1525
None of the above:      12.152
```
The multiplier is multiplied to the difference between the speed limit and the clocked speed to determine the fine's dollar amount.

Use global constants for the multipliers above.

# **User Interaction**
There will be no console interaction with the user for this lab. Instead, you the inputs will be made using command line arguments:

The first user argument will be the database file to read from.

The second user argument will be the start date in the format: year-month-day, such as 2011-11-22

The third user argument will be the end date in the format: year-month-day, such as 2015-11-23

The fourth user argument will be an output file name or a single dash "-". If the user gives you a "-", you will write the report to the console using cout. Otherwise, you will write the report to the given filename.

If the user types - for the output ticket file, you will write the output to the console, otherwise, you will output to an output file.

# **Date Structure**
Create a structure called Date which contains three integers: month, day, and year.

# **Ticket Structure**
Create a structure called Ticket which will describe a single ticket and has the following fields:

1. a string representing the citation number.

2. an Date structure representing the citation date.

3. an integer representing the clocked speed.

4. an integer representing the speed limit.

5. a char representing the type of road.

# **Database Class**
Create a class called "Database" with the following members:

1. a private vector of Ticket structures.

2. a public mutator called add_ticket, which returns nothing and takes a read-only Ticket structure by-reference. This member function will add the given ticket to the private vector.

3. a public accessor called gen_report, which returns a vector of Ticket structures, and takes two Date structures: start and end which will be the start date and end date. This member function will return a vector of Ticket structures whose dates are inclusively between start and end.

# **Standalone Functions**
```
bool Read(Database &d, istream &in);
```
Write a standalone function called Read which returns a bool (true if the input successfully read all tickets, false if it was not). This function will take a Database class by-reference and an input stream by reference. The purpose of this function is to read ALL tickets from the input stream and call add_ticket() on the Database class for each ticket read. NOTE: You will be taking an input stream by reference (istream), NOT an input file stream (ifstream).

```
bool Write(const vector<Ticket> &tickets, ostream &out);
```
Write another standalone function called Write. This function will take a vector of Ticket structures and output them the to an output stream (ostream), NOT an output file stream (ofstream). This allows you to output to cout or an ofstream or stringstream using the same function.

```
int Encode(const Date &d);
```
Write the function Encode. Encode will translate a Date structure containing a month, day, and year into a single integer in the format YYYYMMDD. For example, given October 13, 2018, you would return the integer: 20,181,013 (20181013). The year is always 4 digits, the month is always 2 digits, and day is always 2 digits. A single digit day or month will be preceded by a 0, such as 20190101 would be New Year's Day for 2019.

# **Input File Format**
Each line will contain the following information:

```
<citation number> <month> <day> <year> <clocked speed> <speed limit> <type of road>
```
The citation number may contain numbers and letters.
The month is an integer between 1 (January) and 12 (December).
The day and year are integers.
The clocked speed is an integer in miles per hour.
The speed limit is an integer in miles per hour.
The type of road is a single character: I or i (Interstate), R or r (Residential), H or h (Highway).

# **Output File Format**
Your output file format will be:

```
<day>-<3-character Month>-<Year> <citation> $<fine>
```
1. The day must be exactly two digits. If the day is 1 - 9, it must be 01 - 09.
2. The 3-character month must be the three-character month: Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, or Dec.
3. The year is simply a 2 or 4 digit year. If the year is only two digits, assume the 21st century. For example, year 10 will be the year 2010.
4. The citation is exactly the citation given in the input file, but it will be in a left justified field, 10 characters wide.
5. The $ must follow the citation field.
6. The fine will be a dollar amount in a right justified field, 9 characters wide.
7. You will only output those citations that occur between the given report start date and end dates (inclusively).
8. You must use your Encode function to handle the dates.

# **Restrictions / Hints**
1. You must use I/O manipulators to force the day to be exactly two digits.
2. You must use I/O manipulators to set the fine to two decimal points.
3. You must use global constants for the fine multiplier.
4. Store all months, such as Jan, Feb, Mar, in a global, constant, 12-element array of strings.
5. You must use I/O manipulators to set the field justifications (right and/or left).
6. The minimum fine is $0.00. If you calculate a negative fine, you must round it up to exactly $0.00.
7. You must use your standalone functions and all member functions when writing these labs. You are simulating writing an API for other programmers to use your class and/or functions to generate a report.
8. Do NOT hardcode any extensions or file names. Read the filename directly from the command line, regardless of whether it contains the extension you think it should or not.
9. All classes, structures, and prototypes must be declared ABOVE int main. All definitions must be written BELOW int main.
10. Do not attempt to write to any file if the user gives you a dash "-" for the output file name.

# **Example**
Valid input example:
```
./lab11 ticket.input 2017-7-3 2017-12-27 output.file
```
ticket.input file contains:

```
E059564 8 12 2018 89 55 i
E515522 7 3 2017 105 50 r
E712221 6 4 2015 200 25 h
E219221 12 25 17 2000 10 p
```
output.file contains:

```
03-Jul-2017 E515522    $   943.39
25-Dec-2017 E219221    $ 24182.48
```
Invalid files:
```
./lab11 ticket.idontexist 2017-7-3 2017-12-27 output.file
The file 'ticket.idontexist' cannot be read.
```
Output to console:
```
./lab11 ticket.input 2017-7-3 2017-12-27 -
03-Jul-2017 E515522    $   943.39
25-Dec-2017 E219221    $ 24182.48
```
Not enough arguments:
```
./lab11 ticket.input
Usage: ./lab11 <input file> <start: year-month-day> <end: year-month-day> <output or '-'>
```
# **Submission**
Compile your code using the following
```
g++ -Wall -O0 -g -std=c++11 -o lab lab.cpp
```
