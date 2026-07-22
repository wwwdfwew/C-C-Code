mylog_test: mylog_test.cc myspdlog.cc
	g++ -std=c++17 $^ -o $@ -lspdlog -lpthread -lfmt -lgflags
clean:
	rm -f mylog_test myspdlog.o
