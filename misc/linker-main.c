#include <mu9/mu9_algorithm.h>
#include <mu9/mu9_numeric.h>
#include <mu9/mu9_iterator.h>
#include <mu0/mu0_floating.h>

int main(int argc, const char * argv[])
{
	mu0_sint32_t  v0[3]           = { 3, 1, 4 };
	mu0_distance_t i              = 0;
	mu0_uint32_t v1[10]           = { 0 };
	mu0_fp32_t   v2[10]           = { 
		   3.333f, 4.300f
		,  5.333f, 8.299f
		, -9.300f, 8.300f
		,  1.333f, 4.333f
		,  2.300f, 1.300f
	};

	mu0_sint32_t * it0_first;

	mu0_uint32_t * const it1_first = mu9_infer_begin(v1);
	mu0_uint32_t * const it1_last  = mu9_infer_end  (v1, 10);
	mu0_fp32_t   * const it2_first = mu9_infer_begin(v2);

	mu0_unused(argc);
	mu0_unused(argv);

	it0_first = mu9_infer_begin(v0);
	mu9_advance_n(mu0_sint32_t, it0_first, 2);
	mu0_console_log("%d \n", *it0_first);

	it0_first = mu9_infer_end(v0, 3);
	mu9_advance_n(mu0_sint32_t, it0_first, -2);
	mu0_console_log("%d \n", *it0_first);

	mu9_argument_sort1(mu0_uint32_t
		, it1_first
		, it1_last
		, 0
		, it2_first
	);

	mu0_console_log("\n");
	for (; i < 10; ++i) {
		mu0_console_log("%0.4f, ", *(it2_first + *(it1_first + i)));
	}
	mu0_console_log("\n");

	mu0_console_log("%u %u\n", mu9_gcd_const(2048, 6), mu9_gcd(-2048, 6));

	return 0;
}

/* EOF */