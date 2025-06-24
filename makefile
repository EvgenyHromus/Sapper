build_windows:
	g++ -Wall -O2 -Wextra -o bin/sapper.exe -std=c++20 -pedantic \
	src/Main.cpp \
	lib/libglfw3.a -I lib/glfw3 -lgdi32 -lopengl32
build_linux:
	g++ -Wall -O2 -Wextra -o bin/sapper.out -std=c++20 -pedantic \
	src/Main.cpp \
	lib/libglfw3.a -I lib/glfw3 -lgdi32 -lopengl32