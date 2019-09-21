#include <stdio.h>

const int N = 100000;
const int MAX_FREQUENCY = 20000;
int frequencyOf[N + 10];

struct Data {
    int min;
    int max;

    Data() {
        min = N;
        max = N + 1;
    }

    bool operator<(const Data &rhs) const {
        if (frequencyOf[min] == frequencyOf[rhs.min]) {
            return min < rhs.min;
        }

        return frequencyOf[min] < frequencyOf[rhs.min];
    }

    bool operator>(const Data &rhs) const {
        if (frequencyOf[max] == frequencyOf[rhs.max]) {
            return max > rhs.max;
        }

        return frequencyOf[max] > frequencyOf[rhs.max];
    }
};

const int MAX_SEGMENT_TREE = 4 * N;
Data segmentTree[MAX_SEGMENT_TREE];

void updateNode(int i) {
    segmentTree[i].min =
        segmentTree[i * 2] < segmentTree[i * 2 + 1] ?
        segmentTree[i * 2].min :
        segmentTree[i * 2 + 1].min;

    segmentTree[i].max = 
        segmentTree[i * 2] > segmentTree[i * 2 + 1] ?
        segmentTree[i * 2].max :
        segmentTree[i * 2 + 1].max;
}

void buildSegmentTree() {
    for (int i = (MAX_SEGMENT_TREE) / 2 - 1; i > 0; i--) {
        updateNode(i);
    }
}

void updateSegmentTree(int i, const Data data) {
    i += MAX_SEGMENT_TREE / 2;
    segmentTree[i] = data;
    while (i > 1) {
        i /= 2;
        updateNode(i);
    }
}

int main() {
    frequencyOf[N] = MAX_FREQUENCY;
    frequencyOf[N + 1] = -1;
    
    for (int i = MAX_SEGMENT_TREE / 2; i < MAX_SEGMENT_TREE; i++) {
        segmentTree[i] = Data();
    }
    buildSegmentTree();

    int N, M;
    int sum = 0;
    int cnt = 0;
    scanf("%d%d", &N, &M);

    for (int i = 0; i < M; i++) {
        int mode, id, frequency;
        scanf("%d", &mode);

        if (mode == 0) {
            scanf("%d%d", &id, &frequency);
            sum += frequency;
            cnt++;
            frequencyOf[id] = frequency;
            Data data;
            data.min = id;
            data.max = id;
            updateSegmentTree(id, data);
        } else if (mode == 1) {
           if (cnt > 0) {
               cnt--;
               sum -= frequencyOf[segmentTree[1].min];
               printf("%d\n", segmentTree[1].min);
               Data data;
               updateSegmentTree(segmentTree[1].min, data);
           }
        } else if (mode == 2) {
            if (cnt > 0) {
                cnt--;
                sum -= frequencyOf[segmentTree[1].max];
                printf("%d\n", segmentTree[1].max);
                Data data;
                updateSegmentTree(segmentTree[1].max, data);
            }
        } else {
            if (cnt < 3) {
                printf("0\n");
            } else {
                printf("%d\n", sum - frequencyOf[segmentTree[1].min] - frequencyOf[segmentTree[1].max]);
            }
        }
    }
}