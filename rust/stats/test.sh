#!/usr/bin/env bash

rustc --test -o run.tests.exe *test.rs && ./run.tests.exe
