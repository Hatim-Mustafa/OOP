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

    int& GetXByRef () {
        return x;
    }

    int& GetYByRef () {
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
};

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
        if (direction == "up") {
            ballY++;
        }
        else if (direction == "down") {
            ballY--;
        }
        else if (direction == "left") {
            ballX--;
        }
        else if (direction == "right") {
            ballX++;
        }
        else {
            cout << "Incorrect direction\n";
            return;
        }
        hits++;
    }
};

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
};

class Team {
    public:
    string name;
    Robot* robo;

    Team (string n, Robot* r) {
        name = n;
        robo = r;
    }
};

class Game {
    Team* team1;
    Team* team2;
    Goal* goal;
    Ball* ball;

    public:
    Game (Team* t1, Team* t2) {
        team1 = t1;
        team2 = t2;
        goal = new Goal();
        ball = new Ball();
    }

    ~Game () {
        delete ball;
        delete goal;
    }

    void play (Team* team) {
        string dir;
        while (!goal->isGoalReached(ball->GetX(), ball->GetY())) {
            cout << "Enter Direction: ";
            cin >> dir;
            team->robo->hitBall(ball->GetXByRef(), ball->GetYByRef(), dir);
            cout << "Ball's new position: ";
            int* pos = ball->getPosition();
            cout << "X: " << pos[0] << " Y: " << pos[1] << endl;
            delete [] pos;
        }
        cout << team->name << " scored a goal in " << team->robo->hits << " hits" << endl;
    }

    void declareWinner () {
        if (team1->robo->hits > team2->robo->hits) {
            cout << team2->name << " won\n";
        }
        else if (team1->robo->hits < team2->robo->hits) {
            cout << team1->name << " won\n";
        }
        else {
            cout << "It is a tie\n";
        }
    }

    void startGame() {
        play(this->team1);
        *ball = Ball();
        play(this->team2);
        declareWinner();
    }
};

int main() {
    Robot r1("1");
    Robot r2("2");
    Team t1("Team 1", &r1);
    Team t2("Team 2", &r2);
    Game game(&t1, &t2);
    game.startGame();
}