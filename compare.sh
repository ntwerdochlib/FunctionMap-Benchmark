#! /usr/bin/env bash

if [[ ! -d .venv ]]; then
	echo Setting up python virtual environment
	python3 -m venv --prompt benchmark .venv
	. .venv/bin/activate
	echo Installing requirements
	pip3 install -r build/_deps/benchmark-src/tools/requirements.txt
else
	. .venv/bin/activate
fi

 python3 build/_deps/benchmark-src/tools/compare.py -a filters ./build/fnmapbm ProcessMessage ProcessMessageUnorderedMap
