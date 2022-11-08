all: liba1.so liba2.so main

# liba1.so:a1.cpp
# 	g++ -fpic -shared -o liba1.so a1.cpp

# liba2.so:a2.cpp
# 	g++ -fpic -shared -o liba2.so a2.cpp

# main:main.cpp
# 	g++ -o main main.cpp -ldl

liba1.so:a1.cpp
	clang++ -fpic -shared -o liba1.so a1.cpp

liba2.so:a2.cpp
	clang++ -fpic -shared -o liba2.so a2.cpp

main:main.cpp
	clang++ -o main main.cpp -ldl

clean:
	rm liba1.so liba2.so main
