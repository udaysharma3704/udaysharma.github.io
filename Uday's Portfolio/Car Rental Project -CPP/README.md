# Car Rental System

Welcome to the Car Rental System project! This console-based application allows users to register as customers, rent cars, return cars, and manage basic car rental operations.

## Table of Contents
- [Requirements](#requirements)
- [Tools and Platform](#tools-and-platform)
- [Basic Structure](#basic-structure)
- [Files and Folders](#files-and-folders)
- [Basic Workflow](#basic-workflow)
- [Usage](#usage)

## Requirements
The Car Rental System fulfills the following requirements:
- Customers can register by providing their name, email, and phone number.
- Users can view available cars and their details.
- Customers can rent and return cars, with the system updating availability status.
- Data is stored persistently in text files.

## Tools and Platform
- **Programming Language:** C++
- **Platform:** Console-based (Standard Input/Output)
- **Why C++:** Chosen for its simplicity, efficiency, and suitability for file handling and data manipulation.

## Basic Structure
The project is organized using two main structures:
- `Car`: Holds details about a car (company, model, color, etc.).
- `Customer`: Stores customer information (name, email, phone number).

Functions include data loading/saving, initialization, and user interaction.

## Files and Folders
- **Files:**
  - `car_data.txt`: Stores details about cars.
  - `customer_data.txt`: Stores customer information.

- **Folders:**
  - All files are typically kept in the same directory for simplicity.

- **Libraries (Libs):**
  - The project relies on standard C++ libraries for input/output and file handling.

- **Configs:**
  - Configuration details, such as file names, are directly included in the code.

## Basic Workflow
1. **Initialization:**
   - Load existing data (if any) and initialize cars with sample data.

2. **User Interaction:**
   - Main menu loop presents options to the user.
   - Users can register, rent, return cars, or exit.

3. **Data Handling:**
   - Manipulate data structures based on user actions.
   - Update availability status when renting or returning a car.

4. **Data Persistence:**
   - Save data back to files after significant operations.

5. **Display:**
   - Show relevant information to the user through the console interface.

6. **Exit:**
   - Users can exit the program, saving data for future use.

## Usage
1. Compile the program using a C++ compiler.
2. Run the executable.
3. Follow the on-screen instructions to register, rent, return cars, or exit.


