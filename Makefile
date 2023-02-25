ARDEV = ./gtk2_ardour/ardev
ARDBG = ./gtk2_ardour/ardbg
SESSION = ~/work/Ofenroehr/Ofenroehr.ardour
DEBUG = --debug-symbols

all: configure compile run
configure:
	CXX='ccache g++' CC='ccache gcc' ./waf configure $(DEBUG) --optimize --compile-database
compile:
	mold --run ./waf
	#./waf
run:
	pw-jack $(ARDEV) $(SESSION)
run_empty:
	pw-jack $(ARDEV)
debug:
	pw-jack $(ARDBG) $(SESSION)
clean:
	./waf clean
