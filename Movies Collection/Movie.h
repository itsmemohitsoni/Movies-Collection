#ifndef MOVIE_H
#define MOVIE_H

#include<string>
using namespace std;
#pragma once

class Movie
{
    private:
        string name;
        double rating;// out of 10
        int earning_crores;
        int times_watched;// times watched by me

    public:
        //displays the data stored in given class
        string get_name(){
            return name;
        }
        double get_rating(){
            return rating;
        }
        int get_earnings(){
            return earning_crores;
        }
        int get_times_wathced(){
            return times_watched;
        }

        //changes the amendable things of a movie
        void set_earnings(int n){
            earning_crores = n;
        }
        void set_watchtime(int n){
            times_watched = n;
        }

        //constructor
        Movie(string s = "No name", double rate = 5, int earn = 10, int time = 0);
        ~Movie();
};

#endif