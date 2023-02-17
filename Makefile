ARDEV = ./gtk2_ardour/ardev
ARDBG = ./gtk2_ardour/ardbg

all: configure compile run
configure:
	#CXX='ccache g++' CC='ccache gcc' ./waf configure --debug-symbols --optimize --compile-database
	CXX='ccache g++' CC='ccache gcc' ./waf configure --optimize --compile-database
compile:
	mold -run ./waf
	#./waf
run:
	pw-jack $(ARDEV) ~/work/Ofenroehr/Ofenroehr.ardour
run_empty:
	pw-jack $(ARDEV)
debug:
	pw-jack $(ARDBG) ~/work/Ofenroehr/Ofenroehr.ardour
clean:
	./waf clean
