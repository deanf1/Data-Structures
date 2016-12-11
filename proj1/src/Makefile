all: Driver.o SeismicDataCollector.o SeismicEvent.o AcousticNoise.o AnthropogenicEvent.o Earthquake.o Explosion.o MiningExplosion.o QuarryBlast.o
	g++ -Wall Driver.o SeismicDataCollector.o SeismicEvent.o AcousticNoise.o AnthropogenicEvent.o Earthquake.o Explosion.o MiningExplosion.o QuarryBlast.o -o driver.out

Driver.o: Driver.cpp
	g++ -Wall -c Driver.cpp
	
SeismicDataCollector.o: SeismicDataCollector.cpp
	g++ -Wall -c SeismicDataCollector.cpp

SeismicEvent.o: SeismicEvent.cpp
	g++ -Wall -c SeismicEvent.cpp
	
AcousticNoise.o: AcousticNoise.cpp
	g++ -Wall -c AcousticNoise.cpp
	
AnthropogenicEvent.o: AnthropogenicEvent.cpp
	g++ -Wall -c AnthropogenicEvent.cpp
	
Earthquake.o: Earthquake.cpp
	g++ -Wall -c Earthquake.cpp
	
Explosion.o: Explosion.cpp
	g++ -Wall -c Explosion.cpp
	
MiningExplosion.o: MiningExplosion.cpp
	g++ -Wall -c MiningExplosion.cpp
	
QuarryBlast.o: QuarryBlast.cpp
	g++ -Wall -c QuarryBlast.cpp

clean:
	rm -rf *.o
	rm -f *.out
	rm -f results*.txt
	rm -f *~*.h.gch *#[

run:
	./driver.out $(FILE)