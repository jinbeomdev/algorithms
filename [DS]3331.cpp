#include <assert.h>
#include <stdio.h>
#include <algorithm>
#include <vector>

using namespace std;

int T;
int queries;
int ct;

struct Post {
  int timeStamp;
  int like;

  Post() : timeStamp(0), like(0) {}
  Post(int _timeStamp) : timeStamp(_timeStamp), like(0) {}
} post[100010];

struct User {
  vector<int> posts;
  vector<int> follows;

  User() : posts(vector<int>()), follows(vector<int>()) {}
} user[1010];

bool comp(const int &lhs, const int &rhs) {
  if (post[lhs].like == post[rhs].like) {
    return post[lhs].timeStamp > post[rhs].timeStamp;
  }
  return post[lhs].like > post[rhs].like;
}

bool comp2(const int &lhs, const int &rhs) {
  return post[lhs].timeStamp > post[rhs].timeStamp;
}

void debug() {
  printf("\n%10s%10s%10s\n%30s\n", "postId", "timestamp", "like",
         "---------------");

  for (int i = 0; i < 100010; i++) {
    if (post[i].timeStamp > 0)
      printf("%10d%10d%10d\n", i, post[i].timeStamp, post[i].like);
  }
}

int main() {
  scanf("%d", &T);

  for (int tc = 0; tc < T; tc++) {
    scanf("%d", &queries);
    ct = 0;
    for (int i = 0; i < 100010; i++) {
      if (i < 1010) {
        user[i] = User();
      }
      post[i] = Post();
    }

    for (int query = 0; query < queries; query++) {
      // debug();
      int cmd;
      int uid, pid, timestamp, sid, tid;
      vector<int> postsCanBeRead;
      scanf("%d", &cmd);

      switch (cmd) {
        case 0:
          ct = 0;
          assert(false);
          break;
        case 1:
          scanf("%d%d%d", &uid, &pid, &timestamp);
          ct = timestamp;
          post[pid] = Post(timestamp);
          user[uid].posts.push_back(pid);
          break;
        case 2:
          scanf("%d", &pid);
          post[pid].like++;
          break;
        case 3:
          scanf("%d%d", &sid, &tid);
          user[sid].follows.push_back(tid);
          break;
        case 4:
          scanf("%d%d", &uid, &timestamp);
          ct = timestamp;
          for (int i = 0; i < user[uid].posts.size(); i++) {
            if (post[user[uid].posts[i]].timeStamp > ct - 1000 &&
                post[user[uid].posts[i]].timeStamp <= ct) {
              postsCanBeRead.push_back(user[uid].posts[i]);
            }
          }
          for (int i = 0; i < user[uid].follows.size(); i++) {
            for (int j = 0; j < user[user[uid].follows[i]].posts.size(); j++) {
              if (post[user[user[uid].follows[i]].posts[j]].timeStamp >
                      ct - 1000 &&
                  post[user[user[uid].follows[i]].posts[j]].timeStamp <= ct) {
                postsCanBeRead.push_back(user[user[uid].follows[i]].posts[j]);
              }
            }
          }

          if (postsCanBeRead.size() < 10) {
            vector<int> extraPosts;
            int extra = 10 - postsCanBeRead.size();

            for (int i = 0; i < user[uid].posts.size(); i++) {
              if (post[user[uid].posts[i]].timeStamp > ct - 1000)
                extraPosts.push_back(user[uid].posts[i]);
            }

            for (int i = 0; i < user[uid].follows.size(); i++) {
              for (int j = 0; j < user[user[uid].follows[i]].posts.size();
                   j++) {
                if (post[user[user[uid].follows[i]].posts[j]].timeStamp >
                    ct - 1000)
                  extraPosts.push_back(user[user[uid].follows[i]].posts[j]);
              }
            }

            sort(extraPosts.begin(), extraPosts.end(), comp2);

            for (int i = 0; i < extraPosts.size() && i < extra; i++) {
              postsCanBeRead.push_back(extraPosts[i]);
            }
          }

          if (postsCanBeRead.empty()) {
            printf("1 0\n");
            break;
          } else {
            sort(postsCanBeRead.begin(), postsCanBeRead.end(), comp);
            printf("%d ",
                   ((postsCanBeRead.size() > 10) ? 10 : postsCanBeRead.size()));
            for (int i = 0;
                 i <
                 ((postsCanBeRead.size() > 10) ? 10 : postsCanBeRead.size());
                 i++) {
              printf("%d ", postsCanBeRead[i]);
            }
            puts("");
            break;
          }
          break;
        default:
          // exception
          break;
      }
    }
  }
}