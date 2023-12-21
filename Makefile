ARDEV = ./gtk2_ardour/ardev
ARDBG = ./gtk2_ardour/ardbg
SESSION = ~/work/Ofenroehr/Ofenroehr.ardour
DEBUG = --debug-symbols

all: run
configure:
	CXX='ccache g++' CC='ccache gcc' ./waf configure $(DEBUG) --optimize --compile-database
compile: configure
	mold --run ./waf
run: compile
	pw-jack $(ARDEV) $(SESSION)
e: empty
empty: compile
	pw-jack $(ARDEV)
debug:
	pw-jack $(ARDBG) $(SESSION)
clean:
	./waf clean
