gcc -msse4.1 -o rand.o -c -Ofast -flto -pipe -fPIC -fno-plt -fstack-protector-strong -D_GNU_SOURCE rand.c
gcc -msse4.1 -o rand -Wl,-flto -lm rand.o
strip -s rand
rm rand.o
