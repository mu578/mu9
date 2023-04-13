#include <mu9/mu9_algorithm.h>
#include <mu9/mu9_parallel.h>
#include <mu9/mu9_numeric.h>
#include <mu9/mu9_iterator.h>
#include <mu0/mu0_floating.h>
#include <mu0/mu0_string.h>

__mu0_static_inline__
void argsort(
	  const mu0_uint32_t   n
	, const mu0_fp32_t *   x
	,       mu0_uint32_t * indeces
) {
	      mu0_uint32_t * first   = mu9_begin      (mu0_uint32_t, indeces);
	      mu0_uint32_t * last    = mu9_end        (mu0_uint32_t, indeces, n);
	      mu0_uint32_t   start   = 0;
	const mu0_fp32_t   * s_first = mu9_const_begin(mu0_fp32_t, x);

	mu9_argument_sort1(mu0_infer(*first), first, last, start, s_first);
}

__mu0_static_inline__
mu0_bool_t endswith(
	  const mu0_tchar8_t * haystack
	, const mu0_tchar8_t * needle
) {
	      mu0_bool_t     d_result;
	const mu0_usize_t    n      = mu0_string8_length(haystack);
	const mu0_usize_t    m      = mu0_string8_length(needle);

	const mu0_tchar8_t * first1 = mu9_const_begin   (mu0_tchar8_t, needle);
	const mu0_tchar8_t * last1  = mu9_const_end     (mu0_tchar8_t, needle, m);
	const mu0_tchar8_t * first2 = mu9_const_begin   (mu0_tchar8_t, haystack);
	const mu0_tchar8_t * last2  = mu9_const_end     (mu0_tchar8_t, haystack, n);

	mu9_ends_with1(mu0_tchar8_t, first1, last1, first2, last2, d_result);

	return d_result;
}

int main(int argc, const char * argv[])
{
	      mu0_sint32_t   v0[3]    = { 3, 1, 4 };
	      mu0_distance_t i        = 0;
	      mu0_uint32_t   v1[10]   = { 0 };
	      mu0_fp32_t     v2[10]   = {
	      	   3.333f, 4.300f
	      	,  5.333f, 8.299f
	      	, -9.300f, 8.300f
	      	,  1.333f, 4.333f
	      	,  2.300f, 1.300f
	      };
	      mu0_sint32_t * first0;
	      mu0_uint32_t * first1   = mu9_begin      (mu0_uint32_t, v1);
	      mu0_uint32_t * last1    = mu9_end        (mu0_uint32_t, v1, 10);
	const mu0_fp32_t   * first2   = mu9_const_begin(mu0_fp32_t, v2);
	const mu0_tchar8_t * haystack = u8"hello world!";
	const mu0_tchar8_t * needle   = u8"world!";

	mu0_unused(argc);
	mu0_unused(argv);

	first0 = mu9_begin(mu0_sint32_t, v0);
	mu9_advance_n(mu0_sint32_t, first0, 2);
	mu0_console_log("%d \n", *first0);

	first0 = mu9_end(mu0_sint32_t, v0, 3);
	mu9_advance_n(mu0_sint32_t, first0, -2);
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

	mu0_console_info("%d %u\n"
		, mu9_gcd_constexpr(mu0_sint32_t, 2048, 6)
		, mu9_gcd(mu0_uint32_t, -2048, 6)
	);

	mu0_console_info("%d\n", endswith(haystack, needle));

	return 0;
}

/* EOF */