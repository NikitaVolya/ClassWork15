#include <iostream>


using namespace std;

#include <format>
#include <string>

class Person
{
private:
    string m_firstName;
    string m_lastName;
    int m_age;
protected:
    int prot = 0;
public:
    Person(string firstName = "", string lastName = "", int age = 0) :
        m_firstName(firstName),
        m_lastName(lastName),
        m_age(age)
    {};
    virtual string getInfo() const
    {
        string result = "Person first name - " + m_firstName + "; last name - " + m_lastName + "; age - " + to_string(m_age);
        return result;
    };
    string getFirstname() const { return m_firstName; }
    string getGreetings(string msgText = "") const
    {
        string result = "I am " + m_firstName;
        if (!msgText.empty())
        {
            result += ". I say: ";
            result += msgText;
        }
        else
        {
            result += ". I say nothing.";
        }
        return result;
    }
};

class BasketballPlayer : protected Person
{
private:
    float gameAverage;
    int points;
public:
    BasketballPlayer(string firstName, string lastName, int age, float pGameAverage, int pPoints) : Person(firstName, lastName, age), gameAverage(pGameAverage), points(pPoints) {};

    void setGameAverage(int pValue) { gameAverage = pValue; }
    void setPoints(int pValue) { points = pValue; }
    
    float getGameAverage() const { return gameAverage; }
    int getPoints() const { return points; }

    string getInfo() const
    {
        return Person::getInfo() + " game average - " + to_string(gameAverage) + " points - " + to_string(points);
    }
    void sayScore() const
    {
        std::cout << "Hi, " << getFirstname() << " your average games score is " << gameAverage;
    }
};

class Passport
{
protected:
    string firstName;
    string lastName;
public:
    Passport(string pFirstname, string pLastname) : firstName(pFirstname), lastName(pLastname) {};

    string getFirstname() const { return firstName; }
    string getLastname() const { return lastName; }
};

class ForeignPassport : public Passport
{
private:
    size_t foreignPassportId;
    string data;
public:
    ForeignPassport(string pFirstname, string pLastname, string pData, size_t pForeignPassportId) : Passport(pFirstname, pLastname), foreignPassportId(pForeignPassportId), data(pData) {};

    size_t getID() const {  return foreignPassportId; }
    string getData() const { return data; }

    void print() const { cout << foreignPassportId << " : " << firstName << " " << lastName << " | " << data << endl; }
};



class Vehicle
{
private:
    string name;
public:
    Vehicle(string pName) : name(pName) { cout << "Vehicle" << endl; };
};

class Bicycle : public virtual Vehicle
{
public:
    Bicycle() : Vehicle("Bicycle") { cout << "Bicycle" << endl; };
};

class Motorcycle : public virtual Vehicle
{
public:
    Motorcycle() : Vehicle("Motorcycle") { cout << "Motorcycle" << endl; };
};

class MotoBike : public Bicycle, public Motorcycle
{
public:
    MotoBike() : Vehicle("MotoBike") { cout << "MotoBike" << endl; };
};


int main()
{
    MotoBike test;

	return 0;
}