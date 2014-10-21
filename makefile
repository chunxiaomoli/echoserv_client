all:server client 
.PHONY:all

server:server.o str_echo.o writen.o readline.o sig_chld.o 
	gcc -o server server.o str_echo.o writen.o readline.o sig_chld.o

client:client.o str_echo_client.o writen.o readline.o 
	gcc -o client client.o str_echo_client.o writen.o readline.o
server.o:server.c unp.h
	gcc -c server.c
sig_chld.o:sig_chld.c unp.h
	gcc -c sig_chld.c 
str_echo.o:str_echo.c unp.h
	gcc -c str_echo.c
client.o:client.c  unp.h
	gcc -c client.c  
str_echo_client.o:str_echo_client.c  unp.h
	gcc -c str_echo_client.c 
writen.o:writen.c unp.h
	gcc -c writen.c
readline.o:readline.c unp.h
	gcc -c readline.c
readn.o:readn.c unp.h
	gcc -c readn.c
clean:
	rm -rf *.o
