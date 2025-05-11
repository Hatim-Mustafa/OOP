#include <iostream>
using namespace std;

template <typename T>
class Company {
    T* dept_A;
    T* dept_B;
    int size1;
    int size2;

    public:
    Company (){
        size1 = 3;
        size2 = 3;
        dept_A = new T[3];
        dept_A[0] = "Programming";
        dept_A[1] = "Debugging";
        dept_A[2] = "Requirement Verification";
        dept_B = new T[3];
        dept_B[0] = "Debugging";
        dept_B[1] = "Requirement Verification";
        dept_B[2] = "Testing";
    }

    void Print () {
        for (int i = 0; i < size1; i++) {
            cout << dept_A[i] << endl;
        }

        for (int i = 0; i < size2; i++) {
            cout << dept_B[i] << endl;
        }
    }

    T Union() {
        int size = size1;
        T* temp = new T[size];
        for (int i = 0; i < size; i++) {
            temp[i] = dept_A[i];
        }
        for (int i = 0; i < size2; i++) {
            for (int j = 0; j < size; j++) {
                if (temp[j] != dept_B[i]) {
                    T* temp2 = new T[size+1];
                    temp2[size] = dept_B[j];
                    for (int k = 0; k < size; k++) {
                        temp2[k] = temp[k];
                    }
                    delete [] temp;
                    temp = temp2;
                    size++;
                    break;
                }
            }
        }
        T n = temp[0];
        delete [] temp;
        return n;
    }
};

int main () {
    Company<string> c;
    cout << c.Union() << endl;
}