

#ifndef TWODARRAY_H
#define TWODARRAY_H
//#include <ostream>
#include <iostream>
#include <time.h>
#include <iomanip>
#include <random>
using namespace std;

template <typename T>

struct Chart {
    //Count the number of column spaces in a row

    static int array_size(int* sizes) {

        int* size_walker = sizes;
        int size_count = 0;

        while (*size_walker != -1) {
            size_count++;
            size_walker++;
        }
        return size_count;
    }

    //Prints the number of column spaces in a row

    static void print_array(int* a) {

        int* array_walker = a;

        cout << "sizes:";
        while (*array_walker != -1) {
            cout << setw(4) << *array_walker;
            array_walker++;
        }
        cout << endl;
    }

    //Check if a position is already occupied

    static bool is_unoccupied(T** twod, int* sizes, int row, int col) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; ++j) {
                if (row == i && col == j) {
                    //if the element at the position is not zero, the position is occupied
                    if (*col_walker != 0) {
                        cout << "[" << row << "][" << col << "] is occupied" << endl;
                        return false;
                    }
                }
                col_walker++;
            }
            num_cols_arr++;
        }

        return true;

    }

    //Check a position is outside of the boundary of the 2d array

    static bool is_within_bound(int* sizes, int row, int col) {

        int num_rows = array_size(sizes);

        if (row > num_rows - 1 || row < 0) {
            cout << "[" << row << "][" << col << "] is out-of-bound" << endl;
            return false;
        }

        //find column size
        int* col_walker = sizes;
        col_walker += row;
        int num_cols = *col_walker;
        if (col > num_cols - 1 || col < 0) {
            cout << "[" << row << "][" << col << "] is out-of-bound" << endl;
            return false;
        }

        return true;
    }

    //COME BACK AND WORK ON ME IF HAVE TIME!!
    //    static bool is_digit(int input) {
    //        return true;
    //    }

    //Check if user inputs a valid char for the menu

    static bool input_is_valid_lab(char input) {

        input = tolower(input);

        if (input != 'i' && input != 'o' && input != 'x') {
            cout << "Not a valid input. Try again." << endl;
            return false;
        }

        return true;
    }

    static bool input_is_valid_plane(char input) {

        input = tolower(input);

        if (input != 'r' && input != 'c' && input != 'x') {
            cout << "Not a valid input. Try again." << endl;
            return false;
        }

        return true;
    }

    static void plane_menu() {

        int** p;
        int sizes[] = {5, 5, 5, 5, -1};
        char menu_selection;
        int id = 0; //just make it into array
        int row = 0;
        int col = 0;

        p = allocate_twod(p, sizes);

        init_twod(p, sizes, 0);

        cout << "========================================" << endl << endl << "after init" << endl << endl;

        print_plane(p, sizes);

        do {
            cout << "[r]eserve" << setw(10) << "[c]ancel" << setw(10) << "e[x]it: ";

            cin >> menu_selection;

            if (tolower(menu_selection) == 'r') {

                cout << endl;
                cout << "----RESERVATION----" << endl;
                print_array(sizes);
                //check if the indexes are valid (within bound, unoccupied)
                do {
                    print_plane(p, sizes);
                    cout << "id: ";
                    cin >> id;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. id: ";
                        cin >> id;
                    }
                    cout << "aisle: ";
                    cin >> row;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. aisle: ";
                        cin >> row;
                    }
                    cout << "seat: ";
                    cin >> col;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. seat: ";
                        cin >> col;
                    }
                    cout << endl;
                } while (is_within_bound(sizes, row, col) == false || is_unoccupied(p, sizes, row, col) == false);

                //write id as the value of the double pointer twod
                write_twod(p, sizes, row, col, id);

                cout << "a seat for id#" << id << " is successfully reserved at aisle " << row << " seat " << col << endl;
                print_plane(p, sizes);

            } else if (tolower(menu_selection) == 'c') {

                cout << endl;
                cout << "----CANCELLATION----" << endl;
                print_array(sizes);
                print_plane(p, sizes);
                //prompt user to enter 

                cout << "id: ";
                cin >> id;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Not a valid input. Try again. id: ";
                    cin >> id;
                }

                //if id is found to be logged in...
                if (search_twod(p, sizes, id, row, col) == true) {
                    //log id out by replacing the position with 0
                    write_twod(p, sizes, row, col, 0);
                    cout << "the seat for id#" << id << " is successfully canceled" << endl;
                }//if id is NOT found to be logged in...do nothing
                else {
                    cout << "reservation for id#" << id << " is not found" << endl;
                }
                print_plane(p, sizes);

            }

        } while (!input_is_valid_plane(menu_selection) || tolower(menu_selection) != 'x');

    }

    static void lab_menu() {
        int** lab;
        int sizes[] = {5, 4, 3, 2, -1};
        char menu_selection;
        int id = 0; //just make it into array
        int row = 0;
        int col = 0;

        lab = allocate_twod(lab, sizes);

        init_twod(lab, sizes, 0);

        cout << "========================================" << endl << endl << "after init" << endl << endl;

        print_lab(lab, sizes);

        do {
            cout << "log[i]n" << setw(10) << "log[o]ut" << setw(10) << "e[x]it: ";

            cin >> menu_selection;

            if (tolower(menu_selection) == 'i') {

                cout << endl;
                cout << "----LOG IN----" << endl;
                print_array(sizes);
                //check if the indexes are valid (within bound, unoccupied)
                do {

                    print_lab(lab, sizes);
                    cout << "id: ";
                    cin >> id;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. id: ";
                        cin >> id;
                    }
                    cout << "lab: ";
                    cin >> row;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. lab: ";
                        cin >> row;
                    }
                    cout << "station: ";
                    cin >> col;
                    while (cin.fail()) {
                        cin.clear();
                        cin.ignore();
                        cout << "Not a valid input. Try again. station: ";
                        cin >> col;
                    }
                    cout << endl;
                } while (is_within_bound(sizes, row, col) == false || is_unoccupied(lab, sizes, row, col) == false);

                //write id as the value of the double pointer twod
                write_twod(lab, sizes, row, col, id);

                cout << id << " is logged in successfully" << endl;
                print_lab(lab, sizes);

            } else if (tolower(menu_selection) == 'o') {

                cout << endl;
                cout << "----LOG OUT----" << endl;
                print_array(sizes);
                print_lab(lab, sizes);
                //prompt user to enter 

                cout << "id: ";
                cin >> id;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Not a valid input. Try again. id: ";
                    cin >> id;
                }

                //if id is found to be logged in...
                if (search_twod(lab, sizes, id, row, col) == true) {
                    //log id out by replacing the position with 0
                    write_twod(lab, sizes, row, col, 0);
                    cout << id << " is logged out successfully" << endl;
                }//if id is NOT found to be logged in...do nothing
                else {
                    cout << id << " is not signed in." << endl;
                }
                print_lab(lab, sizes);

            }

        } while (!input_is_valid_lab(menu_selection) || tolower(menu_selection) != 'x');
    }

    //Dynamically allocate space in the heap for the 2d array

    static T** allocate_twod(T** twod, int* sizes) {

        int num_rows = array_size(sizes); //const don't change this
        int num_cols; //will keep on updating

        twod = new T*[num_rows];

        T** row_walker = twod;
        T* col_walker = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *col_walker;
            *row_walker = new T[num_cols];
            row_walker++;
            col_walker++;
        }
        return twod;
    }

    static T** allocate_twod(int* sizes) {
        int num_rows = array_size(sizes); //const don't change this
        int num_cols = 0; //initialize it. but it will keep on updating

        T** twod = new T*[num_rows];

        T** row_walker = twod;
        T* col_walker = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *col_walker;
            *row_walker = new T[num_cols];
            row_walker++;
            col_walker++;
        }

        return twod;
    }

    //initialize the 2d array to zero to indicate unoccupied spaces

    static void init_twod(T** twod, int* sizes, T init_item = T()) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; ++j) {
                *col_walker = 0;
                col_walker++;
            }
            num_cols_arr++;
        }
    }

    static void print_lab(T** twod, int* sizes) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //will change

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            cout << "lab " << i << ":";
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; j++) {
                cout << setw(4) << *col_walker;
                col_walker++;
            }
            cout << endl;
            num_cols_arr++;
        }
        cout << endl;
    }

    static void print_plane(T** twod, int* sizes) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //will change

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            cout << "aisle " << i << ":";
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; j++) {
                cout << setw(4) << *col_walker;
                col_walker++;
            }
            cout << endl;
            num_cols_arr++;
        }
        cout << endl;
    }

    //Given a position, output the item/element occupying the position

    static T read_twod(T** twod, int* sizes, int row, int col) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; ++j) {
                if (row == i && col == j) {
                    return *col_walker;
                }
                col_walker++;
            }
            num_cols_arr++;
        }

    }

    //Given a position, place an item to occupy that position in the 2d array

    static void write_twod(T** twod, int* sizes, int row, int col, const T& item) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; ++j) {
                if (row == i && col == j) {
                    *col_walker = item;
                }
                col_walker++;
            }
            num_cols_arr++;
        }
    }

    //Honestly not too sure what it does...
    //My guess is it takes a position, and returns the address of the 2d array

    static T& get_twod(T** twod, int* sizes, int row, int col) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //will change

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            cout << "aisle " << i << ":";
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; j++) {
                col_walker++;
            }
            num_cols_arr++;
        }
        cout << endl;



        return twod;

    }

    //Given a position, check if a key item is inside the 2d array

    static bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; ++i) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; ++j) {
                if (*col_walker == key) {
                    row = i;
                    col = j;
                    return true;
                }
                col_walker++;
            }
            num_cols_arr++;
        }
        return false;
    }
};

#endif /* TWODARRAY_H */

