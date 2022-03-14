#include "mat.hpp"
#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>

namespace ariel{
    /**
     * @brief 
     * this function get the number of rows , colunms , simbol1, simbol2
     * and the fanction creat a mat in the size rows*colunms with the two simbol
     * we creating a matrix by vectors that will represent our mat.
     * then we fill the matrix with the simbpls like we ask by runing from the 
     * boundris to the center.
     * 
     * @param weight : number of colums
     * @param length : number of rows
     * @param firest_simbol : the firest simbol
     * @param second_simbol : the second simbol
     * @return std::string 
     */
    std::string mat(int weight, int length, char firest_simbol, char second_simbol){
        // the boundris for the chars we can get 
        const int minc = 33;
        const int maxc = 126; 

        if((firest_simbol<minc)||(firest_simbol>maxc))
        {
            throw std::invalid_argument("bad input for simbol A");
        }

        if((second_simbol<minc)||(second_simbol>maxc))
        {
            throw std::invalid_argument("bad input for simbol B");
        }

        //check the number is positive
        if(length<=0 || weight<=0)
        {
             throw std::invalid_argument("bad input cant get negetive");
        }

        //check the number of row and colums is odd
        if(length%2 == 0)
        {
            throw std::invalid_argument("bad input can get only odd");
        }
       
        if(weight%2 == 0)
        {
            throw std::invalid_argument("bad input can get only odd");
        }
        
        // check that the simbol is not ' ' or '    ' or \n or \t
        if(firest_simbol == ' ' || firest_simbol == '\n' || firest_simbol == '\t' || firest_simbol == '\r')
        {
            throw std::invalid_argument("bad input for simbol A");
        }
        
        if(second_simbol == ' ' || second_simbol == '\n' || second_simbol == '\t' || second_simbol == '\r')
        {
            throw std::invalid_argument("bad input for simbol B");
        }
        
        //defind the matrix
        std::vector<std::vector<char>>matrix(length,std::vector<char>(weight));

        // use for the the simbol we work on 
        char simbol = firest_simbol;
        
        for(int count=0; (count<(length+1)/2) && (count<(weight+1)/2); count++)
        {
            // every time we check if count is odd if yes we use second simbol if not use firest simbol
            if(count%2 == 0)
            {
                simbol = firest_simbol;
            }
            else
            {
                simbol = second_simbol;
            }
            // fill the matrix 
            for(int coulm=count; coulm<weight-count ; coulm++)
            {
                matrix[count][coulm] = simbol;
            }

            for(int coulm=count; coulm<weight-count ; coulm++)
            {
                matrix[length-1-count][coulm] = simbol;
            }

            for(int row=count; row<length-count ; row++)
            {
                matrix[row][count] = simbol;
            }

            for(int row=count; row<length-count ; row++)
            {
                matrix[row][weight-1-count] = simbol;
            }
        }

        std::string st;
        //copy the matrix to string
        for(int row=0 ; row < length ; row++)
        {
            for(int coulm = 0 ; coulm < weight; coulm++)
            {
                st += matrix[row][coulm];
            }
            st += "\n";
        }
        
        return st;
    }
}