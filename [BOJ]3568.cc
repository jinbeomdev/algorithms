#include <stdio.h>
#include <algorithm>

using namespace std;

char qurey[121];
char primitive_type[121];
int primitive_type_size = 0;

char common[121];
int common_size = 0;

int main() {
	scanf("%s", qurey);

	char *p = qurey;
	
	while((*p >= 'A' && *p <= 'Z') || (*p >= 'a' && *p <= 'z')) {
		primitive_type[primitive_type_size++] = *p++;
	}
	primitive_type[primitive_type_size] = '\0';

	while(*p != '\0') {
		common[common_size++] = *p++;
	}
	common[common_size] = '\0';

	while(true) {
		char variable[121];
		scanf("%s", variable);

		char name[121];
		int name_size = 0;
		char type[121];
		int type_size = 0;
		char *pv = variable;

		while((*pv >= 'A' && *pv <= 'Z') || (*pv >= 'a' && *pv <= 'z')) {
			name[name_size++] = *pv++;
		}
		name[name_size] = '\0';

		while(*pv != ',' && *pv != ';') {
			if(*pv == '[') {
				type[type_size++] = ']';
				*pv++;
			} else if(*pv == ']') {
				type[type_size++] = '[';
				*pv++;
			} else {
				type[type_size++] = *pv++;
			}
		}
		type[type_size] = '\0';
		reverse(type, type+type_size);
		printf("%s%s%s %s;\n", primitive_type, common, type, name);

		if(*pv == ';') break;
	}
}
