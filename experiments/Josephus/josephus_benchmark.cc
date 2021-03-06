#include "josephus.h"

#include "benchmark/benchmark_api.h"

namespace {

static constexpr int n = 1 << 21;
static constexpr int m = 3;

static void BM_Woodhousea(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(woodhousea(n, state.range_x()));
    }
}
BENCHMARK(BM_Woodhousea)->RangeMultiplier(m)->Range(2, n);

static void BM_ConcreteMath(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(concrete_math(n, state.range_x()));
    }
}
BENCHMARK(BM_ConcreteMath)->RangeMultiplier(m)->Range(2, n);

static void BM_TAOCP(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(taocp(n, state.range_x()));
    }
}
BENCHMARK(BM_TAOCP)->RangeMultiplier(m)->Range(2, n);

static void BM_TAOCPK(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(taocp_k(n, state.range_x(), n));
    }
}
BENCHMARK(BM_TAOCPK)->RangeMultiplier(m)->Range(2, n);

static void BM_Gelgi(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(gelgi(n, state.range_x()));
    }
}
BENCHMARK(BM_Gelgi)->RangeMultiplier(m)->Range(2, n);

static void BM_GelgiImprove(benchmark::State& state) {
    while (state.KeepRunning()) {
        benchmark::DoNotOptimize(gelgi_improve(n, state.range_x()));
    }
}
BENCHMARK(BM_GelgiImprove)->RangeMultiplier(m)->Range(2, n);

}
BENCHMARK_MAIN();
