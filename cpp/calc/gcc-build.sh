#! /usr/bin/env bash

set -o errexit

g++ -std=c++14 src/main.cpp -o build/calc
