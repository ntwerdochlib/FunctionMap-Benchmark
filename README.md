# FunctionMap-Benchmark
Examine the benefits of the use of a function map for handling actions against using a large if/else block.

# Gains
A comparison of the two benchmarks (ProcessMessage and ProcessMessageUnorderedMap) shows and ~81% performance increase and an ~53% performance increase overall.

```
Comparing ProcessMessage to ProcessMessageUnorderedMap (from ./fnmapbm)
Benchmark                                                                            Time             CPU      Time Old      Time New       CPU Old       CPU New
-----------------------------------------------------------------------------------------------------------------------------------------------------------------
[ProcessMessage vs. ProcessMessageUnorderedMap]/repeats:100_pvalue                 0.0000          0.0000      U Test, Repetitions: 100 vs 100
[ProcessMessage vs. ProcessMessageUnorderedMap]/repeats:100_mean                  -0.8136         -0.8136           191            36           191            36
[ProcessMessage vs. ProcessMessageUnorderedMap]/repeats:100_median                -0.8140         -0.8140           191            36           191            36
[ProcessMessage vs. ProcessMessageUnorderedMap]/repeats:100_stddev                -0.9506         -0.9506             2             0             2             0
[ProcessMessage vs. ProcessMessageUnorderedMap]/repeats:100_cv                    -0.7349         -0.7348             0             0             0             0
OVERALL_GEOMEAN                                                                   -0.5332         -0.5332             0             0             0             0

```
