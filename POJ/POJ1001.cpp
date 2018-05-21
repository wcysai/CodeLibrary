#include <stdio.h>
#include <string.h>

int buf[128];

typedef unsigned char byte;

struct pfloat {
	byte digit[128];
	int len;
	int dot;
};

typedef struct pfloat pfloat;

void pfloat_parse(char *input_str, pfloat *num) {
	char *p = input_str+strlen(input_str)-1;
	int post_zero = 0;
	for (; p-input_str>=0 && *p == '0'; -- p) {
		++ post_zero;
	}
	
	if (p-input_str>=0) {
		int dot = 0;
		for (; p-input_str>=0 && *p != '.'; -- p, ++ dot) {
			num->digit[dot] = *p-'0';
		}
		-- p;
		if (p-input_str>=0) { // has dot
			int i, j;
			for (i = dot; p-input_str>=0; -- p, ++ i) {
				num->digit[i] = *p-'0';
			}
			for (j = i-1; j > -1 && num->digit[j] == 0; -- j);
			num->len = j+1;
			num->dot = dot;
		}
		else {
			int j;
			for (j = dot-1; j > -1 && num->digit[j] == 0; -- j);
			num->len = j+1;
			num->dot = -post_zero;
		}
	}
	else {
		num->len = 0;
		num->dot = 0;
	}
}

void pfloat_multi(pfloat *a, pfloat *b, pfloat *r) {
	memset(buf, 0, sizeof(int)*128);
	
	for (int i = 0; i < a->len; ++ i) {
		for (int j = 0; j < b->len; ++ j) {
			buf[i+j] += a->digit[i] * b->digit[j];
		}
	}
	
	int c = 0; int len;
	for (len = 0; len < a->len+b->len-1; ++ len) {
		int k = buf[len]+c;
		buf[len] = k%10;
		c = k/10;
	}
	if (c || buf[len]) {
		buf[len] = buf[len]+c;
		++ len;
	}
	
	for (int i = 0; i < len; ++ i) {
		r->digit[i] = buf[i];
	}
	r->len = len;
	r->dot = a->dot + b->dot;
}

void pfloat_print(pfloat *p) {
	if (p->len == 0) {
		printf("0\n");
		return;
	}
	
	if (p->dot <= 0) {
		for (int i = 0; i < p->len; ++ i) {
			printf("%d", p->digit[p->len-1-i]);
		}
		for (int i = p->dot; i < 0; ++ i) {
			printf("0");
		}
	}
	
	else if (p->dot < p->len) {
		int i;
		for (i = 0; i < p->len-p->dot; ++ i) {
			printf("%d", p->digit[p->len-1-i]);
		}
		printf(".");
		for (; i < p->len; ++ i) {
			printf("%d", p->digit[p->len-1-i]);
		}
	}
	
	else {
		printf(".");
		for (int i = 0; i < p->dot-p->len; ++ i) {
			printf("0");
		}
		for (int i = 0; i < p->len; ++ i) {
			printf("%d", p->digit[p->len-1-i]);
		}
	}
	printf("\n");
}

int main(int argc, char **argv)
{
	char input[32];
	int exp;
	
	pfloat *a = new pfloat, *b = new pfloat;
	while (scanf("%s%d", input, &exp) != EOF) {
		pfloat_parse(input, a);
		b->len = 1, b->digit[0] = 1, b->dot = 0;
		for (int i = 0; i < exp; ++ i) {
			pfloat_multi(a, b, b);
		}
		pfloat_print(b);
	}
	delete a, delete b;
	return 0;
}