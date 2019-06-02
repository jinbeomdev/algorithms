#include <stdio.h>
#include <assert.h>

#include <vector>

using namespace std;

vector<int> dateTable[40000];
vector<int> idTable[10001];

int getMaxDay(int year, int month) {
    if(month == 1 || month == 3 || month == 5 || 
    month == 7 || month == 8 || month == 10 || month == 12) {
        return 31;
    } else if(month == 4 || month == 6 || month == 9 || month == 11) {
        return 30;
    } else if(month == 2){
        if((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
            return 29;
        } else {
            return 28;
        }
    } else {
        printf("getMaxDay : month %d \n", month);
        assert(false);
    }
}

int getDay(int date) {
    date = date % 100;
    if(date > 31) assert(false);
    return date;
}

int getMonth(int date) {
    date = date % 10000;
    date = date / 100;
    if(date > 12) assert(false);
    return date;
}

int getDate(int date, int type) {
    int year = date / 10000;
    date = date % 10000;
    int month = date / 100;
    date = date % 100;
    int day = date;

    if(type <= 7) {
        day += type;
        if(day > getMaxDay(year, month)) {
           day = day - getMaxDay(year, month);
           month++;
           if(month > 12) {
               month = 1;
               year++;
           }
        }
    }

    if(type == 8) {
        month += 1;
        if(month > 12) {
            month = 1;
            year++;
        }
    }

    if(type == 9) {
        year += 1;
    }

    return year * 10000 + month * 100 + day;
}

int getIndex(int date) {
    int baseYear = 2018;
    int year = date / 10000;
    date = date % 10000;
    int month = date / 100;
    date = date % 100;
    int day = date;
    int ret = day;

    ret += (((year - baseYear) * 365) + (((year - 1) / 4) - (baseYear / 4)));
    if(year > 2100) {
        ret -= 1;
    }
    
    for(int i = 1; i < month; i++) {
        ret += getMaxDay(year, i);
    }

    return ret;
}

void insert(int id, int index) {
    dateTable[index].push_back(id);
    idTable[id].push_back(index);
}

void cancleInDateTable(int id, int index) {
    for(int i = 0; i < dateTable[index].size(); i++) {
        if(dateTable[index][i] == id) {
            dateTable[index].erase(dateTable[index].begin() + i);
            break;
        }
    }
}

void cancleInIdTable(int id, int index) {
    for(int i = 0; i < idTable[id].size(); i++) {
        if(idTable[id][i] == index) {
            idTable[id].erase(idTable[id].begin() + i);
            break;
        }
    }
}

void cancleAllByDate(int index) {
    vector<int>::iterator it = dateTable[index].begin();
    while(it != dateTable[index].end()) {
        int id = *it;
        cancleInIdTable(id, index);
        it = dateTable[index].erase(it);
    }
}

void cancleAllById(int id) {
    vector<int>::iterator it = idTable[id].begin();
    while(it != idTable[id].end()) {
        int index = *it;
        cancleInDateTable(id, index);
        it = idTable[id].erase(it);
    }
}

void cancleAllByDateAndId(int id, int index) {
    vector<int>::iterator it = dateTable[index].begin();
    while(it != dateTable[index].end()) {
        int id = *it;
        cancleInIdTable(id, index);
        it = dateTable[index].erase(it);
        cancleAllById(id);
    }
}

int getCount(int index) {
    int ret = 0;
    for(int i = index; i < index + 30; i++) {
        if(index > getIndex(21171231)) break;
        ret += dateTable[i].size();
    }
    return ret;
}

int main() {
    int T;

    scanf("%d", &T);
    while(T--) {
        for(int i = 0; i < 40000; i++) {
            dateTable[i].clear();
        }
        for(int i = 0; i < 10001; i++) {
            idTable[i].clear();
        }
        int numQuery;
        scanf("%d", &numQuery);
        while(numQuery--) {
            int queryType;
            int id, type, cnt, date;
            int index;
            scanf("%d", &queryType);

            switch (queryType)
            {
            case 1:
                scanf("%d%d%d%d", &id, &type, &cnt, &date);
                if(type == 0) cnt = 1;
                /*
                if(type == 8 && (getDay(date) == 29 || getDay(date) == 30 || getDay(date) == 31)) {
                    break;
                }
                if(type == 9 && getMonth(date) == 2 && getDay(date) == 29) {
                    break;
                }
                */
                while(cnt--) {
                    index = getIndex(date);
                    if(index > getIndex(21171231)) break;
                    insert(id, index);
                    date = getDate(date, type);
                }
                break;
            case 2:
                scanf("%d%d", &type, &date);
                if(type == 0) cancleAllByDate(getIndex(date));
                if(type == 1) cancleAllByDateAndId(id, getIndex(date));
                if(type == 2) cancleAllById(date);
                break;
            case 3:
                scanf("%d", &date);
                printf("%d\n", getCount(getIndex(date)));
                break;
            default:
                assert(false);
                break;
            }
        }
    }
}