run.exe: yourfile.cpp
    clang++ -o run.exe code.cpp

clean:
    del run.exe
