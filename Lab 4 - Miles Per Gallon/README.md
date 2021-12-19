# Miles Per Gallon

# **Assignment**
You will be creating a program that calculates a fleet's car and truck miles per gallon.

Create a program that continually asks for a command, which will be "car", "truck", or "done". If the user does not specify one of these commands, output "Unknown command."

If the user types "done", calculate the average miles per gallon of all of the given cars and calculate the average miles per gallon of all of the given trucks. If the user did not provide any cars, output "Fleet has no cars." If the user did not provide any trucks, output "Fleet has no trucks." Otherwise, output "Average car MPG = " and "Average truck MPG = ".

If the user types "truck" or "car", then ask the user for the number of miles and number of gallons of fuel used on either the truck or car. This will be a running total. You will need to store the total number of miles, total number of gallons, and total number of cars and trucks.

You must also make a check to ensure the user gives you proper input. If improper input was given, keep asking the user to give you legitimate values until they comply (see examples below).

# **Examples**
```
./lab4
Enter command: car
Enter car's miles: 255
Enter car's gallons: 13
Enter command: car
Enter car's miles: 715
Enter car's gallons: 33
Enter command: truck
Enter truck's miles: 477
Enter truck's gallons: 22
Enter command: done
Average car MPG = 21.087
Average truck MPG = 21.6818
```
```
./lab4
Enter command: done
Fleet has no cars.
Fleet has no trucks.
```
```
./lab4
Enter command: car
Enter car's miles: 177.25
Enter car's gallons: 22.182
Enter command: done
Average car MPG = 7.99071
Fleet has no trucks.
```
```
./lab4
Enter command: car
Enter car's miles: z41
Enter car's miles: kcc
Enter car's miles: llkaj
Enter car's miles: m81
Enter car's miles: 18.2lkjalj
Enter car's gallons: Enter car's gallons: n55
Enter car's gallons: ooslei.83
Enter car's gallons: p
Enter car's gallons: 22.15
Enter command: ca
Unknown command.
Enter command: d
Unknown command.
Enter command: done
Average car MPG = 0.82167
Fleet has no trucks.
```
