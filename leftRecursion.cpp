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
  for (map<char, vector<string>>::iterator itr = prod.begin(); itr != prod.end(); ++itr) {
    vector<string> alpha, beta;
    for (int i = 0; i < itr->second.size(); i++) {
      if (itr->first == itr->second[i][0]) {
        alpha.push_back(itr->second[i].substr(1, itr->second[i].length() - 1));
      } else {
        beta.push_back(itr->second[i]);
      }
    }
    if (alpha.size() < 1)
      continue;
    itr->second.clear();
    char ch = 'A' + prod.size();
    for (int i = 0; i < beta.size(); i++) {
      itr->second.push_back(beta[i] + ch);
    }
    for (int i = 0; i < alpha.size(); i++) {
      prod[ch].push_back(alpha[i] + ch);
    }
    prod[ch].push_back("^");
  }
  cout << "Grammar after removing left recursion is :" << endl << endl;

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
