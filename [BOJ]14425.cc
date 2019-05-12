#include <stdio.h>

class Trie {
public:
    Trie *children[26];
    bool output;

    Trie() : output(false) {
        for(int i = 0; i < 26; i++) {
            children[i] = 0;
        }
    }

    void insert(char *str) {
        if(*str == '\0') {
            output = true;
        } else {
            if(!children[*str -'a']) {
                children[*str - 'a'] = new Trie();
            }
            children[*str-'a']->insert(str+1);
        }
    }

    bool search(char *str) {
        if(output) return true;
        if(!children[*str - 'a']) return false;
        return children[*str - 'a']->search(str + 1);
    }
};

const int MAX_LENGTH = 501;
int main() {
    int N, M;
    Trie *root = new Trie();
    scanf("%d%d", &N, &M);
    for(int i = 0; i < N; i++) {
        char S[MAX_LENGTH];
        scanf("%s", S);
        root->insert(S);
    }

    int answer = 0;
    for(int i = 0; i < M; i++) {
        char S[MAX_LENGTH];
        scanf("%s", S);
        if(root->search(S)) {
            answer++;
        }
    }
    printf("%d", answer);
}