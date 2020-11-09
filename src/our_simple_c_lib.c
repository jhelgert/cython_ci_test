#include <stdio.h>
#include <stdlib.h>
#include "our_simple_c_lib.h"

c_vec* clib_init(int n){
	c_vec* v = malloc(sizeof(c_vec));
	v->data = calloc(n, sizeof(double));
	v->size = n;
	return v;
}

void clib_fill(c_vec* v){
	for (int i = 0; i < v->size; ++i){
		v->data[i] = (double) i;
	}
}

void clib_print(c_vec* v){
	for (int i = 0; i < v->size; ++i){
		printf("%3.1lf ", v->data[i]);
        if(i == 10 || (i+1) % 10 == 0){
            printf("\n");
        }
	}
	printf("\n");
}

double clib_sum(c_vec* v){
	double s = 0.0;
	for (int i = 0; i < v->size; ++i){
		s += v->data[i];
	}
	return s;
}

void clib_free(c_vec* v){
	free(v->data);
	free(v);
}