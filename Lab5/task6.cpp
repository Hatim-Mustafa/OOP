#include <iostream>
#include <string>
using namespace std;

class Movie {
    int duration;
    string title;
    string director;

    public:
    Movie () {}
    Movie(int m, string t, string d) {
        duration = m;
        title = t;
        director = d;
    }

    void displayDetails () {
        cout << "Movie Title: " << title << endl;
        cout << "Movie Duration: " << duration << endl;
        cout << "Movie Director: " << director << endl;
    }

    ~Movie () {
        cout << "Movie destroyed" << endl;
    }
};

class CinemaHall {
    Movie** movies;
    string city;
    int numOfMovies;

    public:
    CinemaHall (int m, Movie** b, string c) {
        city = c;
        numOfMovies = m;
        movies = b;
    }

    void displayDetails () {
        cout << "City: " << city << endl;
        for (int i = 0; i < numOfMovies; i++) {
            cout << endl;
            movies[i]->displayDetails();
        }
        cout << endl;
    }

    ~CinemaHall () {
        for (int i = 0; i < numOfMovies; i++) {
            delete movies[i];
        }
        delete [] movies;
        cout << "Cinema Hall destroyed\n";
    }
};

int main () {
    int n = 3;
    Movie** movies = new Movie*[n];
    movies[0] = new Movie(132, "Harry Potter", "JK Rowling");
    movies[1] = new Movie(161, "Avengers", "Joss Whedon");
    movies[2] = new Movie(151, "Interstellar", "Christopher Nolan");

    CinemaHall ch(n, movies, "California");

    ch.displayDetails();
}

