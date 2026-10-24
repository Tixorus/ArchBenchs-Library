# ArchBenchs

Ранний вариант общей структуры на примере quick sort.

- `common` - общая часть проекта, пока только с параметрами исполнения в виде количества потоков;
- `toolchains` - файлы настройки CMake для выбора компилятора/архитектуры;
- `SortsBenchmark/include` - публичный заголовок;
- `SortsBenchmark/src` - реализация сортировки;
- `SortsBenchmark/tests` - проверка корректности;
- `SortsBenchmark/benchmarks` - замер времени.

Сборка:

icx:
```
cmd /k "call YOUR_PATH\Intel\oneAPI\setvars.bat"
cmake --fresh -B build-icpx -G Ninja -DCMAKE_BUILD_TYPE=Release "-DCMAKE_TOOLCHAIN_FILE=toolchains/x86_icx.cmake"
cmake --build build-icpx --config Release
```

gcc:
```
cmake --fresh -B build-gcc -G Ninja -DCMAKE_BUILD_TYPE=Release "-DCMAKE_TOOLCHAIN_FILE=toolchains/x86_gcc.cmake"
cmake --build build-gcc --config Release
```

Запуск теста:
```
ctest --test-dir build-icpx --output-on-failure

ctest --test-dir build-gcc --output-on-failure
```
Запуск замера (размер, число потоков, число повторов):

```
./build-icpx/SortsBenchmark/sort_benchmark.exe 1000000 4 5
```
