#ifndef NULL
#define NULL  0
#endif
 
const int MAX_ID = 100000;
int frequencyOf[MAX_ID + 10];

struct Data {
    int min;
    int max;

    Data() {
        min = MAX_ID;
        max = MAX_ID + 1;
    }

    bool operator<(const Data &rhs) {
        if (frequencyOf[min] == frequencyOf[rhs.min]) {
            return min < rhs.min;
        }

        return frequencyOf[min] < frequencyOf[rhs.min];
    }

    bool operator>(const Data &rhs) {
        if (frequencyOf[max] == frequencyOf[rhs.max]) {
            return max > rhs.max;
        }

        return frequencyOf[max] > frequencyOf[rhs.max];
    }
};

const int MAX_SEGMENT_TREE_SIZE = 4 * MAX_ID;
//segmentTree[0] 참여도가 낮은 그룹, segmentTree[1] 참여도가 높은 그룹
Data segmentTree[2][MAX_SEGMENT_TREE_SIZE];
int sum[2];
int size[2];

void updateNode(int g, int i) {
    segmentTree[g][i].min =
        segmentTree[g][i * 2] < segmentTree[g][i * 2 + 1] ?
        segmentTree[g][i * 2].min :
        segmentTree[g][i * 2 + 1].min;

    segmentTree[g][i].max = 
        segmentTree[g][i * 2] > segmentTree[g][i * 2 + 1] ?
        segmentTree[g][i * 2].max :
        segmentTree[g][i * 2 + 1].max;
}

void buildSegmentTree() {
    for (int i = MAX_SEGMENT_TREE_SIZE / 2 - 1; i > 1; i--) {
        updateNode(0, i);
        updateNode(1, i);
    }
}

void updateSegmentTree(int g, int i, Data data) {
    i += MAX_SEGMENT_TREE_SIZE / 2;
    segmentTree[g][i] = data;
    while (i > 1) {
        i /= 2;
        updateNode(g, i);
    }
}

void addMember(Member obj){
    frequencyOf[obj.id] = obj.frequency;

    Data data, del;
    data.min = obj.id;
    data.max = obj.id;
    updateSegmentTree(0, obj.id, data);
    sum[0] += frequencyOf[obj.id];
    size[0]++;

    int median = segmentTree[0][1].max;
    Data medianData;
    medianData.min = median;
    medianData.max = median;

    updateSegmentTree(1, median, medianData);
    sum[1] += frequencyOf[median];
    size[1]++;
    updateSegmentTree(0, median, del);
    sum[0] -= frequencyOf[median];
    size[0]--;

    if (size[0] < size[1]) {
        int min = segmentTree[1][1].min;
        Data minData;
        minData.min = min;
        minData.max = min;

        updateSegmentTree(1, min, del);
        sum[1] -= frequencyOf[min];
        size[1]--;
        updateSegmentTree(0, min, minData);
        sum[0] += frequencyOf[min];
        size[0]++;
    }
}
 
int removeMembers(int mode){
    if (mode == 0) {
        int del = segmentTree[0][1].min;
        Data data;
        updateSegmentTree(0, del, data);
        sum[0] -= frequencyOf[del];
        size[0]--;
        return del;
    } else if (mode == 1) {
        if ((size[0] + size[1]) % 2 == 0) { //짝수
            int sumDel = segmentTree[0][1].max + segmentTree[1][1].min;
            int del;
            Data data;

            del = segmentTree[0][1].max;
            updateSegmentTree(0, del, data);
            size[0] -= frequencyOf[del];
            size[0]--;

            del = segmentTree[1][1].min;
            updateSegmentTree(1, del, data);
            size[1] -= frequencyOf[del];
            size[1]--;

            return sumDel;
        } else { //홀수
            int del = segmentTree[0][1].max;
            Data data;
            updateSegmentTree(0, del, data);
            size[0] -= frequencyOf[del];
            size[0]--;
            return del;
        }
    } else {
        int del = segmentTree[1][1].max;
        Data data;
        updateSegmentTree(1, del, data);
        sum[1] -= frequencyOf[del];
        size[1]--;
        return del;
    }
}
 
void getSum(int sum2[]){
    sum2[1] = sum[1];
    if ((size[0] + size[1]) % 2 == 1) {
        sum2[0] = sum[0] - frequencyOf[segmentTree[0][1].max];
    } else {
        sum2[0] = sum[0];
    }
}
 
void userInit(int memberCount, Member members[]){
    sum[0] = sum[1] = size[0] = size[1] = 1;
    for (int i = 0; i < MAX_ID; i++) {
        frequencyOf[i] = 0;
    }
    frequencyOf[MAX_ID] = 100000;
    frequencyOf[MAX_ID + 1] = -1;

    for (int i = MAX_SEGMENT_TREE_SIZE / 2; i < MAX_SEGMENT_TREE_SIZE; i++) {
        segmentTree[0][i].min = segmentTree[1][i].min = MAX_ID;
        segmentTree[0][i].max = segmentTree[1][i].max = MAX_ID + 1;
    }
    buildSegmentTree();

    for (int i = 0; i < memberCount; i++) {
        addMember(members[i]);
    }
}