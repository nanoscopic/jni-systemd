CC = gcc
CFLAGS = -Wall -D_JNI_IMPLEMENTATION_ -I/usr/lib/jvm/java-1.7.0/include -I/usr/lib/jvm/java-1.7.0/include/linux -g -m64
MAKELIB = $(CC) $(CFLAGS) -shared -fPIC
COMPILE = $(CC) $(CFLAGS) -c

all: libSystemDTools.so Test Testc SystemDTools.jar

SystemDTools.jar: com/codechild/SystemDTools.class
	jar cf SystemDTools.jar com/codechild/*.class

Test: Test.java
	javac Test.java

Testc: main.o SystemDTools.o libSystemDTools.so
	$(CC) -o testc main.o -L. -lSystemDTools -lsystemd-daemon -ljvm -L/usr/lib/jvm/java-1.7.0/jre/lib/amd64/server

main.o: main.c
	$(COMPILE) -o main.o main.c

libSystemDTools.so: com_codechild_SystemDTools.h SystemDTools.c
	$(MAKELIB) -o libSystemDTools.so SystemDTools.c -lsystemd-daemon

com_codechild_SystemDTools.h: com/codechild/SystemDTools.class
	javah -jni com.codechild.SystemDTools

com/codechild/SystemDTools.class:
	javac com/codechild/SystemDTools.java

clean:
	rm -rf libSystemDTools.so *.class *.h *.o testc com/codechild/*.class

cleanall:
	rm -rf *.jar *.so
