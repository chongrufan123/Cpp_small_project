address_book.out:contens.o main.o contact.o basic.o file.o
	g++ *.o -o $@
contens.o:../Source/contents.cpp
	g++ -c ../Source/contents.cpp -o $@ -I ../Include/
main.o:../Source/main.cpp
	g++ -c ../Source/main.cpp -o $@ -I ../Include/
contact.o:../Source/contact.cpp
	g++ -c ../Source/contact.cpp -o $@ -I ../Include/
basic.o:../Source/basic.cpp
	g++ -c ../Source/basic.cpp -o $@ -I ../Include/
file.o:../Source/file.cpp
	g++ -c ../Source/file.cpp -o $@ -I ../Include/

clean:
	rm -f *.o address_book.out
