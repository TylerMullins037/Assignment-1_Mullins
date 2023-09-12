#ifndef ARRAY_MANAGER_H
#define ARRAY_MANAGER_H

#include <iostream>
#include <fstream>

class Array_Manager {
public:
    // Constructor to initialize the arrayManager object with a file path
    Array_Manager(const std::string& filepath);

    // Function to check if an integer exists in the array and return its index if found
    int find_integer(int target) const;

    // Function to modify the value of an integer at a specific index and return old and new values
    std::pair<int, int> modify_value(int index, int new_value);

    // Function to add an integer to the end of the array 
    void add_integer(int value);
        
    // Function to removes the value at a specific index
    void remove(int index);

    // Function to print the current array
    void print_array() const;
    

private:
    std::string filepath_;
    int* data_; // Assuming a maximum of 100 integers in the file
    int capacity_;
    int size_; // Actual number of ints in the array
    // Private function to check if the file exists
    bool file_exists(const std::string& filename) const; //Function to check if the file exists

    void expand_array(); // function to increase the capacity of the array
};

#endif // ARRAY_MANAGER_H
