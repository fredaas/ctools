#!/usr/bin/env bash

./main > out_c.txt
./main.py > out_py.txt

diff out_c.txt out_py.txt && echo "OK" || echo "Error: CRCs do not match"
