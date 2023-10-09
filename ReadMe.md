# mu9

A micro software algorithms template library for embedded-C. Re-introducing
C++ procedural, object-oriented and generic programming paradigms in vanilla C,
however, the library remains container agnostic.

To know, the most part of the procedural programming `cross-target engine` and
`logic` is provided by `mu0`, e.g C is an imperative procedural language by
nature and definition. The generic programming interface is supported through
C-macro directives i.e meta-programming for preprocessing and then compile time
code generation (limitation: no possible recursivity) while the object-oriented
programming interface via operator-functional indirections and abstractions.

Most of the type-independent algorithm front-ends are following the same design
in mind than the STL: https://en.cppreference.com/w/cpp/algorithm for temporary
reference. Last, for the embedded C++ community, I think it is also interesting to have
a look at the excellent John Wellbelove's Embedded Template Library: https://github.com/ETLCPP/etl.

# EOF