/**
 * Author: Vincent X
 * Date: 2021-12-14
 * Practices the basics of a map
 */

#include <iostream>
#include <map>

using namespace std;

int main() {
    map<string, int> grades;

    grades.insert(pair<string, int>("Bruce", 88));
    grades.insert(pair<string, int>("Lisa", 95));
    grades.insert(pair<string, int>("Ashley", 63));

    // Print the pairs in the map
    for (map<string, int>::iterator itr = grades.begin(); itr != grades.end(); itr++)
        cout << itr->first << " " << itr->second << endl;

    // Delete Ashley's grade
    int gradeCount = grades.erase("Ashley");
    cout << endl << "Removed " << gradeCount << " grades" << endl;

    // Print the remaining grades
    cout << endl << "Remaining grades:" << endl;
    for (map<string, int>::iterator itr = grades.begin(); itr != grades.end(); itr++)
        cout << itr->first << " " << itr->second << endl;

    
    // Search the map
    cout << endl << "Searching for grades:" << endl;
    string searchName = "Lisa";
    if (grades.find(searchName) == grades.end())
        cout << "Unable to find grade for " << searchName << endl;
    else
        cout << searchName << "'s grade is " << grades.at(searchName) << endl;


    return 0;
}
