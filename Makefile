CFLAGFS:=-I include/  -Wall -Wextra -g
SANFLAGS:=-fsanitize=address -fsanitize=undefined -fsanitize=leak

hw_0: obj/main.o obj/bmp.o obj/stego.o | obj
	gcc obj/main.o obj/bmp.o obj/stego.o -o hw_01

run: ./hw_01
	@LSAN_OPTIONS=detect_leaks=1 ./hw_01 $(ARGS)

obj:
	mkdir obj

obj/main.o: src/main.c include/bmp.h | obj
	gcc -c $(CFLAGFS) src/main.c -o obj/main.o 	

obj/bmp.o: src/bmp.c include/bmp.h | obj
	gcc -c $(CFLAGFS) src/bmp.c -o obj/bmp.o

obj/stego.o: src/stego.c include/stego.h include/bmp.h | obj 
	gcc -c $(CFLAGFS) src/stego.c -o obj/stego.o 	

.PHONY: clean run
clean: 
	rm -rf hw_01 obj *.bmp *.txt