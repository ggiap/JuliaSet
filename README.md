# JuliaSet
Julia set explorer. The app captures images every time the camera moves and saves them in a folder located in the application directory.

## Built With

* [SFML](https://www.sfml-dev.org/) - The framework used for rendering
* [CMake](https://cmake.org/) - Build System
* [conan](https://conan.io/) - Open source package manager/dependency manager

## Prerequisites

### $Windows

#### Python/pip
```
Download and install Python and pip from the official website.
```

#### CMake
```
Donwload and install CMake from the official website.
```

#### conan
After installing pip run the following command:
```
pip install conan
```

## Installing

### Clone the repo
```
git clone https://github.com/ggiap/JuliaSet.git
```

### Create a build folder

```
cd JuliaSet
mkdir build
cd build
```

### Build the executable

***Using MinGW:***
##### Debug build
```
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Debug .. && mingw32-make -j4
```

##### Release build
```
cmake -G "MinGW Makefiles" -DCMAKE_BUILD_TYPE=Release .. && mingw32-make -j4
```

##### Run
```
cd bin && ./JuliaSet
```


***Using MSVC:***
##### Debug build
```
cmake -DCMAKE_BUILD_TYPE=Debug ..
```

##### Release build
```
cmake -DCMAKE_BUILD_TYPE=Release ..
```

##### Run
```
Locate the .sln file and open it
```
```
Select Build -> Build Solution
```
```
Select Debug -> Start without debugging
```


### $Manjaro

#### pip
```
sudo pacman -Syu python-pip
```

#### conan
```
pip install conan
```

#### CMake
```
sudo pacman -Syu cmake
```

## Installing

### Clone the repo
```
git clone https://github.com/ggiap/JuliaSet.git
```

### Create a build folder

```
cd JuliaSet
mkdir build
cd build
```

### Build the executable

##### Debug build
```
cmake -DCMAKE_BUILD_TYPE=Debug .. && make
```

##### Release build
```
cmake -DCMAKE_BUILD_TYPE=Release .. && make
```

##### Run
```
cd bin && ./JuliaSet
```

![](Gif/Julia.gif)

## Controls

* **W A S D:** Camera panning
* **- +:** Zoom in/out

## License

This project is licensed under the MIT License - see the [LICENSE.md](https://github.com/ggiap/MandelbrotSet/blob/master/LICENSE) file for details

