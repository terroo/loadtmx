# LoadTmx
To Parser .tmx with C++ to TileMap

---

# How to use parser
To use it, you need to either install [TinyXML2](https://github.com/leethomason/tinyxml2) or use it without installing [in this repository](https://github.com/terroo/tinyxml2) in short that I did a *fork*.

But the best option is to install it on your system. Below example of installation on **Ubuntu** and derivatives:

```sh
sudo apt install libtinyxml2-dev
```

Now just clone with your preferred version control, example with [Git](https://github.com/git/git)

```sh
git clone https://github.com/terroo/loadtmx
```
> And copy the `loadtmx.hpp` file to your project.

To implement it, just create any file, include `loadtmx.hpp` and use either `std::vector<std::vector<int>>` or `auto`, for example:

> `vim main.cpp`
```cpp
#include "loadtmx.hpp"

int main( int argc , char **argv ){
  auto map = LoadTmx::tilemap("file.tmx");
}
```

Suppose you have [this `.tmx`](https://gist.github.com/terroo/875d1b41a823c35b20c7c3cdb3004753) and you want to parser each number in it:
> To download this example use *raw* from Gist or run the command below:
```sh
wget https://cutt.ly/tilemaptmx -O tilemap.tmx
```

Now add it to your code and print each position with a `for` loop:

```cpp
#include "loadtmx.hpp"

int main( int argc , char **argv ){
  auto map = LoadTmx::tilemap("tilemap.tmx");

  for(auto &line : map){
    for(auto &col : line){
      std::cout << col;
    }
    std::cout << '\n';
  }
  return 0;
}
```

To compile, run:
```sh
g++ main.cpp -ltinyxml2
./a.out
```
> The possible output will be precisely the position numbers that were stored in `line` and `col`

If you want to use a classic loop it would be:

```cpp
for(std::size_t i{}; i < map.size(); ++i){
  for(std::size_t j{}; j < map[i].size(); ++j){
    std::cout << map[i][j];
  }
  std::cout << '\n';
}
```

If using local TinyXML2 instead of installed on your system, compile along with the TinyXML2 `.cpp` file, eg `g++ main.cpp tinyxml2/tinyxml2.cpp`.

> **Note**: It already includes the `<iostream>` and `<vector>` by default, so including it you can already remove any other use of these libraries in your code to avoid overhead.



