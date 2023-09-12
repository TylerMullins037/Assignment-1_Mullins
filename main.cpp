#include <iostream>
#include "Assignment-1.h"
#include <limits> // for clearing input buffer

int main() {
    try {
        Array_Manager arrayManager("list.txt"); // Provide the path to your data file

        // Test operations
        // Question #1 part 1 
        try { // catches invalid user inputted errors (i.e. wrong datatypes)
            int target;
            std::cout << "Enter the integer to search for: ";
            std::cin >> target;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid value inputted \n");
            }
            int index1 = arrayManager.find_integer(target); // Searches the array for the 'target' and returns index of 'target'

            if (index1 != -1) {
                std::cout << "Integer " << target << " found at index " << index1 << "\n" << std::endl;
            }
            else {
                std::cout << "Integer " << target << " not found in the array" << "\n" << std::endl;
            }
            
        }
        catch (const std::exception& e) {
            std::cerr << "Error finding value: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            
        }

        
       
        // Question #1 part 2 
        try { // try and catch block needed for question 2 part a (i.e. for wrong datatypes or index out of range)
            int index2;
            std::cout << "Enter the index you would like to modify: ";
            std::cin >> index2;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid Index Input \n");
            }

            int new_value;
            std::cout << "Enter an integer to replace the old value: ";
            std::cin >> new_value;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid value inputted \n");
            }

            std::pair<int, int> modification_result = arrayManager.modify_value(index2, new_value); // modifies the given index with the given value and returns old and new value
            std::cout << "Old value: " << modification_result.first
                << ", New value: " << modification_result.second << "\n" << std::endl;
        }
        catch (const std::exception& e) {
            std::cerr << "Error modifying value: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        // Question 1 part 3
        try { // try and catch block needed for question 2 part b (i.e for wrong datatypes)
            int add_value;
            std::cout << "Enter an integer to add to the end of the array: ";
            std::cin >> add_value;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid value inputted \n");
            }
            arrayManager.add_integer(add_value); // adds an integer tho the end of the array
        }
        catch (const std::exception& e) {
            std::cerr << "Error adding value: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Question 1 part 4
        try { // catches invalid user inputs errors (i.e. wrong datatypes or index out of range)
            
            int remove_index;
            std::cout << "Enter the index you would like to remove: ";
            std::cin >> remove_index;
            if (std::cin.fail()) {
                throw std::invalid_argument("Invalid Index Input \n");
            }
            arrayManager.remove(remove_index); // Removes the integer at index 'remove_index" and shifts everything down
        }
        catch (const std::exception& e) {
            std::cerr << "Error removing value: " << e.what() << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }

        // Prints the array
        arrayManager.print_array();
    }
    catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}


    




