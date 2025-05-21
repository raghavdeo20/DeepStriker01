# Chemistry Lab Management System - Project Report

---

## 1. Introduction

This project is a Chemistry Lab Management System developed using Object-Oriented Programming in C++. It provides a robust interface for managing experiments, chemical inventories, and laboratory apparatus. The system reads and writes data from CSV files and allows users to perform key lab operations from a menu-driven interface.

## 2. Objective

To create a terminal-based Chemistry Lab Management System that enables users to:

* Add and view experiments
* Manage chemical and apparatus inventories
* Search across all modules

This solution provides persistent storage using CSV files and emphasizes clean structure using object-oriented design.

## 3. System Features

### 3.1 Experiment Management

* Add new experiments with description, chemicals used, and date.
* View all past experiments.
* Each experiment is uniquely identified with a UUID.

### 3.2 Chemical Inventory

* Add chemicals to inventory.
* View list of available chemicals.
* Store chemical name, expiry date, and usage percentage.

### 3.3 Apparatus Inventory

* Add apparatus to inventory.
* View all apparatus with quantities.

### 3.4 Search Functionality

* Search by keyword across experiments, chemicals, and apparatus.
* Supports case-insensitive partial match.

### 3.5 User Interface

* Menu-driven UI with options from 1 to 10.
* Boot screen with simulated loading using delays.
* Screen clearing after each operation.

## 4. Object-Oriented Design

The project is built around three main classes:

### 4.1 Class: `Experiment`

* **Attributes**: id, description, chemicals used, date
* **Methods**: input from user, display, static view/load/save functions

### 4.2 Class: `Chemical`

* **Attributes**: id, name, expiry date, usage percentage
* **Methods**: input, display, static view/load/save

### 4.3 Class: `Apparatus`

* **Attributes**: id, name, quantity
* **Methods**: input, display, static view/load/save

### 4.4 Class: `LabManagementSystem`

* Handles menu, system initialization, and user interaction.

## 5. File Structure

* `experiments.csv`: Stores experiment records
* `chemical_inventory.csv`: Stores chemicals
* `apparatus_inventory.csv`: Stores apparatus

Each record is stored in a comma-separated format, ensuring compatibility with Excel and other software.

## 6. Libraries Used

### Standard C++ Libraries:

| Library       | Role in the Program                                |
| ------------- | -------------------------------------------------- |
| `<iostream>`  | Console I/O (main communication with user)         |
| `<fstream>`   | Reading and writing `.csv` files                   |
| `<string>`    | Storing and manipulating textual data              |
| `<vector>`    | Dynamic lists of objects (like experiments)        |
| `<sstream>`   | CSV parsing and string conversion                  |
| `<algorithm>` | Case-insensitive search via string transformations |
| `<cctype>`    | Character-wise manipulation                        |
| `<cstdlib>`   | Clearing the terminal screen                       |
| `<thread>`    | Sleep functions for simulated system loading       |
| `<chrono>`    | Time measurement and delays                        |
| `<limits>`    | Input buffer clearing for robust user input        |

These libraries form the backbone of the system's input/output, storage, user interaction, and text processing.

## 7. Conclusion

This project showcases practical application of object-oriented principles in building a useful terminal-based application. The system is modular, easily extensible, and demonstrates file handling, string processing, and interactive console development in C++. The structure ensures a clean separation of responsibilities between different components of the system.

Future improvements may include:

* Adding delete/edit functionality
* GUI-based interface
* Automated alerts for expired chemicals
* Enhanced reporting and analytics
