#include "barvinok/barvinok.h"
#include "isl/ctx.h"
#include "isl/set.h"
#include "isl/polynomial.h"
#include "isl/printer.h"
#include <stdio.h>
#include <stdlib.h>

/*
 * count_integer_points.c
 *
 *  Created on: Feb 29, 2016
 *      Author: stg
 */


int main(int argc, char **argv) {
	int maxInputLen = 4096;
	char setStr[maxInputLen];
	char *success = fgets(setStr, maxInputLen, stdin);
	if (!success) {
		fprintf(stderr, "Failed to read from STDIN.\n");
		return 1;
	}
	isl_ctx *ctx = isl_ctx_alloc();
	isl_set *s = isl_set_read_from_str(ctx, setStr);
	if (!s) {
		fprintf(stderr, "Failed to interpret the input as an Isl set.\n");
		return 1;
	}
	isl_pw_qpolynomial *nElemsPoly = isl_set_card(s);
	isl_printer *p = isl_printer_to_str(ctx);
	p = isl_printer_print_pw_qpolynomial(p, nElemsPoly);
	printf("%s\n", isl_printer_get_str(p));
	isl_printer_free(p);
	isl_pw_qpolynomial_free(nElemsPoly);
	isl_set_free(s);
//	isl_ctx_free(ctx);
	return 0;
}
