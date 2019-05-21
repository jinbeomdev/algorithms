#include <stdio.h>
#include <string.h>

const int MAX = 95;
int cntOfWords;

class Trie {
public:
    Trie *children[MAX];
    int numOfWords;
    bool output;
    char orginStr[31];

    Trie() : numOfWords(0) {
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

    void insert(char *str, char *orginStr_) {
        if(*str == '\0') {
            numOfWords++;

            if(!output) {
                output = true;
                strcpy(orginStr, orginStr_);
            }
            return;
        }

        int next = *str - ' ';
        if(!children[next]) {
            children[next] = new Trie();
        }

        children[next]->insert(str + 1, orginStr_);
    }

    void solve() {
        if(output) {
            printf("%s %.4lf\n", orginStr, (double)numOfWords/cntOfWords*100);
        }

        for(int i = 0; i < MAX; i++) {
            if(children[i]) {
                children[i]->solve();
            }
        }
    }
};

int main() {
    char str[31];
    cntOfWords = 0;
    Trie *root = new Trie();
    
    int T;
    scanf("%d%*c", &T);
    for(int i = 0; i < T; i++) {
        scanf("%[^\n]%*c", str);
        cntOfWords++;
        root->insert(str, str);
    }

    root->solve();
}