#!/usr/bin/env bash

set -e
set -o pipefail

function print_header() {
    echo -e "\n***** ${1} *****"
}

print_header "RUN cppcheck"
if [ "${1}" == "--local" ]; then
	CPPCHECK="cppcheck"
else
	CPPCHECK="./linters/cppcheck/cppcheck"
fi
${CPPCHECK} . -ibuild -iext -igtest -ideps --enable=all --error-exitcode=1 -I include --suppress=missingIncludeSystem # --check-config

print_header "RUN cpplint.py"
python2.7 ./linters/cpplint/cpplint.py --extensions=cpp include/* src/*

print_header "SUCCESS"
