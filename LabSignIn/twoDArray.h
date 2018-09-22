

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
    //Implemented -- print the sizes[] array 

    static void print_array(int* a) {
        int* array_walker = a;

        cout << "lab:";
        while (*array_walker != -1) {
            cout << setw(4) << *array_walker;
            array_walker++;
        }
        cout << endl;
    }

    //NOT YET!!--NEXT!!

    static bool is_unoccupied(T** twod, int* sizes, int row, int col) {

        //        cout << "enter unoccupid" << endl;
        //        int num_rows = array_size(sizes); //number of rows of the 2d array is fixed
        //        int num_cols; //number of columns of the 2d array changes with each row
        //
        //        T** row_walker = twod;
        //        T* col_walker = *row_walker;
        //        T* sizes_walker = sizes;
        //
        //        //traverse through the rows
        //        for (int i = 0; i < num_rows; i++) {
        //            //number of columns changes for each row, as indicated by the sizes array
        //            num_cols = *sizes_walker;
        //            //traverse through the columns
        //            for (int j = 0; j < num_cols; j++) {
        //                //if detecting a non-zero spot (already logged-in), return false
        //                if (*col_walker != 0) {
        //                    cout << "this positinon is already occupied." << endl;
        //                    return false;
        //                }
        //                col_walker++;
        //            }
        //            
        //            sizes_walker++;
        //        }
        //        cout << "exit unoccup" << endl;

    }

    //Implemented

    static bool is_within_bound(int* sizes, int row, int col) {
        int num_rows = array_size(sizes);

        if (row > num_rows - 1 || row < 0) {
            cout << "[" << row << "][" << col << "] is out-of-bound" << endl << endl;
            return false;
        }

        //find column size
        int* col_walker = sizes;
        col_walker += row;
        int num_cols = *col_walker;
        if (col > num_cols - 1 || col < 0) {
            cout << "[" << row << "][" << col << "] is out-of-bound" << endl << endl;
            return false;
        }

        return true;
    }

    //Implemented

    static bool input_is_valid(char input) {

        if (input != 'i' && input != 'o' && input != 'e') {
            cout << "Not a valid input. Try again." << endl;
            return false;
        }

        return true;
    }

    //NOT YET finished

    static void lab_menu() {
        int** p;
        int sizes[] = {4, 3, 6, -1};
        char menu_selection;
        int id_input; //just make it into array
        int row;
        int col;

        p = allocate_twod(p, sizes);

        init_twod_lab(p, sizes, 0);
        cout << "========================================" << endl << endl << "after init" << endl << endl;
        print(p, sizes);
        cout << endl;
        do {
            cout << "log[i]n" << setw(10) << "log[o]ut" << setw(10) << "[e]xit: ";
            cin >> menu_selection;

            if (menu_selection == 'i') {

                cout << endl;
                cout << "----LOG IN----" << endl;
                print_array(sizes);
                cout << endl;
                //check if the indexes are valid (within bound, unoccupied)
                do {
                    print(p, sizes);
                    cout << endl << "id: ";
                    cin >> id_input;
                    cout << "lab: ";
                    cin >> row;
                    cout << "station: ";
                    cin >> col;
                    cout << endl;
                } while (!is_within_bound(sizes, row, col));

                cout << "exit" << endl;
                cout << row << " is row and " << col << " is col" << endl;

                //write id as the value of the double pointer twod


            } else if (menu_selection == 'o') {
                //do everything logout does
            }

        } while (!input_is_valid(menu_selection) || menu_selection != 'e');


        //keep prompting the user to enter an lab number (i, row) and station number (j, col) unless exiting program
        //write_twod()
        //print_twod() to update the plane seats
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
        int num_cols = 0; //initialize it. but it will keep on updating

        twod = new T*[num_rows];

        T** row_walker = twod;
        T* col_walker = sizes;

        for (int i = 0; i < num_rows; i++) {
            num_cols = *col_walker;
            *row_walker = new T[num_cols];
            row_walker++;
            col_walker++;
        }

        ////        Keep for Testing purpose
        //                T* c_w = sizes;
        //                
        //                for (int i = 0; i < num_rows; i++) {
        //                    for (int j = 0; j < *c_w; j++) {
        //                        twod[i][j] = j;
        //                        cout << twod[i][j] << " ";
        //                    }
        //                    c_w++;
        //                    cout << endl;
        //                }
        return twod;
    }

    //Implemented

    static T** allocate_twod(int* sizes) {
        int num_rows = array_size(sizes); //const don't change this
        int num_cols = 0; //initialize it. but it will keep on updating

        T** twod = new T*[num_rows];

        T** row_walker = twod;
        T* col_walker = sizes;

        for (int i = 0; i < num_rows; i++) {
            num_cols = *col_walker;
            *row_walker = new T[num_cols];
            row_walker++;
            col_walker++;
        }

        return twod;
    }

    //Implemented

    static void init_twod_lab(T** twod, int* sizes, T init_item = T()) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //keep on updating for each row that you enter

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; i++) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; j++) {
                *col_walker = 0;
                col_walker++;
            }
            num_cols_arr++;
        }
    }

    //Implemented

    static void print(T** twod, int* sizes) {

        int num_rows = array_size(sizes); //stays the same
        int num_cols; //will change

        T** row_walker = twod;
        T* col_walker = *row_walker;
        T* num_cols_arr = sizes;

        for (int i = 0; i < num_rows; i++) {
            num_cols = *num_cols_arr;
            for (int j = 0; j < num_cols; j++) {
                cout << setw(4) << *col_walker;
                col_walker++;
            }
            cout << endl;
            num_cols_arr++;
        }
    }


    //NOT YET IMPLEMENTED
    static T read_twod(T** twod, int row, int col);

    //NOT YET IMPLEMENTED
    static void write_twod(T** twod, int row, int col, const T& item);

    //NOT YET IMPLEMENTED
    static T& get_twod(T** twod, int row, int col);

    //NOT YET IMPLEMENTED
    static bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

    //NOT YET IMPLEMENTED
    static std::ostream& print_twod(T** twod, int* sizes, std::ostream& outs);

};
//lastly, struct these functions???

#endif /* TWODARRAY_H */

