#pragma once

#include <archbenchs/execution_options.hpp>

#include <cstdint>

namespace archbenchs::sorting
{

void parallel_quick_sort(double* arr, int64_t size, const ExecutionOptions& options = {});

}
