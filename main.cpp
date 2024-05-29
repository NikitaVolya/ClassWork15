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

int main()
{
    BasketballPlayer test("Nikita", "Volianskyi", 18, 7.8f, 25);

    std::cout << test.getInfo() << std::endl;
    test.sayScore();


	return 0;
}