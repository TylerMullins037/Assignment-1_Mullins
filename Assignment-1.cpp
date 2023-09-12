#include "Assignment-1.h"


Array_Manager::Array_Manager(const std::string& filepath) :capacity_(100), size_(0) {
    // pre-condtion: 'filepath' is a valid path to an existing file
    //                or if it is in your working directory, ensure its the correct name
    // post-condition: The constructor initializes the 'Array_Manager' object,
    //                 reads integers from the file located at 'filepath', and stores them in 
    //                 the array 'data_'. If the file does not exist, it throws a runtime error
    data_ = new int[capacity_];

    if (!file_exists(filepath)) {
        throw std::runtime_error("File does not exist");
    }

    std::ifstream file(filepath);
    int value;

    while (file >> value) {
        if (size_ < capacity_) {
            data_[size_++] = value;
        }
        else {
            expand_array(); 
            data_[size_++] = value;
        }
    }
}

int Array_Manager::find_integer(int target) const {
    // pre-condition: 'target' must be an integer
    // post-condition: Returns the index of the first occurrence of 'target' in the 
    //                 array if found; otherwise, returns -1    
    for (int i = 0; i < size_; ++i) {
        if (data_[i] == target) {
            return i;
        }
    }
    return -1; // Integer not found
}

std::pair<int, int> Array_Manager::modify_value(int index, int new_value) {
    // pre-condition: 'index' and 'new_value' are integers 
    //                and 'index' is a valid index within the array
    // post-condition: If 'index' is valid, it replaces the value at that index with 'new_value'
    //                 and returns a 'std::pair' containing the old value and the new value. 
    //                 If 'index is out of range, it throws a out of range exception
        if (index >= 0 && index < size_) {
            int old_value = data_[index];
            data_[index] = new_value;
            return std::make_pair(old_value, new_value);
        }
        else {
            throw std::out_of_range("Index out of range \n");
        }
    
}


void Array_Manager::add_integer(int value) {
    // pre-condition: 'value' is an integer
    // post-condition: Adds the integer 'value' to the end of the array if there is enough capacity. 
    //                 If the array is full, it dynamically allocates more space by doubling the capacity 
    //                 and then adds 'value'. Prints a message to indicate the addition of the integer.
    if (size_ < capacity_) {
        data_[size_++] = value;
    }
    else {
        expand_array();
        data_[size_++] = value;
    }
    std::cout << "Added integer " << value << " to the end of the array\n" << std::endl;
    
}

void Array_Manager::remove(int index) {
    // pre-condition: 'index' is an integer and a valid index within the array
    // post-condition: If 'index' is valid, it removes the value at that index by shifting all subsequent 
    //                 elements one position left. Prints a message indicating the removal. If 'index' is out 
    //                 of range, it throws an out of range exception.
    if (index >= 0 && index < size_) {
        for (int i = index; i < size_ - 1; ++i) {
            data_[i] = data_[i + 1];
        }
        size_--;
        std::cout << "Removed value at index " << index << "\n" << std::endl;
    }
    else {
        throw std::out_of_range("Index out of range");
    } 
}

void Array_Manager::expand_array() {
    // pre-condition: None.
    // post-condition: Doubles the capacity of the dynamic array 'data_', copies the existing elements to the
    //                 new array and deallocates the old array. This function is called when the array is full
    int new_capacity = capacity_ * 2; 
    int* new_data = new int[new_capacity];
    for (int i = 0; i < size_; ++i) {
        new_data[i] = data_[i];
    }

    delete[] data_;
    data_ = new_data;
    capacity_ = new_capacity;
}

void Array_Manager::print_array() const {
    // pre-condition: None.
    // post-condition: Prints the elements of the current array to the standard output, separated by spaces.
    for (int i = 0; i < size_; ++i) {
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

bool Array_Manager::file_exists(const std::string& filename) const {
    // pre-condition: None.
    // post-condition: Returns 'true' if the file with the given 'filename' exists and is accessible; 
    //                 otherwise, returns 'false'. Use internally to check if a file exists before reading from it.
    std::ifstream file(filename);
    return file.good();
}