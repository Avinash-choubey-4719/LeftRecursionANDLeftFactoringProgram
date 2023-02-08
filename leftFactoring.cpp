#include <bits/stdc++.h>
#include <iostream>
using namespace std;

int main() {
  map<char, vector<string>> prod;
  int n;
  cout << "Enter number of productions : ";
  cin >> n;
  cout << "Enter productions : " << endl;
  for (int i = 0; i < n; i++) {
    char ch;
    string s;
    cin >> ch;
    cout << " -> ";
    cin >> s;
    prod[ch].push_back(s);
  }

  cout << "Given grammar is :" << endl << endl;
  for (map<char, vector<string>>::iterator i = prod.begin(); i != prod.end();
       i++) {
    cout << i->first << " -> ";
    for (int j = 0; j < i->second.size(); j++) {
      cout << i->second[j];
      if (j != i->second.size() - 1)
        cout << " | ";
    }
    cout << endl;
  }

  for (map<char, vector<string>>::iterator itr = prod.begin();
       itr != prod.end(); ++itr) {

    vector<string> v = itr->second;
    int min_len = INT_MAX;
    for (int j = 0; j < v.size(); j++) {
      if (v[j].length() < min_len)
        min_len = v[j].length();
    }
    for (int i = 0; i < v.size(); i++) {
      int prev = 0, curr = 0, len = 0;

      for (int j = 1; j <= min_len; j++) {
        string s = v[i].substr(0, j);
        curr = 0;
        for (int k = 0; k < v.size(); k++) {
          if (k == i)
            continue;
          if (v[k].substr(0, j).compare(s) == 0)
            curr++;
        }

        if (curr < prev)
          break;
        prev = curr;
        len = j;
      }
      if (prev != 0) {

        char ch = 'A' + prod.size();
        string s = v[i].substr(0, len);

        for (int j = 0; j < v.size(); j++) {
          if (v[j].substr(0, len).compare(s) == 0) {
            v[j] = s + ch;
            itr->second[j] = v[j];
            prod[ch].push_back(v[j].substr(len, v[j].size() - len));
          }
        }
      }
    }
  }
  cout << "Grammar after removing left factoring is :" << endl << endl;
  for (map<char, vector<string>>::iterator i = prod.begin(); i != prod.end();
       i++) {
    cout << i->first << " -> ";
    for (int j = 0; j < i->second.size(); j++) {
      cout << i->second[j];
      if (j != i->second.size() - 1)
        cout << " | ";
    }
    cout << endl;
  }
}