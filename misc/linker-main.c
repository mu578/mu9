#include <mu9/mu9_algorithm.h>
#include <mu9/mu9_iterator.h>
#include <stdio.h>

int main(int argc, const char * argv[])
{
	mu0_sint32_t  v0[3] = { 3, 1, 4 };
	mu0_vsint32_t it0_first; 
	
	it0_first = mu9_begin(mu0_sint32_t, v0);
	mu9_advance_n(mu0_sint32_t, it0_first, 2);
	mu0_console_log("%d \n", *it0_first);

	it0_first = mu9_end(mu0_sint32_t, v0, 3);
	mu9_advance_n(mu0_sint32_t, it0_first, -2);
	mu0_console_log("%d \n", *it0_first);

	mu0_distance_t i        = 0;

	mu0_uint32_t v1[10]     = { 0 };
	mu0_fp32_t   v2[10]     = { 3, 4, 5 , 8, 9 , 8, 1, 4, 2, 1 };

	const mu0_vuint32_t it1_first = mu9_const_begin(mu0_uint32_t, v1);
	const mu0_vuint32_t it1_last  = mu9_const_end  (mu0_uint32_t, v1, 10);
	const mu0_vfp32_t   it2_first = mu9_const_begin(mu0_fp32_t, v2);

	mu9_argument_sort1(mu0_uint32_t, it1_first, it1_last, 0, it2_first);

	mu0_console_log("\n");
	for (; i < 10; ++i) {
		mu0_console_log("%f ", *(it2_first + *(it1_first + i)));
	}
	mu0_console_log("\n");

	return 0;
}

/* EOF */