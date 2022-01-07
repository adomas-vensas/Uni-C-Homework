all: main2

main2: main2.c
		gcc main2.c slltool.c revlist.c -o main2.exe
