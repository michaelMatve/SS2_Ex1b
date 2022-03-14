#include <iostream>
#include <string>
#include "mat.hpp"

/**
 * @brief 
 * this main use for the user for insert inputs for creating new mat.
 * the main will ask the use if hi want to continue and hi will need to insert 'n' for no
 * and 'y' for yes
 * @return int 
 */
int main(){

    char flage_continue = 'y';
    int col,row;
    char simbol1, simbol2;

    while(flage_continue == 'y'){
        // ask for insert the coulm number and save it as int
        std::cout << "insert the number of columns: " << std::endl;
        std::cin >> col;

        // ask for insert the rows number and save it as int
        std::cout << "insert the number of rows: " << std::endl;
        std::cin >> row;

        // ask for insert symbols and then save tham as char
        std::cout << "insert the firest simbol: " << std::endl;
        std::cin >> simbol1;

        std::cout << "insert the second simbol :" << std::endl;
        std::cin >> simbol2;

        //call the fanction mat in ariel namespace for creat a mat 
        //and then print the string that the func return
        std::string new_mat = ariel::mat(col,row,simbol1,simbol2);
        std::cout << "this is your mat: " << std::endl << new_mat;

        //ask the user if he want to continue for stop insert 'n' for yes insert 'y'
        std::cout<< "do you want to insert another mat?"<< std::endl << "for yes insert 'y' for no insert 'n'";
        std::cin>> flage_continue;
    }

}