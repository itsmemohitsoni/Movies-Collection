// Made by Mohit Soni
// Github - itsmemohitsoni
// Instagram - its_me_mohitsoni

#include <iostream>
#include <string>
#include <vector>
#include <bits/stdc++.h>
#include "Movie.h"

using namespace std;

// displays the list of availabe options to the user
void display_options()
{
    cout << "\nGiven are the services provided by this program: " << endl;
    cout << "1. Display the current database: " << endl;
    cout << "2. Update a movie in the database: " << endl;
    cout << "3. Enter a new movie in the database: " << endl;
    cout << "4. Find a movie in the database: " << endl;
    cout << "5. Delete the current database: " << endl;
    cout << "6. Quit: " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "Enter your choice: ";
}

// displays the current movie collection
void display_database(vector<Movie> &data)
{
    if (data.size() == 0)
    {
        cout << "Database is empty\n";
        cout << "-----------------------------------------------" << endl;
        return;
    }
    else
    {
        int n = data.size();
        for (int i = 0; i < n; i++)
        {
            cout << endl;
            cout << i + 1 << ". Movie's name: " << data[i].get_name() << endl;
            cout << "   Movie's rating: " << data[i].get_rating() << endl;
            cout << "   Movie's earning in crores: " << data[i].get_earnings() << endl;
            cout << "   No of times movie was watched by you: " << data[i].get_times_wathced() << endl;
        }
        cout << "\nTotal number of movies in the database: " << n << endl;
        cout << "-----------------------------------------------" << endl;
    }
    return;
}

// welcomes the user and prints menu to the user
void autoprint()
{
    system("cls");
    cout << "Namaste user, Welcome to Movies Collection: \n";
    display_options();
}

// sets up an initial database with 5 movies
void create_databse(vector<Movie> &data)
{
    Movie RRR{"RRR", 8.4, 1000, 1};
    data.push_back(RRR);

    Movie Iron_Man{"Iron Man", 7.9, 4800, 1};
    data.push_back(Iron_Man);

    Movie Avengers_Endgame{"Avengers Endgame", 8.4, 20524, 1};
    data.push_back(Avengers_Endgame);

    Movie Bahubali{"Bahubali", 8, 800, 8};
    data.push_back(Bahubali);

    Movie Bajrangi_bhaijaan{"Bajrangi bhaijaan", 7.5, 600, 3};
    data.push_back(Bajrangi_bhaijaan);
}

// finds the position of the movie given as a string named input
int movie_index(vector<Movie> &data, string input)
{
    int n = data.size();
    for (int i = 0; i < n; i++)
    {
        if (data[i].get_name() == input)
            return i;
    }
    return n;
}

//function updates the attributes of a certain movie
void update_movie(vector<Movie> &data, int i)
{
    cout << "\nChoose what you want to update: " << endl;
    cout << "1. " << data[i].get_name() << "'s earning in crores\n";
    cout << "2. " << data.at(i).get_name() << "'s watched no.\n";
    cout << "\nEnter updation choice: ";
    int c;
    cin >> c;
    if (c == 1)
    {
        cout << "Enter the new earnings of " << data[i].get_name() << ": ";
        int num;
        cin >> num;
        data.at(i).set_earnings(num);
        cout << "Earnings updated\n";
        return;
    }
    else if (c == 2)
    {
        cout << "Enter the no. the movie was watched: ";
        int num;
        cin >> num;
        data.at(i).set_watchtime(num);
        cout << "Watchtime updated\n";
        return;
    }
    else
        cout << "Incorrect updation choice\n";
}

// prints the movie at the provided index
void print_movie(vector<Movie> &data, int i)
{
    cout << data.at(i).get_name() << " was found in the database\n";
    cout << "Related information is given below: " << endl;
    cout << "Movie's rating: " << data[i].get_rating() << endl;
    cout << "Movie's earning in crores: " << data[i].get_earnings() << endl;
    cout << "No of times movie was watched by you: " << data[i].get_times_wathced() << endl;
}

// main function starts here
int main()
{
    autoprint();
    int choice;
    cin >> choice;

    // database of the program
    vector<Movie> data;
    create_databse(data);
    while (choice != 6)
    {
        if (choice == 1)
        {
            display_database(data);
        }

        else if (choice == 5)
        {
            data.clear();
            cout << "Database Cleared\n";
            cout << "-----------------------------------------------" << endl;
        }

        else if (choice == 2)
        {
            cout << "Enter the name of the movie to update: ";
            string input;
            fflush(stdin);
            getline(cin, input);
            // cout << input << endl;
            int idx = movie_index(data, input);
            if (idx == data.size())
                cout << input << " not present" << endl;
            else
                update_movie(data, idx);
            cout << "-----------------------------------------------" << endl;
        }
        else if (choice == 3)
        {
            string s;
            cout << "Enter the name of the movie you want to update: ";
            fflush(stdin);
            getline(cin, s);
            int idx = movie_index(data, s);
            if (idx != data.size())
                cout << s << " already present in the database\n";
            else
            {
                double r;
                cout << "Enter the rating(<= 10) for " << s << ": ";
                cin >> r;
                int rup;
                cout << "Enter the earnings of " << s << " in crores: ";
                cin >> rup;
                int wat;
                cout << "How many tiimes you have watched this movie: ";
                cin >> wat;
                Movie new_movie{s, r, rup, wat};
                data.push_back(new_movie);
                cout << "Successfully added movie " << s << " in the database\n";
            }
            cout << "-----------------------------------------------" << endl;
        }

        else if (choice == 4)
        {
            string input;
            cout << "Enter the name of the movie to be found: ";
            fflush(stdin);
            getline(cin, input);
            int idx;
            idx = movie_index(data, input);
            if (idx == data.size())
                cout << input << " not present" << endl;
            else
                print_movie(data, idx);
            cout << "-----------------------------------------------" << endl;
        }

        else
        {
            cout << "Incorrect choice..." << endl;
            cout << "-----------------------------------------------" << endl;
        }

        display_options();
        cin >> choice;
    }
    cout << "\nThank you for using the program\n";
    cout << "Have a great day ahead\n";
}
// program ends here