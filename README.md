Linear Equation System Manager
This project is a C++ command-line application designed to parse, store, and perform arithmetic operations on systems of linear equations. It handles algebraic terms, merges duplicates, and supports various query commands to analyze the input system.
Features
•	Parsing: Automatically parses linear equation strings into structured data.
•	Unique Variable Counting: Identify the total number of unique variables across the system.
•	Arithmetic Operations: Perform addition and subtraction between equations with automated coefficient merging.
•	Column Analysis: Extract and print coefficients for specific variables across all equations.
Prerequisites
•	A C++ compiler (e.g., g++, clang, or Visual Studio C++).
•	A terminal or command prompt environment.
How to Compile and Run
1) Ensure all files (equation.h, implementation.cpp, and linear_eqs.cpp) are in the same directory.
1.	2) Compile using the following command:
g++ linear_eqs.cpp implementation.cpp -o equation_manager
2.	3) Run the program:
•	Linux/macOS: ./equation_manager
•	Windows: equation_manager.exe
Usage Instructions
Once the program is running, input the number of equations followed by the equations themselves (e.g., 2x+3y=5). After entering the data, you can use the following commands:
•	num_vars: Displays the number of unique variables in the system.
•	equation [i]: Prints the equation at index i (starting from 1).
•	column [varName]: Prints the coefficient of a specific variable for every equation in the system.
•	add [i] [j]: Adds equation i and j and prints the result.
•	subtract [i] [j]: Subtracts equation j from equation i and prints the result.
•	quit: Exits the program.
