#makefile MethodRating class
CC= g++
MethodRating: MethodRatingApp.o MethodRating.o
	$(CC) MethodRatingApp.o MethodRating.o -o MethodRating

MethodRatingApp.o: MethodRatingApp.cpp
	$(CC) -c MethodRatingApp.cpp

MethodRating.o: MethodRating.h MethodRating.cpp
	$(CC) -c MethodRating.h
	$(CC) -c MethodRating.cpp
clean:
	rm -rf *o MethodRating
	rm -rf *h.gch MethodRating
