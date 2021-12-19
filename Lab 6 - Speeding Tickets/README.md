# Speeding Ticket
# **Assignment**

You will be developing a speeding ticket fee calculator. This program will ask for a ticket file, which is produced by a central police database, and your program will output to a file. Furthermore, your program will restrict the output to the starting and ending dates given by the user.

The ticket fee is calculated using four multipliers, depending on the type of road the ticket was issued:

```
Interstate multiplier:  5.2252
Highway multiplier:     9.4412
Residential multiplier: 17.1525
None of the above:      12.152
```
The multiplier is multiplied to the difference between the speed limit and the clocked speed to determine the fine's dollar amount.

# **Console User Interaction**
You must ask the user on the console for an input ticket file, an output report file, a report starting date, and a report ending date. The following prompts must be used:

```
"Enter a ticket file: "
"Enter a report file: "
"Enter report start date (mm dd yyyy): "
"Enter report end date   (mm dd yyyy): "
```
# **Input File Format**
Each line will contain the following information:
```
<citation number> <month> <day> <year> <clocked speed> <speed limit> <type of road>
```

1. The citation number may contain numbers and letters.
2. The month is an integer between 1 (January) and 12 (December).
3. The day and year are integers.
4. The clocked speed is an integer in miles per hour.
5. The speed limit is an integer in miles per hour.
6. The type of road is a single character: I or i (Interstate), R or r (Residential), H or h (Highway).

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

# **Restrictions / Hints**
1. You must use I/O manipulators to force the day to be exactly two digits.
2. You must use I/O manipulators to set the fine to two decimal points.
3. You must use a constant ARRAY to store (and determine) the 3-character month.
4. You must use constants for the fine multiplier.
5. You must use a switch statement to apply the fine multiplier.
6. You must use I/O manipulators to set the field justifications (right and/or left).
7. The minimum fine is $0.00. If you calculate a negative fine, you must round it up to exactly $0.00.

# **Example**
Valid input example:
```
./lab6
Enter a ticket file: ticket
Enter a report file: output
Enter report start date (mm dd yyyy): 7 1 2017
Enter report end date   (mm dd yyyy): 8 11 2018
```
ticket file contains:
```
E059564 8 12 2018 89 55 i
E515522 7 3 2017 105 50 r
E712221 6 4 2015 200 25 h
E219221 12 25 17 2000 10 p
```
output file contains:
```
03-Jul-2017 E515522    $   943.39
25-Dec-2017 E219221    $ 24182.48
```
Missing file example:
```
./lab6 
Enter a ticket file: somebadfilename
Unable to open somebadfilename.
```
# **Submission**
Compile your code using the following
```
g++ -Wall -O0 -g -std=c++11 -o lab lab.cpp
```
