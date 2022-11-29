# Configure with ccache:
CXX='ccache g++' CC='ccache gcc' ./waf configure --optimize --compile-database

# Compile:
./waf

# Use lld: (While configuring: ... --use-lld)

# Use mold: (While compiling: mold -run ...)

# Debug grid
cd gtk2_ardour; pw-jack ./ardev -D Grid ~/work/Ofenroehr/Ofenroehr.ardour
