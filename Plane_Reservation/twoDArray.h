

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

    static void plane_get_input(int& row, int& col) {
        cout << "How many aisles does this plane have? ";
        cin >> row;
        cout << "How many seating does each aisle have? ";
        cin >> col;
    }
    
    //NOT YET IMPLEMENTED
    //initialize an array of seating sizes of 6
    static int array_size(int* sizes, int horizontal) {

        //note that horizontal is also col, which is gotten through userinput for plane project and rand() for lab project
        int count = 0;
        int* walker = sizes;
        while (walker != sizes + horizontal) {
            count++;
            walker++;
        }
        return count;
    }

    /*Dividing the non-templates with the templates*/

    //CURRENTLY IMPLEMETING...

    //template <class T>

    static void lab_menu() {

        //calls print_twod() to display the initialized 2d array of plane seats


        //keep prompting the user to enter an lab number (i, row) and station number (j, col) unless exiting program
        //check if user input is_valid()
        //write_twod()
        //print_twod() to update the plane seats
    };
    //CURRENTLY IMPLEMETING...

    static void plane_menu() {

        //     //a double pointer is declared for constructing the 2d array
        //    T* sizes; //a pointer holding the sizes of the horizontal array
        int aisles;
        int seats;
        plane_get_input(aisles, seats);
        

        //    init_twod_plane(twod, sizes, 0);


        //calls print_twod() to display the initialized 2d array of plane seats


        //keep prompting the user to enter an aisle number (i, row) and seating number (j, col) unless exiting program
        //check if user input is_valid()
        //write_twod()
        //print_twod() to update the plane seats

    }
    //NOT YET IMPLEMENTED

    static T** allocate_twod(T** twod, int* sizes, int col) {

        //    array_size()
        //find out the sizes of the twod
        //    T** twod = new T*
        return twod;
    }

    //NOT YET IMPLEMENTED
    //is this misnamed? it was named allocate 2d

    static T** de_allocate_twod(int* sizes) {

        T** twod;
        return twod;
    }

    //NOT YET IMPLEMENTED
    static T read_twod(T** twod, int row, int col);

    //NOT YET IMPLEMENTED
    static void write_twod(T** twod, int row, int col, const T& item);

    //NOT YET IMPLEMENTED
    static T& get_twod(T** twod, int row, int col);

    //Currently under construction~~~~~~~~~

    static void init_twod_plane(T** twod, int* sizes, T init_item = T()) {
        //    twod = new T**[sizes];
    }
    //NYI--NEXT!!!
    static void init_twod_lab(T** twod, int* sizes, T init_item = T()) {
        srand(time(NULL));
        
        //*something = rand() %  + 1;
    }

    //NOT YET IMPLEMENTED
    static bool search_twod(T** twod, int* sizes, const T& key, int& row, int& col);

    //NOT YET IMPLEMENTED
    static std::ostream& print_twod(T** twod, int* sizes, std::ostream& outs);

};
//lastly, struct these functions???

#endif /* TWODARRAY_H */

