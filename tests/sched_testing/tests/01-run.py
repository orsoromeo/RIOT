#!/usr/bin/env python3

import sys


def testfunc(child):
    child.expect_exact('The output should be: yield 1, snd_thread running, '
                       'yield 2, done')
    child.expect_exact('---------------------------------------------------'
                       '-------------')
    child.expect_exact('yield 1')
    child.expect_exact('snd_thread running')
    child.expect_exact('yield 2')
    child.expect_exact('done')


if __name__ == "__main__":
    from testrunner import run
    sys.exit(run(testfunc))
