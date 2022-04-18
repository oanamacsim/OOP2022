#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <map>
#include <algorithm>
#include <queue>
using namespace std;

class cmp {
public:
    bool operator()(const pair<string, int>& a, const pair<string, int>& b)
    {
        if (a.second > b.second)
            return false;
        else
            if (a.second < b.second)
                return true;
            else //a.second == b.second
            {
                //compare lexycographically
                int res = a.first.compare(b.first);
                if (res == 0 || res < 0)
                    return false;
                return true;
            }
    }
};

int main()
{

    ifstream in("input.txt");
    string text;
    string line;
    string separators = " !?.,";
    string word;
    vector<string>words;
    while (getline(in, line))
        text += line;
    cout << "\n-------------------------------------------------------------\n";
    cout << "Input from file:" << text << '\n';
    cout << "\n-------------------------------------------------------------\n";


    int from = text.find_first_not_of(separators, 0);
    int to;

    while (from != string::npos) {
        to = text.find_first_of(separators, from + 1);
        words.push_back(text.substr(from, to - from));
        from = text.find_first_not_of(separators, to + 1);
    }

    cout << "The total number of words is: " << words.size() << '\n';
    cout << "\n-------------------------------------------------------------\n";
    cout << "The words are: \n";
    for (auto x : words)
        cout << x << '\n';


    map<string, int>wordMap;

    vector<string>::iterator it;
    for (it = words.begin(); it != words.end(); it++)
    {
        string helper = *it;

        transform(helper.begin(), helper.end(), helper.begin(), ::tolower);

        wordMap[helper]++;
    }


    map<string, int>::iterator it2;

    cout << "\n-------------------------------------------------------------\n";
    cout << "\nThe frecuency of the words (non-case-sensitive) are: \n";

    for (it2 = wordMap.begin(); it2 != wordMap.end(); it2++)
    {
        cout << it2->first << " : " << it2->second << '\n';
    }

    auto my_comp = [](const pair<string, int>& a, const pair<string, int>& b)
    {

    };


    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq(wordMap.begin(), wordMap.end());

    cout << "\n-------------------------------------------------------------\n";

    cout << "\nPQ ordered: \n";

    while (!pq.empty()) {
        pair<string, int> top = pq.top();
        cout << top.first << " => " << top.second << '\n';
        pq.pop();
    }

    return 0;
}