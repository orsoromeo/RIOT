#!/usr/bin/env python3

import sys


def testfunc(child):
    child.expect('START')

    for i in range(12):
        child.expect('Creating thread with arg {}'.format(i + 1))

    for i in range(12):
        child.expect('join thread {}'.format(i + 1))

    child.expect('SUCCESS')


if __name__ == "__main__":
    from testrunner import run
    sys.exit(run(testfunc))
