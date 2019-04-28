#include <stdio.h>

const int MAX_LENGTH_WORD = 81;

int num_words;

class Trie {
public:
    Trie *children[26];
    bool output;
    int branch;
    int words;

    Trie() : output(false), branch(0), words(0) {
        for(int i = 0; i < 26; i++) {
            children[i] = 0;
        }
    }

    ~Trie() {
        for(int i = 0 ; i < 26; i++) {
            if(!children[i]) delete children[i];
        }
    }

    void insert(char *str) {
        if(*str == '\0') {
            branch++;
            output = true;
        } else {
            if(!children[*str - 'a']) {
                branch++;
                children[*str - 'a'] = new Trie();
            }

            words++;
            children[*str - 'a']->insert(str + 1);
        }
    }

    long long search(bool is_root = false) {
        long long result = 0;
        if(is_root || branch > 1) result = words;
        for(int i = 0; i < 26; i++) {
            if(children[i]) result += children[i]->search();
        }
        return result;
    }
};

int main() {
    while(scanf("%d", &num_words) != EOF) {
        Trie *trie = new Trie();
        for(int i = 0; i < num_words; i++) {
            char S[MAX_LENGTH_WORD];
            scanf("%s", S);
            trie->insert(S);
        }
    
        printf("%.2lf\n", (1.0*trie->search(true))/num_words);
        delete trie;
    }
}