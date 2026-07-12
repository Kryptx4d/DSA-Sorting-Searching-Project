#include <iostream>

int main() {
    char choice;

    do {
        std::cout << "\n" << std::endl;
        std::cout << "# Sorting and Searching Interface DSA #\n";
        std::cout << "A. Display all records: \n";
        std::cout << "B. Sort Records: \n";
        std::cout << "C. Search for numbers: \n";
        std::cout << "D. Exit\n" << std::endl;

        std::cout << "Enter your choice(A-D): ";
        std::cin >> choice;

        std::cout <<"\n" << std::endl;

        switch (choice) {
            case 'A':
                std::cout << "Displaying all records....\n" << std::endl;
                break;

            case 'B':
                std::cout << "Sorting records.....\n"<< std::endl;
                break;

            case 'C':
                std::cout << "Searching for numbers....\n"<< std::endl;
                break;

            case 'D':
                std::cout << "Exiting Application...\n"<< std::endl;
                break;
            
            default:
                std::cout << "Invalid Choice. Please enter letters between A-D in upper case. Try Again."<< std::endl;

        }
    } while (choice != 'D');



    return 0;
}
