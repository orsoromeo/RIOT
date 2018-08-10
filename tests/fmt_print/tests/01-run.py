#!/usr/bin/env python3

import sys


def testfunc(child):
    child.expect_exact('If you can read this:')
    child.expect_exact('Test successful.')


if __name__ == "__main__":
    from testrunner import run
    sys.exit(run(testfunc))
