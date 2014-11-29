#ifndef KSON_H
#define KSON_H

#include <stdint.h>

#define KSON_TYPE_NO_QUOTE  1
#define KSON_TYPE_SGL_QUOTE 2
#define KSON_TYPE_DBL_QUOTE 3
#define KSON_TYPE_ANGLE     4
#define KSON_TYPE_CURLY     5

typedef struct {
	uint64_t type:3, n:61;
	char *key;
	union {
		int *child;
		char *str;
	} v;
} kson_node_t;

#ifdef __cplusplus
extern "C" {
#endif

	kson_node_t *kson_parse_core(const char *json, int *n);

#ifdef __cplusplus
}
#endif

#endif