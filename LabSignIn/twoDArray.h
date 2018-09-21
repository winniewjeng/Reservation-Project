

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
    //NOT YET IMPLEMENTED
    static int print_array(int* a);
    //NOT YET IMPLEMENTED
    static bool index_is_valid(int* sizes, int row, int col);
    //NOT YET IMPLEMENTED

    static void lab_menu() {
        T** twod;
        T* sizes;
        //delete
        allocate_twod(twod, sizes);
        //calls print_twod() to display the initialized 2d array of plane seats
        //keep prompting the user to enter an lab number (i, row) and station number (j, col) unless exiting program
        //check if user input is_valid()
        //write_twod()
        //print_twod() to update the plane seats
    };

    //IMPLEMENTED

    static int array_size(int* sizes) {

        int* size_walker = sizes;
        int size_count = 0;

        while (*size_walker != -1) {
            size_count++;
            size_walker++;
        }
        return size_count;
    }

    //IMPLEMENTED????????

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

//        Testing purpose
                T* c_w = sizes;
                
                for (int i = 0; i < num_rows; i++) {
                    for (int j = 0; j < *c_w; j++) {
                        twod[i][j] = j;
                        cout << twod[i][j] << " ";
                    }
                    c_w++;
                    cout << endl;
                }
        return twod;
    }

    //IMPLEMENTED??????????

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

    //NYI--NEXT!!!

    static void init_twod_lab(T** twod, int* sizes, T init_item = T()) {
        T** vertical_walker = twod;
        int* horizontal_walker = sizes;
        int num_rows = array_size(sizes);
        //walk through the vertical spaces of the array
        for (int i = 0; i < num_rows; i++) {
            //walk through the horizontal spaces of the array
            while (horizontal_walker != (*sizes) + sizes) {
                //initialize the space to 0;
                *horizontal_walker = 0;
                horizontal_walker++;
            }
            vertical_walker += (*sizes);
            sizes++;
        }

    }

    //TESTING TO BE DELETED

    static void init_and_print(T** twod, int* sizes) {

        T** vertical_walker = twod;
        int* size_walker = sizes;

        allocate_twod(twod, sizes);
        //walk through the vertical spaces of the 2d array 
        //        while(**vertical_walker != -1) {
        //            //walker through the horizontal spaces of the 2d array
        //            
        //            cout << "hey" << endl;
        //            cout << *size_walker << " ";
        //            size_walker++;
        //            //walker through the horizontal spaces of the 2d array
        ////            while (size_walker != sizes + (*sizes)){
        ////                cout << *horizontal_walker << " ";
        ////                horizontal_walker++;
        ////            }
        ////            sizes++;
        ////            horizontal_walker = sizes;
        ////            cout << "\n" << *horizontal_walker<< endl;
        ////            cout << endl;
        ////            vertical_walker++;
        //        }
        //        int num_rows = array_size(sizes);
        //        for (int i = 0; i < num_rows; i++) {
        //            cout << i << endl;
        //            //walk through the horizontal spaces of the array
        //        }
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
