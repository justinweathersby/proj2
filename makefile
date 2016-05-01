CC= g++
CCFLAGS= -g -Wall

exec: main.o bank.o makefile Customer.o manager.o teller.o
	$(CC) $(CCFLAGS) -o Prog main.o bank.o customer.o manager.o teller.o

main.o: main.C bank.h
	$(CC) $(CCFLAGS) -c main.C

bank.o: bank.C bank.h
	$(CC) $(CCFLAGS) -c bank.C

manager.o: manager.C manager.h
	$(CC) $(CCFLAGS) -c manager.C

Customer.o: Customer.C Customer.h
	$(CC) $(CCFLAGS) -c Customer.C

teller.o: teller.C teller.h
	$(CC) $(CCFLAGS) -c Teller.C

goodTeller.o: goodTeller.C goodTeller.h
	$(CC) $(CCFLAGS) -c goodTeller.C

badTeller.o: badTeller.C badTeller.h
	$(CC) $(CCFLAGS) -c badTeller.C

clean:
	rm -rf *.o
