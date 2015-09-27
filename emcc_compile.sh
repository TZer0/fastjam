#!/bin/bash

mkdir -p ../fastjam-js/
FLAGS='-O2 -s USE_SDL=2 -std=c++14'

if [ "$1" = "test" ]; then
	emcc test/*.cpp engine/*.cpp $FLAGS -o ../fastjam-js/test.html
else
	emcc main.cpp $FLAGS -o ../fastjam-js/game.html
fi
