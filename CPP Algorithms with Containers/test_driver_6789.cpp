#include <iostream>
#include "Dog.h"
#include <iosfwd>
#include <algorithm>
#include <vector>
#include <set>
#include <functional>


using std::cin;
using std::cout;
using std::endl;
using std::string;

//-----------------------task 6
//Determines if a phrase is a palindrome
bool is_palindrome(const string& phrase) {

    string temp;
    string::iterator it = temp.begin();

    std::remove_copy_if(phrase.begin(), phrase.end(), inserter(temp, it),
                   [](char x) {return !isalpha(x); });// lambda function return only alphabet
    std::transform(temp.begin(), temp.end(), temp.begin(),
                   [](char x) {return tolower(x); });// lambda function return lower case

    return std::equal(temp.begin(),temp.end(),temp.rbegin());// compare from start to end with from end to start;
}

void test_is_palindrome()
{
    std::string cat_i_saw = std::string("was it a car or A Cat I saW?");
    assert(is_palindrome(cat_i_saw) == true);
    cout << "the phrase \"" + cat_i_saw + "\" is a palindrome\n";

    std::string cat_u_saw = std::string("was it A Car or a cat U saW?");
    assert(is_palindrome(cat_u_saw) == false);
    cout << "the phrase \"" + cat_u_saw + "\" is not a palindrome\n";
}


//-----------------------task 7
//A function template that finds the second largest element
template <class Iterator>
std::pair <Iterator, bool>
second_max(Iterator start, Iterator finish)
{
    //tests if set is empty,then return (finish, false)
    if (start == finish)
    {
        return std::make_pair(finish, false);
    }

    auto value = *start;
    bool equal = true;

    for (auto it = start; it != finish; it++)
    {
        if (value != *it)
        {
            equal = false;
            break;
        }
    }

    //If all the values in the range are equal, return (start,false)
    if (equal)
    {
        return std::make_pair(start, false);
    }

    auto largest = start;
    auto second_largest = start;

    for (auto it = start; it != finish; ++it)
    {
        if (*largest < *it)
        {
            second_largest = largest;
            largest = it;
        }

        else if (*second_largest < *it && *largest > * it)
        {
            second_largest = it;
        }
    }
    //If the second largest element can be found, return this element + boolean "true"
    return std::make_pair(second_largest, true);
}

void test_second_max(std::vector<int> vec)
{
// note: auto in the following statement is deduced as
// std::pair<std::vector<int>::iterator, bool>
    auto retval = second_max(vec.begin(), vec.end());
    if (retval.second)
    {
        cout << "The second largest element in vec is "
             << *retval.first << endl;
    }
    else
    {
        if (retval.first == vec.end())
            cout << "List empty, no elements\n";
        else
            cout << "Container's elements are all equal to "
                 << *retval.first << endl;
    }
}

//-----------------------task 8
//return the number of elements in the vec that are of length n.
int count_using_lambda (const std::vector<std::string>& vec, int n)
{
    //using the "count_if" algorithm with lambda function
    int count = std::count_if(vec.begin(), vec.end(),
                              [n](std::string new_string) {return (n == new_string.length());});
    return count;
}

bool freeFun(const string& string, int n)
{
    return (string.length() == n);
}

int count_using_Free_Func(const std::vector<std::string>& vec, int n)
{

    return std::count_if(vec.begin(), vec.end(), std::bind(freeFun, std::placeholders::_1, n));

}


struct CountFunctor
{
    int n;
    CountFunctor(int newOne) : n(newOne) {}
    bool operator () (std::string str)
    {
        if (n == str.length())
        {
            return true;
        }
        return false;
    }
};

int count_using_Functor(const std::vector<std::string>& vec, int n)
{
    CountFunctor countsStringsFunctor(n);
    int count = std::count_if(vec.begin(), vec.end(), countsStringsFunctor);

    return count;
}

void task_8_test_driver()
{
    std::vector<std::string> vecstr
            { "count_if", "Returns", "the", "number", "of", "elements", "in", "the",
              "range", "[first", "last)", "for", "which", "pred", "is", "true."
            };
    cout << count_using_lambda(vecstr, 5) << endl;
    cout << count_using_Free_Func(vecstr, 5) << endl;
    cout << count_using_Functor(vecstr, 5) << endl;
    cout << "\n";
}


