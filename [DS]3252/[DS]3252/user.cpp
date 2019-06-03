/// ===== user.cpp  =====
#ifndef NULL
#define NULL 0
#endif

struct Data {
	long long extractedData;
	int dataId;
};

int _dataNum;
int _data[10005][100];
int _dataLength[10005];

int _extractDataTableSize;
Data _extractDataTable[100 * 10005];

bool _isSorted = false;

long long extractData(int args[8]) {
	long long var1 = (((long long)(args[0] + 128)) << 56);
	long long var2 = (((long long)(args[1] + 128)) << 48);
	long long var3 = (((long long)(args[2] + 128)) << 40);
	long long var4 = (((long long)(args[3] + 128)) << 32);
	long long var5 = (((long long)(args[4] + 128)) << 24);
	long long var6 = (((long long)(args[5] + 128)) << 16);
	long long var7 = (((long long)(args[6] + 128)) << 8);
	long long var8 = ((long long)(args[7] + 128));

	return var1 | var2 | var3 | var4 | var5 | var7 | var8;
}

void merge(int l, int m, int r)
{
	int i, j, k;
	int n1 = m - l + 1;
	int n2 = r - m;

	/* create temp arrays */
	Data *L = new Data[n1];
	Data *R = new Data[n2];

	/* Copy data to temp arrays L[] and R[] */
	for (i = 0; i < n1; i++)
		L[i] = _extractDataTable[l + i];
	for (j = 0; j < n2; j++)
		R[j] = _extractDataTable[m + 1 + j];

	/* Merge the temp arrays back into arr[l..r]*/
	i = 0; // Initial index of first subarray 
	j = 0; // Initial index of second subarray 
	k = l; // Initial index of merged subarray 
	while (i < n1 && j < n2)
	{
		if (L[i].extractedData <= R[j].extractedData)
		{
			_extractDataTable[k] = L[i];
			i++;
		}
		else
		{
			_extractDataTable[k] = R[j];
			j++;
		}
		k++;
	}

	/* Copy the remaining elements of L[], if there
	   are any */
	while (i < n1)
	{
		_extractDataTable[k] = L[i];
		i++;
		k++;
	}

	/* Copy the remaining elements of R[], if there
	   are any */
	while (j < n2)
	{
		_extractDataTable[k] = R[j];
		j++;
		k++;
	}
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int l, int r)
{
	if (l < r)
	{
		// Same as (l+r)/2, but avoids overflow for 
		// large l and h 
		int m = l + (r - l) / 2;

		// Sort first and second halves 
		mergeSort(l, m);
		mergeSort(m + 1, r);

		merge(l, m, r);
	}
}

void swap(Data &lhs, Data &rhs) {
	Data temp = lhs;
	lhs = rhs;
	rhs = temp;
}

int partition(int low, int high)
{
	Data pivot = _extractDataTable[high];    // pivot 
	int i = (low - 1);  // Index of smaller element 

	for (int j = low; j <= high - 1; j++)
	{
		// If current element is smaller than or 
		// equal to pivot 
		if (_extractDataTable[j].extractedData <= pivot.extractedData)
		{
			i++;    // increment index of smaller element 
			swap(_extractDataTable[i], _extractDataTable[j]);
		}
	}
	swap(_extractDataTable[i + 1], _extractDataTable[high]);
	return (i + 1);
}

/* The main function that implements QuickSort
 arr[] --> Array to be sorted,
  low  --> Starting index,
  high  --> Ending index */
void quickSort(int low, int high)
{
	if (low < high)
	{
		/* pi is partitioning index, arr[p] is now
		   at right place */
		int pi = partition(low, high);

		// Separately sort elements before 
		// partition and after partition 
		quickSort(low, pi - 1);
		quickSort(pi + 1, high);
	}
}

void initUser(int dataN) {
	_isSorted = false;
	_dataNum = dataN;
	_extractDataTableSize = 0;

	for (int i = 0; i < 10005; i++) {
		_dataLength[i] = 0;

		for (int j = 0; j < 100; j++) {
			_data[i][j] = 0;
		}
	}

	for (int i = 0; i < 100 * 10005; i++) {
		_extractDataTable[i].extractedData = 0;
		_extractDataTable[i].dataId = 0;
	}
}

void registerData(int dataID, int dataLen, int dataArr[100]) {
	_dataLength[dataID] = dataLen;
	for (int i = 0; i < dataLen; i++) {
		_data[dataID][i];
	}

	for(int i = 0; i <= dataLen - 8; i++) {
		int args[8];

		for(int j = 0; j < 8; j++) {
			args[j] = dataArr[i + j];
		}
	
		_extractDataTable[_extractDataTableSize].dataId = dataID;
		_extractDataTable[_extractDataTableSize++].extractedData = extractData(args);
	}
}

int findID(int args[8]) {
	if (!_isSorted) {
		quickSort(0, _extractDataTableSize - 1);
		_isSorted = true;
	}

	long long key = extractData(args);

	int left = 0, right = _extractDataTableSize - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		
		if (key < _extractDataTable[mid].extractedData) {
			right = mid - 1;
		}
		else if (key > _extractDataTable[mid].extractedData) {
			left = mid + 1;
		}
		else {
			break;
		}
	}

	return _extractDataTable[mid].dataId;
}