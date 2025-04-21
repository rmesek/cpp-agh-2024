#include <iostream>
using namespace std;

class Instrument {
public:
	virtual ~Instrument() = default;
	virtual void play() const = 0;
};

class Wind : public Instrument {
public:
	void play() const override { cout << "Wind::play" << endl; }
};

class Percussion : public Instrument {
public:
	void play() const override { cout << "Percussion::play" << endl; }
};

class Stringed : public Instrument {
public:
	void play() const override { cout << "Stringed::play" << endl; }
};

class Brass : public Wind {
public:
	void play() const override { cout << "Brass::play" << endl; }
};

class Woodwind : public Wind {
public:
	void play() const override { cout << "Woodwind::play" << endl; }
};

void tune(Instrument& i) { i.play(); }

int main() {

	//	Upcasting during array initialization:
	Instrument *orchestra[] = {
		new Wind,
		new Percussion,
		new Stringed,
		new Brass,
		new Woodwind
	};

	for (auto *instrument : orchestra) {
		tune(*instrument);
		delete instrument;
	}

	return EXIT_SUCCESS;
}

