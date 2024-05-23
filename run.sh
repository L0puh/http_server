if [ ! -d "$build" ];
then mkdir build 
fi
cd build
cp ../res . -r
cmake ..
make
./server $1 
cd ..
