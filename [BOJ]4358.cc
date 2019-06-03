#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

const int MAX = 95;
int cntOfWords;

string str[1000001];

class Trie {
public:
    Trie *children[MAX];
    int numOfWords;
    bool isPrinted;

    Trie() : numOfWords(0), isPrinted(false) {
        for(int i = 0; i < MAX; i++) {
            children[i] = 0;
        }
    }

    ~Trie() {
        for(int i = 0; i < MAX; i++) {
            if(children[i]) {
                delete children[i];
            }
        }
    }

    void insert(const char *str_) {
        if(*str_ == '\0') {
            numOfWords++;
            return;
        }

        int next = *str_ - ' ';
        if(!children[next]) {
            children[next] = new Trie();
        }

        children[next]->insert(str_ + 1);
    }

    int find(const char *str) {
        if(*str == '\0') {
            if(isPrinted == false) {
                isPrinted = true;
                return numOfWords;
            }

            return -1;
        }

        int next = *str - ' ';
        return children[next]->find(str + 1);
    }
};

int main() {
    cntOfWords = 0;
    Trie *root = new Trie();
    
    while(getline(cin, str[cntOfWords])) {
        root->insert(str[cntOfWords++].c_str());
    }

    sort(str, str + cntOfWords);

    for(int i = 0; i < cntOfWords; i++) {
        int frequncy = root->find(str[i].c_str());
        if(frequncy == -1) continue;
        printf("%s %.4lf\n", str[i].c_str(), ((double)frequncy/cntOfWords)*100);
    }
}