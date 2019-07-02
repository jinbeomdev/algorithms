#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

const int UID = 1001;
const int PID = 100001;

struct Post {
  int postId;
  bool uesrs[UID];
  int likeCnt;
  int timeStamp;

  void push(int _postId, int _uid, int _timeStamp) {
    postId = _postId;
    uesrs[_uid] = true;
    timeStamp = _timeStamp;
    likeCnt = 0;
  }

  bool operator< (const Post lhs) const {
    if(likeCnt == lhs.likeCnt) return timeStamp > lhs.timeStamp;
    return likeCnt > lhs.likeCnt;
  }
};

Post postArr[PID];
int postSize;

vector<int> uesrPostArr[UID];
vector<int> uesrFollowingArr[UID];

int ct;

void cmd0() {
  ct = 0;
  postSize = 0;
  for(int i = 0; i < UID; i++) {
    uesrPostArr[i].clear();
    uesrFollowingArr[i].clear();
  }
}

void cmd1() {
  int uid, pid, timeStamp;
  scanf("%d%d%d", &uid, &pid, &timeStamp);
  pid--;
  postArr[postSize++].push(pid, uid, timeStamp);
  uesrPostArr[uid].push_back(pid);

  ct = timeStamp;
}

void cmd2() {
  int pid;
  scanf("%d", &pid);
  pid--;
  postArr[pid].likeCnt++;
}

void cmd3() {
  int sid, tid;
  scanf("%d%d", &sid, &tid);
  uesrFollowingArr[sid].push_back(tid);
}

bool comp(const Post *lhs, const Post *rhs) {
  if(lhs->likeCnt == rhs->likeCnt) {
    return lhs->timeStamp > rhs->timeStamp;
  }
  return lhs->likeCnt > rhs->likeCnt;
}

void printAnswer(int ret[], int retSize) {
  printf("%d", retSize);
  for(int i = 0; i < retSize; i++) {
    printf(" %d", ret[i]);
  }
  puts("");
}

void cmd4() {
  int uid, timeStamp;
  scanf("%d%d", &uid, &timeStamp);
  
  for(int i = 0; i < uesrFollowingArr[uid].size(); i++) {
      for(int j = 0; j < uesrPostArr[uesrFollowingArr[uid][i]].size(); j++) {
          postArr[uesrPostArr[uesrFollowingArr[uid][i]][j]].uesrs[uid] = true;
      }
  }

  ct = timeStamp;

  int ret[10];
  int retSize = 0;
  
  Post *ptrPost[1002];
  int ptrPostSize = 0;

  int postIdx = postSize;
  while(--postIdx >= 0 && postArr[postIdx].timeStamp >= ct - 1000) {
    //printf("postArr[%d].timeStamp : %d\n", postIdx, postArr[postIdx].timeStamp);
    if(!(ptrPostSize < 1002)) break;
    if(!postArr[postIdx].uesrs[uid]) continue;

    ptrPost[ptrPostSize++] = &postArr[postIdx];
  }
  
  sort(ptrPost, ptrPost + ptrPostSize, comp);

  for(int i = 0; i < ptrPostSize && i < 10; i++) {
    ret[retSize++] = ptrPost[i]->postId + 1;
  }

  if(retSize == 10) {
    printAnswer(ret, retSize);
    return;
  }

  postIdx++;
  while (--postIdx >= 0) {
    if(!(retSize < 10)) break;
    if(!postArr[postIdx].uesrs[uid]) continue;

    ret[retSize++] = postIdx;
  }

  if(retSize == 0) {
    printf("1 0\n");
    return;
  }

  printAnswer(ret, retSize);
  return;
}

void getQuery() {
  int type;

  scanf("%d", &type);

  if(type == 0) {
    cmd0();
    return;
  }

  if(type == 1) {
    cmd1();
    return;
  }

  if(type == 2) {
    cmd2();
    return;
  }

  if(type == 3) {
    cmd3();
    return;
  }

  if(type == 4) {
    cmd4();
    return;
  }

}

int main() {
  int T;

  scanf("%d", &T);
  for(int tc = 1; tc <= T; tc++) {
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++) getQuery();
  }
}