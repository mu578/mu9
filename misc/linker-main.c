#include <mu9/mu9_algorithm.h>
#include <mu9/mu9_iterator.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
	mu0_sint32_t  v0[3] = { 3, 1, 4 };
	mu0_vsint32_t vit; 
	
	vit = mu9_iterator_begin(mu0_sint32_t, v0);
	mu9_advance_n(mu0_sint32_t, vit, 2);
	mu0_console_log("%d \n", *vit);

	vit = mu9_iterator_end(mu0_sint32_t, v0, 3);
	mu9_advance_n(mu0_sint32_t, vit, -2);
	mu0_console_log("%d \n", *vit);

	mu0_distance_t i;

	mu0_sint32_t v1[10] = { 0 };
	mu0_fp32_t   v2[10] = { 3, 4, 5 , 8, 9 , 8, 1, 4, 2, 1 };

	mu0_vsint32_t v1_first;
	mu0_vsint32_t v1_last;
	mu0_vfp32_t   v2_first;

	v1_first = mu9_iterator_begin(mu0_sint32_t, v1);
	v1_last  = mu9_iterator_end(mu0_sint32_t, v1, 10);
	v2_first = mu9_iterator_begin(mu0_fp32_t, v2);

	mu9_argument_sort1(mu0_float32_t, mu0_sint32_t
		, v1_first
		, v1_last
		, 0
		, v2_first
	);

	mu0_console_log("\n");

	v1_first = mu9_iterator_begin(mu0_sint32_t, v1);
	for (i = 0; i < 10; ++i) {
		mu0_console_log("%f ", *(v2_first + *(v1_first + i)));
	}

	mu0_console_log("\n");

	return 0;
}

/* EOF */