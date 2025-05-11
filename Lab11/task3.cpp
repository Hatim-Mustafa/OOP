#include <iostream>
#include <string>
#include <exception>
using namespace std;

class Fileexception : public exception
{
public:
    virtual const char *what() const noexcept override
    {
        return ("File exception called.");
    }
};
class Filenotfoundexception : public Fileexception
{
public:
    const char *what() const noexcept override
    {
        return "File not found exception";
    }
};
class Permissiondeniedexcption : public Fileexception
{
public:
    const char *what() const noexcept override
    {
        return "Permission denied!";
    }
};
void readFile(const string &filename)
{
    if (filename == "missing.txt")
    {
        throw Filenotfoundexception();
    }
    else if (filename == "secret.txt")
    {
        throw Permissiondeniedexcption();
    }
    else
    {
        cout << "File '" << filename << "' read successfully." << endl;
    }
}
int main()
{
    string file[3] = {"missing.txt", "secret.txt", "made.txt"};

    for (int i = 0; i < 3; i++)
    {
        try
        {
            cout << "Opening file...";
            readFile(file[i]);
        }
        catch (const Filenotfoundexception &obj)
        {
            cout << obj.what() << endl;
        }
        catch (const Permissiondeniedexcption &obj)
        {
            cout << obj.what() << endl;
        }
        catch (const Fileexception &obj)
        {
            cout << obj.what() << endl;
        }
    }
    return 0;
}