//-----------------------task 9
//Defining a class Comparator to ensure sorting

struct Comparator
{
    bool operator () (std::string s1, std::string s2) const
    {
        if (s1.length() == s2.length())
        {
            return (s1 < s2);
        }
        else if (s1.length() < s2.length()) {

            return true;
        }
        return false;
    }
};

void multisetUsingMyComparator()
{
    std::multiset<std::string, Comparator> strSet; // an empty set

    // a set that uses the default std::less<int> to sort the set elements
    std::vector<std::string> vec{ "C", "BB", "A", "CC", "A", "B", "BB", "A", "D", "CC", "DDD", "AAA" };

    // copy the vector elements to our set.

    std::copy(vec.begin(), vec.end(),                // source start and finish
              std::inserter(strSet, strSet.begin())); // destination start with

    // create an ostream_iterator for writing to cout, using a space " " as a separator
    std::ostream_iterator<std::string> out(std::cout, " ");

    // output the set elements to cout separating them with a space
    std::copy(strSet.begin(), strSet.end(), out);
}



int main() {
//-----------------------task 1
    DogMap dogMap1{};
    load_DogMap(dogMap1, "/Users/yunni/Desktop/CPP/5421A5/dogDB.csv" );
//    cout << "open ok" << endl;
    cout << "Task No.1" << endl;
    cout << dogMap1 << "==========" << endl;

//    //Testing "trim" method:
//    string newString = trim("  Ninni  ");
//    cout << newString << endl;

//-----------------------task 2
    DogMap dogMap2{};
    load_DogMap_Using_For_Each(dogMap2, "/Users/yunni/Desktop/CPP/5421A5/dogDB.csv");
    cout << "Task No.2" << endl;
    cout << dogMap2 << "==========" << endl;
//
//-----------------------task 3
    DogMap dogMap3{};
    load_DogMap_Using_Transform(dogMap3, "/Users/yunni/Desktop/CPP/5421A5/dogDB.csv");
    cout << "Task No.3" << endl;
    cout << dogMap3 << "==========" << endl;

//-----------------------task 4
    DogMapReversed dogMap4{};
    load_DogMap_Reversed_Order(dogMap4, "/Users/yunni/Desktop/CPP/5421A5/dogDB.csv");
    cout << "Task No.4" << endl;
    cout << dogMap4 << "==========" << endl;

//-----------------------task 5
    cout << "Task No.5" << endl;
    std::multimap<std::string, Dog> dogMap5{};

    load_DogMap(dogMap5,  "/Users/yunni/Desktop/CPP/5421A5/dogDB2.csv");
//    cout << dogMap << "==========" << endl;
    DogMap brMap1 = findBreedRange(dogMap5, std::string("Greyhound"));
    cout << brMap1 << "----------" << endl;
    DogMap brMap2 = findBreedRange(dogMap5, std::string("Lakeland Terrier"));
    cout << brMap2 << "----------" << endl;
    DogMap brMap3 = findBreedRange(dogMap5, std::string("Pug"));
    cout << brMap3 << "----------" << endl;
    DogMap brMap4 = findBreedRange(dogMap5, std::string("Xyz"));
    cout << brMap4 << "----------" << endl;


//-----------------------task 6
    cout << "Task No.6" << endl;
    test_is_palindrome();
    cout << "\n";

//-----------------------task 7
    cout << "Task No.7" << endl;
    std::vector<int> v1{ 1 }; // one element
    test_second_max(v1);
    std::vector<int> v2{ 1, 1 }; // all elements equal
    test_second_max(v2);
    std::vector<int> v3{ 1, 1, 3, 3, 7, 7 }; // at least with two distict elements
    test_second_max(v3);
    cout << "\n";

//-----------------------task 8
    cout << "Task No.8" << endl;
    task_8_test_driver();
    cout << "\n";


//-----------------------task 9
    cout << "Task No.9" << endl;
    multisetUsingMyComparator();
    cout << "\n";
    return 0;
}
