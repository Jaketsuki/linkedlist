CC=g++
GTESTDIR=~/googletest/googletest
CFLAGS=-isystem
export COV_OUTPUT=./cov_output
testfunk: gtest-all.o libgtest.a test_case.c linkedlist.c Gtest_main.c linkedlist.h
	$(CC) -o my_test $(CFLAGS) $(GTESTDIR)/include -pthread test_case.c linkedlist.c Gtest_main.c libgtest.a --coverage
	make clean
gtest-all.o: 
	$(CC) $(CFLAGS) $(GTESTDIR)/include -I $(GTESTDIR) -pthread -c $(GTESTDIR)/src/gtest-all.cc
libgtest.a:
	ar -rv libgtest.a gtest-all.o
report:
	lcov -rc lcov_branch_coverage=1 -c -i -d . -o .coverage.base
	lcov -rc lcov_branch_coverage=1 -c -d . -o .coverage.run
	lcov -rc lcov_branch_coverage=1 -d . -a .coverage.base -a .coverage.run -o .coverage.total
	genhtml --branch-coverage -o ${COV_OUTPUT} .coverage.total
	rm -f .coverage.base .coverage.run .coverage.tota
clean:
	