//24K-0673
//HATIM MUSTAFA

#include <iostream>
#include <string>
using namespace std;

class Ball;
class Robot;
class Goal;
class Team;

class Ball {
    int x;
    int y;

    public:
    Ball () {
        this->x = 0;
        this->y = 0;
    }

    int GetX() {
        return x;
    }

    int GetY() {
        return y;
    }

    void move(int dx, int dy) {
        x += dx;
        y += dy;
    }

    int* getPosition() {
        int* arr = new int[2];
        arr[0] = x;
        arr[1] = y;
        return arr;
    }
}

class Robot {
    public:
    string name;
    int hits;

    public:
    Robot (string n) {
        name = n;
        hits = 0;
    }

    void hitBall(int &ballX, int &ballY, const string &direction) {
        switch(direction) {
            case "up":
            ballY++;
            break;

            case "down":
            ballY--;
            break;

            case "left":
            ballX--;
            break;

            case "right":
            ballX++;
            break;
        }
        hits++;
    }
}

class Goal {
    int x;
    int y;

    public:
    Goal () {
        x = 3;
        y = 3;
    }

    bool isGoalReached (int ballX, int ballY) {
        if (ballX == x && ballY == y) {
            return true;
        }
        else {
            return false;
        }
    }
}

class Team {
    public:
    string name;
    Robot* robo;

    Team (string n, Robot* r) {
        name = n;
        robo = r;
    }
}

class Game {
    Team team1;
    Team team2;
    Goal goal;
    Ball ball;

    public:
    Game (Team t1, Team t2) {
        team1 = t1;
        team2 = t2;
    }

    void play (Team* team) {

    }

    void declareWinner () {
        if (team1.robo->hits > team2.robo->hits) {
            cout << "Team 2 won\n";
        }
        else if (team1.robo->hits < team2.robo->hits) {
            cout << "Team 1 won\n";
        }
        else {
            cout << "It is a tie\n";
        }
    }

    void startGame() {
        play(this->team1);
        play(this->team2);
        declareWinner();
    }

}