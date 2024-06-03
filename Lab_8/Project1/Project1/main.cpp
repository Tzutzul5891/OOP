#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <queue>
#include <vector>
#include <cctype>

using namespace std;

vector<string> split(string str) {
    vector<string> words;
    string word;
    for (char c : str) {
        if (isspace(c) || ispunct(c)) {
            if (!word.empty()) {
                words.push_back(word);
                word.clear();
            }
        }
        else {
            word += tolower(c);
        }
    }
    if (!word.empty()) {
        words.push_back(word);
    }
    return words;
}

struct cmp {
    bool operator() (const pair<string, int>& a, const pair<string, int>& b) {
        if (a.second == b.second) {
            return a.first > b.first;
        }
        else {
            return a.second < b.second;
        }
    }
};

int main() {
    ifstream file("input.txt");

    string phrase;
    getline(file, phrase);
    file.close();

    vector<string> words = split(phrase);

    map<string, int> word_count;
    for (const string& word : words) {
        ++word_count[word];
    }

    priority_queue<pair<string, int>, vector<pair<string, int>>, cmp> pq;
    for (const auto& entry : word_count) {
        pq.push(entry);
    }

    while (!pq.empty()) {
        const auto& entry = pq.top();
        cout << entry.first << " => " << entry.second << endl;
        pq.pop();
    }

    return 0;
}
