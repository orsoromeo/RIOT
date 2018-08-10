#!/usr/bin/env python3

import sys


def testfunc(child):
    child.expect('main starting')
    child.expect('msg available: 1 \(should be 1\!\)')


if __name__ == "__main__":
    from testrunner import run
    sys.exit(run(testfunc))
