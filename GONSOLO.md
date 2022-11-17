# Configure with ccache
CXX='ccache g++' CC='ccache gcc' ./waf configure --optimize --compile-database

# Debug grid
cd gtk2_ardour; pw-jack ./ardev -D Grid ~/work/Ofenroehr/Ofenroehr.ardour
