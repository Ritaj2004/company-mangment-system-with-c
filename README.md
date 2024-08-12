# Company Management System
![interface](https://github.com/user-attachments/assets/3c4760d1-3466-423c-8845-56c769763627)
## Description
The Company Management System is a C program designed to help manage employee information within a company. It provides various functionalities for adding, displaying, and manipulating employee data across different departments.

## Features
- Add new employees and departments
- Display all employee information
- Search for employees by ID
- Display employees with the highest salary
- Add new departments and their managers
- Search by department and display manager and employees
- Count the number of managers and employees in the company
- Count the number of employees in each department
- Edit employee information

## Menu Options
1. Enter new employee information
2. Display all employee information
3. Search employee by ID
4. Display employee with highest salary
5. Add new department and its manager
6. Search by department and display manager and employees
7. Count number of managers and employees in the company
8. Count number of employees in each department
9. Edit employee information
10. Exit

## Data Structures
The program uses two main structures:
- `Employee`: Stores individual employee data
- `department`: Stores department information and associated employee data

## Limitations
- The program can store up to 50 employees and 50 departments.
- Employee ages must be between 17 and 60.
- Salaries must be positive numbers.
- The program does not persist data between runs (no file or database storage).
- There's no built-in data validation for phone numbers or addresses.
- The program assumes unique department names and doesn't handle duplicates.
- There's no functionality to delete employees or departments.
- The program doesn't handle memory dynamically, which limits scalability.
- Error handling is minimal and may not cover all edge cases.
- The user interface is text-based and may not be intuitive for all users.

## Test Cases

Here are some test cases to verify the functionality of the program:

1. Adding a new employee:
   - Input valid employee details
   - Try to add an employee with an age below 17 or above 60
   - Attempt to add an employee with a negative salary

2. Adding a new department:
   - Create a new department with a unique name
   - Attempt to create a department with an existing name

3. Searching for an employee:
   - Search for an existing employee by ID
   - Search for a non-existent employee ID

4. Displaying highest salary:
   - Add multiple employees with different salaries
   - Verify that the correct employee(s) with the highest salary are displayed

5. Searching by department:
   - Search for an existing department
   - Search for a non-existent department

6. Editing employee information:
   - Edit various fields of an existing employee
   - Attempt to edit the owner's information (should be prevented)

7. Counting employees:
   - Add employees to different departments
   - Verify the count of employees in each department
   - Check the total count of employees and managers

8. Edge cases:
   - Try to add more than 50 employees or departments
   - Attempt to perform operations when no employees or departments exist

## Contributing
Feel free to fork this project and submit pull requests with improvements or additional features. Some areas for potential improvement include:
- Implementing data persistence
- Adding more robust error handling and input validation
- Creating a graphical user interface
- Implementing employee deletion functionality
- Adding sorting and filtering options for employee lists
