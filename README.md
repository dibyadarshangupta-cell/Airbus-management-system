# Airbus-management-system
it is my first git repository
Features of Airbus Management System
1. Add New Flights

The system allows the admin/user to add new flights.

Stores flight number, source, destination, and total seats.

Data is saved in a binary file (flights.dat) for future use.

2. View All Flights

Displays a list of all flights stored in the file.

Shows flight number, route, and seats available.

Useful for checking current flight availability.
Uniqueness of This Code
1. Uses Binary File Handling for Data Storage

Unlike simple programs using arrays or text files, this code uses binary files, which makes:

Faster reading/writing

Secure and compact data storage

Real-life resemblance to databases
4. Prevents Crashing with File-Exist Checks

Code checks whether files exist before reading.

Prevents runtime errors like segmentation faults.
