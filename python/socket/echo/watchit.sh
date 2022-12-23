#!/usr/bin/env sh

watch 'netstat -an | grep 127.0.0.1 && lsof -i -n | grep -i python'
