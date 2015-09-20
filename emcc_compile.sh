#!/bin/bash

mkdir -p ../fastjam-js/

if [ "$1" = "test" ]; then
	emcc test/*.cpp engine/*.cpp -O2 -s USE_SDL=2 -o ../fastjam-js/test.html
else
	emcc main.cpp -O2 -s USE_SDL=2 -o ../fastjam-js/game.html
fi
