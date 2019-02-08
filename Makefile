me3-0: ctrlshow.o title.o load.o main.o
	cc ctrlshow.o title.o load.o main.o -lncurses -o me3-0

main.o: main.c ctrlshow.h load.h title.h structure.h
	cc -c main.c -lncurses -Wall

ctrlshow.o: ctrlshow.c ctrlshow.h structure.h
	cc -c ctrlshow.c -lncurses -Wall

title.o: title.c title.h structure.h
	cc -c title.c -lncurses -Wall

load.o: load.c load.h structure.h
	cc -c load.c -lncurses -Wall

.PHONY: clean distclean

clean:
	-rm *.o

distclean: clean
	-rm me3-0

dist: distclean
	(cd ..; tar zcvf me3-0.tgz me3-0)
