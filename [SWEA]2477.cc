#include <stdio.h>
#include <queue>
#include <vector>

using namespace std;

int T;
int N, M, K;
int A, B;
int rec_time[9];
int rep_time[9];
int arrive_time[1000];
int num_costomer;

struct CI { //Customer Infomation
    int num;
    int end_time;
    CI() {}
    CI(int num_, int end_time_) : num(num_), end_time(end_time_) {}
};

CI rec[9];
CI rep[9];

queue<int> rec_q;
queue<int> rep_q;

struct Log {
    int rec;
    int rep;
};

Log log[1000];

int main() {
    scanf("%d", &T);

    for(int tc = 1; tc <= T; tc++) {
        scanf("%d%d%d%d%d", &N, &M, &K, &A, &B);
        for(int i = 0; i < N; i++) {
            scanf("%d", &rec_time[i]);
            rec[i].num = -1;
            rec[i].end_time = -1;
        }
        for(int i = 0; i < M; i++) {
            scanf("%d", &rep_time[i]);
            rep[i].num = -1;
            rep[i].end_time = -1;
        }
        for(int i = 0; i < K; i++) {
            scanf("%d", &arrive_time[i]);
            log[i].rec = -1;
            log[i].rep = -1;
        }

        rec_q = queue<int>();
        rep_q = queue<int>();
        num_costomer = 0;
        for(int t = 0;; t++) {
            for(int i = 0; i < K; i++) {
                if(arrive_time[i] == t) {
                    rec_q.push(num_costomer++);
                }
            }

            for(int i = 0; i < N; i++) {
                if(rec[i].end_time == t) {
                    rep_q.push(rec[i].num);
                    rec[i].num = -1;
                    rec[i].end_time = -1;
                }
            }

            bool exit = false;
            for(int i = 0; i < M; i++) {
                if(rep[i].end_time == t) {
                    if(rep[i].num == K - 1) exit = true;
                    rep[i].num = -1;
                    rep[i].end_time = -1;
                }
            }
            if(exit) break;

            for(int i = 0; i < N; i++) {
                if(!rec_q.empty() && rec[i].num == -1) {
                    int num = rec_q.front();
                    rec_q.pop();
                    rec[i].num = num;
                    rec[i].end_time = t + rec_time[i];
                    log[num].rec = i;
                }
            }

            for(int i = 0; i < M; i++) {
                if(!rep_q.empty() && rep[i].num == -1) {
                    int num = rep_q.front();
                    rep_q.pop();
                    rep[i].num = num;
                    rep[i].end_time = t + rep_time[i];
                    log[num].rep = i;
                }
            }

            /*
            int rec_q_size = rec_q.size();
            printf("%s", "reception queue : ");
            for(int i = 0; i < rec_q_size; i++) {
                int num = rec_q.front();
                rec_q.pop();
                rec_q.push(num);
                printf("%d ", num);
            }
            puts("");

            int rep_q_size = rep_q.size();
            printf("%s", "repair queue : ");
            for(int i = 0; i < rep_q_size; i++) {
                int num = rep_q.front();
                rep_q.pop();
                rep_q.push(num);
                printf("%d ", num);
            }
            puts("");

            printf("%s", "status of recpetion desk : ");
            for(int i = 0; i < N; i++) {
                printf("[%d, %d] ", rec[i].num, rec[i].end_time);
            }
            puts("");

            printf("%s", "status of repair desk : ");
            for(int i = 0; i < M; i++) {
                printf("[%d %d] ", rep[i].num, rep[i].end_time);
            }
            puts("");
            */
        }

        int answer = -1;
        for(int i = 0; i < K; i++) {
            if(log[i].rec == A - 1 && log[i].rep == B - 1) {
                if(answer == -1) {
                    answer = i + 1;
                } else {
                    answer += i + 1;
                }
            }
        }

        printf("#%d %d\n", tc, answer);
    }
}