#ifndef NULL
#define NULL 0
#endif 

#define bit7(x) ((x>>8) & ((1<<7) - 1)) // 15bit 중 앞 7bit 추출

int N, len[10005], Data[10005][200], *arr;
const int hn (1 << 21); //hash 크기
struct Hash {
    int id, start;
    Hash *next;
    Hash (int _id, int _start, Hash *_next) {
        id = _id, start = _start, next = _next;
    }
} *hash[hn];

void push(int p, int id, int start) {
    hash[p] = new Hash(id, start, hash[p]);
}

void pop(int p) {
    Hash *tmp = hash[p];
    hash[p] = hash[p]->next;
    delete tmp;
}

void initUser(int soundNum){
    N = soundNum;
    for (int i = 0; i < hn; i++) while(hash[i] != 0) pop(i);
}

int key(int a, int b, int c) {
    return (bit7(a) << 14) + (bit7(b) << 7) + bit7(c);
}
 
void registerSound(int soundID, int soundLen, int soundArr[200]){
    len[soundID] = soundLen;
    int i, tmp;
    for(int i = 0; i < soundLen; i++) Data[soundID][i] = soundArr[i];
    for(int i = 0; i < soundLen - 8; i++) {
        tmp = key(soundArr[i], soundArr[i + 1], soundArr[i + 2]);
        push(tmp, soundID, i);
    }
}

int chk(int id, int start) {
    for(int i = 0; i < 8; i++) {
        if (Data[id][start + i] - 128 > arr[i] || Data[id][start + i] + 127 < arr[i]) return 0;
    }
    return 1;
}

int search(Hash *p) {
    if(!p) return 0;
    if(chk(p->id, p->start)) return p->id;
    return search(p->next);
}

int p[3][8] = {
    {-127, -127, -127, -127, +128, +128, +128, +128},
    {-127, -127, +128, +128, -127, -127, +128, +128},
    {-127, +128, -127, +128, -127, +128, -127, +128}
};

int  plagiarismCheck(int newData[8])
{
    arr = newData;
    int tmp, i, id = 0;
    for(int i = 0; i < 8 && id == 0; i++) {
        tmp = key(arr[0]+ p[0][i], arr[1] + p[1][i], arr[2] + p[2][i]);
        id = search(hash[tmp]);
    }

    return id;
}