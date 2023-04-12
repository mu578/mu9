#include <mu9/mu9_algorithm.h>
#include <mu9/mu9_parallel.h>
#include <mu9/mu9_numeric.h>
#include <mu9/mu9_iterator.h>
#include <mu0/mu0_floating.h>

__mu0_static_inline__
void argsort(
	  const mu0_uint32_t n
	, const mu0_fp32_t * x
	, mu0_uint32_t *     indeces
) {
	      mu0_uint32_t * first   = mu9_infer_begin(indeces);
	      mu0_uint32_t * last    = mu9_infer_end  (indeces, n);
	      mu0_uint32_t   start   = 0;
	const mu0_fp32_t   * s_first = mu9_infer_begin(x);

	mu9_argument_sort1(mu0_infer(*first), first, last, start, s_first);
}

int main(int argc, const char * argv[])
{
	mu0_sint32_t   v0[3]  = { 3, 1, 4 };
	mu0_distance_t i      = 0;
	mu0_uint32_t   v1[10] = { 0 };
	mu0_fp32_t     v2[10] = {
		   3.333f, 4.300f
		,  5.333f, 8.299f
		, -9.300f, 8.300f
		,  1.333f, 4.333f
		,  2.300f, 1.300f
	};

	mu0_sint32_t * first0;

	mu0_uint32_t * const first1 = mu9_infer_begin(v1);
	mu0_uint32_t * const last1  = mu9_infer_end  (v1, 10);
	mu0_fp32_t   * const first2 = mu9_infer_begin(v2);

	mu0_unused(argc);
	mu0_unused(argv);

	first0 = mu9_infer_begin(v0);
	mu9_infer_advance_n(first0, 2);
	mu0_console_log("%d \n", *first0);

	first0 = mu9_infer_end(v0, 3);
	mu9_infer_advance_n(first0, -2);
	mu0_console_log("%d \n", *first0);

	mu9_argument_sort1(mu0_uint32_t
		, first1
		, last1
		, 0
		, first2
	);
	mu0_console_log("\n");
	for (; i < 10; ++i) {
		mu0_console_log("%0.4f, ", *(first2 + *(first1 + i)));
	}
	mu0_console_log("\n");

	argsort(10, v2, v1);
	mu0_console_log("\n");
	for (i = 0; i < 10; ++i) {
		mu0_console_warn("%0.4f, ", v2[v1[i]]);
	}
	mu0_console_log("\n");

	mu0_console_info("%d %u\n", mu9_gcd_const(mu0_sint32_t, 2048, 6), mu9_infer_gcd(-2048, 6));

	return 0;
}

/* EOF */