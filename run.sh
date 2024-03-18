if [[ ! -d ./build ]]; then
	which ninja > /dev/null
	if [[ $? -eq 0 ]]; then
		cmake --preset linux-ninja
	else
		cmake --preset linux
	fi
fi
cmake --build build
./build/fnmapbm --benchmark_out_format=json --benchmark_out=results.json --benchmark_report_aggregates_only=true
