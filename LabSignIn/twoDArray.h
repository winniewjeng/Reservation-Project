

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
    //Implemented

    static void print_array(int* a) {

        int* array_walker = a;

        cout << "lab:";
        while (*array_walker != -1) {
            cout << setw(4) << *array_walker;
            array_walker++;
        }
        cout << endl;
    }

    //Implemented

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
                    if (*col_walker != 0) {
                        cout << "[" << row << "][" << col << "] is occupied" << endl;
                        return false;
                    }
                }
                col_walker++;
            }
            num_cols_arr++;
        }

        //        T** row_walker = twod;
        //        row_walker += row;
        //        T* col_walker = *row_walker;
        //        col_walker += col;
        //
        //        if (*col_walker != 0) {
        //            cout << "[" << row << "][" << col << "] is occupied" << endl << endl;
        //            return false;
        //        }

        return true;

    }

    //Implemented

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

    //    static bool is_digit(int input) {
    //        return true;
    //    }

    //Implemented

    static bool input_is_valid(char input) {

        input = tolower(input);

        if (input != 'i' && input != 'o' && input != 'x') {
            cout << "Not a valid input. Try again." << endl;
            return false;
        }

        return true;
    }
    
    //NOT YET IMPLEMENTED
    
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
            cout << "log[i]n" << setw(10) << "log[o]ut" << setw(10) << "e[x]it: ";

            cin >> menu_selection;

            if (tolower(menu_selection) == 'i') {

                cout << endl;
                cout << "----LOG IN----" << endl;
                print_array(sizes);
                //check if the indexes are valid (within bound, unoccupied)
                do {
                    print_plane(p, sizes);
                    cout << "id: ";
                    cin >> id;
                    cout << "asile: ";
                    cin >> row;
                    cout << "seat: ";
                    cin >> col;
                    cout << endl;
                } while (is_within_bound(sizes, row, col) == false || is_unoccupied(p, sizes, row, col) == false);

                //write id as the value of the double pointer twod
                write_twod(p, sizes, row, col, id);

                cout << id << " is logged in successfully" << endl;
                print_plane(p, sizes);

            } else if (tolower(menu_selection) == 'o') {

                cout << endl;
                cout << "----LOG OUT----" << endl;
                print_array(sizes);
                print_plane(p, sizes);
                //prompt user to enter 

                cout << "id: ";
                cin >> id;
                while (cin.fail()) {
                    cin.clear();
                    cin.ignore();
                    cout << "Not a valid input. Try again." << endl;
                    cin >> id;
                }
                
                //if id is found to be logged in...
                if (search_twod(p, sizes, id, row, col) == true) {
                    //log id out by replacing the position with 0
                    write_twod(p, sizes, row, col, 0);   
                    cout << id << " is logged out successfully" << endl;
                }
                //if id is NOT found to be logged in...do nothing
                else {
                    cout << id << " is not signed in." << endl; 
                }      
                print_plane(p, sizes);

            }

        } while (!input_is_valid(menu_selection) || tolower(menu_selection) != 'x');
    
    }

    //UNDER CONSTRUCTION

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
                    cout << "lab: ";
                    cin >> row;
                    cout << "station: ";
                    cin >> col;
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
                    cout << "Not a valid input. Try again." << endl;
                    cin >> id;
                }
                
                //if id is found to be logged in...
                if (search_twod(lab, sizes, id, row, col) == true) {
                    //log id out by replacing the position with 0
                    write_twod(lab, sizes, row, col, 0);   
                    cout << id << " is logged out successfully" << endl;
                }
                //if id is NOT found to be logged in...do nothing
                else {
                    cout << id << " is not signed in." << endl; 
                }      
                print_lab(lab, sizes);

            }

        } while (!input_is_valid(menu_selection) || tolower(menu_selection) != 'x');
    }

    //Implemented

    static int array_size(int* sizes) {

        int* size_walker = sizes;
        int size_count = 0;

        while (*size_walker != -1) {
            size_count++;
            size_walker++;
        }
        return size_count;
    }

    //Implemented

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

        //        //        Keep for Testing purpose
        //                        T* c_w = sizes;
        //                        
        //                        for (int i = 0; i < num_rows; i++) {
        //                            for (int j = 0; j < *c_w; j++) {
        //                                twod[i][j] = j;
        //                                cout << twod[i][j] << " ";
        //                            }
        //                            c_w++;
        //                            cout << endl;
        //                        }
        return twod;
    }

    //Implemented

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

    //Implemented

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

    //Implemented

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
    

    //Implemented

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

    //Implemented

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
        //DO NOT DELETE FOR FUTURE REFERENCE
        //IT'S A THEORETICALLY CORRECT ALGORITHM
        //NOT WORKING FOR THIS PARTICULAR 2D ARR OF POINTERS
        //        T** row_walker = twod;
        //        T** trow_walker = twod;
        //        cout << trow_walker << endl;
        //        cout << "the previous row is on " << **row_walker << endl;
        //        row_walker += row;
        //        cout << "the current row is on " << **row_walker << endl;
        //        T* col_walker = *row_walker;
        //        //        cout << "col_walker " << *col_walker << endl;
        //        col_walker += col;
        //        *(col_walker) = item;
    }

    //NOT SURE WHAT IT DOES?????????????????????

    static T& get_twod(T** twod, int sizes, int row, int col);

    //Implemented

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

    //NOT YET IMPLEMENTED
    static std::ostream& print_twod(T** twod, int* sizes, std::ostream& outs);

};

#endif /* TWODARRAY_H */

