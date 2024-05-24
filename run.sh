if [ ! -d "$build" ];
then mkdir build 
fi
cd build
cp ../res . -r
cmake .. -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
make
./server $1 
cd ..
