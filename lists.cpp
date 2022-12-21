// Copyright (c) 2022 KestrelBryce All rights reserved
//
// Created by: KestrelBryce
// Created on: Dec. 20, 2022
// This program asks the user
// to input grades from 1 to
// 100, and then finds the
// average of the grades


#include <cmath>
#include <cstdlib>
#include <iostream>
#include <list>
#include <string>

// calcAverage function
// template <size_t MAX>
int calcAverage(std::list<int> gradeNumList) {
    // Initializing sum
    int sum = 0;
    int finalSum;
    // int numAmount;
    for (int aSingleNumber : gradeNumList) {
        // Reassigning sum
        sum = sum + aSingleNumber;
    }
    // Initializing numAmount
    int numAmount = gradeNumList.size();
    if (numAmount == 0) {
        return -1;
    } else {
        finalSum = sum / numAmount;
        return finalSum;
    }
}

int main() {
    // Introductory paragraph
    std::cout << "This program asks the user\n";
    std::cout << "to input grades from 1 to\n";
    std::cout << "100, and then finds the\n";
    std::cout << "average of the grades";
    std::cout << "\n";

    // Initializing variables
    // gradeNumList
    std::list<int> gradeNumList;
    // userInput
    std::string userInput;
    // userInputInt
    int userInputInt;

    // Generating numbers
    while (true) {
        // Getting numbers
        std::cout << "Enter a positive number [enter stop to stop]: ";
        std::cin >> userInput;
        // Checking to see if loop continues
        if (userInput == "stop") {
            break;
        }
        // Checking valid input
        try {
            userInputInt = std::stoi(userInput);

            // Checking if input is within range
            if (userInputInt > 100 || userInputInt < 1) {
                std::cout << "Please enter a grade between 1 and 100.";
                continue;
            } else {
                // Adding input to list
                gradeNumList.push_back(userInputInt);
            }
        } catch (std::invalid_argument) {
            // Error message
            std::cout << "Please enter a numerical grade.";
        }
    }
    // Calling calcAverage()
    int trueSum = calcAverage(gradeNumList);

    // Checking results
    if (trueSum == -1) {
        // Error message (not enough grades)
        std::cout << "Please enter two or more grades.";
    } else {
        // Displaying results
        std::cout << "The average grade is ";
        std::cout << trueSum;
        std::cout << "%.";
        std::cout << "\n";
    }
}
